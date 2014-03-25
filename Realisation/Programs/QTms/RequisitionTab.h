#ifndef REQUISITIONTAB_H
#define REQUISITIONTAB_H

#include "LogisticTab.h"
#include <QDebug>
#include <QDate>
#include <QLabel>
#include <QTreeWidgetItem>
#include "requisition.h"

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
    void reloadTableView();
    void refreshTableView();
    void resetFields();

protected:

	Ui::RequisitionTab* ui;

private slots:

	void on_countryCodeLineEdit_textChanged(const QString& newText);
	void on_idLineEdit_textChanged(const QString& newText);
	void on_originLineEdit_textChanged(const QString& newText);
	void on_destinationLineEdit_textChanged(const QString& newText);
	void on_deliveryDateEdit_dateChanged(const QDate& date);
    void on_dataListView_clicked(const QModelIndex &index);
    void on_confirmationOkPushButton_clicked();

    void on_requesterNameLineEdit_textChanged(const QString &newText);

    void on_projectManagerLineEdit_textChanged(const QString &newText);

    void on_financeOfficerLineEdit_textChanged(const QString &newText);

    void on_logisticsLineEdit_textChanged(const QString &newText);

    void on_globalFleetBaseLineEdit_textChanged(const QString &newText);

    void on_requesterDateEdit_dateChanged(const QDate &newText);

    void on_projectManagerDateEdit_dateChanged(const QDate &date);

    void on_financeOfficerDateEdit_dateChanged(const QDate &date);

    void on_logisticsDateEdit_dateChanged(const QDate &date);

    void on_globalFleetBaseDateEdit_dateChanged(const QDate &date);

    void on_requestDateEdit_dateChanged(const QDate &date);

    void on_commitPushButton_clicked();

    void on_rollbackPushButton_clicked();

    void on_addPushButton_clicked();

private:

    bool adding;
    bool editing;
	bool countryCodeIsValid;
	bool requisitionIdIsValid;
	bool originIsValid;
	bool destinationIsValid;
    bool deliveryDateIsValid;
    QString requisitionId;
    QVector <QString> idList;
    Requisition *currentRequisition;

    bool currentRequisitionIsEdited;
    QVector <Requisition *> *requisitionList;



};

#endif // REQUISITIONTAB_H
