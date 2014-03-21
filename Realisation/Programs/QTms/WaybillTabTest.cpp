#include "WaybillTabTest.h"
#include "ui_WaybillTab.h"
#include "Util.h"
#include <QtTest>
#include <QtWidgets>

WaybillTabTest::WaybillTabTest(QWidget* parent) :
	WaybillTab(parent) {
    loadCss();
}

WaybillTabTest::~WaybillTabTest() {
}

void
WaybillTabTest::loadCss() {
    QFile css("WebCommon.css");
    if (css.open(QIODevice::ReadOnly)) {
        qApp->setStyleSheet(css.readAll());
        css.close();
    }
}

void
WaybillTabTest::testCountryCode() {
	lineEditTest(ui->countryCodeLineEdit, QString("Fr"), QString("Fr"));
}

void
WaybillTabTest::testId() {
	lineEditTest(ui->idLineEdit, QString("7"), QString("7"));
}

void
WaybillTabTest::testPlannedLoading() {
	lineEditTest(ui->plannedLoadingActorLineEdit,     QString("Actor"),     QString("Actor"));
	lineEditTest(ui->plannedLoadingConditionLineEdit, QString("Condition"), QString("Condition"));
	lineEditTest(ui->plannedLoadingLocationLineEdit,  QString("Location"),  QString("Location"));
}

void
WaybillTabTest::testPlannedReception() {
	lineEditTest(ui->plannedReceptionActorLineEdit,     QString("Actor"),     QString("Actor"));
	lineEditTest(ui->plannedReceptionConditionLineEdit, QString("Condition"), QString("Condition"));
	lineEditTest(ui->plannedReceptionLocationLineEdit,  QString("Location"),  QString("Location"));
}

void
WaybillTabTest::testPlannedTransport() {
	lineEditTest(ui->plannedTransportActorLineEdit,     QString("Actor"),     QString("Actor"));
	lineEditTest(ui->plannedTransportConditionLineEdit, QString("Condition"), QString("Condition"));
	lineEditTest(ui->plannedTransportLocationLineEdit,  QString("Location"),  QString("Location"));
}

void
WaybillTabTest::testRealLoading() {
	lineEditTest(ui->realLoadingActorLineEdit,     QString("Actor"),     QString("Actor"));
	lineEditTest(ui->realLoadingConditionLineEdit, QString("Condition"), QString("Condition2"));
	lineEditTest(ui->realLoadingLocationLineEdit,  QString("Location"),  QString("Location"));
}

void
WaybillTabTest::testRealReception() {
	lineEditTest(ui->realReceptionActorLineEdit,     QString("Actor"),     QString("Actor"));
	lineEditTest(ui->realReceptionConditionLineEdit, QString("Condition"), QString("Condition"));
	lineEditTest(ui->realReceptionLocationLineEdit,  QString("Location"),  QString("Location"));
}

void
WaybillTabTest::testRealTransport() {
	lineEditTest(ui->realTransportActorLineEdit,     QString("Actor"),     QString("Actor"));
	lineEditTest(ui->realTransportConditionLineEdit, QString("Condition"), QString("Condition"));
	lineEditTest(ui->realTransportLocationLineEdit,  QString("Location"),  QString("Location"));
}

#if 0
void
MainWindowTest::testStatus(){
	QComboBox *test = ui->waybillStatusComboBox_3;
	QCOMPARE(test->itemText(0) ,QString("Cancelled"));
	QCOMPARE(test->itemText(1) ,QString("Cancelled and deleted"));
	QCOMPARE(test->itemText(2) ,QString("Done"));
	QCOMPARE(test->itemText(3) ,QString("In progress"));
	QCOMPARE(test->itemText(4) ,QString("Undelivered"));
}
#endif

/*void
WaybillTabTest::testStatusComment() {
    textEditTest(ui->, QString("Blablabla"), QString("Blablabla"));
}*/

void
WaybillTabTest::testTransportRegistrationNo() {
	lineEditTest(ui->transportRegistrationNoLineEdit, QString("200"), QString("200"));
}

void
WaybillTabTest::testTransportVehicle() {
	lineEditTest(ui->transportVehicleLineEdit, QString("100"), QString("100"));
}

void
WaybillTabTest::testWarehouse() {
	lineEditTest(ui->warehouseLineEdit, QString("Marseille"), QString("Marseille"));
}

void
WaybillTabTest::lineEditTest(QLineEdit* tested, const QString& entry, const QString& expected) {
	QTest::mouseClick(tested, Qt::LeftButton, Qt::NoModifier, tested->pos());
	QTest::keyClicks(tested, entry);
	QCOMPARE(tested->text(), expected);
}

void
WaybillTabTest::textEditTest(QTextEdit* tested, const QString& entry, const QString& expected) {
	QTest::mouseClick(tested, Qt::LeftButton, Qt::NoModifier, tested->pos());
	QTest::keyClicks(tested, entry);
	QCOMPARE(tested->toPlainText(), expected);
}

void
WaybillTabTest::cleanupTestCase(){
    QTest::qWait(5000);
}

void
WaybillTabTest::initTestCase() {

}
