
QT +=core gui widgets sql charts serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT       += core gui sql serialport
QT += charts
QT += printsupport
QT += core gui printsupport sql widgets pdf
QT += qml quick quickwidgets
QT += qml quick

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../../Downloads/qrcodegen.cpp \
    arduino.cpp \
    connection.cpp \
    equipement.cpp \
    gcandidat.cpp \
    candidat.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    ../../Downloads/qrcodegen.hpp \
    arduino.h \
    candidat.h \
    connection.h \
    equipement.h \
    gcandidat.h \
    mainwindow.h

FORMS += \
    gcandidat.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES += \
    speech_to_text.py
