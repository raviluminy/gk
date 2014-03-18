#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget* parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	dao.connect();
	ui->waybillTableView->setModel(dao.waybillModel());

	connect(ui->waybillTableView, SIGNAL(clicked(QModelIndex)), this, SLOT(on_waybillTableView_clicked(QModelIndex)));
}

MainWindow::~MainWindow() {
	dao.disconnect();
	delete ui;
}

void
MainWindow::on_waybillTableView_clicked(const QModelIndex index) {
	if (!index.isValid()) return;
	QModelIndex pkindex = index.sibling(index.row(), 0);
	qDebug() << "primary key clicked:" << pkindex.data();
}

