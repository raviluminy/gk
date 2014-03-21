#include "StatusWidgetGroupTest.h"
#include "ui_StatusWidgetGroup.h"
#include "Util.h"
#include <QtTest>
#include <QtWidgets>

StatusWidgetGroupTest::StatusWidgetGroupTest(QWidget* parent) :
    StatusWidgetGroup(parent) {
    loadCss();
}

StatusWidgetGroupTest::~StatusWidgetGroupTest() {
}

void
StatusWidgetGroupTest::loadCss() {
    QFile css("WebCommon.css");
    if (css.open(QIODevice::ReadOnly)) {
        qApp->setStyleSheet(css.readAll());
        css.close();
    }
}

void StatusWidgetGroupTest::testComment(){
    textEditTest(ui->statusCommentTextEdit, QString("Blablabla"), QString("Blablabla"));
}

void
StatusWidgetGroupTest::lineEditTest(QLineEdit* tested, const QString& entry, const QString& expected) {
    QTest::mouseClick(tested, Qt::LeftButton, Qt::NoModifier, tested->pos());
    QTest::keyClicks(tested, entry);
    QCOMPARE(tested->text(), expected);
}

void
StatusWidgetGroupTest::textEditTest(QTextEdit* tested, const QString& entry, const QString& expected) {
    QTest::mouseClick(tested, Qt::LeftButton, Qt::NoModifier, tested->pos());
    QTest::keyClicks(tested, entry);
    QCOMPARE(tested->toPlainText(), expected);
}

void
StatusWidgetGroupTest::cleanupTestCase(){
    QTest::qWait(5000);
}

void
StatusWidgetGroupTest::initTestCase() {

}
