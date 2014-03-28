#include "requisition.h"

Requisition::Requisition(QString requisitionId, QString countryCode, QString forCostEstimate, QString forPurchase,
                         QString whDispatchRelease, QDate requisitionDate, QDate desiredDeliveryDate, QString transportMeans,
                         QString localisationId, QString localisationId_1, QString currencyId, QDate agreementDate,
                         QString personId, QDate agreementDate_manager, QString personId_2, QDate agreementDate_requester,
                         QString personId_3, QDate agreementDate_logistics, QString personId_4, QDate agreementDate_globalFleetBase,
                         QString personId_5)
{
    this->requisitionId = requisitionId;
    this->countryCode = countryCode;
    this->forCostEstimate = forCostEstimate;
    this->forPurchase = forPurchase;
    this->whDispatchRelease = whDispatchRelease;
    this->requisitionDate = requisitionDate;
    this->desiredDeliveryDate = desiredDeliveryDate;
    this->transportMeans = transportMeans;
    this->localisationId = localisationId;
    this->localisationId_1 = localisationId_1;
    this->currencyId = currencyId;
    this->agreementDate = agreementDate;
    this->personId = personId;
    this->agreementDate_manager = agreementDate_manager;
    this->personId_2 = personId_2;
    this->agreementDate_requester = agreementDate_requester;
    this->personId_3 = personId_3;
    this->agreementDate_logistics = agreementDate_logistics;
    this->personId_4 = personId_4;
    this->agreementDate_globalFleetBase = agreementDate_globalFleetBase;
    this->personId_5 = personId_5;
    this->edited = false;
    this->isNew = false;
}

/**Static : get one requisition by its id**/
Requisition *Requisition::getRequisition(QString id){
    QSqlQuery requeteur;
    Requisition *req = NULL;
    if (!requeteur.exec("SELECT * FROM Requisition WHERE RequisitionId = " + id + ";")) QMessageBox::critical(0, QObject::tr("erreur requete SQL"), requeteur.lastQuery());
    while(requeteur.next())
    {
        QString requisitionId = requeteur.value(0).toString();
        QString countryCode = requeteur.value(1).toString();
        QString forCostEstimate = requeteur.value(2).toString();
        QString forPurchase = requeteur.value(3).toString();
        QString whDispatchRelease = requeteur.value(4).toString();
        QDate requisitionDate = QDate::fromString(requeteur.value(5).toString(), "dd-MM-yyyy");
        QDate desiredDeliveryDate = QDate::fromString(requeteur.value(6).toString(), "dd-MM-yyyy");
        QString transportMeans = requeteur.value(7).toString();
        QString localisationId = requeteur.value(8).toString();
        QString localisationId_1 = requeteur.value(9).toString();
        QString currencyId = requeteur.value(10).toString();
        QDate agreementDate = QDate::fromString(requeteur.value(11).toString(), "dd-MM-yyyy");
        QString personId = requeteur.value(12).toString();
        QDate agreementDate_manager = QDate::fromString(requeteur.value(13).toString(), "dd-MM-yyyy");
        QString personId_2 = requeteur.value(14).toString();
        QDate agreementDate_requester = QDate::fromString(requeteur.value(15).toString(), "dd-MM-yyyy");
        QString personId_3 = requeteur.value(16).toString();
        QDate agreementDate_logistics = QDate::fromString(requeteur.value(17).toString(), "dd-MM-yyyy");
        QString personId_4 = requeteur.value(18).toString();
        QDate agreementDate_globalFleetBase = QDate::fromString(requeteur.value(19).toString(), "dd-MM-yyyy");
        QString personId_5 = requeteur.value(20).toString();
        req = new Requisition(requisitionId, countryCode, forCostEstimate, forPurchase, whDispatchRelease,
                                                requisitionDate, desiredDeliveryDate, transportMeans, localisationId, localisationId_1,
                                                currencyId, agreementDate, personId, agreementDate_manager, personId_2,
                                                agreementDate_requester, personId_3, agreementDate_logistics, personId_4,
                                                agreementDate_globalFleetBase, personId_5);
    }
    return req;
}

/**Static : get all the requisitions**/
QVector<Requisition *> *Requisition::getList(){
    QVector <Requisition *> *requisitionList = new QVector <Requisition *>;
    QSqlQuery requeteur;
    if (!requeteur.exec("SELECT * FROM Requisition;")) QMessageBox::critical(0, QObject::tr("erreur requete SQL"), requeteur.lastQuery());
    while(requeteur.next())
    {
        QString requisitionId = requeteur.value(0).toString();
        QString countryCode = requeteur.value(1).toString();
        QString forCostEstimate = requeteur.value(2).toString();
        QString forPurchase = requeteur.value(3).toString();
        QString whDispatchRelease = requeteur.value(4).toString();
        QDate requisitionDate = QDate::fromString(requeteur.value(5).toString(), "dd-MM-yyyy");
        QDate desiredDeliveryDate = QDate::fromString(requeteur.value(6).toString(), "dd-MM-yyyy");
        QString transportMeans = requeteur.value(7).toString();
        QString localisationId = requeteur.value(8).toString();
        QString localisationId_1 = requeteur.value(9).toString();
        QString currencyId = requeteur.value(10).toString();
        QDate agreementDate = QDate::fromString(requeteur.value(11).toString(), "dd-MM-yyyy");
        QString personId = requeteur.value(12).toString();
        QDate agreementDate_manager = QDate::fromString(requeteur.value(13).toString(), "dd-MM-yyyy");
        QString personId_2 = requeteur.value(14).toString();
        QDate agreementDate_requester = QDate::fromString(requeteur.value(15).toString(), "dd-MM-yyyy");
        QString personId_3 = requeteur.value(16).toString();
        QDate agreementDate_logistics = QDate::fromString(requeteur.value(17).toString(), "dd-MM-yyyy");
        QString personId_4 = requeteur.value(18).toString();
        QDate agreementDate_globalFleetBase = QDate::fromString(requeteur.value(19).toString(), "dd-MM-yyyy");
        QString personId_5 = requeteur.value(20).toString();
        requisitionList->append(new Requisition(requisitionId, countryCode, forCostEstimate, forPurchase, whDispatchRelease,
                                                requisitionDate, desiredDeliveryDate, transportMeans, localisationId, localisationId_1,
                                                currencyId, agreementDate, personId, agreementDate_manager, personId_2,
                                                agreementDate_requester, personId_3, agreementDate_logistics, personId_4,
                                                agreementDate_globalFleetBase, personId_5));
    }
    return requisitionList;
}

bool Requisition::add(){
    QSqlQuery requeteur;
    if (!requeteur.exec("INSERT INTO Requisition VALUES('" + requisitionId +
                        "', '" + countryCode +
                        "', '" + forCostEstimate +
                        "', '" + forPurchase +
                        "', '" + whDispatchRelease +
                        "', '" + requisitionDate.toString("dd-MM-yyyy") +
                        "', '" + desiredDeliveryDate.toString("dd-MM-yyyy") +
                        "', '" + transportMeans +
                        "', '" + localisationId +
                        "', '" + localisationId_1 +
                        "', '" + currencyId +
                        "', '" + agreementDate.toString("dd-MM-yyyy") +
                        "', '" + personId +
                        "', '" + agreementDate_manager.toString("dd-MM-yyyy") +
                        "', '" + personId_2 +
                        "', '" + agreementDate_requester.toString("dd-MM-yyyy") +
                        "', '" + personId_3 +
                        "', '" + agreementDate_logistics.toString("dd-MM-yyyy") +
                        "', '" + personId_4 +
                        "', '" + agreementDate_globalFleetBase.toString("dd-MM-yyyy") +
                        "', '" + personId_5 +

                        "');"
                        )){
        QMessageBox::critical(0, QObject::tr("erreur requete SQL"), requeteur.lastQuery());
        qDebug() << requeteur.lastQuery();
        return false;
    }
    isNew = false;
    edited = false;
    return true;
}

bool Requisition::update(){
    if (isNew){
        return add();
    }
    QSqlQuery requeteur;
    if (!requeteur.exec("UPDATE Requisition SET CountryCode = '" + countryCode +
                        "', ForCostEstimate = '" + forCostEstimate +
                        "', ForPurchase = '" + forPurchase +
                        "', WhDispatchRelease = '" + whDispatchRelease +
                        "', RequisitionDate = '" + requisitionDate.toString("dd-MM-yyyy") +
                        "', DesiredDeliveryDate = '" + desiredDeliveryDate.toString("dd-MM-yyyy") +
                        "', TransportMeans = '" + transportMeans +
                        "', LocalisationId = '" + localisationId +
                        "', LocalisationId_1 = '" + localisationId_1 +
                        "', CurrencyId = '" + currencyId +
                        "', AgreementDate = '" + agreementDate.toString("dd-MM-yyyy") +
                        "', PersonId = '" + personId +
                        "', AgreementDate_manager = '" + agreementDate_manager.toString("dd-MM-yyyy") +
                        "', PersonId_2 = '" + personId_2 +
                        "', AgreementDate_requester = '" + agreementDate_requester.toString("dd-MM-yyyy") +
                        "', PersonId_3 = '" + personId_3 +
                        "', AgreementDate = '" + agreementDate_logistics.toString("dd-MM-yyyy") +
                        "', PersonId_4 = '" + personId_4 +
                        "', AgreementDate_globalFleetBase = '" + agreementDate_globalFleetBase.toString("dd-MM-yyyy") +
                        "', PersonId_5 = '" + personId_5 +

                        "' WHERE RequisitionId = " +
                            requisitionId + ";"
                        )){
        QMessageBox::critical(0, QObject::tr("erreur requete SQL"), requeteur.lastQuery());
        return false;
    }
    edited = false;
    return true;
}


void Requisition::remove(){
    QSqlQuery requeteur;
    if (!requeteur.exec("DELETE FROM Requisition WHERE RequisitionId = " + requisitionId + ";"))
        QMessageBox::critical(0, QObject::tr("erreur requete SQL"), requeteur.lastQuery());
}

QString Requisition::getRequisitionId() const
{
    return requisitionId;
}

void Requisition::setRequisitionId(QString value)
{
    requisitionId = value;
}
QString Requisition::getCountryCode() const
{
    return countryCode;
}

void Requisition::setCountryCode(const QString &value)
{
    countryCode = value;
}
QString Requisition::getForCostEstimate() const
{
    return forCostEstimate;
}

void Requisition::setForCostEstimate(const QString &value)
{
    forCostEstimate = value;
}
QString Requisition::getForPurchase() const
{
    return forPurchase;
}

void Requisition::setForPurchase(const QString &value)
{
    forPurchase = value;
}
QString Requisition::getWhDispatchRelease() const
{
    return whDispatchRelease;
}

void Requisition::setWhDispatchRelease(const QString &value)
{
    whDispatchRelease = value;
}
QDate Requisition::getRequisitionDate() const
{
    return requisitionDate;
}

void Requisition::setRequisitionDate(const QDate &value)
{
    requisitionDate = value;
}
QDate Requisition::getDesiredDeliveryDate() const
{
    return desiredDeliveryDate;
}

void Requisition::setDesiredDeliveryDate(const QDate &value)
{
    desiredDeliveryDate = value;
}
QString Requisition::getTransportMeans() const
{
    return transportMeans;
}

void Requisition::setTransportMeans(const QString &value)
{
    transportMeans = value;
}
QString Requisition::getLocalisationId() const
{
    return localisationId;
}

void Requisition::setLocalisationId(const QString &value)
{
    localisationId = value;
}
QString Requisition::getLocalisationId_1() const
{
    return localisationId_1;
}

void Requisition::setLocalisationId_1(const QString &value)
{
    localisationId_1 = value;
}
QString Requisition::getCurrencyId() const
{
    return currencyId;
}

void Requisition::setCurrencyId(const QString &value)
{
    currencyId = value;
}
QDate Requisition::getAgreementDate() const
{
    return agreementDate;
}

void Requisition::setAgreementDate(const QDate &value)
{
    agreementDate = value;
}
QString Requisition::getPersonId() const
{
    return personId;
}

void Requisition::setPersonId(const QString &value)
{
    personId = value;
}
QDate Requisition::getAgreementDate_manager() const
{
    return agreementDate_manager;
}

void Requisition::setAgreementDate_manager(const QDate &value)
{
    agreementDate_manager = value;
}
QString Requisition::getPersonId_2() const
{
    return personId_2;
}

void Requisition::setPersonId_2(const QString &value)
{
    personId_2 = value;
}
QDate Requisition::getAgreementDate_requester() const
{
    return agreementDate_requester;
}

void Requisition::setAgreementDate_requester(const QDate &value)
{
    agreementDate_requester = value;
}
QString Requisition::getPersonId_3() const
{
    return personId_3;
}

void Requisition::setPersonId_3(const QString &value)
{
    personId_3 = value;
}
QDate Requisition::getAgreementDate_logistics() const
{
    return agreementDate_logistics;
}

void Requisition::setAgreementDate_logistics(const QDate &value)
{
    agreementDate_logistics = value;
}
QString Requisition::getPersonId_4() const
{
    return personId_4;
}

void Requisition::setPersonId_4(const QString &value)
{
    personId_4 = value;
}
QDate Requisition::getAgreementDate_globalFleetBase() const
{
    return agreementDate_globalFleetBase;
}

void Requisition::setAgreementDate_globalFleetBase(const QDate &value)
{
    agreementDate_globalFleetBase = value;
}
QString Requisition::getPersonId_5() const
{
    return personId_5;
}

void Requisition::setPersonId_5(const QString &value)
{
    personId_5 = value;
}
bool Requisition::getEdited() const
{
    return edited;
}

void Requisition::setEdited(bool value)
{
    edited = value;
}

QString Requisition::nextId(){
    QSqlQuery requeteur;
    int id = -1;
    if (!requeteur.exec("SELECT max(RequisitionId) FROM Requisition;")) QMessageBox::critical(0, QObject::tr("erreur requete SQL"), requeteur.lastQuery());
    if(requeteur.next())
    {
        id = requeteur.value(0).toInt() + 1;
    }
    return QString::number(id);
}
bool Requisition::getIsNew() const
{
    return isNew;
}

void Requisition::setIsNew(bool value)
{
    isNew = value;
}





















