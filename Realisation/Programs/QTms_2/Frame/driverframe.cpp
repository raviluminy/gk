#include "driverframe.h"
#include "ui_driverframe.h"

DriverFrame::DriverFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::DriverFrame)
{
    ui->setupUi(this);
}

DriverFrame::~DriverFrame()
{
    delete ui;
}
