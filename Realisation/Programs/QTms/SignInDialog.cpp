#include "SignInDialog.h"
#include "ui_SignInDialog.h"

SignInDialog::SignInDialog(Directory *dir, QWidget *parent) :
	QDialog(parent),
	ui(new Ui::SignInDialog)
{
	ui->setupUi(this);
    this->dir = dir;
}

SignInDialog::~SignInDialog()
{
	delete ui;
}

void SignInDialog::on_submit_clicked()
{
    QString login = ui->userNameLineEdit->text();
    QString pass = ui->userPasswordLineEdit->text();
    bool logged = dir->authentification(login, pass);
    if (!logged) QMessageBox::critical(this, "Login failed", "Failed to log as " + login);
    else QMessageBox::about(this, "Login succeed", "You are now logged as " + login);
    emit auth(logged, login);
    parent()->deleteLater();
}
