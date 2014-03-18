#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget* parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	dao.setupDb();
	ui->waybillTableView->setModel(dao.waybillModel());
}

MainWindow::~MainWindow() {
	delete ui;
}

void
MainWindow::activeWaybill(const int x, const int y) {
	const int id = -1;
	id = dao.waybillModel()->data(QModelIndex(0,y));
	dao.activedWaybillModel(id); // model retourné à appliquer à la frame...
}

