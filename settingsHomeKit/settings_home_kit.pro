#-------------------------------------------------
#
# Project created by QtCreator 2017-08-04T17:05:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = settings_home_kit
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui


include ("/home/optimus/Documentos/source_code/qt/qt_libs/qextserialport-1.2rc/src/qextserialport.pri")
