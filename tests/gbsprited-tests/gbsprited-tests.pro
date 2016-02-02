#-------------------------------------------------
#
# Project created by QtCreator 2016-02-01T17:56:08
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_sprite
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_sprite.cpp \
	../../gbsprited/sprite.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"
