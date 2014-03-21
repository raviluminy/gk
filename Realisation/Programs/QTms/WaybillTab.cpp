#include "WaybillTab.h"
#include "ui_WaybillTab.h"

WaybillTab::WaybillTab(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::WaybillTab)
{
	ui->setupUi(this);

	dao.connect();
	ui->dataListView->setModel(dao.waybillModel());
	ui->countryCodeWidgetGroup->setProperty("alert","warning");
	ui->idLineEdit->setProperty("alert","info");
	ui->requestDateWidgetGroup->setProperty("alert","error");
	ui->requisitionIdLabel->setProperty("alert","success");

	ui->idWidget->hide();
	ui->planningWidget->hide();
	ui->statusWidget->hide();
	ui->transportWidget->hide();

	ui->idTitle->toggle();
	ui->statusTitle->toggle();
}

WaybillTab::~WaybillTab()
{
	dao.disconnect();
	delete ui;
}

void
WaybillTab::on_idTitle_toggled(const bool checked) {
	if (checked) ui->idWidget->show();
	else         ui->idWidget->hide();
}

void
WaybillTab::on_planningTitle_toggled(const bool checked) {
	if (checked) ui->planningWidget->show();
	else         ui->planningWidget->hide();
}

void
WaybillTab::on_statusTitle_toggled(const bool checked) {
	if (checked) ui->statusWidget->show();
	else         ui->statusWidget->hide();
}

void
WaybillTab::on_transportTitle_toggled(const bool checked) {
//	if (checked) ui->transportWidget->show();
//	else         ui->transportWidget->hide();
	ui->transportWidget->setVisible(checked);
}
