#include "Etablissement.h"

Etablissement::Etablissement(int id_eta, const QString& nom_eta, const QString& type,
                             const QString& ville, const QString& gouvernorat,
                             const QString& directeur, int nb_salles)
    : id_eta(id_eta), nom_eta(nom_eta), type(type), ville(ville),
    gouvernorat(gouvernorat), directeur(directeur), nb_salles(nb_salles) {}

// Getters
int Etablissement::getIdEta() const {
    return id_eta;
}

QString Etablissement::getNomEta() const {
    return nom_eta;
}

QString Etablissement::getType() const {
    return type;
}

QString Etablissement::getVille() const {
    return ville;
}

QString Etablissement::getGouvernorat() const {
    return gouvernorat;
}

QString Etablissement::getDirecteur() const {
    return directeur;
}

int Etablissement::getNbSalles() const {
    return nb_salles;
}

// Setters
void Etablissement::setNomEta(const QString& nom_eta) {
    this->nom_eta = nom_eta;
}

void Etablissement::setType(const QString& type) {
    this->type = type;
}

void Etablissement::setVille(const QString& ville) {
    this->ville = ville;
}

void Etablissement::setGouvernorat(const QString& gouvernorat) {
    this->gouvernorat = gouvernorat;
}

void Etablissement::setDirecteur(const QString& directeur) {
    this->directeur = directeur;
}

void Etablissement::setNbSalles(int nb_salles) {
    this->nb_salles = nb_salles;
}
