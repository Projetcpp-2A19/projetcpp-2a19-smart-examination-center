#ifndef ETABLISSEMENT_H
#define ETABLISSEMENT_H

#include <QSqlQueryModel>
#include <QString>

class Etablissement {
private:
    QString id_etablissement; // Clé primaire
    QString gouvernorat_etablissement;
    QString type_etablissement;
    QString directeur_etablissement;
    QString nom_etablissement;
    int nombreSalle_etablissement;
    QString ville_etablissement;
<<<<<<< HEAD
    QString adresse_etablissement;


public:
    Etablissement();
    Etablissement(QString id, QString gouvernorat, QString type, QString directeur, QString nom, int nombreSalle, QString ville ,QString adresse);
=======

public:
    Etablissement();
    Etablissement(QString id, QString gouvernorat, QString type, QString directeur, QString nom, int nombreSalle, QString ville);
>>>>>>> c72197f8b0853cd878fb0a1821205a90fddb9313

    QString getId() const;
    QString getGouvernorat() const;
    QString getType() const;
    QString getDirecteur() const;
    QString getNom() const;
    int getNombreSalle() const;
    QString getVille() const;
<<<<<<< HEAD
    QString getAdresse() const;
=======
>>>>>>> c72197f8b0853cd878fb0a1821205a90fddb9313

    void setId(QString id);
    void setGouvernorat(QString gouvernorat);
    void setType(QString type);
    void setDirecteur(QString directeur);
    void setNom(QString nom);
    void setNombreSalle(int nombreSalle);
    void setVille(QString ville);
<<<<<<< HEAD
    void setAdresse(QString adresse);


=======

>>>>>>> c72197f8b0853cd878fb0a1821205a90fddb9313
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(QString id);
    bool modifier();
};

#endif // ETABLISSEMENT_H
