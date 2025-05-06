#include "Superviseur.h"
#include <QSqlQuery>
#include <QVariant>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QObject>  // Ajoutez cet en-tête pour utiliser la fonction tr()
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QPushButton> // Ajoute cette ligne si ce n'est pas encore fait
#include <QPrintPreviewDialog>
#include <QPrinter>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QTextDocument>
#include <QSqlRecord> // Ajoutez cette inclusion
#include <QDateTime>
// Constructeurs
Superviseur::Superviseur() {}

Superviseur::Superviseur(QString id, int cin, QString statut, QString poste, QString prenom,
                         QString nom, QString numtel, QString email, QString zone)
    : id_superviseur(id), cin_superviseur(cin), statut_superviseur(statut), poste(poste),
    prenom_superviseur(prenom), nom_superviseur(nom), numtel_superviseur(numtel), email_superviseur(email), zone_superviseur(zone) {}

QString Superviseur::getId() const { return id_superviseur; }
int Superviseur::getCIN() const { return cin_superviseur; }
QString Superviseur::getStatut() const { return statut_superviseur; }
QString Superviseur::getPoste() const { return poste; }
QString Superviseur::getPrenom() const { return prenom_superviseur; }
QString Superviseur::getNom() const { return nom_superviseur; }
QString Superviseur::getNumTel() const { return numtel_superviseur; }
QString Superviseur::getEmail() const { return email_superviseur; }
QString Superviseur::getZone() const {
    return zone_superviseur;
}

void Superviseur::setId(const QString id) { this->id_superviseur = id; }
void Superviseur::setCIN(const int &cin) { this->cin_superviseur = cin; }
void Superviseur::setStatut(const QString &statut) { this->statut_superviseur = statut; }
void Superviseur::setPoste(const QString &poste) { this->poste = poste; }
void Superviseur::setPrenom(const QString &prenom) { this->prenom_superviseur = prenom; }
void Superviseur::setNom(const QString &nom) { this->nom_superviseur = nom; }
void Superviseur::setNumTel(const QString &numTel) { this->numtel_superviseur = numTel; }
void Superviseur::setEmail(const QString &email) { this->email_superviseur = email; }
void Superviseur::setZone(const QString &zone) {
    zone_superviseur = zone;
}

bool Superviseur::ajouter() {
    // Vérifier la connexion à la base de données
    if (!QSqlDatabase::database().isOpen()) {
        qDebug() << "Erreur de connexion à la base de données.";
        return false;
    }

    // Vérification de l'existence de l'ID dans la base de données
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM SUPERVISEURS WHERE ID_SUPERVISEUR = :id");
    checkQuery.bindValue(":id", id_superviseur);
    if (checkQuery.exec() && checkQuery.next() && checkQuery.value(0).toInt() > 0) {
        qDebug() << "Erreur: ID du superviseur déjà existant.";
        return false;
    }

    // Préparer la requête d'insertion
    QSqlQuery query;
    query.prepare("INSERT INTO SUPERVISEURS (ID_SUPERVISEUR, CIN_SUPERVISEUR, STATUT_SUPERVISEUR, POSTE, "
                  "PRENOM_SUPERVISEUR, NOM_SUPERVISEUR, NUMTEL_SUPERVISEUR, EMAIL_SUPERVISEUR, ZONE_SUPERVISEUR) "
                  "VALUES (:id, :cin, :statut, :poste, :prenom, :nom, :numTel, :email, :zone)");

    // Lier les valeurs des paramètres
    query.bindValue(":id", id_superviseur);
    query.bindValue(":cin", cin_superviseur);
    query.bindValue(":statut", statut_superviseur);
    query.bindValue(":poste", poste);
    query.bindValue(":prenom", prenom_superviseur);
    query.bindValue(":nom", nom_superviseur);
    query.bindValue(":numTel", numtel_superviseur);
    query.bindValue(":email", email_superviseur);
    query.bindValue(":zone", zone_superviseur);

    // Vérifier et exécuter la requête
    if (!query.exec()) {
        qDebug() << "Erreur d'insertion dans la base de données : " << query.lastError().text();
        return false;
    }

    return true;
}


//affichage tableau

QSqlQueryModel * Superviseur::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM Superviseurs");


    // Définition des en-têtes des colonnes
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Statut"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Poste"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("NumTel"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Zone"));  // Ajout de la colonne "Zone"

    return model;
}


//Fonction Supprimer
bool Superviseur::supprimer(QString id) {
    QSqlQuery query;
    query.prepare("DELETE FROM SUPERVISEURS WHERE ID_SUPERVISEUR = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Erreur SQL lors de la suppression :" << query.lastError().text();
        return false;
    }

    return true;
}

//fonction Modifier
bool Superviseur::modifier(QString id) {
    QSqlQuery query;

    if (!QSqlDatabase::database().isOpen()) {
        qDebug() << "Erreur: La base de données n'est pas connectée.";
        return false;
    }

    query.prepare("UPDATE SUPERVISEURS SET CIN_SUPERVISEUR = :cin, STATUT_SUPERVISEUR = :statut, POSTE = :poste, "
                  "PRENOM_SUPERVISEUR = :prenom, NOM_SUPERVISEUR = :nom, NUMTEL_SUPERVISEUR = :numtel, EMAIL_SUPERVISEUR = :email, ZONE_SUPERVISEUR = :zone "  // Ajouter zone ici
                  "WHERE ID_SUPERVISEUR = :id");

    query.bindValue(":id", id);
    query.bindValue(":cin", cin_superviseur);
    query.bindValue(":statut", statut_superviseur);
    query.bindValue(":poste", poste);
    query.bindValue(":prenom", prenom_superviseur);
    query.bindValue(":nom", nom_superviseur);
    query.bindValue(":numtel", numtel_superviseur);
    query.bindValue(":email", email_superviseur);
    query.bindValue(":zone", zone_superviseur);  // Lier la zone

    if (query.exec()) {
        qDebug() << "Mise à jour réussie";
        return true;
    } else {
        qDebug() << "Erreur SQL lors de la mise à jour : " << query.lastError().text();
        return false;
    }
}
// Fonction de recherche par ID
QSqlQueryModel* Superviseur::rechercherParID(QString idRecherche)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    // Remplacez "ID" par le nom correct de la colonne dans la base de données
    query.prepare("SELECT * FROM superviseurs WHERE ID_SUPERVISEUR = :id");
    query.bindValue(":id", idRecherche);  // Utilisation de QString

    if (query.exec()) {
        model->setQuery(query);
    } else {
        model->clear();
        qDebug() << query.lastError().text();  // Pour afficher plus d'informations sur l'erreur
    }

    return model;
}
// Méthode pour trier les superviseurs par ordre alphabétique (A-Z)

QSqlQueryModel* Superviseur::trierNoms()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT * FROM superviseurs ORDER BY nom_superviseur ASC");

    if (!query.exec()) {
        qDebug() << "Erreur de tri :" << query.lastError().text();
        delete model;
        return nullptr;
    }

    model->setQuery(query);

    // Définir des en-têtes personnalisés
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Statut"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Poste"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Numéro de Téléphone"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Zone"));

    qDebug() << "Tri effectué, nombre de lignes :" << model->rowCount();

    return model;
}

//stat
QMap<QString, int> Superviseur::getStatistiquesParZone() {
    QMap<QString, int> stats;
    QSqlQuery query("SELECT zone_superviseur, COUNT(*) FROM SUPERVISEURS GROUP BY zone_superviseur");

    while (query.next()) {
        QString type = query.value(0).toString();
        int count = query.value(1).toInt();
        stats[type] = count;
    }

    return stats;
}
//pdf
bool Superviseur::exporterVersPDF(const QString &fileName)
{
    if (fileName.isEmpty()) return false;

    QPdfWriter pdfWriter(fileName);
    pdfWriter.setPageSize(QPageSize::A4);
    pdfWriter.setResolution(600);
    pdfWriter.setPageMargins(QMarginsF(20, 20, 20, 20)); // Marges

    QPainter painter;
    if (!painter.begin(&pdfWriter)) {
        qDebug() << "Erreur d'initialisation du PDF";
        return false;
    }

    // Police
    QFont titleFont("Arial", 14, QFont::Bold);
    QFont headerFont("Arial", 10, QFont::Bold);
    QFont dataFont("Arial", 9);

    // Titre
    painter.setFont(titleFont);
    painter.drawText(50, 50, "LISTE DES SUPERVISEURS");

    // En-têtes
    painter.setFont(headerFont);
    int yPos = 80;
    int columnWidth[5] = {60, 120, 150, 100, 100}; // id, cin, email, numtel, zone

    painter.drawText(50, yPos, "ID");
    painter.drawText(50 + columnWidth[0], yPos, "CIN");
    painter.drawText(50 + columnWidth[0] + columnWidth[1], yPos, "Email");
    painter.drawText(50 + columnWidth[0] + columnWidth[1] + columnWidth[2], yPos, "NumTel");
    painter.drawText(50 + columnWidth[0] + columnWidth[1] + columnWidth[2] + columnWidth[3], yPos, "Zone");

    painter.drawLine(50, yPos + 5, 550, yPos + 5); // ligne sous les en-têtes

    // Requête SQL optimisée
    QSqlQuery query;
    query.prepare("SELECT id, cin, email, numtel, zone FROM superviseurs");

    if (!query.exec()) {
        qDebug() << "Erreur SQL : " << query.lastError().text();
        painter.end();
        return false;
    }

    // Données
    painter.setFont(dataFont);
    yPos += 30;

    while (query.next()) {
        painter.drawText(50, yPos, query.value(0).toString()); // ID
        painter.drawText(50 + columnWidth[0], yPos, query.value(1).toString()); // CIN
        painter.drawText(50 + columnWidth[0] + columnWidth[1], yPos, query.value(2).toString()); // Email
        painter.drawText(50 + columnWidth[0] + columnWidth[1] + columnWidth[2], yPos, query.value(3).toString()); // NumTel
        painter.drawText(50 + columnWidth[0] + columnWidth[1] + columnWidth[2] + columnWidth[3], yPos, query.value(4).toString()); // Zone

        yPos += 15;

        if (yPos > pdfWriter.height() - 50) {
            pdfWriter.newPage();
            yPos = 50;
        }
    }

    painter.end();
    return true;

}
//Arduino
QString Superviseur::getStatutByRFID(const QString& rfid_code) {
    // Exemple statique — remplace par ton propre système de données
    if (rfid_code == "ABCD1234") { // Remplace avec un vrai UID
        return "occupé";
    } else if (rfid_code == "1234ABCD") {
        return "libre";
    }
    return "inconnu";
}

