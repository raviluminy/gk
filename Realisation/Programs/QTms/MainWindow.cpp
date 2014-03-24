#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QFile>

void
MainWindow::loadCss() {
	QFile css("Web.css");
	if (css.open(QIODevice::ReadOnly)) {
		qApp->setStyleSheet(css.readAll());
		css.close();
	}
}

MainWindow::MainWindow(QWidget* parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	setWindowFlags(Qt::Window);// | Qt::FramelessWindowHint);
	loadCss();
	dao.connect();
	ui->providerTab   ->setModel(dao.providerModel());
	ui->requisitionTab->setModel(dao.requisitionModel());
	ui->staffTab      ->setModel(dao.staffModel());
	ui->vehicleTab    ->setModel(dao.vehicleModel());
	ui->waybillTab    ->setModel(dao.waybillModel());
}

MainWindow::~MainWindow() {
	dao.disconnect();
	delete ui;
}
/*
void
MainWindow::on_waybillTableView_clicked(const QModelIndex index) {
	if (!index.isValid()) return;
	QModelIndex pkindex = index.sibling(index.row(), 0);
	qDebug() << "primary key clicked:" << pkindex.data();
}
*/
