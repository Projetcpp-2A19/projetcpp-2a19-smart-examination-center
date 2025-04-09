QT       += core gui sql network
QT += core gui widgets sql charts
QT += charts



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets



CONFIG += c++17

SOURCES += \
    Fournisseurs.cpp \
    connection.cpp \
    main.cpp \
    mainwindow.cpp \
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
    simple-mail/src/serverreply.cpp

HEADERS += \
    fournisseurs.h \
    connection.h \
    mainwindow.h \
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
    simple-mail/src/serverreply.h

FORMS += \
    mainwindow.ui

INCLUDEPATH += $$PWD/simple-mail/src
DEPENDPATH += $$PWD/simple-mail/src
DEFINES += SIMPLE_MAIL_QT_STATIC
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
LIBS += -lQt6Charts
