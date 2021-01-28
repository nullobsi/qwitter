//
// Created by nullobsi on 2021/01/27.
//

#ifndef QWITTER_TIMELINETWEET_H
#define QWITTER_TIMELINETWEET_H

#include <QWidget>
QT_BEGIN_NAMESPACE
namespace Ui { class TimelineTweet; }
QT_END_NAMESPACE

class TimelineTweet : public QWidget {
Q_OBJECT

public:
    explicit TimelineTweet(QWidget *parent = nullptr);

    ~TimelineTweet() override;
    void setUsername(QString s);
    void setContent(QString c);
private:
    Ui::TimelineTweet *ui;
};

#endif //QWITTER_TIMELINETWEET_H
