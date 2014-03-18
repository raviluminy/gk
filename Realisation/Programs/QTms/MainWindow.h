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

	explicit MainWindow(QWidget *parent = 0);

	virtual ~MainWindow();

public slots:

	void activeWaybill(const int, const int);

private:

	Ui::MainWindow *ui;

	LogisticDao dao;

};

#endif // MAINWINDOW_H
