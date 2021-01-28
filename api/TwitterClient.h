//
// Created by nullobsi on 2021/01/27.
//

#ifndef QWITTER_TWITTERCLIENT_H
#define QWITTER_TWITTERCLIENT_H
#include <QtNetworkAuth/QtNetworkAuth>


class TwitterClient : public QOAuth1 {
    Q_OBJECT
public:
    TwitterClient(QString clientId, QString clientSecret, QObject *parent = nullptr);
public slots:
    static void openBrowser(const QUrl& url);
    void getTimeline();

signals:
    void Authenticated();

    void TimelineUpdated(const QJsonDocument response);

private slots:
    void gotTimeline();
private:
    QOAuthHttpServerReplyHandler *replyHandler = nullptr;

    static const QJsonDocument parseJson(QNetworkReply *resp);
    static const QUrl timelineHome;
};


#endif //QWITTER_TWITTERCLIENT_H
