#include "requisitionTest.h"
#include <QtTest>
#include <QtWidgets>


requisitionTest::requisitionTest(QWidget* parent)
{
    req = new Requisition(QString("01"), QString("fra"), QString("100"), QString("01"),
                          QString("bla"), QDate(2014,03,27), QDate(2014,03,28), QString("sea"),
                          QString("01"),QString("02"), QString("02"), QDate(2014,03,28),
                          QString("01"), QDate(2014,03,28), QString("02"), QDate(2014,03,28),
                          QString("03"), QDate(2014,03,28), QString("04"), QDate(2014,03,28),
                          QString("05"));
   requisitionList = new QVector <Requisition *>;
}

requisitionTest::~requisitionTest()
{

}

void requisitionTest::testGetRequisition()
{
    QCOMPARE(req->getRequisition("02")->getCountryCode() ,QString("RW"));
}

void requisitionTest::testGetList()
{
   requisitionList = Requisition::getList();
}

void requisitionTest::cleanupTestCase()
{

}

void requisitionTest::initTestCase()
{

    dao.connect();
}
