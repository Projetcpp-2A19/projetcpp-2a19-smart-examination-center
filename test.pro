QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connection.cpp \
    examen.cpp \
    gestion_examens.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    connection.h \
    examen.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    img/batiment-educatif.png \
    img/candidat.png \
    img/close.png \
    img/equipe.png \
    img/examen.png \
    img/home.png \
    img/livreur.png \
    img/logo.png \
    img/mail.png \
    img/notif.png \
    img/plus-moins.png \
    img/recherche.png \
    img/rechercher-des-personnes.png \
    img/refresh.png \
    img/settings.png

RESOURCES += \
    img.qrc
