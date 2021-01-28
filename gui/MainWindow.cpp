//
// Created by nullobsi on 2021/01/27.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "TimelineTweet.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    scrollLayout = new QVBoxLayout(ui->scrollAreaWidgetContents);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::SetTwitterClient(TwitterClient *inclient) {
    client = inclient;

    qDebug() << client->tokenCredentials();
    this->show();
    connect(client, &TwitterClient::TimelineUpdated, this, &MainWindow::timelineUpdated);
    client->getTimeline();
}

void MainWindow::timelineUpdated(const QJsonDocument doc) {
    if (doc.isObject()) {
        const auto obj = doc.object();
        const auto errs = obj.value("errors").toArray();
        QStringList errors;
        for (const auto err : errs) {
            errors.append(err.toObject().value("message").toString());
        }

        QMessageBox::warning(this, "Error!", errors.join("<br/>"));
        return;
    }

    const auto tweets = doc.array();
    for (const auto tweet : tweets) {
        TimelineTweet *dispTweet = new TimelineTweet(ui->scrollAreaWidgetContents);
        const auto obj = tweet.toObject();
        dispTweet->setContent(obj.value("text").toString());
        dispTweet->setUsername(obj.value("user").toObject().value("name").toString());
        scrollLayout->addWidget(dispTweet);
    }
}
