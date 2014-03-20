#include "requisitionframe.h"
#include "ui_requisitionframe.h"

RequisitionFrame::RequisitionFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::RequisitionFrame)
{
    ui->setupUi(this);

    /**Logical Init**/
    countryCodeIsValid = false;
    requestedDateIsValid = false;
    requisitionIdIsValid = false;
    warehouseIsValid = false;
    vehicleIsValid = false;
    registrationNumberIsvalid = false;
    plannedLoadingActorIsValid = false;
    realLoadingActorIsValid = true;             //This is not a required field
    plannedTransportActorIsValid = false;
    realTransportActorIsValid = true;           //This is not a required field
    plannedReceptionActorIsValid = false;
    realReceptionActorIsValid = true;           //This is not a required field
    plannedLoadingDateIsValid = false;
    realLoadingDateIsValid = true;             //This is not a required field
    plannedTransportDateIsValid = false;
    realTransportDateIsValid = true;           //This is not a required field
    plannedReceptionDateIsValid = false;
    realReceptionDateIsValid = true;           //This is not a required field

    /**Default Values Init**/
    //Wwill trigger the related slots
    ui->requisitionRequestedDate->setDate(QDate::currentDate());
    ui->waybillPlanningPlannedLoadingDateEdit_2->setDate(QDate::currentDate());
    ui->waybillPlanningRealLoadingDateEdit_2->setDate(QDate::currentDate());
    ui->waybillPlanningPlannedTransportDateEdit_2->setDate(QDate::currentDate());
    ui->waybillPlanningRealTransportDateEdit_2->setDate(QDate::currentDate());
    ui->waybillPlanningPlannedReceptionDateEdit_2->setDate(QDate::currentDate());
    ui->waybillPlanningRealReceptionDateEdit_2->setDate(QDate::currentDate());

    /**ToolTips and errors init**/
    /** required fields**/
    ui->countryCodeValidatity->setToolTip(tr("Country code field must be filled"));
    ui->requisitionIdValidity->setToolTip(tr("Requisition ID field must be filled"));
    ui->warehouseValidity->setToolTip(tr("Warehouse field must be filled"));
    ui->vehicleValidity->setToolTip(tr("Vehicle field must be filled"));
    ui->registrationNumberValidity->setToolTip(tr("Registration number field must be filled"));
    ui->plannedLoadingActorValidity->setToolTip(tr("Planned loading actor field must be filled"));
    ui->plannedReceptionActorValidity->setToolTip(tr("Planned reception actor field must be filled"));
    ui->plannedTransportActorValidity->setToolTip(tr("Planned transport actor field must be filled"));
    /** not required fields**/
    ui->realLoadingActorValidity->hide();
    ui->realReceptionActorValidity->hide();
    ui->realTransportActorValidity->hide();

    /**Existing values Init**/
    //Will trigger the related slots and manage the errors

}

RequisitionFrame::~RequisitionFrame()
{
    delete ui;
}

void
RequisitionFrame::on_requisitionCountryCodeLineEdit_textChanged(const QString &newtext)
{
    /**Apply eventual conditions over countryCode**/
    if (newtext.size() != 3){
        ui->countryCodeValidatity->show();
        ui->countryCodeValidatity->setToolTip(tr("Country code must be 3 character"));
        countryCodeIsValid = false;
        return;
    }
    ui->countryCodeValidatity->hide();
    countryCodeIsValid = true;
}

void
RequisitionFrame::on_requisitionRequestedDate_dateChanged(const QDate &date)
{
    /**Apply eventual conditions over requisition requested date**/
    if (date < QDate::currentDate()){
        ui->requestDateValidity->show();
        ui->requestDateValidity->setToolTip(tr("Requested date must be at least today"));
        requestedDateIsValid = false;
        return;
    }
    ui->requestDateValidity->hide();
    requestedDateIsValid = true;
}

void RequisitionFrame::on_requisitionIdLineEdit_textChanged(const QString &newText)
{
    /**Apply eventual conditions over requisitionId**/
    if (newText.isEmpty()){
        ui->requisitionIdValidity->show();
        requisitionIdIsValid = false;
        //Tooltip remain the same
        return;
    }
    ui->requisitionIdValidity->hide();
    requisitionIdIsValid = true;
}

void RequisitionFrame::on_waybillWarehouseLineEdit_2_textChanged(const QString &newText)
{
    /**Apply eventual conditions over warehouse**/
    if (newText.isEmpty()){
        ui->warehouseValidity->show();
        warehouseIsValid = false;
        //Tooltip remain the same
        return;
    }
    ui->warehouseValidity->hide();
    warehouseIsValid = true;
}

void RequisitionFrame::on_waybillTransportVehicleLineEdit_2_textChanged(const QString &newText)
{
    /**Apply eventual conditions over vehicle**/
    if (newText.isEmpty()){
        ui->vehicleValidity->show();
        vehicleIsValid = false;
        //Tooltip remain the same
        return;
    }
    ui->vehicleValidity->hide();
    vehicleIsValid = true;
}

void RequisitionFrame::on_waybillTransportRegistrationNoLineEdit_2_textChanged(const QString &newText)
{
    /**Apply eventual conditions over registration number**/
    if (newText.isEmpty()){
        ui->registrationNumberValidity->show();
        registrationNumberIsvalid = false;
        //Tooltip remain the same
        return;
    }
    ui->registrationNumberValidity->hide();
    registrationNumberIsvalid = true;
}

void RequisitionFrame::on_waybillPlanningPlannedLoadingActorLineEdit_2_textChanged(const QString &newText)
{
    /**Apply eventual conditions over planned loading actor**/
    if (newText.isEmpty()){
        ui->plannedLoadingActorValidity->show();
        plannedLoadingActorIsValid = false;
        //Tooltip remain the same
        return;
    }
    ui->plannedLoadingActorValidity->hide();
    plannedLoadingActorIsValid = true;
}

void RequisitionFrame::on_waybillPlanningPlannedTransportActorLineEdit_2_textChanged(const QString &newText)
{
    /**Apply eventual conditions over planned transport actor**/
    if (newText.isEmpty()){
        ui->plannedTransportActorValidity->show();
        plannedTransportActorIsValid = false;
        //Tooltip remain the same
        return;
    }
    ui->plannedTransportActorValidity->hide();
    plannedTransportActorIsValid = true;
}

void RequisitionFrame::on_waybillPlanningPlannedReceptionActorLineEdit_2_textChanged(const QString &newText)
{
    /**Apply eventual conditions over planned transport actor**/
    if (newText.isEmpty()){
        ui->plannedReceptionActorValidity->show();
        plannedReceptionActorIsValid = false;
        //Tooltip remain the same
        return;
    }
    ui->plannedReceptionActorValidity->hide();
    plannedReceptionActorIsValid = true;
}

void RequisitionFrame::on_waybillPlanningPlannedLoadingDateEdit_2_dateChanged()
{
    checkPlannedDates();
}

void RequisitionFrame::on_waybillPlanningRealLoadingDateEdit_2_dateChanged()
{
    checkRealDates();
}

void RequisitionFrame::on_waybillPlanningPlannedTransportDateEdit_2_dateChanged()
{
    checkPlannedDates();
}

void RequisitionFrame::on_waybillPlanningRealTransportDateEdit_2_dateChanged()
{
    checkRealDates();
}

void RequisitionFrame::on_waybillPlanningPlannedReceptionDateEdit_2_dateChanged()
{
    checkPlannedDates();
}

void RequisitionFrame::on_waybillPlanningRealReceptionDateEdit_2_dateChanged()
{
    checkRealDates();
}

void RequisitionFrame::checkPlannedDates(){
    /**Errors will stack**/
    QString errors;
    QDate loadingDate = ui->waybillPlanningPlannedLoadingDateEdit_2->date();
    QDate transportDate = ui->waybillPlanningPlannedTransportDateEdit_2->date();
    QDate receptionDate = ui->waybillPlanningPlannedReceptionDateEdit_2->date();

    /**Hiding all the labels**/
    ui->plannedLoadingDateValidity->hide();
    ui->plannedReceptionDateValidity->hide();
    ui->plannedTransportDateValidity->hide();
    /**Setting validators at true**/
    plannedLoadingDateIsValid = true;
    plannedTransportDateIsValid = true;
    plannedReceptionDateIsValid = true;

    /**Loading > Transport**/
    if (loadingDate > transportDate){
        errors.append("\nTransport date must be at least loading date");
        plannedLoadingDateIsValid = false;
        plannedTransportDateIsValid = false;
        ui->plannedLoadingDateValidity->show();
        ui->plannedTransportDateValidity->show();
    }
    /**Loading > Reception**/
    if (loadingDate > receptionDate){
        errors.append("\nReception date must be at least loading date");
        plannedLoadingDateIsValid = false;
        plannedReceptionDateIsValid = false;
        ui->plannedLoadingDateValidity->show();
        ui->plannedReceptionDateValidity->show();
    }
    /**Transport > Reception**/
    if (transportDate > receptionDate){
        errors.append("\nReception date must be at least transport date");
        plannedTransportDateIsValid = false;
        plannedReceptionDateIsValid = false;
        ui->plannedTransportDateValidity->show();
        ui->plannedReceptionDateValidity->show();
    }

    /**Setting up the tooltips**/
    ui->plannedLoadingDateValidity->setToolTip(errors.mid(1));
    ui->plannedReceptionDateValidity->setToolTip(errors.mid(1));
    ui->plannedTransportDateValidity->setToolTip(errors.mid(1));
}

void RequisitionFrame::checkRealDates(){
    /**Errors will stack**/
    QString errors;
    QDate loadingDate = ui->waybillPlanningRealLoadingDateEdit_2->date();
    QDate transportDate = ui->waybillPlanningRealTransportDateEdit_2->date();
    QDate receptionDate = ui->waybillPlanningRealReceptionDateEdit_2->date();

    /**Hiding all the labels**/
    ui->realLoadingDateValidity->hide();
    ui->realReceptionDateValidity->hide();
    ui->realTransportDateValidity->hide();
    /**Setting validators at true**/
    realLoadingDateIsValid = true;
    realTransportDateIsValid = true;
    realReceptionDateIsValid = true;

    /**Loading > Transport**/
    if (loadingDate > transportDate){
        errors.append("\nTransport date must be at least loading date");
        realLoadingDateIsValid = false;
        realTransportDateIsValid = false;
        ui->realLoadingDateValidity->show();
        ui->realTransportDateValidity->show();
    }
    /**Loading > Reception**/
    if (loadingDate > receptionDate){
        errors.append("\nReception date must be at least loading date");
        realLoadingDateIsValid = false;
        realReceptionDateIsValid = false;
        ui->realLoadingDateValidity->show();
        ui->realReceptionDateValidity->show();
    }
    /**Transport > Reception**/
    if (transportDate > receptionDate){
        errors.append("\nReception date must be at least transport date");
        realTransportDateIsValid = false;
        realReceptionDateIsValid = false;
        ui->realTransportDateValidity->show();
        ui->realReceptionDateValidity->show();
    }

    /**Setting up the tooltips**/
    ui->realLoadingDateValidity->setToolTip(errors.mid(1));
    ui->realReceptionDateValidity->setToolTip(errors.mid(1));
    ui->realTransportDateValidity->setToolTip(errors.mid(1));
}
