#include "fournisseurs.h"
#include <QDebug>

// 🔹 Constructeur par défaut
Fournisseur::Fournisseur() : id_fourn(""), nom_fourn(""), adresse(""),
    email(""), numTel(0), typeService("") {}


// ✅ Constructeur utilisé pour la modification (ID nécessaire)
Fournisseur::Fournisseur(const QString& id_fourn, const QString& nom_fourn, const QString& adresse, const QString& email, int numTel, const QString& typeService)
    : id_fourn(id_fourn), nom_fourn(nom_fourn), adresse(adresse),
    email(email), numTel(numTel), typeService(typeService) {}

// 🔹 Constructeur sans ID (utilisé pour ajout)
Fournisseur::Fournisseur(const QString& nom_fourn, const QString& adresse, const QString& email, int numTel, const QString& typeService)
    : id_fourn(""), nom_fourn(nom_fourn), adresse(adresse),
    email(email), numTel(numTel), typeService(typeService) {}

// 🔹 Getters
QString Fournisseur::getIdFourn() const { return id_fourn; }
QString Fournisseur::getNomFourn() const { return nom_fourn; }
QString Fournisseur::getAdresse() const { return adresse; }
QString Fournisseur::getEmail() const { return email; }
int Fournisseur::getNumTel() const { return numTel; }
QString Fournisseur::getTypeService() const { return typeService; }

// 🔹 Setters
void Fournisseur::setIdFourn(const QString& id) { this->id_fourn = id; }

void Fournisseur::setNomFourn(const QString& nom_fourn) { this->nom_fourn = nom_fourn; }
void Fournisseur::setAdresse(const QString& adresse) { this->adresse = adresse; }
void Fournisseur::setEmail(const QString& email) { this->email = email; }
void Fournisseur::setNumTel(int numTel) { this->numTel = numTel; }
void Fournisseur::setTypeService(const QString& typeService) { this->typeService = typeService; }

// 🔹 Vérifier si un fournisseur existe déjà
bool Fournisseur::existeDeja(int id) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM FOURNISSEURS WHERE ID_FOURNISSEUR = :id");
    query.bindValue(":id", id);
    if (query.exec() && query.next()) {
        return query.value(0).toInt() > 0;
    }
    qDebug() << "Erreur SQL lors de la vérification de l'existence : " << query.lastError().text();
    return false;
}

// 🔹 Ajouter un fournisseur
bool Fournisseur::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO FOURNISSEURS (ID_FOURNISSEUR, NOM_FOURNISSEUR, EMAIL_FOURNISSEUR, NUMTEL_FOURNISSEUR, ADRESSE_FOURNISSEUR, TYPESERVICE_FOURNISSEUR) "
                  "VALUES (fournisseurs_seq.NEXTVAL, :nom_fourn, :email, :numTel, :adresse, :typeService)");

    query.bindValue(":nom_fourn", nom_fourn);
    query.bindValue(":email", email);
    query.bindValue(":numTel", numTel);
    query.bindValue(":adresse", adresse);
    query.bindValue(":typeService", typeService);

    if (!query.exec()) {
        lastError = query.lastError();
        qDebug() << "Erreur lors de l'ajout du fournisseur :" << lastError.text();
        return false;
    }
    return true;
}
// 🔹 Afficher la liste des fournisseurs
QSqlQueryModel* Fournisseur::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();

    // Vérifier si la base de données est connectée
    if (!QSqlDatabase::database().isOpen()) {
        qDebug() << "❌ ERREUR : La base de données n'est pas connectée.";
        return nullptr;
    } else {
        qDebug() << "✅ Base de données connectée avec succès.";
    }

    // Exécuter la requête
    model->setQuery("SELECT ID_FOURNISSEUR, NOM_FOURNISSEUR, NUMTEL_FOURNISSEUR, EMAIL_FOURNISSEUR, ADRESSE_FOURNISSEUR, TYPESERVICE_FOURNISSEUR FROM FOURNISSEURS");

    // Vérifier si la requête SQL a bien fonctionné
    if (model->lastError().isValid()) {
        qDebug() << "❌ ERREUR SQL : " << model->lastError().text();
        return nullptr;
    }

    qDebug() << "📊 Nombre de fournisseurs récupérés :" << model->rowCount();
    if (model->rowCount() == 0) {
        qDebug() << "⚠️ Aucune donnée trouvée. Vérifie si ta table contient bien des enregistrements.";
    }

    // 🔹 Définition des en-têtes des colonnes
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Numéro"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Service"));

    return model;
}
// 🔹 Gestion des erreurs SQL
QSqlError Fournisseur::getLastError() const {
    return lastError;
}


// 🔹 Supprimer un fournisseur
bool Fournisseur::supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM FOURNISSEURS WHERE ID_FOURNISSEUR = :id_fourn");
    query.bindValue(":id_fourn", id);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la suppression du fournisseur :" << query.lastError().text();
        return false;
    }
    return true;
}

// 🔹 Modifier un fournisseur existant
// 🔹 Fonction Modifier un Fournisseur
bool Fournisseur::modifier( QString id) {
    QSqlQuery query;
    query.prepare("UPDATE FOURNISSEURS SET NOM_FOURNISSEUR = :nom, "
                  "NUMTEL_FOURNISSEUR = :numtel, EMAIL_FOURNISSEUR = :email, "
                  "ADRESSE_FOURNISSEUR = :adresse, TYPESERVICE_FOURNISSEUR = :typeService "
                  "WHERE ID_FOURNISSEUR = :id");

    query.bindValue(":id", id);
    query.bindValue(":nom", nom_fourn);
    query.bindValue(":numtel", numTel);
    query.bindValue(":email", email);
    query.bindValue(":adresse", adresse);
    query.bindValue(":typeService", typeService);

    if (!query.exec()) {
        qDebug() << "❌ ERREUR SQL lors de la mise à jour : " << query.lastError().text();
        return false;
    }
    return true;
}



// 🔹 Afficher les détails sous forme de texte
QString Fournisseur::afficherDetails() const {
    return "ID: " + id_fourn + "\n" +
           "Nom: " + nom_fourn + "\n" +
           "Adresse: " + adresse + "\n" +
           "Email: " + email + "\n" +
           "Numéro de Téléphone: " + QString::number(numTel) + "\n" +  // ✅ Convertir int en QString
           "Type de Service: " + typeService;
}
