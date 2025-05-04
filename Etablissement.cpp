#include "Etablissement.h"
#include <QSqlQuery>
#include <QVariant>
#include <QSqlQueryModel>
#include <QSqlError>

// Constructeurs
Etablissement::Etablissement() {}

Etablissement::Etablissement(QString id, QString gouvernorat, QString type, QString directeur,
                             QString nom, int nombreSalle, QString ville, QString adresse,
                             QString imagePath, QString idSuperviseur, QString idEquipement)
    : idEtablissement(id), gouvernoratEtablissement(gouvernorat), typeEtablissement(type),
    directeurEtablissement(directeur), nomEtablissement(nom), nombreSalleEtablissement(nombreSalle),
    villeEtablissement(ville), adresseEtablissement(adresse), imagePath(imagePath),
    idSuperviseur(idSuperviseur), idEquipement(idEquipement) {}

// Getters
QString Etablissement::getId() const { return idEtablissement; }
QString Etablissement::getGouvernorat() const { return gouvernoratEtablissement; }
QString Etablissement::getType() const { return typeEtablissement; }
QString Etablissement::getDirecteur() const { return directeurEtablissement; }
QString Etablissement::getNom() const { return nomEtablissement; }
int Etablissement::getNombreSalle() const { return nombreSalleEtablissement; }
QString Etablissement::getVille() const { return villeEtablissement; }
QString Etablissement::getAdresse() const { return adresseEtablissement; }
QString Etablissement::getImagePath() const { return imagePath; }
QString Etablissement::getIdSuperviseur() const { return idSuperviseur; }
QString Etablissement::getIdEquipement() const { return idEquipement; }

// Setters
void Etablissement::setId(QString id) { idEtablissement = id; }
void Etablissement::setGouvernorat(QString gouvernorat) { gouvernoratEtablissement = gouvernorat; }
void Etablissement::setType(QString type) { typeEtablissement = type; }
void Etablissement::setDirecteur(QString directeur) { directeurEtablissement = directeur; }
void Etablissement::setNom(QString nom) { nomEtablissement = nom; }
void Etablissement::setNombreSalle(int nombreSalle) { nombreSalleEtablissement = nombreSalle; }
void Etablissement::setVille(QString ville) { villeEtablissement = ville; }
void Etablissement::setAdresse(QString adresse) { adresseEtablissement = adresse; }
void Etablissement::setImagePath(QString path) { imagePath = path; }
void Etablissement::setIdSuperviseur(QString id) { idSuperviseur = id; }
void Etablissement::setIdEquipement(QString id) { idEquipement = id; }

// Ajouter un établissement
bool Etablissement::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO ETABLISSEMENT (ID_ETABLISSEMENT, GOUVERNORAT_ETABLISSEMENT, TYPE_ETABLISSEMENT, "
                  "DIRECTEUR_ETABLISSEMENT, NOM_ETABLISSEMENT, NOMBRESALLE_ETABLISSEMENT, "
                  "VILLE_ETABLISSEMENT, ADRESSE_ETABLISSEMENT, IMAGE_PATH, ID_SUPERVISEUR, ID_EQUIPEMENT) "
                  "VALUES (:id, :gouvernorat, :type, :directeur, :nom, :nombreSalle, :ville, :adresse, :imagePath, :idSuperviseur, :idEquipement)");

    query.bindValue(":id", idEtablissement);
    query.bindValue(":gouvernorat", gouvernoratEtablissement);
    query.bindValue(":type", typeEtablissement);
    query.bindValue(":directeur", directeurEtablissement);
    query.bindValue(":nom", nomEtablissement);
    query.bindValue(":nombreSalle", nombreSalleEtablissement);
    query.bindValue(":ville", villeEtablissement);
    query.bindValue(":adresse", adresseEtablissement);
    query.bindValue(":imagePath", imagePath);
    query.bindValue(":idSuperviseur", idSuperviseur);
    query.bindValue(":idEquipement", idEquipement);

    return query.exec();
}

// Afficher les établissements
QSqlQueryModel* Etablissement::afficher() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT ID_ETABLISSEMENT, GOUVERNORAT_ETABLISSEMENT, TYPE_ETABLISSEMENT, "
                    "DIRECTEUR_ETABLISSEMENT, NOM_ETABLISSEMENT, NOMBRESALLE_ETABLISSEMENT, "
                    "VILLE_ETABLISSEMENT, ADRESSE_ETABLISSEMENT, IMAGE_PATH, ID_SUPERVISEUR, ID_EQUIPEMENT "
                    "FROM ETABLISSEMENT");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Gouvernorat"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Directeur"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Nombre de Salles"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Ville"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Image"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("ID Superviseur"));
    model->setHeaderData(10, Qt::Horizontal, QObject::tr("ID Equipement"));

    return model;
}

// Supprimer un établissement
bool Etablissement::supprimer(QString id) {
    QSqlQuery query;
    query.prepare("DELETE FROM ETABLISSEMENT WHERE ID_ETABLISSEMENT = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Erreur SQL lors de la suppression :" << query.lastError().text();
        return false;
    }

    return true;
}

// Modifier un établissement
bool Etablissement::modifier() {
    QSqlQuery query;
    query.prepare("UPDATE ETABLISSEMENT SET GOUVERNORAT_ETABLISSEMENT = :gouvernorat, TYPE_ETABLISSEMENT = :type, "
                  "DIRECTEUR_ETABLISSEMENT = :directeur, NOM_ETABLISSEMENT = :nom, "
                  "NOMBRESALLE_ETABLISSEMENT = :nombreSalle, VILLE_ETABLISSEMENT = :ville, "
                  "ADRESSE_ETABLISSEMENT = :adresse, IMAGE_PATH = :imagePath, "
                  "ID_SUPERVISEUR = :idSuperviseur, ID_EQUIPEMENT = :idEquipement "
                  "WHERE ID_ETABLISSEMENT = :id");

    query.bindValue(":id", idEtablissement);
    query.bindValue(":gouvernorat", gouvernoratEtablissement);
    query.bindValue(":type", typeEtablissement);
    query.bindValue(":directeur", directeurEtablissement);
    query.bindValue(":nom", nomEtablissement);
    query.bindValue(":nombreSalle", nombreSalleEtablissement);
    query.bindValue(":ville", villeEtablissement);
    query.bindValue(":adresse", adresseEtablissement);
    query.bindValue(":imagePath", imagePath);
    query.bindValue(":idSuperviseur", idSuperviseur);
    query.bindValue(":idEquipement", idEquipement);

    if (!query.exec()) {
        qDebug() << "Erreur SQL lors de la modification :" << query.lastError().text();
        qDebug() << "Requête SQL :" << query.lastQuery();
        qDebug() << "Valeurs bindées :";
        qDebug() << "ID:" << idEtablissement;
        qDebug() << "Gouvernorat:" << gouvernoratEtablissement;
        qDebug() << "Type:" << typeEtablissement;
        qDebug() << "Directeur:" << directeurEtablissement;
        qDebug() << "Nom:" << nomEtablissement;
        qDebug() << "Nombre de salles:" << nombreSalleEtablissement;
        qDebug() << "Ville:" << villeEtablissement;
        qDebug() << "Adresse:" << adresseEtablissement;
        qDebug() << "Image:" << imagePath;
        qDebug() << "idSuperviseur:" << idSuperviseur;
        qDebug() << "idEquipement:" << idEquipement;

        return false;
    }

    return query.numRowsAffected() > 0;
}
