//
// Created by nullobsi on 2021/01/27.
//

#ifndef QWITTER_MAINWINDOW_H
#define QWITTER_MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include "../api/TwitterClient.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;
public slots:
    void SetTwitterClient(TwitterClient *client);
    void timelineUpdated(const QJsonDocument doc);
private:
    Ui::MainWindow *ui;
    TwitterClient *client;
    QVBoxLayout *scrollLayout;
};

#endif //QWITTER_MAINWINDOW_H
