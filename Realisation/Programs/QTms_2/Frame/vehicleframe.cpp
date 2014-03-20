#include "vehicleframe.h"
#include "ui_vehicleframe.h"

VehicleFrame::VehicleFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::VehicleFrame)
{
    ui->setupUi(this);
}

VehicleFrame::~VehicleFrame()
{
    delete ui;
}
