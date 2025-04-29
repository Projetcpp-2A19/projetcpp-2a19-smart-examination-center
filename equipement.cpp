#include "equipement.h"
#include <QString>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlQueryModel>

// Constructeur
Equipement::Equipement( QString nom, QString type, QString statut, int quantite)
 :nom(nom), type(type), statut(statut), quantite(quantite) {}

Equipement::Equipement()
    : id("0"), nom(""), type(""), statut(""), quantite(0) {}

QString Equipement::getNom() const {
    return nom;
}

QString Equipement::getType() const {
    return type;
}

QString Equipement::getStatut() const {
    return statut;
}

int Equipement::getQuantite() const {
    return quantite;
}

// Mutateurs
void Equipement::setNom(QString nom) {
    this->nom = nom;
}

void Equipement::setType(QString type) {
    this->type = type;
}

void Equipement::setStatut(QString statut) {
    this->statut = statut;
}

void Equipement::setQuantite(int quantite) {
    this->quantite = quantite;
}

// Ajouter un équipement
bool Equipement::ajouter() {
    qDebug() << "Tentative d'ajout dans la base de données...";

    // Retrieve the last inserted ID (max ID)
    QSqlQuery maxIdQuery;
    maxIdQuery.prepare("SELECT MAX(ID_EQUIPEMENT) FROM EQUIPEMENTS");

    if (!maxIdQuery.exec()) {
        qDebug() << "Erreur lors de la récupération du dernier ID:" << maxIdQuery.lastError();
        return false;
    }

    int lastId = 0;  // Default to 0 if there are no records yet
    if (maxIdQuery.next()) {
        lastId = maxIdQuery.value(0).toInt();
    }
    int newId = lastId + 1;  // Increment the last ID by 1

    qDebug() << "Dernier ID trouvé:" << lastId << ", Nouvel ID pour insertion:" << newId;

    // Prepare the insert query with the new ID
    QSqlQuery query;
    query.prepare("INSERT INTO EQUIPEMENTS (ID_EQUIPEMENT, NOM_EQUIPEMENT, TYPE_EQUIPEMENT, STATUT_EQUIPEMENT, QUANTITE__EQUIPEMENT) "
                  "VALUES (:id, :nom, :type, :statut, :quantite)");

    // Bind values for insertion
    query.bindValue(":id", QString::number(newId));  // Converts the int to a QString
    query.bindValue(":nom", nom);
    query.bindValue(":type", type);
    query.bindValue(":statut", statut);
    query.bindValue(":quantite", quantite);

    // Execute the query
    if (query.exec()) {
        qDebug() << "Insertion réussie de l'équipement avec les valeurs :"
                 << "ID:" << newId << ", Nom:" << nom << ", Type:" << type << ", Statut:" << statut << ", Quantité:" << quantite;
        return true;
    } else {
        qDebug() << "Erreur insertion équipement:" << query.lastError();
        return false;
    }
}


// Afficher les équipements
QSqlQueryModel* Equipement::afficher() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT ID_EQUIPEMENT, NOM_EQUIPEMENT, TYPE_EQUIPEMENT, STATUT_EQUIPEMENT, QUANTITE__EQUIPEMENT FROM EQUIPEMENTS ORDER BY ID_EQUIPEMENT ASC");
    return model;
}

// Modifier un équipement

// Supprimer un équipement
bool Equipement::supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM EQUIPEMENTS  WHERE ID_EQUIPEMENT = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Erreur suppression équipement:" << query.lastError();
        return false;
    }
    return true;
}
bool Equipement::modifier(int equipmentId, const QString &nom, const QString &type, const QString &statut, int quantite)
{
    QSqlQuery query;
    query.prepare("UPDATE EQUIPEMENTS SET NOM_EQUIPEMENT = :nom, TYPE_EQUIPEMENT = :type, "
                  "STATUT_EQUIPEMENT = :statut, QUANTITE__EQUIPEMENT = :quantite "
                  "WHERE ID_EQUIPEMENT = :id");

    // Bind values
    query.bindValue(":nom", nom);
    query.bindValue(":type", type);
    query.bindValue(":statut", statut);
    query.bindValue(":quantite", quantite);
    query.bindValue(":id", equipmentId);  // Bind the ID of the equipment to modify

    if (query.exec()) {
        qDebug() << "Modification réussie de l'équipement avec ID:" << equipmentId;
        return true;
    } else {
        qDebug() << "Erreur lors de la modification de l'équipement:" << query.lastError();
        return false;
    }
}
QSqlQueryModel* Equipement::trierParNom()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT ID_EQUIPEMENT, NOM_EQUIPEMENT, TYPE_EQUIPEMENT, STATUT_EQUIPEMENT, QUANTITE__EQUIPEMENT FROM EQUIPEMENTS ORDER BY NOM_EQUIPEMENT ASC");
    return model;
}
QSqlQueryModel* Equipement::rechercherParNom(const QString &nom) {
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * FROM EQUIPEMENTS WHERE ID_EQUIPEMENT LIKE :nom");
    query.bindValue(":nom", nom);
    query.exec();
    model->setQuery(query);
    return model;
}

