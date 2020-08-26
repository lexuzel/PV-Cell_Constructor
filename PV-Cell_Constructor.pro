QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Builders/Builder.cpp \
    LayerManager.cpp \
    PVLayer.cpp \
    Screens/FileManagerScreen.cpp \
    Screens/InfoScreen.cpp \
    Screens/LayerOptionsScreen.cpp \
    Screens/PreferencesScreen.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Builders/Builder.h \
    LayerManager.h \
    PVLayer.h \
    Screens/FileManagerScreen.h \
    Screens/InfoScreen.h \
    Screens/LayerOptionsScreen.h \
    Screens/PreferencesScreen.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    PV-Cell_Constructor_uk_UA.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
