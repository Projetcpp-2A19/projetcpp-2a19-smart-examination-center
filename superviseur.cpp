#include "Superviseur.h"
#include <QSqlQuery>
#include <QVariant>
#include <QSqlQueryModel>

// Constructeurs
Superviseur::Superviseur() {}

Superviseur::Superviseur(QString  id, int cin, QString statut, QString poste, QString prenom,
                         QString nom, int numtel, QString email)
    : id_superviseur(id), cin_superviseur(cin), statut_superviseur(statut), poste(poste),
    prenom_superviseur(prenom), nom_superviseur(nom), numtel_superviseur(numtel), email_superviseur(email) {}

QString Superviseur::getId() const { return id_superviseur; }
int Superviseur::getCIN() const { return cin_superviseur; }
QString Superviseur::getStatut() const { return statut_superviseur; }
QString Superviseur::getPoste() const { return poste; }
QString Superviseur::getPrenom() const { return prenom_superviseur; }
QString Superviseur::getNom() const { return nom_superviseur; }
int Superviseur::getNumTel() const { return numtel_superviseur; }
QString Superviseur::getEmail() const { return email_superviseur; }

void Superviseur::setId(const QString id) { this->id_superviseur = id; }
void Superviseur::setCIN(const int &cin) { this->cin_superviseur = cin; }
void Superviseur::setStatut(const QString &statut) { this->statut_superviseur = statut; }
void Superviseur::setPoste(const QString &poste) { this->poste = poste; }
void Superviseur::setPrenom(const QString &prenom) { this->prenom_superviseur = prenom; }
void Superviseur::setNom(const QString &nom) { this->nom_superviseur = nom; }
void Superviseur::setNumTel(const int &numTel) { this->numtel_superviseur = numTel; }
void Superviseur::setEmail(const QString &email) { this->email_superviseur = email; }

bool Superviseur::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO SUPERVISEURS (ID_SUPERVISEUR, CIN_SUPERVISEUR, STATUT_SUPERVISEUR, POSTE, "
                  "PRENOM_SUPERVISEUR, NOM_SUPERVISEUR, NUMTEL_SUPERVISEUR, EMAIL_SUPERVISEUR) "
                  "VALUES (:id, :cin, :statut, :poste, :prenom, :nom, :numTel, :email)");

    query.bindValue(":id", id_superviseur);
    query.bindValue(":cin", cin_superviseur);
    query.bindValue(":statut", statut_superviseur);
    query.bindValue(":poste", poste);
    query.bindValue(":prenom", prenom_superviseur);
    query.bindValue(":nom", nom_superviseur);
    query.bindValue(":numTel", numtel_superviseur);
    query.bindValue(":email", email_superviseur);

    return query.exec();
}
QSqlQueryModel * Superviseur::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM Superviseurs");

    // Définition des en-têtes des colonnes
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Statut"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Poste"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("NumTel"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Email"));

    return model;
}

