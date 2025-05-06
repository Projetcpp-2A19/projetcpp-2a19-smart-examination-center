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
    bool ajouterEquip();
    QSqlQueryModel* afficherEquip();
    bool modifierEquip(int equipmentId, const QString &nom, const QString &type, const QString &statut, int quantite);
    bool supprimerEquip(int id);
    QSqlQueryModel*  trierParNom();
    QSqlQueryModel* rechercherParNom(const QString &nom);
};

#endif // EQUIPEMENT_H
