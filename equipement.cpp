#include "equipement.h"
#include <QString>
#include <QSqlError>
#include <QDebug>


// Constructeur
Equipement::Equipement(int id, QString nom, QString type, QString statut, int quantite)
    : id(id), nom(nom), type(type), statut(statut), quantite(quantite) {}

// Accesseurs
int Equipement::getId() const {
    return id;
}

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
    QSqlQuery query;
    query.prepare("INSERT INTO equipement (nom, type, statut, quantite) VALUES (:nom, :type, :statut, :quantite)");
    query.bindValue(":nom", nom);
    query.bindValue(":type", type);
    query.bindValue(":statut", statut);
    query.bindValue(":quantite", quantite);

    if (!query.exec()) {
        qDebug() << "Erreur insertion équipement:" << query.lastError();
        return false;
    }
    return true;
}

// Afficher les équipements
QSqlQueryModel* Equipement::afficher() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT id, nom, type, statut, quantite FROM equipement ORDER BY id ASC");
    return model;
}

// Modifier un équipement
bool Equipement::modifier(int id) {
    QSqlQuery query;
    query.prepare("UPDATE equipement SET nom = :nom, type = :type, statut = :statut, quantite = :quantite WHERE id = :id");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":type", type);
    query.bindValue(":statut", statut);
    query.bindValue(":quantite", quantite);

    return query.exec();
}

// Supprimer un équipement
bool Equipement::supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM equipement WHERE id = :id");
    query.bindValue(":id", id);

    return query.exec();
}
