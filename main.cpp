#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connection c;
    bool test = c.createconnect();

    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("Database ouverte"),
                                 QObject::tr("Connexion réussie.\n"
                                             "Cliquez sur Annuler pour fermer."), QMessageBox::Cancel);

        MainWindow w;
        w.show();

        return a.exec();
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Database non ouverte"),
                              QObject::tr("Échec de connexion.\n"
                                          "Cliquez sur Annuler pour fermer."), QMessageBox::Cancel);
        return -1;
    }
}
