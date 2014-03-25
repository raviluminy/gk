#-------------------------------------------------
#
# Project created by QtCreator 2014-03-16T17:45:46
#
#-------------------------------------------------

QT       += core gui sql testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QTms
TEMPLATE = app

SOURCES += Main.cpp\
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
    annuaire/Directory.cpp \
    annuaire/LDAPConnection.cpp \
    annuaire/StringList.cpp

HEADERS  += MainWindow.h \
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
    annuaire/Directory.h \
    annuaire/LDAPConnection.h \
    annuaire/StringList.h

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
    StatusWidgetGroup.ui

RESOURCES += \
    Gui.qrc

OTHER_FILES += \
    Logistic.DB.ini \
    Web.css \
    Web.Alert.css

LIBS += -L$$PWD/annuaire/lib/ -lldapsdk

win32: INCLUDEPATH += $$PWD/annuaire/include/windows
else:unix:!macx:!symbian: INCLUDEPATH += $$PWD/annuaire/include/linux

win32: DEPENDPATH += $$PWD/annuaire/include/windows
else:unix:!macx:!symbian: DEPENDPATH += $$PWD/annuaire/include/linux
