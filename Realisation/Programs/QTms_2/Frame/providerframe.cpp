#include "providerframe.h"
#include "ui_providerframe.h"

ProviderFrame::ProviderFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::ProviderFrame)
{
    ui->setupUi(this);
}

ProviderFrame::~ProviderFrame()
{
    delete ui;
}
