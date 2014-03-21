#include "RequisitionTabTest.h"
#include "ui_RequisitionTab.h"
#include "Util.h"
#include <QtTest>
#include <QtWidgets>

RequisitionTabTest::RequisitionTabTest(QWidget* parent) :
    RequisitionTab(parent) {
    loadCss();
}

RequisitionTabTest::~RequisitionTabTest() {
}

void
RequisitionTabTest::loadCss() {
    QFile css("WebCommon.css");
    if (css.open(QIODevice::ReadOnly)) {
        qApp->setStyleSheet(css.readAll());
        css.close();
    }
}

void
RequisitionTabTest::testCountryCode() {
    lineEditTest(ui->countryCodeLineEdit, QString("Fr"), QString("Fr"));
}

void
RequisitionTabTest::testId() {
    lineEditTest(ui->idLineEdit, QString("8"), QString("8"));
}

void
RequisitionTabTest::testOrigin() {
    lineEditTest(ui->originLineEdit, QString("Name1"), QString("Name1"));
}

void
RequisitionTabTest::testDestination() {
    lineEditTest(ui->destinationLineEdit, QString("Name2"), QString("Name2"));
}

void
RequisitionTabTest::testRequesterName() {
    lineEditTest(ui->requesterNameLineEdit, QString("Requester Name"), QString("Requester Name"));
}

void
RequisitionTabTest::testProjectManager() {
    lineEditTest(ui->projectManagerLineEdit, QString("Project Manager"), QString("Project Manager"));
}

void
RequisitionTabTest::testFinanceOfficer() {
    lineEditTest(ui->financeOfficerLineEdit, QString("Finance Officer"), QString("Finance Officer"));
}

void
RequisitionTabTest::testLogistics() {
    lineEditTest(ui->logisticsLineEdit, QString("Logistics"), QString("Logistics"));
}

void
RequisitionTabTest::testGlobalFleetBase() {
    lineEditTest(ui->globalFleetBaseLineEdit, QString("Logistics"), QString("Logistics"));
}

void
RequisitionTabTest::lineEditTest(QLineEdit* tested, const QString& entry, const QString& expected) {
    QTest::mouseClick(tested, Qt::LeftButton, Qt::NoModifier, tested->pos());
    QTest::keyClicks(tested, entry);
    QCOMPARE(tested->text(), expected);
}

void
RequisitionTabTest::textEditTest(QTextEdit* tested, const QString& entry, const QString& expected) {
    QTest::mouseClick(tested, Qt::LeftButton, Qt::NoModifier, tested->pos());
    QTest::keyClicks(tested, entry);
    QCOMPARE(tested->toPlainText(), expected);
}

void
RequisitionTabTest::cleanupTestCase(){
    QTest::qWait(5000);
}

void
RequisitionTabTest::initTestCase() {

}
