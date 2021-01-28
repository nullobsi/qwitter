//
// Created by nullobsi on 2021/01/27.
//

// You may need to build the project (run Qt uic code generator) to get "ui_TimelineTweet.h" resolved

#include "TimelineTweet.h"
#include "ui_TimelineTweet.h"

TimelineTweet::TimelineTweet(QWidget *parent) :
        QWidget(parent), ui(new Ui::TimelineTweet) {
    ui->setupUi(this);
}

TimelineTweet::~TimelineTweet() {
    delete ui;
}

void TimelineTweet::setUsername(QString s) {
    ui->userName->setText(s);
}

void TimelineTweet::setContent(QString c) {
    ui->tweetContent->setText(c);
}
