#include "Etablissement.h"
#include <QSqlQuery>
#include <QVariant>
#include <QSqlQueryModel>
#include <QSqlError>

// Constructeurs
Etablissement::Etablissement() {}

Etablissement::Etablissement(QString id, QString gouvernorat, QString type, QString directeur,
                             QString nom, int nombreSalle, QString ville, QString adresse , QString imagePath)
    : id_etablissement(id), gouvernorat_etablissement(gouvernorat), type_etablissement(type),
    directeur_etablissement(directeur), nom_etablissement(nom), nombreSalle_etablissement(nombreSalle),
    ville_etablissement(ville), adresse_etablissement(adresse) , imagePath(imagePath) {}

// Getters
QString Etablissement::getId() const { return id_etablissement; }
QString Etablissement::getGouvernorat() const { return gouvernorat_etablissement; }
QString Etablissement::getType() const { return type_etablissement; }
QString Etablissement::getDirecteur() const { return directeur_etablissement; }
QString Etablissement::getNom() const { return nom_etablissement; }
int Etablissement::getNombreSalle() const { return nombreSalle_etablissement; }
QString Etablissement::getVille() const { return ville_etablissement; }
QString Etablissement::getAdresse() const { return adresse_etablissement; }
QString Etablissement::getImagePath() const { return imagePath; }


// Setters
void Etablissement::setId(QString id) { this->id_etablissement = id; }
void Etablissement::setGouvernorat(QString gouvernorat) { this->gouvernorat_etablissement = gouvernorat; }
void Etablissement::setType(QString type) { this->type_etablissement = type; }
void Etablissement::setDirecteur(QString directeur) { this->directeur_etablissement = directeur; }
void Etablissement::setNom(QString nom) { this->nom_etablissement = nom; }
void Etablissement::setNombreSalle(int nombreSalle) { this->nombreSalle_etablissement = nombreSalle; }
void Etablissement::setVille(QString ville) { this->ville_etablissement = ville; }
void Etablissement::setAdresse(QString adresse) { this->adresse_etablissement = adresse; }
void Etablissement::setImagePath(QString path) { this->imagePath = path; }

// Ajouter un établissement
bool Etablissement::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO ETABLISSEMENT (ID_ETABLISSEMENT, GOUVERNORAT_ETABLISSEMENT, TYPE_ETABLISSEMENT, DIRECTEUR_ETABLISSEMENT, NOM_ETABLISSEMENT, NOMBRESALLE_ETABLISSEMENT, VILLE_ETABLISSEMENT, ADRESSE_ETABLISSEMENT, IMAGE_PATH) "
                  "VALUES (:id, :gouvernorat, :type, :directeur, :nom, :nombreSalle, :ville, :adresse, :imagePath)");

    query.bindValue(":id", id_etablissement);
    query.bindValue(":gouvernorat", gouvernorat_etablissement);
    query.bindValue(":type", type_etablissement);
    query.bindValue(":directeur", directeur_etablissement);
    query.bindValue(":nom", nom_etablissement);
    query.bindValue(":nombreSalle", nombreSalle_etablissement);
    query.bindValue(":ville", ville_etablissement);
    query.bindValue(":adresse", adresse_etablissement); // Nouveau bind
    query.bindValue(":imagePath", imagePath);

    return query.exec();
}

// Afficher les établissements
QSqlQueryModel* Etablissement::afficher() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT ID_ETABLISSEMENT, GOUVERNORAT_ETABLISSEMENT, TYPE_ETABLISSEMENT, "
                    "DIRECTEUR_ETABLISSEMENT, NOM_ETABLISSEMENT, NOMBRESALLE_ETABLISSEMENT, "
                    "VILLE_ETABLISSEMENT, ADRESSE_ETABLISSEMENT, IMAGE_PATH FROM ETABLISSEMENT");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Gouvernorat"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Directeur"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Nombre de Salles"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Ville"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Image"));

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
                  "ADRESSE_ETABLISSEMENT = :adresse, IMAGE_PATH = :imagePath "
                  "WHERE ID_ETABLISSEMENT = :id");

    query.bindValue(":id", id_etablissement);
    query.bindValue(":gouvernorat", gouvernorat_etablissement);
    query.bindValue(":type", type_etablissement);
    query.bindValue(":directeur", directeur_etablissement);
    query.bindValue(":nom", nom_etablissement);
    query.bindValue(":nombreSalle", nombreSalle_etablissement);
    query.bindValue(":ville", ville_etablissement);
    query.bindValue(":adresse", adresse_etablissement);
    query.bindValue(":imagePath", imagePath);

    if (!query.exec()) {
        qDebug() << "Erreur SQL lors de la modification :" << query.lastError().text();
        qDebug() << "Requête SQL :" << query.lastQuery();
        qDebug() << "Valeurs bindées :";
        qDebug() << "ID:" << id_etablissement;
        qDebug() << "Gouvernorat:" << gouvernorat_etablissement;
        qDebug() << "Type:" << type_etablissement;
        qDebug() << "Directeur:" << directeur_etablissement;
        qDebug() << "Nom:" << nom_etablissement;
        qDebug() << "Nombre de salles:" << nombreSalle_etablissement;
        qDebug() << "Ville:" << ville_etablissement;
        qDebug() << "Adresse:" << adresse_etablissement;
        qDebug() << "Image :" << imagePath;

        return false;
    }

    return query.numRowsAffected() > 0;
}
