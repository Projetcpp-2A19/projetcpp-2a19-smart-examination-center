#ifndef SUPERVISEUR_H
#define SUPERVISEUR_H
#include <QSqlQueryModel>
#include <QString>
class Superviseur {
private:
    QString id_superviseur;
     int cin_superviseur;
    QString statut_superviseur;
    QString poste;
    QString prenom_superviseur;
    QString nom_superviseur;
    int numtel_superviseur;
    QString email_superviseur;

public:
    Superviseur();
    Superviseur(QString id, int cin, QString statut, QString poste, QString prenom,
                QString nom, int numtel, QString email);

    QString getId() const;
    int getCIN() const;
   QString getStatut() const;
    QString getPoste() const;
    QString getPrenom() const;
    QString getNom() const;
    int getNumTel() const;
    QString getEmail() const;

    void setId(QString id);
    void setCIN(const int  &cin);
    void setStatut(const QString &statut);
    void setPoste(const QString &poste);
    void setPrenom(const QString &prenom);
    void setNom(const QString &nom);
    void setNumTel(const int &numTel);
    void setEmail(const QString &email);

    bool ajouter();
    QSqlQueryModel* afficher();
};

#endif // SUPERVISEUR_H
