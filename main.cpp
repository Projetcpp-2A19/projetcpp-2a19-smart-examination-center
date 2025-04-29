#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <QSslSocket>
#include <QTextStream>
#include <QSqlQuery>
#include <QSqlError>
#include <QSerialPort>
#include <QSerialPortInfo>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Vérification OpenSSL
    if (!QSslSocket::supportsSsl()) {
        QMessageBox::critical(nullptr, "Erreur SSL", "❌ OpenSSL n’est pas pris en charge !");
        return -1;
    }

    qDebug() << "✅ SSL Supporté : " << QSslSocket::supportsSsl();
    qDebug() << "🔐 OpenSSL build : " << QSslSocket::sslLibraryBuildVersionString();
    qDebug() << "🔐 OpenSSL runtime : " << QSslSocket::sslLibraryVersionString();

    Connection c;
    bool test = c.createconnect();

    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("Database ouverte"),
                                 QObject::tr("Connexion réussie.\nCliquez sur Annuler pour fermer."), QMessageBox::Cancel);

        MainWindow w;
        w.show();

        return a.exec();
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Database non ouverte"),
                              QObject::tr("Échec de connexion.\nCliquez sur Annuler pour fermer."), QMessageBox::Cancel);
        return -1;
    }
}


