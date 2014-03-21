#include "RequisitionTab.h"
#include "ui_RequisitionTab.h"

RequisitionTab::RequisitionTab(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::RequisitionTab)
{
	ui->setupUi(this);
}

RequisitionTab::~RequisitionTab()
{
	delete ui;
}
