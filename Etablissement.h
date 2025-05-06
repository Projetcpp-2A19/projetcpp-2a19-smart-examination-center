#ifndef ETABLISSEMENT_H
#define ETABLISSEMENT_H

#include <QSqlQueryModel>
#include <QString>
#include <QImage>
#include <QSqlError>
#include <QDebug>
class Etablissement {
private:
    QString idEtablissement; // Clé primaire
    QString gouvernoratEtablissement;
    QString typeEtablissement;
    QString directeurEtablissement;
    QString nomEtablissement;
    int nombreSalleEtablissement;
    QString villeEtablissement;
    QString adresseEtablissement;
    QString imagePath;
    QString idSuperviseur;
    QString idEquipement;

public:
    Etablissement();
    Etablissement(QString id, QString gouvernorat, QString type, QString directeur, QString nom,
                  int nombreSalle, QString ville, QString adresse, QString imagePath = "",
                  QString idSuperviseur = "", QString idEquipement = "");

    bool isPanoramic() const {
        if (imagePath.isEmpty()) return false;

        QImage img(imagePath);
        if (img.isNull()) return false;

        // Ratio caractéristique des images 360° (au moins 2:1)
        float ratio = static_cast<float>(img.width()) / img.height();

        return imagePath.contains("_panoramic.", Qt::CaseInsensitive) ||
               imagePath.contains("_360.", Qt::CaseInsensitive) ||
               (ratio >= 2.0f); // Ratio largeur/hauteur ≥ 2
    }

    // Getters
    QString getId() const;
    QString getGouvernorat() const;
    QString getType() const;
    QString getDirecteur() const;
    QString getNom() const;
    int getNombreSalle() const;
    QString getVille() const;
    QString getAdresse() const;
    QString getImagePath() const;
    QString getIdSuperviseur() const;
    QString getIdEquipement() const;

    // Setters
    void setId(QString id);
    void setGouvernorat(QString gouvernorat);
    void setType(QString type);
    void setDirecteur(QString directeur);
    void setNom(QString nom);
    void setNombreSalle(int nombreSalle);
    void setVille(QString ville);
    void setAdresse(QString adresse);
    void setImagePath(QString path);
    void setIdSuperviseur(QString id);
    void setIdEquipement(QString id);

    // Méthodes CRUD
    bool ajouterEta();
    QSqlQueryModel* afficherEta();
    bool supprimerEta(QString id);
    bool modifierEta();
};

#endif // ETABLISSEMENT_H
