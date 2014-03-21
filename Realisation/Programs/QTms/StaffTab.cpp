#include "StaffTab.h"
#include "ui_StaffTab.h"

StaffTab::StaffTab(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::StaffTab)
{
	ui->setupUi(this);
}

StaffTab::~StaffTab() {
	delete ui;
}
