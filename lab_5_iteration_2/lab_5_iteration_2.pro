######################################################################
# Automatically generated by qmake (3.1) Fri May 24 12:37:55 2019
######################################################################

TEMPLATE = app
TARGET = lab_5_iteration_2
INCLUDEPATH += .

QT += widgets

# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += controller.h domain.h repository.h tests.h ui.h utils.h widget.h
SOURCES += controller.cpp \
           domain.cpp \
           main.cpp \
           repository.cpp \
           tests.cpp \
           ui.cpp \
           utils.cpp