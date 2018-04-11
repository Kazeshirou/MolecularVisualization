#-------------------------------------------------
#
# Project created by QtCreator 2017-12-14T12:27:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = molecularvisualization
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    dialog.cpp \
    view.cpp \
    context.cpp \
    colorbutton.cpp \
    sphere.cpp \
    camera.cpp \
    cilinder.cpp \
    atom.cpp \
    bond.cpp \
    molecule.cpp \
    contextgl.cpp \
    contextshader.cpp \
    viewgl.cpp \
    viewshader.cpp \
    basecontext.cpp \
    baseview.cpp

HEADERS += \
        mainwindow.h \
    dialog.h \
    baseview.h \
    view.h \
    transformational.h \
    basecontext.h \
    context.h \
    colorbutton.h \
    sphere.h \
    camera.h \
    cilinder.h \
    atom.h \
    bond.h \
    molecule.h \
    contextgl.h \
    contextshader.h \
    viewgl.h \
    viewshader.h

FORMS += \
        mainwindow.ui \
    dialog.ui

DISTFILES += \
    vert.vsh \
    frag.fsh \
    spherefrag.fsh \
    spherevert.vsh

RESOURCES += \
    resource.qrc
