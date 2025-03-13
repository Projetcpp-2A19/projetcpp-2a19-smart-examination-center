QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    candidat.cpp \
    connection.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    candidat.h \
    connection.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    ProjetLlou_fr_TN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ressources.qrc

DISTFILES += \
    ../img/accueil.png \
    ../img/batiment-educatif.png \
    ../img/candidat.png \
    ../img/chatbot.png \
    ../img/close.png \
    ../img/email.png \
    ../img/equipe.png \
    ../img/examen.png \
    ../img/fermer-la-fenetre.png \
    ../img/home.png \
    ../img/livreur.png \
    ../img/logo.png \
    ../img/mail.png \
    ../img/notif.png \
    ../img/parametres.png \
    ../img/pdf.png \
    ../img/plus-moins.png \
    ../img/profil.png \
    ../img/recherche.png \
    ../img/rechercher-des-personnes.png \
    ../img/settings.png \
    ../img/supprimer.png
