#include "Util.h"
#include <QtTest>
#include "WaybillTabTest.h"
#include "RequisitionTabTest.h"
#include "MainWindow.h"
#include <QApplication>

int main(int argc, char** argv) {

    QApplication a(argc, argv);
    if (argc > 1){
        WaybillTabTest test;
        RequisitionTabTest test2;
        return QTest::qExec(&test) | QTest::qExec(&test2) ;
    }
    else{
        MainWindow w;
        w.show();
        return a.exec();
    }
}


