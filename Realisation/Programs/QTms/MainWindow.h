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

//	void on_waybillTableView_clicked(const QModelIndex index);

	void loadCss();

private slots:

	void on_waybillIdTitle_toggled(const bool checked);

	void on_waybillPlanningTitle_toggled(const bool checked);

	void on_waybillStatusTitle_toggled(const bool checked);

	void on_waybillTransportTitle_toggled(const bool checked);

private:

	Ui::MainWindow *ui;

	LogisticDao dao;

};

#endif // MAINWINDOW_H
