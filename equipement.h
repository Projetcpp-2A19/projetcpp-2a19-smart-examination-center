#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Equipement {
private:
    int id;
    QString nom;
    QString type;
    QString statut;
    int quantite;

public:
    // Constructeur
    Equipement(int id, QString nom, QString type, QString statut, int quantite);

    Equipement();


    // Accesseurs (Getters)
    int getId() const;
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
    bool modifier(int id);
    bool supprimer(int id);
};

#endif // EQUIPEMENT_H
