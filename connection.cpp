#include "connection.h"

Connection::Connection()
{
    // Constructeur de la classe. La connexion sera initialisée ici.
}

bool Connection::createconnect()
{
    // Vérifier si la connexion est déjà ouverte
    if (db.isOpen()) {
        qDebug() << "La base de données est déjà ouverte.";
        return true;
    }

    // Créer une nouvelle connexion à la base de données en utilisant ODBC
    db = QSqlDatabase::addDatabase("QODBC");  // Utilise l'instance existante
    db.setDatabaseName("Projet2A19");  // Le nom de la source de données
    db.setUserName("maram");  // Nom d'utilisateur
    db.setPassword("system");  // Mot de passe

    if (!db.open()) {
        qDebug() << "Erreur lors de l'ouverture de la base de données : " << db.lastError().text();
        return false;
    }

    qDebug() << "Connexion à la base de données réussie!";
    return true;
}

void Connection::closeConnection()
{
    if (db.isOpen()) {
        db.close();  // Fermer la connexion
        qDebug() << "Connexion fermée.";
    }
}
