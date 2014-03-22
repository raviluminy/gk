/* Tests */
#include "Util.h"
#include <QtTest>
#include "WaybillTabTest.h"
#include "RequisitionTabTest.h"
#include "StatusWidgetGroupTest.h"
#include "VehicleTabTest.h"
#include "StaffTabTest.h"
#include "ProviderTabTest.h"
#include "LdapTest.h"
/* Tests */

#include "MainWindow.h"
#include <QApplication>

int main(int argc, char** argv) {

    QApplication a(argc, argv);
    if (argc > 1){
        if (argv[1] == QString("-test1")){
            WaybillTabTest test;
            return QTest::qExec(&test) ;
         }
        else if (argv[1] == QString("-test2")){
            RequisitionTabTest test2;
            return QTest::qExec(&test2);
         }
        else if (argv[1] == QString("-test3")){
            StatusWidgetGroupTest test3;
            return QTest::qExec(&test3);
        }
        else if (argv[1] == QString("-test4")){
            VehicleTabTest test4;
            return QTest::qExec(&test4);
        }
        else if (argv[1] == QString("-test5")){
            StaffTabTest test5;
            return QTest::qExec(&test5);
        }

        else if (argv[1] == QString("-test6")){
            ProviderTabTest test6;
            return QTest::qExec(&test6);
        }
        else if (argv[1] == QString("-testldap")){
            LdapTest testldap;
            return QTest::qExec(&testldap);
        }
        else if (argv[1] == QString("-testall")){
            WaybillTabTest test;
            RequisitionTabTest test2;
            StatusWidgetGroupTest test3;
            VehicleTabTest test4;
            StaffTabTest test5;
            ProviderTabTest test6;
            LdapTest testldap;
            return QTest::qExec(&test) | QTest::qExec(&test2) | QTest::qExec(&test3) | QTest::qExec(&test4) | QTest::qExec(&test5)
                    | QTest::qExec(&test6) | QTest::qExec(&testldap);

        }

    }
    else{
        MainWindow w;
        w.show();
        return a.exec();
    }
}


