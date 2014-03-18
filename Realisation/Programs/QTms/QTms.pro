#-------------------------------------------------
#
# Project created by QtCreator 2014-03-16T17:45:46
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QTms
TEMPLATE = app


SOURCES += Main.cpp\
        MainWindow.cpp \
    LogisticDao.cpp

HEADERS  += MainWindow.h \
    LogisticDao.h

FORMS    += \
    MainWindow.ui

RESOURCES += \
    gui.qrc
