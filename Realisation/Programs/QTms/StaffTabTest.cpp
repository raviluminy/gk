#include "StaffTabTest.h"
#include "ui_StaffTab.h"
#include "Util.h"
#include <QtTest>
#include <QtWidgets>

void
StaffTabTest::loadCss() {
    QFile css("Theme/Web/main.css");
    if (css.open(QIODevice::ReadOnly)) {
        qApp->setStyleSheet(css.readAll());
        css.close();
    }
}

StaffTabTest::StaffTabTest(QWidget* parent) :
    StaffTab(parent){
    loadCss();
}

StaffTabTest::~StaffTabTest(){

}

void
StaffTabTest::testId (){
    lineEditTest(ui->idLineEdit,QString("55"),QString("55"));
}

void
StaffTabTest::testLastName (){
    lineEditTest(ui->lastnameLineEdit,QString("Agopian"),QString("Agopian"));
}

void
StaffTabTest::testFirstName(){
    lineEditTest(ui->firstnameLineEdit,QString("Roland"),QString("Roland"));
}

void
StaffTabTest::testFix(){
    lineEditTest(ui->fixLineEdit,QString("0491502148"),QString("0491502148"));
}

void
StaffTabTest::testMobil(){
    lineEditTest(ui->mobilLineEdit,QString("0691502148"),QString("0691502148"));
}

void
StaffTabTest::testEmail(){
    lineEditTest(ui->emailLineEdit,QString("roland@agopian.fr"),QString("roland@agopian.fr"));
}

void
StaffTabTest::testAddress(){
    lineEditTest(ui->addressLineEdit,QString("171 Avenue de Luminy"),QString("171 Avenue de Luminy"));
}

void
StaffTabTest::testCategoty(){
    lineEditTest(ui->categoryLineEdit,QString("Class A"),QString("Class A"));
}


void
StaffTabTest::testNumber(){
    lineEditTest(ui->numberLineEdit,QString("15648547"),QString("15648547"));
}

void
StaffTabTest::lineEditTest(QLineEdit* tested, const QString& entry, const QString& expected) {
    QTest::mouseClick(tested, Qt::LeftButton, Qt::NoModifier, tested->pos());
    QTest::keyClicks(tested, entry);
    QCOMPARE(tested->text(), expected);
}

void
StaffTabTest::textEditTest(QTextEdit* tested, const QString& entry, const QString& expected) {
    QTest::mouseClick(tested, Qt::LeftButton, Qt::NoModifier, tested->pos());
    QTest::keyClicks(tested, entry);
    QCOMPARE(tested->toPlainText(), expected);
}

void
StaffTabTest::cleanupTestCase(){
    QTest::qWait(5000);
}

void
StaffTabTest::initTestCase() {

}


