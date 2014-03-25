#ifndef REQUISITION_H
#define REQUISITION_H

#include <QString>
#include <QDate>
#include <QVector>
#include <QtSql/QSqlDatabase>
#include <QtSQL/QSqlError>
#include <QtSQL/QSqlQuery>
#include <QMessageBox>
#include <QVariant>
#include <QDebug>

class Requisition
{
public:
    Requisition(QString requisitionId, QString countryCode, QString forCostEstimate, QString forPurchase,
                QString whDispatchRelease, QDate requisitionDate, QDate desiredDeliveryDate, QString transportMeans,
                QString localisationId, QString localisationId_1, QString currencyId, QDate agreementDate,
                QString personId, QDate agreementDate_manager, QString personId_2, QDate agreementDate_requester,
                QString personId_3, QDate agreementDate_logistics, QString personId_4, QDate agreementDate_globalFleetBase,
                QString personId_5);

    static QVector<Requisition *> *getList();

    static Requisition *getRequisition(QString id);

    bool add();

    bool update();

    QString getRequisitionId() const;
    void setRequisitionId(QString value);

    QString getCountryCode() const;
    void setCountryCode(const QString &value);

    QString getForCostEstimate() const;
    void setForCostEstimate(const QString &value);

    QString getForPurchase() const;
    void setForPurchase(const QString &value);

    QString getWhDispatchRelease() const;
    void setWhDispatchRelease(const QString &value);

    QDate getRequisitionDate() const;
    void setRequisitionDate(const QDate &value);

    QDate getDesiredDeliveryDate() const;
    void setDesiredDeliveryDate(const QDate &value);

    QString getTransportMeans() const;
    void setTransportMeans(const QString &value);

    QString getLocalisationId() const;
    void setLocalisationId(const QString &value);

    QString getLocalisationId_1() const;
    void setLocalisationId_1(const QString &value);

    QString getCurrencyId() const;
    void setCurrencyId(const QString &value);

    QDate getAgreementDate() const;
    void setAgreementDate(const QDate &value);

    QString getPersonId() const;
    void setPersonId(const QString &value);

    QDate getAgreementDate_manager() const;
    void setAgreementDate_manager(const QDate &value);

    QString getPersonId_2() const;
    void setPersonId_2(const QString &value);

    QDate getAgreementDate_requester() const;
    void setAgreementDate_requester(const QDate &value);

    QString getPersonId_3() const;
    void setPersonId_3(const QString &value);

    QDate getAgreementDate_logistics() const;
    void setAgreementDate_logistics(const QDate &value);

    QString getPersonId_4() const;
    void setPersonId_4(const QString &value);

    QDate getAgreementDate_globalFleetBase() const;
    void setAgreementDate_globalFleetBase(const QDate &value);

    QString getPersonId_5() const;
    void setPersonId_5(const QString &value);

    bool getEdited() const;
    void setEdited(bool value);
    static QString nextId();

    bool getIsNew() const;
    void setIsNew(bool value);

private:
    QString requisitionId;
    QString countryCode;
    QString forCostEstimate;
    QString forPurchase;
    QString whDispatchRelease;
    QDate requisitionDate;
    QDate desiredDeliveryDate;
    QString transportMeans;
    QString localisationId;
    QString localisationId_1;
    QString currencyId;
    QDate agreementDate;
    QString personId;
    QDate agreementDate_manager;
    QString personId_2;
    QDate agreementDate_requester;
    QString personId_3;
    QDate agreementDate_logistics;
    QString personId_4;
    QDate agreementDate_globalFleetBase;
    QString personId_5;
    bool edited;
    bool isNew;
};

#endif // REQUISITION_H
