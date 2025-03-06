#include "Etablissement.h"

// Constructeur
Etablissement::Etablissement(int id_eta, const QString& nom_eta, const QString& type,
                             const QString& ville, const QString& gouvernorat,
                             const QString& directeur, int nb_salles)
    : id_eta(id_eta), nom_eta(nom_eta), type(type), ville(ville),
    gouvernorat(gouvernorat), directeur(directeur), nb_salles(nb_salles) {}

// Getters
int Etablissement::getIdEta() const { return id_eta; }
QString Etablissement::getNomEta() const { return nom_eta; }
QString Etablissement::getType() const { return type; }
QString Etablissement::getVille() const { return ville; }
QString Etablissement::getGouvernorat() const { return gouvernorat; }
QString Etablissement::getDirecteur() const { return directeur; }
int Etablissement::getNbSalles() const { return nb_salles; }

// Setters
void Etablissement::setNomEta(const QString& nom_eta) { this->nom_eta = nom_eta; }
void Etablissement::setType(const QString& type) { this->type = type; }
void Etablissement::setVille(const QString& ville) { this->ville = ville; }
void Etablissement::setGouvernorat(const QString& gouvernorat) { this->gouvernorat = gouvernorat; }
void Etablissement::setDirecteur(const QString& directeur) { this->directeur = directeur; }
void Etablissement::setNbSalles(int nb_salles) { this->nb_salles = nb_salles; }

// Ajouter un établissement dans la base de données
bool Etablissement::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO etablissements (id_eta, nom_eta, type, ville, gouvernorat, directeur, nb_salles) "
                  "VALUES (:id_eta, :nom_eta, :type, :ville, :gouvernorat, :directeur, :nb_salles)");
    query.bindValue(":id_eta", id_eta);
    query.bindValue(":nom_eta", nom_eta);
    query.bindValue(":type", type);
    query.bindValue(":ville", ville);
    query.bindValue(":gouvernorat", gouvernorat);
    query.bindValue(":directeur", directeur);
    query.bindValue(":nb_salles", nb_salles);

    return query.exec();
}

// Supprimer un établissement de la base de données
bool Etablissement::supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM etablissements WHERE id_eta = :id_eta");
    query.bindValue(":id_eta", id);

    return query.exec();
}

// Modifier un établissement existant
bool Etablissement::modifier() {
    QSqlQuery query;
    query.prepare("UPDATE etablissements SET nom_eta = :nom_eta, type = :type, ville = :ville, "
                  "gouvernorat = :gouvernorat, directeur = :directeur, nb_salles = :nb_salles "
                  "WHERE id_eta = :id_eta");
    query.bindValue(":id_eta", id_eta);
    query.bindValue(":nom_eta", nom_eta);
    query.bindValue(":type", type);
    query.bindValue(":ville", ville);
    query.bindValue(":gouvernorat", gouvernorat);
    query.bindValue(":directeur", directeur);
    query.bindValue(":nb_salles", nb_salles);

    return query.exec();
}

// Afficher la liste des établissements
QSqlQueryModel* Etablissement::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM etablissements");
    return model;
}

// Afficher les détails sous forme de QString
QString Etablissement::afficherDetails() const {
    return "ID: " + QString::number(id_eta) + "\n" +
           "Nom: " + nom_eta + "\n" +
           "Type: " + type + "\n" +
           "Ville: " + ville + "\n" +
           "Gouvernorat: " + gouvernorat + "\n" +
           "Directeur: " + directeur + "\n" +
           "Nombre de Salles: " + QString::number(nb_salles);
}
