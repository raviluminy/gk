#include "Util.h"
#include <QtTest>
#include "WaybillTabTest.h"
#include "MainWindow.h"
#include <QApplication>

int main(int argc, char** argv) {

    QApplication a(argc, argv);
    if (argc > 1){
        WaybillTabTest test;
        return QTest::qExec(&test) ;
    }
    else{
        MainWindow w;
        w.show();
        return a.exec();
    }
}


