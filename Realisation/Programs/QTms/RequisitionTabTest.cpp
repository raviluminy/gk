#include "RequisitionTabTest.h"
#include "ui_RequisitionTab.h"
#include "Util.h"

#ifdef TEST_GUI_WAYBILL_TAB

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
    QTest::qWait(10000);
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




#endif // TEST_GUI_WAYBILL_TAB

