#include "candidat.h"
#include <QSqlError>
#include <QDebug>

// Constructeur avec paramètres
Candidat::Candidat(QString nom, QString prenom, int code, int cin, QString adresse, int numTel, QString niveau)
{
    this->nom = nom;
    this->prenom = prenom;
    this->code = code;
    this->cin = cin;
    this->adresse = adresse;
    this->numTel = numTel;
    this->niveau = niveau;
}

// Ajouter un candidat
bool Candidat::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO CANDIDATS (NOMCANDIDAT, PRENOMCANDIDAT, CODE, CIN, ADRESSECANDIDAT, NUMTELCANDIDAT, NIVEAUCANDIDAT) "
                  "VALUES (:nom, :prenom, :code, :cin, :adresse, :numTel, :niveau)");

    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":code", code);
    query.bindValue(":cin", cin);
    query.bindValue(":adresse", adresse);
    query.bindValue(":numTel", numTel);
    query.bindValue(":niveau", niveau);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'ajout du candidat:" << query.lastError().text();
        return false;
    }
    return true;
}

// Afficher tous les candidats
QSqlQueryModel *Candidat::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT CODE, NOMCANDIDAT, PRENOMCANDIDAT, CIN, ADRESSECANDIDAT, NUMTELCANDIDAT, NIVEAUCANDIDAT FROM CANDIDATS");
    return model;
}

// Supprimer un candidat par code
bool Candidat::supprimer(int code)
{
    QSqlQuery query;
    query.prepare("DELETE FROM CANDIDATS WHERE CODE = :code");
    query.bindValue(":code", code);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la suppression du candidat:" << query.lastError().text();
        return false;
    }
    return true;
}

// Modifier un candidat
bool Candidat::modifier(int code, QString nom, QString prenom, int cin, QString adresse, int numTel, QString niveau)
{
    QSqlQuery query;
    query.prepare("UPDATE CANDIDATS SET NOMCANDIDAT = :nom, PRENOMCANDIDAT = :prenom, CIN = :cin, ADRESSECANDIDAT = :adresse, "
                  "NUMTELCANDIDAT = :numTel, NIVEAUCANDIDAT = :niveau WHERE CODE = :code");
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":cin", cin);
    query.bindValue(":adresse", adresse);
    query.bindValue(":numTel", numTel);
    query.bindValue(":niveau", niveau);
    query.bindValue(":code", code);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la modification du candidat:" << query.lastError().text();
        return false;
    }
    return true;
}

