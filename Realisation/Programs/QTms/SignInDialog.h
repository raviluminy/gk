#ifndef SIGNINDIALOG_H
#define SIGNINDIALOG_H

#include <QDialog>
#include <QDebug>
#include "Ldap/Directory.h"
#include <QMessageBox>

namespace Ui {
class SignInDialog;
}

class SignInDialog : public QDialog
{
	Q_OBJECT

public:
    explicit SignInDialog(Directory *dir, QWidget *parent = 0);
	~SignInDialog();

private slots:
    void on_submit_clicked();

signals:
    void auth(bool, QString);

private:
	Ui::SignInDialog *ui;
    Directory *dir;
};

#endif // SIGNINDIALOG_H
