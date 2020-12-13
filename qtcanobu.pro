QT       += core gui \
            uitools

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

DEFINES += VERSION="1.2"

win32:{
    RC_ICONS = $$PWD/img/main/cut.ico
    VERSION = 1.2
    QMAKE_TARGET_COMPANY = Kanobu Inc.
    QMAKE_TARGET_PRODUCT = QtCanobu
    QMAKE_TARGET_DESCRIPTION = Rewritten to c++ Qt port of original kanobu
    QMAKE_TARGET_COPYRIGHT = jDan735
}

SOURCES += \
    aboutapp.cpp \
    aboutqt.cpp \
    main.cpp \
    mainwindow.cpp \
    result.cpp

HEADERS += \
    aboutapp.h \
    aboutqt.h \
    mainwindow.h \
    result.h
    aboutapp.h

FORMS += \
    aboutqt.ui \
    mainwindow.ui \
    aboutapp.ui \
    result.ui

RESOURCES += \
    resources.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
