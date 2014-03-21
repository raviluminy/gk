#include "ProviderTab.h"
#include "ui_ProviderTab.h"

ProviderTab::ProviderTab(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::ProviderTab)
{
	ui->setupUi(this);
}

ProviderTab::~ProviderTab()
{
	delete ui;
}
