#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H

#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>

class Fournisseur {
private:
    QString id_fourn;
    QString nom_fourn;
    QString adresse;
    QString email;
    int numTel;
    QString typeService;
    QSqlError lastError;  // Stocke la dernière erreur SQL

public:

public:
    Fournisseur();  // ✅ Constructeur par défaut

    // ✅ Constructeur utilisé pour la modification (ID nécessaire)
    Fournisseur(const QString& id_fourn, const QString& nom_fourn, const QString& adresse,
                const QString& email, int numTel, const QString& typeService);

    // ✅ Constructeur utilisé pour l'ajout (sans ID, car généré par la BD)
    Fournisseur(const QString& nom_fourn, const QString& adresse,
                const QString& email, int numTel, const QString& typeService);

    // 🔹 Getters
    QString getIdFourn() const;
    QString getNomFourn() const;
    QString getAdresse() const;
    QString getEmail() const;
    int getNumTel() const;
    QString getTypeService() const;

    // 🔹 Setters
    void setIdFourn(const QString& id);  // Ajout du setter pour l'ID
    void setNomFourn(const QString& nom_fourn);
    void setAdresse(const QString& adresse);
    void setEmail(const QString& email);
    void setNumTel(int numTel);  // ✅ Doit prendre un `int`

    void setTypeService(const QString& typeService);

    // 🔹 CRUD Methods
    bool ajouter();
    bool existeDeja(int id);
    bool supprimer(int id);
    //modification

    bool modifier(QString id);
    QSqlQueryModel* afficher();

    // 🔹 Gestion des erreurs SQL
    QSqlError getLastError() const;

    // 🔹 Affichage des détails
    QString afficherDetails() const;

};


#endif // FOURNISSEUR_H
