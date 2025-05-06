QT       += core gui sql texttospeech printsupport network charts serialport widgets quick
QT += qml quick quickwidgets
QT += qml quick
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
    speechtotext.cpp \
    panoramicviewer.cpp \
    simple-mail/src/emailaddress.cpp \
    simple-mail/src/mimemessage.cpp \
    simple-mail/src/mimetext.cpp \
    simple-mail/src/mimepart.cpp \
    simple-mail/src/mimeattachment.cpp \
    simple-mail/src/mimehtml.cpp \
    simple-mail/src/mimefile.cpp \
    simple-mail/src/mimeinlinefile.cpp \
    simple-mail/src/mimemultipart.cpp \
    simple-mail/src/mimecontentformatter.cpp \
    simple-mail/src/quotedprintable.cpp \
    simple-mail/src/server.cpp \
    simple-mail/src/serverreply.cpp \
    Etablissement.cpp \
    Fournisseurs.cpp\
    qrcodegen.cpp \
    candidat.cpp \
    equipement.cpp


HEADERS += \
    Superviseur.h \
    arduino.h \
    connection.h \
    mainwindow.h \
    examen.h \
    examenfilterproxymodel.h \
    speechtotext.h \
    panoramicviewer.h \
    simple-mail/src/emailaddress.h \
    simple-mail/src/mimemessage.h \
    simple-mail/src/mimetext.h \
    simple-mail/src/mimepart.h \
    simple-mail/src/mimeattachment.h \
    simple-mail/src/mimehtml.h \
    simple-mail/src/mimefile.h \
    simple-mail/src/mimeinlinefile.h \
    simple-mail/src/mimemultipart.h \
    simple-mail/src/quotedprintable.h \
    simple-mail/src/server.h \
    simple-mail/src/smtpexports.h \
    simple-mail/src/serverreply.h \
    Etablissement.h \
    fournisseurs.h \
    qrcodegen.hpp  \
    candidat.h \
    equipement.h


FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    ProjetLlou_fr_TN.ts
CONFIG += lrelease
CONFIG += embed_translations
INCLUDEPATH += $$PWD/simple-mail/src
DEPENDPATH += $$PWD/simple-mail/src
DEFINES += SIMPLE_MAIL_QT_STATIC
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target





DISTFILES += \
    ../Users/bessa/Downloads/etablissementsImg/etablissements/02-TUTO-PHOTO-360-VENISE.jpg \
    ../Users/bessa/Downloads/etablissementsImg/etablissements/360.jpg \
    ../Users/bessa/Downloads/etablissementsImg/etablissements/aze_360.jpg \
    ../Users/bessa/Downloads/etablissementsImg/etablissements/benarous_360.jpg \
    ../Users/bessa/Downloads/etablissementsImg/etablissements/dd_360.jpeg \
    ../Users/bessa/Downloads/etablissementsImg/etablissements/ecole1.jpg \
    ../Users/bessa/Downloads/etablissementsImg/etablissements/ecole2.jpg \
    ../Users/bessa/Downloads/etablissementsImg/etablissements/f_360.jpeg \
    ../Users/bessa/Downloads/etablissementsImg/etablissements/manar_360.jpg \
    ../Users/bessa/Downloads/etablissementsImg/etablissements/q_360.jpg \
    ../Users/bessa/Downloads/etablissementsImg/etablissements/ss_360.jpg \
    ../Users/bessa/Downloads/etablissementsImg/etablissements/sss_360.jpg \
    ../Users/bessa/Downloads/etablissementsImg/etablissements/technique_360.jpg \
    ../Users/bessa/Downloads/etablissementsImg/img/marker.png \
    etablissements/02-TUTO-PHOTO-360-VENISE.jpg \
    etablissements/360.jpg \
    etablissements/aze_360.jpg \
    etablissements/benarous_360.jpg \
    etablissements/dd_360.jpeg \
    etablissements/ecole1.jpg \
    etablissements/ecole2.jpg \
    etablissements/f_360.jpeg \
    etablissements/manar_360.jpg \
    etablissements/q_360.jpg \
    etablissements/ss_360.jpg \
    etablissements/sss_360.jpg \
    etablissements/technique_360.jpg \
    map.qml \
    speech_to_text.py  \
    speech_to_textEqui.py




RESOURCES += \
    img.qrc \
    ressources.qrc \
    resources.qrc

