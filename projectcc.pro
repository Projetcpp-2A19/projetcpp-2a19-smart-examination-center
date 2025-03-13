QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Etablissement.cpp \
    connection.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Etablissement.h \
    connection.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    img/480403914_1638328830141470_6590277718263893232_n.jpg \
    img/analytics.png \
    img/batiment-educatif.png \
    img/candidat.png \
    img/close.png \
    img/en-arriere.png \
    img/equipe.png \
    img/examen.png \
    img/home.png \
    img/images-removebg-preview.png \
    img/livreur.png \
    img/logo.png \
    img/mail.png \
    img/notif.png \
    img/pdf.png \
    img/plus-moins.png \
    img/recherche.png \
    img/rechercher-des-personnes.png \
    img/refresh.png \
    img/settings.png \
    img/supprimer.png

RESOURCES += \
    img.qrc
