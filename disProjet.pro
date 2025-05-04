QT       += core gui sql texttospeech printsupport network charts serialport widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    connection.cpp \
    main.cpp \
    mainwindow.cpp \
    superviseur.cpp \
    examen.cpp \
    examenfilterproxymodel.cpp \
    speechtotext.cpp


HEADERS += \
    Superviseur.h \
    arduino.h \
    connection.h \
    mainwindow.h \
    examen.h \
    examenfilterproxymodel.h \
    speechtotext.h


FORMS += \
    mainwindow.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target





DISTFILES += \
    speech_to_text.py




RESOURCES += \
    img.qrc
