#include "WidgetGroup.h"
#include "ui_WidgetGroup.h"

WidgetGroup::WidgetGroup(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::WidgetGroup)
{
	ui->setupUi(this);
}

WidgetGroup::~WidgetGroup()
{
	delete ui;
}
