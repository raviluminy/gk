#ifndef WAYBILLTAB_H
#define WAYBILLTAB_H

#include "Util.h"
#include "LogisticTab.h"

class QAbstractItemModel;
class QWidget;

namespace Ui {
class WaybillTab;
}

class WaybillTab : public LogisticTab {

	Q_OBJECT

public:

	explicit WaybillTab(QWidget* parent = 0);
	virtual ~WaybillTab();

	virtual void setModel(QAbstractItemModel* model);

private slots:

	void on_idTitle_toggled(const bool checked);
	void on_planningTitle_toggled(const bool checked);
	void on_statusTitle_toggled(const bool checked);
	void on_transportTitle_toggled(const bool checked);

	void on_cancelEdition_clicked();
	void on_okEdition_clicked();

protected:

	void editDataEditionFields(const QModelIndex& index);
	void fillDataEditionFields(const QModelIndex& index);

	Ui::WaybillTab* ui;

private slots:

	void on_requestDateEdit_dateChanged(const QDate& date);
	void on_requisitionIdComboBox_textChanged(const QString& newText);
	void on_warehouseLineEdit_textChanged(const QString& newText);
	void on_countryCodeLineEdit_textChanged(const QString& newtext);
	void on_transportVehicleLineEdit_textChanged(const QString& newText);
	void on_transportRegistrationNoLineEdit_textChanged(const QString& newText);
	void on_plannedLoadingActorLineEdit_textChanged(const QString& newText);
	void on_plannedTransportActorLineEdit_textChanged(const QString& newText);
	void on_plannedReceptionActorLineEdit_textChanged(const QString& newText);
	void on_plannedLoadingDateEdit_dateChanged();
	void on_realLoadingDateEdit_dateChanged();
	void on_plannedTransportDateEdit_dateChanged();
	void on_realTransportDateEdit_dateChanged();
	void on_plannedReceptionDateEdit_dateChanged();
	void on_realReceptionDateEdit_dateChanged();

	void on_dataListView_clicked(const QModelIndex& index);

private:

	void initBooleans();
	void initFields();

	void checkPlannedDates();
	void checkRealDates();

protected:

	void setAlertMessageOn(const QVariant& alert, const char* message, const QList<QWidget*> widgets);

	enum DbColumn {
		CountryCode = 0, // destine a disparaitre
		Id,
		RequestDate,
		TransportMean,
		RequisitionId,
		RequisitionCountryCode, // destine a disparaitre
		VehicleId
//		ContractId // non present actuellement
		/* PLANNED PLANNING */
		/* Planned loading */
//		plannedLoadingActor,
//		plannedLoadingDate,
//		plannedLoadingLocation,
//		plannedLoadingCondition,
		/* Planned transport */
//		plannedTransportActor,
//		plannedTransportDate,
//		plannedTransportLocation,
//		plannedTransportCondition,
		/* Planned reception */
//		plannedReceptionActor,
//		plannedReceptionDate,
//		plannedReceptionLocation,
//		plannedReceptionCondition,
		/* REAL PLANNING */
		/* Real loading */
//		realLoadingActor,
//		realLoadingDate,
//		realLoadingLocation,
//		realLoadingCondition,
		/* Real transport */
//		realTransportActor,
//		realTransportDate,
//		realTransportLocation,
//		realTransportCondition,
		/* Real reception */
//		realReceptionActor,
//		realReceptionDate,
//		realReceptionLocation,
//		realReceptionCondition,
	};

	QVariant dataAt(const QModelIndex& index, const DbColumn column);
	QModelIndex indexAt(const QModelIndex& index, const DbColumn column);

private:

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

#endif // WAYBILLTAB_H
