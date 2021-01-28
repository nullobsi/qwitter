//
// Created by nullobsi on 2021/01/27.
//

#include "TwitterClient.h"
#include <QDesktopServices>

const QUrl TwitterClient::timelineHome = QUrl("https://api.twitter.com/1.1/statuses/home_timeline.json");


TwitterClient::TwitterClient(QString clientId, QString clientSecret, QObject *parent):
    QOAuth1(clientId, clientSecret, nullptr, parent) {

    replyHandler = new QOAuthHttpServerReplyHandler(1337, this);
    replyHandler->setCallbackPath("callback");

    setReplyHandler(replyHandler);
    setTemporaryCredentialsUrl(QUrl("https://api.twitter.com/oauth/request_token"));
    setAuthorizationUrl(QUrl("https://api.twitter.com/oauth/authorize"));
    setTokenCredentialsUrl(QUrl("https://api.twitter.com/oauth/access_token"));

    connect(this, &QAbstractOAuth::authorizeWithBrowser, this, &TwitterClient::openBrowser);
    connect(this, &QOAuth1::granted, this, &TwitterClient::Authenticated);

    grant();
}

void TwitterClient::openBrowser(const QUrl& url) {
    QDesktopServices::openUrl(url);
}

void TwitterClient::gotTimeline() {
    auto resp = qobject_cast<QNetworkReply*>(sender());

    emit TimelineUpdated(TwitterClient::parseJson(resp));
}

void TwitterClient::getTimeline() {
    QNetworkReply *reply = get(TwitterClient::timelineHome);

    connect(reply, &QNetworkReply::finished, this, &TwitterClient::gotTimeline);
}

const QJsonDocument TwitterClient::parseJson(QNetworkReply *resp) {
    resp->deleteLater();

    QJsonParseError e;
    const auto data = resp->readAll();
    auto doc = QJsonDocument::fromJson(data, &e);

    if (e.error) {
        qCritical() << "Error getting timeline!" << e.errorString();
        return QJsonDocument();
    }
    return doc;
}
