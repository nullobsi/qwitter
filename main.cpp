#include <QApplication>
#include <QPushButton>
#include "gui/AuthenticateDialog.h"
#include "gui/MainWindow.h"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    AuthenticateDialog d;
    QObject::connect(&d, &AuthenticateDialog::FinishedAuthenticating, &w, &MainWindow::SetTwitterClient);
    w.show();
    d.show();

    return QApplication::exec();
}
