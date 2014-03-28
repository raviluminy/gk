#include "ProviderTabTest.h"
#include "ui_ProviderTab.h"
#include "Util.h"
#include <QtTest>
#include <QtWidgets>

void
ProviderTabTest::loadCss() {
    QFile css("Theme/Web/main.css");
    if (css.open(QIODevice::ReadOnly)) {
        qApp->setStyleSheet(css.readAll());
        css.close();
    }
}

ProviderTabTest::ProviderTabTest(QWidget* parent) :
    ProviderTab(parent){
    loadCss();
}

ProviderTabTest::~ProviderTabTest(){

}

void
ProviderTabTest::testWaybillCountryCode (){
    lineEditTest(ui->waybillCountryCodeLineEdit,QString("FRA"),QString("FRA"));
}

void
ProviderTabTest::testWaybillId (){
    lineEditTest(ui->waybillIdLineEdit,QString("110"),QString("110"));
}

void
ProviderTabTest::testWaybillTransportVehicle (){
    lineEditTest(ui->waybillTransportVehicleLineEdit,QString("vh120"),QString("vh120"));
}

void
ProviderTabTest::testWaybillTransportRegistration (){
    lineEditTest(ui->waybillTransportRegistrationNoLineEdit,QString("56"),QString("56"));
}

void
ProviderTabTest::lineEditTest(QLineEdit* tested, const QString& entry, const QString& expected) {
    QTest::mouseClick(tested, Qt::LeftButton, Qt::NoModifier, tested->pos());
    QTest::keyClicks(tested, entry);
    QCOMPARE(tested->text(), expected);
}

void
ProviderTabTest::textEditTest(QTextEdit* tested, const QString& entry, const QString& expected) {
    QTest::mouseClick(tested, Qt::LeftButton, Qt::NoModifier, tested->pos());
    QTest::keyClicks(tested, entry);
    QCOMPARE(tested->toPlainText(), expected);
}

void
ProviderTabTest::cleanupTestCase(){
    QTest::qWait(5000);
}

void
ProviderTabTest::initTestCase() {

}
