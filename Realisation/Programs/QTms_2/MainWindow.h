#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "LogisticDao.h"

#include <QMainWindow>
#include "Frame/requisitionframe.h"
#include "Frame/waybillframe.h"
#include "Frame/driverframe.h"
#include "Frame/vehicleframe.h"
#include "Frame/providerframe.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:

	explicit MainWindow(QWidget *parent = 0);

	virtual ~MainWindow();


	void loadCss();


private:
    void requisitionTabInit();
    void wayBillTabInit();
    void vehicleTabInit();
    void providerTabInit();
    void driverTabInit();

private:

	Ui::MainWindow *ui;

	LogisticDao dao;

};

#endif // MAINWINDOW_H
