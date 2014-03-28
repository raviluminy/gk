#-------------------------------------------------
#
# Project created by QtCreator 2014-03-16T17:45:46
#
#-------------------------------------------------

QT       += core gui sql testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QTms
TEMPLATE = app

SOURCES += \
    Main.cpp\
    MainWindow.cpp \
    LogisticDao.cpp \
    WidgetGroup.cpp \
    DataInteractionToolBar.cpp \
    DataFrame.cpp \
    WaybillTab.cpp \
    RequisitionTab.cpp \
    StaffTab.cpp \
    ProviderTab.cpp \
    VehicleTab.cpp \
    WaybillTabTest.cpp \
    Util.cpp \
    StatusWidgetGroup.cpp \
    RequisitionTabTest.cpp \
    StatusWidgetGroupTest.cpp \
    VehicleTabTest.cpp \
    StaffTabTest.cpp \
    ProviderTabTest.cpp \
    LdapMock.cpp \
    LdapTest.cpp \
    LogisticTab.cpp \
    Ldap/Directory.cpp \
    Ldap/LDAPConnection.cpp \
    Ldap/StringList.cpp \
    SignInDialog.cpp \
    requisition.cpp \
    requisitionTest.cpp

HEADERS  += \
    MainWindow.h \
    LogisticDao.h \
    WidgetGroup.h \
    DataInteractionToolBar.h \
    DataFrame.h \
    WaybillTab.h \
    RequisitionTab.h \
    StaffTab.h \
    ProviderTab.h \
    VehicleTab.h \
    WaybillTabTest.h \
    Util.h \
    StatusWidgetGroup.h \
    RequisitionTabTest.h \
    StatusWidgetGroupTest.h \
    VehicleTabTest.h \
    StaffTabTest.h \
    ProviderTabTest.h \
    LdapMock.h \
    LdapTest.h \
    LogisticTab.h \
    Ldap/Directory.h \
    Ldap/LDAPConnection.h \
    Ldap/StringList.h \
    SignInDialog.h \
    requisition.h \
    requisitionTest.h

FORMS    += \
    MainWindow.ui \
    WidgetGroup.ui \
    DataInteractionToolBar.ui \
    DataFrame.ui \
    WaybillTab.ui \
    RequisitionTab.ui \
    StaffTab.ui \
    ProviderTab.ui \
    VehicleTab.ui \
    StatusWidgetGroup.ui \
    SignInDialog.ui

RESOURCES += \
    Gui.qrc

OTHER_FILES += \
    Logistic.DB.ini \
    Theme/Web/main.css \
    Theme/Web/alert.css

LIBS += -L$$PWD/Ldap/lib/ -lldapsdk

win32: INCLUDEPATH += $$PWD/Ldap/include/windows
else:unix:!macx:!symbian: INCLUDEPATH += $$PWD/Ldap/include/linux

win32: DEPENDPATH += $$PWD/Ldap/include/windows
else:unix:!macx:!symbian: DEPENDPATH += $$PWD/Ldap/include/linux
