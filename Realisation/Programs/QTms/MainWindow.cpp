#include "MainWindow.h"
#include "ui_MainWindow.h"

void
MainWindow::loadCss() {
    QFile css("WebCommon.css");
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
	dao.connect();
	ui->waybillListTableView->setModel(dao.waybillModel());
	ui->waybillCountryCodeWidget->setProperty("alert","warning");
	ui->waybillIdLineEdit->setProperty("alert","info");
	ui->waybillRequestDateWidget->setProperty("alert","error");
	ui->waybillRequisitionIdLabel->setProperty("alert","success");

	ui->waybillIdWidget->hide();
	ui->waybillPlanningWidget->hide();
	ui->waybillStatusWidget->hide();
	ui->waybillTransportWidget->hide();

	ui->waybillIdTitle->toggle();
	ui->waybillStatusTitle->toggle();

//	connect(ui->waybillListTableView, SIGNAL(clicked(QModelIndex)), this, SLOT(on_waybillTableView_clicked(QModelIndex)));

	loadCss();
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

void
MainWindow::on_waybillIdTitle_toggled(const bool checked) {
	if (checked) ui->waybillIdWidget->show();
	else         ui->waybillIdWidget->hide();
}

void
MainWindow::on_waybillPlanningTitle_toggled(const bool checked) {
	if (checked) ui->waybillPlanningWidget->show();
	else         ui->waybillPlanningWidget->hide();
}

void
MainWindow::on_waybillStatusTitle_toggled(const bool checked) {
	if (checked) ui->waybillStatusWidget->show();
	else         ui->waybillStatusWidget->hide();
}

void
MainWindow::on_waybillTransportTitle_toggled(const bool checked) {
	if (checked) ui->waybillTransportWidget->show();
	else         ui->waybillTransportWidget->hide();
}
