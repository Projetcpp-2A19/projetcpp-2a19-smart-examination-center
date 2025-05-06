#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include "mainwindow.h"
#include <QSslSocket>
#include <QTextStream>
#include <QSqlQuery>
#include <QSqlError>
#include <QSerialPort>
#include <QSerialPortInfo>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Connection c;
    // Vérification OpenSSL
    if (!QSslSocket::supportsSsl()) {
        QMessageBox::critical(nullptr, "Erreur SSL", "❌ OpenSSL n’est pas pris en charge !");
        return -1;
    }

    qDebug() << "✅ SSL Supporté : " << QSslSocket::supportsSsl();
    qDebug() << "🔐 OpenSSL build : " << QSslSocket::sslLibraryBuildVersionString();
    qDebug() << "🔐 OpenSSL runtime : " << QSslSocket::sslLibraryVersionString();

    bool test=c.createconnect();
    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("Database is open"),
                                 QObject::tr("Connection successful.\n"
                                             "Click Cancel to exit."),
                                 QMessageBox::Cancel);

        w.show();

        QSqlQueryModel * afficher();// Appeler afficher() immédiatement après show()
        w.updateTableView();


    }
    if(test)
    {
        w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                                 QObject::tr("connection successful.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                              QObject::tr("connection failed.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
}

