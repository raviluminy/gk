#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

	QSqlTableModel* MainWindow::requisitionModel();
	QSqlTableModel* MainWindow::waybillModel();

	virtual void closeEvent(QCloseEvent* e);

	void loadDbSettings();
	void saveDbSettings();

public slots:
	void addRequisition();

private:
	Ui::MainWindow *ui;
	QString dbDriver;
	QString dbHostName;
	QString dbName;
	QString dbUserName;
	QString dbPassword;
	QSqlTableModel* reqModel;
	QSqlDatabase db2;

};

#endif // MAINWINDOW_H
