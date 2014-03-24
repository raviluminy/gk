#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "LogisticDao.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:

	explicit MainWindow(QWidget* parent = 0);

	virtual ~MainWindow();

public slots:

	void loadTheme(const QString& name);

	void onSignIn();
	void onSignOut();

private:

	Ui::MainWindow *ui;

	LogisticDao dao;

	QString theme;

};

#endif // MAINWINDOW_H
