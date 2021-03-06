#-------------------------------------------------
#
# Project created by QtCreator 2016-02-01T14:50:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gbsprited
TEMPLATE = app

CONFIG   += -std=c++11
QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    drawingcanvas.cpp \
    newimagedialog.cpp \
    sprite.cpp \
    cppspriteexporter.cpp \
    binaryspriteexporter.cpp \
    gbspriteexporter.cpp \
    spriteexporter.cpp \
    customspriteexporter.cpp \
    spriteimporter.cpp

HEADERS  += mainwindow.h \
    drawingcanvas.h \
    newimagedialog.h \
    sprite.h \
    cppspriteexporter.h \
    binaryspriteexporter.h \
    gbspriteexporter.h \
    spriteexporter.h \
    customspriteexporter.h \
    spriteimporter.h

FORMS    += mainwindow.ui \
    newimagedialog.ui
