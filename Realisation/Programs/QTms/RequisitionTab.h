#ifndef REQUISITIONTAB_H
#define REQUISITIONTAB_H

#include "LogisticTab.h"

class QAbstractItemModel;
class QWidget;

namespace Ui {
class RequisitionTab;
}

class RequisitionTab : public LogisticTab {

	Q_OBJECT

public:

	explicit RequisitionTab(QWidget* parent = 0);
	virtual ~RequisitionTab();

	virtual void setModel(QAbstractItemModel* model);

private:

	void initBooleans();
	void initFields();
	void setAlertMessageOn(const QVariant& alert, const char* message, const QList<QWidget*> widgets);

protected:

	Ui::RequisitionTab* ui;

private slots:

	void on_countryCodeLineEdit_textChanged(const QString& newText);
	void on_idLineEdit_textChanged(const QString& newText);
	void on_originLineEdit_textChanged(const QString& newText);
	void on_destinationLineEdit_textChanged(const QString& newText);
	void on_deliveryDateEdit_dateChanged(const QDate& date);

private:

	bool countryCodeIsValid;
	bool requisitionIdIsValid;
	bool originIsValid;
	bool destinationIsValid;
	bool deliveryDateIsValid;

};

#endif // REQUISITIONTAB_H
