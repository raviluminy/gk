#ifndef REQUISITIONFRAME_H
#define REQUISITIONFRAME_H

#include <QFrame>
#include <QDebug>

namespace Ui {
class RequisitionFrame;
}

class RequisitionFrame : public QFrame
{
    Q_OBJECT

public:
    explicit RequisitionFrame(QWidget *parent = 0);
    ~RequisitionFrame();

private slots:

    void on_requisitionRequestedDate_dateChanged(const QDate &date);

    void on_requisitionIdLineEdit_textChanged(const QString &newText);

    void on_waybillWarehouseLineEdit_2_textChanged(const QString &newText);

    void on_requisitionCountryCodeLineEdit_textChanged(const QString &newtext);

    void on_waybillTransportVehicleLineEdit_2_textChanged(const QString &newText);

    void on_waybillTransportRegistrationNoLineEdit_2_textChanged(const QString &newText);

    void on_waybillPlanningPlannedLoadingActorLineEdit_2_textChanged(const QString &newText);

    void on_waybillPlanningPlannedTransportActorLineEdit_2_textChanged(const QString &newText);

    void on_waybillPlanningPlannedReceptionActorLineEdit_2_textChanged(const QString &newText);

    void on_waybillPlanningPlannedLoadingDateEdit_2_dateChanged();

    void on_waybillPlanningRealLoadingDateEdit_2_dateChanged();

    void on_waybillPlanningPlannedTransportDateEdit_2_dateChanged();

    void on_waybillPlanningRealTransportDateEdit_2_dateChanged();

    void on_waybillPlanningPlannedReceptionDateEdit_2_dateChanged();

    void on_waybillPlanningRealReceptionDateEdit_2_dateChanged();

private:
    void checkPlannedDates();
    void checkRealDates();

private:
    Ui::RequisitionFrame *ui;

    bool countryCodeIsValid;
    bool requestedDateIsValid;
    bool requisitionIdIsValid;
    bool warehouseIsValid;
    bool vehicleIsValid;
    bool registrationNumberIsvalid;
    bool plannedLoadingActorIsValid;
    bool realLoadingActorIsValid;
    bool plannedTransportActorIsValid;
    bool realTransportActorIsValid;
    bool plannedReceptionActorIsValid;
    bool realReceptionActorIsValid;
    bool plannedLoadingDateIsValid;
    bool realLoadingDateIsValid;
    bool plannedTransportDateIsValid;
    bool realTransportDateIsValid;
    bool plannedReceptionDateIsValid;
    bool realReceptionDateIsValid;
};

#endif // REQUISITIONFRAME_H
