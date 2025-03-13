#include "candidat.h"
#include <QSqlError>
#include <QDebug>

// Constructeur avec paramètres
Candidat::Candidat(QString code, QString prenom, int cin, QString adresse, QString nom, int numTel, QString niveau, QByteArray photo)
{
    this->code = code;
    this->prenom = prenom;
    this->cin = cin;
    this->adresse = adresse;
    this->nom = nom;
    this->numTel = numTel;
    this->niveau = niveau;
    this->photo = photo;
}

// Ajouter un candidat
bool Candidat::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO CANDIDAT (CODE_CANDIDAT, PRENOM_CANDIDAT, CIN_CANDIDAT, ADRESSE_CANDIDAT, NOM_CANDIDAT, NUMTEL_CANDIDAT, NIVEAU_CANDIDAT, PHOTO_CANDIDAT) "
                  "VALUES (:code, :prenom, :cin, :adresse, :nom, :numTel, :niveau, :photo)");

    query.bindValue(":code", code);
    query.bindValue(":prenom", prenom);
    query.bindValue(":cin", cin);
    query.bindValue(":adresse", adresse);
    query.bindValue(":nom", nom);
    query.bindValue(":numTel", numTel);
    query.bindValue(":niveau", niveau);
    query.bindValue(":photo", photo);

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
    model->setQuery("SELECT CODE_CANDIDAT, NOM_CANDIDAT, PRENOM_CANDIDAT, CIN_CANDIDAT, ADRESSE_CANDIDAT, NUMTEL_CANDIDAT, NIVEAU_CANDIDAT FROM CANDIDAT");
    return model;
}

bool Candidat::supprimer(QString code)
{
    QSqlQuery query;
    query.prepare("DELETE FROM CANDIDAT WHERE CODE_CANDIDAT = :code");
    query.bindValue(":code", code);

    return query.exec();  // Retourne vrai si la suppression a réussi
}


bool Candidat::modifier(QString code, QString prenom, int cin, QString adresse, QString nom, int numTel, QString niveau, QByteArray photo)
{
    QSqlQuery query;
    query.prepare("UPDATE CANDIDAT SET PRENOM_CANDIDAT=:prenom, CIN_CANDIDAT=:cin, "
                  "ADRESSE_CANDIDAT=:adresse, NOM_CANDIDAT=:nom, NUMTEL_CANDIDAT=:numTel, "
                  "NIVEAU_CANDIDAT=:niveau, PHOTO_CANDIDAT=:photo WHERE CODE_CANDIDAT=:code");

    query.bindValue(":code", code);
    query.bindValue(":prenom", prenom);
    query.bindValue(":cin", cin);
    query.bindValue(":adresse", adresse);
    query.bindValue(":nom", nom);
    query.bindValue(":numTel", numTel);
    query.bindValue(":niveau", niveau);
    query.bindValue(":photo", photo);

    return query.exec();  // Retourne vrai si la modification réussit
}
bool Candidat::chercherCandidat(QString code)
{
    QSqlQuery query;
    query.prepare("SELECT PRENOM_CANDIDAT, CIN_CANDIDAT, ADRESSE_CANDIDAT, NOM_CANDIDAT, NUMTEL_CANDIDAT, NIVEAU_CANDIDAT FROM CANDIDAT WHERE CODE_CANDIDAT = :code");
    query.bindValue(":code", code);

    if (query.exec() && query.next()) { // Si le candidat existe
        prenom = query.value(0).toString();
        cin = query.value(1).toInt();
        adresse = query.value(2).toString();
        nom = query.value(3).toString();
        numTel = query.value(4).toInt();
        niveau = query.value(5).toString();
        return true;
    }
    return false;
}

