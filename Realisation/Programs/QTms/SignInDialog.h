#ifndef SIGNINDIALOG_H
#define SIGNINDIALOG_H

#include <QDialog>

namespace Ui {
class SignInDialog;
}

class SignInDialog : public QDialog
{
	Q_OBJECT

public:
	explicit SignInDialog(QWidget *parent = 0);
	~SignInDialog();

private:
	Ui::SignInDialog *ui;
};

#endif // SIGNINDIALOG_H
