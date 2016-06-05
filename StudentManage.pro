#-------------------------------------------------
#
# Project created by QtCreator 2016-05-10T01:07:02
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StudentManage
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    login.cpp \
    database.cpp

HEADERS  += widget.h \
    login.h \
    database.h

FORMS    += widget.ui \
    login.ui
