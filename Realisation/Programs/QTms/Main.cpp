/* Tests */
#include "Util.h"
#include <QtTest>
#include "WaybillTabTest.h"
#include "RequisitionTabTest.h"
#include "StatusWidgetGroupTest.h"
/* Tests */

#include "MainWindow.h"
#include <QApplication>

int main(int argc, char** argv) {

    QApplication a(argc, argv);
    if (argc > 1){
        WaybillTabTest test;
        RequisitionTabTest test2;
        StatusWidgetGroupTest test3;
        return QTest::qExec(&test) | QTest::qExec(&test2) | QTest::qExec(&test3) ;
    }
    else{
        MainWindow w;
        w.show();
        return a.exec();
    }
}


