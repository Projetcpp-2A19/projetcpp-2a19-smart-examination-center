#ifndef CANDIDAT_H
#define CANDIDAT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Candidat
{
public:
    QString nom;
    QString prenom;
    int code;
    int cin;
    QString adresse;
    int numTel;
    QString niveau;
    // Getters
    QString getNom() const { return nom; }
    QString getPrenom() const { return prenom; }
    int getCode() const { return code; }
    int getCIN() const { return cin; }
    QString getAdresse() const { return adresse; }
    int getNumTel() const { return numTel; }
    QString getNiveau() const { return niveau; }


public:
    // Constructeurs
    Candidat() {}
    Candidat(QString nom, QString prenom, int code, int cin, QString adresse, int numTel, QString niveau);

    // CRUD
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int code);
    bool modifier(int code, QString nom, QString prenom, int cin, QString adresse, int numTel, QString niveau);
};

#endif // CANDIDAT_H
