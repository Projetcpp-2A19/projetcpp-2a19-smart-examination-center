#ifndef CANDIDAT_H
#define CANDIDAT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QByteArray>

class Candidat
{
private:
    QString code;
    QString prenom;
    int cin;
    QString adresse;
    QString nom;
    int numTel;
    QString niveau;
    QByteArray photo;

public:
    // Constructeurs
    Candidat() {}
    Candidat(QString code, QString prenom, int cin, QString adresse, QString nom, int numTel, QString niveau, QByteArray photo);

    // CRUD
    bool ajouterCand();
    QSqlQueryModel *afficherCand();
    bool supprimerCand(QString code);
    bool modifierCand(QString code, QString prenom, int cin, QString adresse, QString nom, int numTel, QString niveau, QByteArray photo);
    bool chercherCandidat(QString code);
    QSqlQuery trierParNiveauQuery(QString niveau);
    QSqlQuery chercherParCodeDansTable(QString code);
    QSqlQuery statistiquesParNiveau();
    void on_btnpdf_clicked();    // ← ajoute bien ceci




    // Getters
    QString getCode() const { return code; }
    QString getPrenom() const { return prenom; }
    int getCin() const { return cin; }
    QString getAdresse() const { return adresse; }
    QString getNom() const { return nom; }
    int getNumTel() const { return numTel; }
    QString getNiveau() const { return niveau; }
    QByteArray getPhoto() const { return photo; }
};

#endif // CANDIDAT_H
