#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Projet2A19");//inserer le nom de la source de données
    db.setUserName("Loussaif");//inserer nom de l'utilisateur
    db.setPassword("azerty");//inserer mot de passe de cet utilisateur

    if (db.open())
        test=true;





    return  test;
}
