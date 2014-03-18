#include "MainWindow.h"
#include "ui_MainWindow.h"

void
MainWindow::loadCss() {
	QFile css("web.css");
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
	dao.connect();
	ui->waybillTableView->setModel(dao.waybillModel());

	connect(ui->waybillTableView, SIGNAL(clicked(QModelIndex)), this, SLOT(on_waybillTableView_clicked(QModelIndex)));
	connect(ui->waybillAddPushButton, SIGNAL(clicked()), this, SLOT(loadCss()));

	ui->waybillIdLabel->setProperty("corner-bl", true);
	ui->waybillIdLabel->setProperty("corner-tl", true);
	ui->waybillIdLineEdit->setProperty("corner-br", true);
	ui->waybillIdLineEdit->setProperty("corner-tr", true);
	ui->waybillRequisitionIdLabel->setProperty("corner-bl", true);
	ui->waybillRequisitionIdLabel->setProperty("corner-tl", true);
	ui->waybillRequisitionIdComboBox->setProperty("corner-br", true);
	ui->waybillRequisitionIdComboBox->setProperty("corner-tr", true);
	ui->waybillCountryCodeLabel->setProperty("corner-bl", true);
	ui->waybillCountryCodeLabel->setProperty("corner-tl", true);
	ui->waybillCountryCodeLineEdit->setProperty("corner-br", true);
	ui->waybillCountryCodeLineEdit->setProperty("corner-tr", true);
	loadCss();
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

