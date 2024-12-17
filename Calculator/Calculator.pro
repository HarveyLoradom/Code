QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    capacity.cpp \
    currency.cpp \
    date.cpp \
    main.cpp \
    mainwindow.cpp \
    mylineedit.cpp \
    programmer.cpp \
    science.cpp

HEADERS += \
    capacity.h \
    currency.h \
    date.h \
    mainwindow.h \
    mylineedit.h \
    programmer.h \
    science.h

FORMS += \
    capacity.ui \
    currency.ui \
    date.ui \
    mainwindow.ui \
    programmer.ui \
    science.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    rsc.qrc

DISTFILES += \
    img/Capacity.svg \
    img/Currency.svg \
    img/Date.svg \
    img/Menu.svg \
    img/Programmer.svg \
    img/Science.svg \
    img/Standard.svg
