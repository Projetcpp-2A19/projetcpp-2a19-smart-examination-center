#include "connection.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

Connection::Connection() {}

bool Connection::createconnect()
{
    bool test = false;

    // Créer une connexion à la base de données via ODBC
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

    // Configurer la source de données (DSN)
    db.setDatabaseName("Projet2A19"); // Nom de la source de données ODBC
    db.setUserName("Imen");           // Nom d'utilisateur de la base de données
    db.setPassword("CppQt");          // Mot de passe de l'utilisateur

    // Tentative d'ouverture de la connexion
    if (db.open()) {
        test = true; // La connexion a réussi
        qDebug() << "Connexion à la base de données réussie !";
    } else {
        // Afficher l'erreur en cas d'échec de la connexion
        qDebug() << "Erreur de connexion à la base de données :" << db.lastError().text();
    }

    return test;
}
