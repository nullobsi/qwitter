//
// Created by nullobsi on 2021/01/27.
//

#ifndef QWITTER_AUTHENTICATEDIALOG_H
#define QWITTER_AUTHENTICATEDIALOG_H
#include "keychain.h"
#include <QDialog>
#include "../api/TwitterClient.h"
QT_BEGIN_NAMESPACE
namespace Ui { class AuthenticateDialog; }
QT_END_NAMESPACE

class AuthenticateDialog : public QDialog {
Q_OBJECT

public:
    explicit AuthenticateDialog(QWidget *parent = nullptr);

    ~AuthenticateDialog() override;
public slots:
    void TwitDoneAuth();
    void AuthenticateClicked();
signals:
    void FinishedAuthenticating(TwitterClient *client);


private:
    Ui::AuthenticateDialog *ui;
    QKeychain::WritePasswordJob *job;
    TwitterClient *client;
};

#endif //QWITTER_AUTHENTICATEDIALOG_H
