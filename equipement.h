#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Equipement {
private:
    QString id;
    QString nom;
    QString type;
    QString statut;
    int quantite;
public:
    Equipement();

    // Constructor without ID
    Equipement(QString nom, QString type, QString statut, int quantite);

    // Existing constructor with ID (if still needed)
    Equipement(QString id, QString nom, QString type, QString statut, int quantite);
    // Accesseurs (Getters)

    QString getNom() const;
    QString getType() const;
    QString getStatut() const;
    int getQuantite() const;

    // Mutateurs (Setters)
    void setNom(QString nom);
    void setType(QString type);
    void setStatut(QString statut);
    void setQuantite(int quantite);


    // CRUD Operations
    bool ajouter();
    QSqlQueryModel* afficher();
    bool modifier(int equipmentId, const QString &nom, const QString &type, const QString &statut, int quantite);
    bool supprimer(int id);
};

#endif // EQUIPEMENT_H
