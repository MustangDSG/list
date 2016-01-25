QT += core
QT -= gui

CONFIG += c++11

QMAKE_CXXFLAGS += -Wall -O2

TARGET = List
CONFIG += console
CONFIG -= app_bundle

#To build the program in Linux-like system, you must disable #define windows

DEFINES += "windows"

TEMPLATE = app

SOURCES += main.cpp
