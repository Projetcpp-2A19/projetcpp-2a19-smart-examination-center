#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
<<<<<<< HEAD
#include "mainwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Connection c;
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

=======
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


>>>>>>> b6702fb4186800406ca9e0726db1397b5b8a17b0
