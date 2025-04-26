#ifndef SUPERVISEUR_H
#define SUPERVISEUR_H
#include <QSqlQueryModel>
#include <QString>
#include <QMap>
#include <QPrinter>
#include <QSqlQuery>

class Superviseur {

private:
    QString id_superviseur;
     int cin_superviseur;
    QString statut_superviseur;
    QString poste;
    QString prenom_superviseur;
    QString nom_superviseur;
    QString numtel_superviseur;
    QString email_superviseur;
    QString zone_superviseur;

public:
    Superviseur();
    Superviseur(QString id, int cin, QString statut, QString poste, QString prenom,
                QString nom, QString numtel, QString email, QString zone);

    QString getId() const;
    int getCIN() const;
   QString getStatut() const;
    QString getPoste() const;
    QString getPrenom() const;
    QString getNom() const;
    QString getNumTel() const;
    QString getEmail() const;
    QString getZone() const;

    void setId(QString id);
    void setCIN(const int  &cin);
    void setStatut(const QString &statut);
    void setPoste(const QString &poste);
    void setPrenom(const QString &prenom);
    void setNom(const QString &nom);
    void setNumTel(const QString &numTel);
    void setEmail(const QString &email);
    void setZone(const QString &zone);

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer (QString id);
    bool modifier(QString id);

    // Fonction de recherche
    QString getStatutByRFID(const QString& rfid_code);
    QSqlQueryModel* rechercherParID(QString idRecherche);
    QSqlQueryModel* trierNoms(); // Méthode pour trier les noms des superviseurs de A à Z
    QMap<QString, int> getStatistiquesParZone(); //stat
public:
    // Ajoutez cette méthode
    static bool exporterVersPDF(const QString &fileName);


};

#endif // SUPERVISEUR_H
