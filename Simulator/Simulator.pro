#-------------------------------------------------
#
# Project created by QtCreator 2015-03-29T16:46:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Simulator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    IFormat.cpp \
    Instruction.cpp \
    JFormat.cpp \
    RFormat.cpp \
    Simulator.cpp \
    simulatorwindow.cpp

HEADERS  += mainwindow.h \
    IFormat.h \
    Instruction.h \
    JFormat.h \
    RFormat.h \
    Simulator.h \
    simulatorwindow.h

FORMS    += mainwindow.ui \
    simulatorwindow.ui
