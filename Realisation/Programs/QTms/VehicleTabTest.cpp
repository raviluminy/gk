#include "VehicleTabTest.h"
#include "ui_VehicleTab.h"
#include "Util.h"
#include <QtTest>
#include <QtWidgets>

void
VehicleTabTest::loadCss() {
    QFile css("Theme/Web/main.css");
    if (css.open(QIODevice::ReadOnly)) {
        qApp->setStyleSheet(css.readAll());
        css.close();
    }
}

VehicleTabTest::VehicleTabTest(QWidget* parent) :
    VehicleTab(parent){
    loadCss();
}

VehicleTabTest::~VehicleTabTest(){

}

void
VehicleTabTest::testVehicule (){
    lineEditTest(ui->vehicleLineEdit,QString("vh100"),QString("vh100"));
}

void
VehicleTabTest::testVehiculeRegistration (){
    lineEditTest(ui->registrationNoLineEdit,QString("100"),QString("100"));
}

void
VehicleTabTest::lineEditTest(QLineEdit* tested, const QString& entry, const QString& expected) {
    QTest::mouseClick(tested, Qt::LeftButton, Qt::NoModifier, tested->pos());
    QTest::keyClicks(tested, entry);
    QCOMPARE(tested->text(), expected);
}

void
VehicleTabTest::textEditTest(QTextEdit* tested, const QString& entry, const QString& expected) {
    QTest::mouseClick(tested, Qt::LeftButton, Qt::NoModifier, tested->pos());
    QTest::keyClicks(tested, entry);
    QCOMPARE(tested->toPlainText(), expected);
}

void
VehicleTabTest::cleanupTestCase(){
    QTest::qWait(50000);
}

void
VehicleTabTest::initTestCase() {

}
