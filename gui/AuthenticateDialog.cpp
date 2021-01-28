//
// Created by nullobsi on 2021/01/27.
//

// You may need to build the project (run Qt uic code generator) to get "ui_AuthenticateDialog.h" resolved

#include "AuthenticateDialog.h"
#include "ui_AuthenticateDialog.h"

AuthenticateDialog::AuthenticateDialog(QWidget *parent) :
        QDialog(parent), ui(new Ui::AuthenticateDialog) {
    ui->setupUi(this);

    connect(ui->authenticateButton, &QPushButton::clicked, this, &AuthenticateDialog::AuthenticateClicked);
}

AuthenticateDialog::~AuthenticateDialog() {
    delete ui;
}

void AuthenticateDialog::AuthenticateClicked() {
    this->setEnabled(false);
    client = new TwitterClient(ui->consumerId->text(), ui->consumerSecret->text());
    connect(client, &TwitterClient::Authenticated, this, &AuthenticateDialog::TwitDoneAuth);
}

void AuthenticateDialog::TwitDoneAuth() {
    emit FinishedAuthenticating(client);
}
