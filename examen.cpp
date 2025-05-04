#include "examen.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>
#include <QStandardItemModel>

// Constructeur par défaut
Examen::Examen() : id_examen("") {}

// Constructeur paramétré
Examen::Examen( QString type_examen, QString statut_examen, QString niveau_examen,
               QString matiere_examen, QByteArray enonce_examen, QString duree_examen, QDate date_examen)
    : type_examen(type_examen), statut_examen(statut_examen), niveau_examen(niveau_examen),
    matiere_examen(matiere_examen), enonce_examen(enonce_examen), duree_examen(duree_examen), date_examen(date_examen) {}

// Getters
QString Examen::getIdExamen() const { return id_examen; }
QString Examen::getTypeExamen() const { return type_examen; }
QString Examen::getStatutExamen() const { return statut_examen; }
QString Examen::getNiveauExamen() const { return niveau_examen; }
QString Examen::getMatiereExamen() const { return matiere_examen; }
QByteArray Examen::getEnonceExamen() const { return enonce_examen; }
QString Examen::getDureeExamen() const { return duree_examen; }
QDate Examen::getDateExamen() const { return date_examen; }

// Setters
void Examen::setIdExamen(QString id) { this->id_examen = id; }
void Examen::setTypeExamen(QString type) { this->type_examen = type; }
void Examen::setStatutExamen(QString statut) { this->statut_examen = statut; }
void Examen::setNiveauExamen(QString niveau) { this->niveau_examen = niveau; }
void Examen::setMatiereExamen(QString matiere) { this->matiere_examen = matiere; }
void Examen::setEnonceExamen(QByteArray enonce) { this->enonce_examen = enonce; }
void Examen::setDureeExamen(QString duree) { this->duree_examen = duree; }
void Examen::setDateExamen(QDate date) { this->date_examen = date; }

QSqlQueryModel *Examen::afficherExamen() {
    qDebug() << "=== Starting afficherExamen ===";
    QSqlQueryModel *m_examenModel = new QSqlQueryModel();  // Create new model each time

    if (!m_examenModel) {
        qDebug() << "Creating new model instance...";
        m_examenModel = new QSqlQueryModel();
    }

    qDebug() << "Executing query...";
    QString queryStr = "SELECT ID_EXAMEN, MATIERE_EXAMEN, TYPE_EXAMEN, STATUT_EXAMEN, "
                       "NIVEAU_EXAMEN, DUREE_EXAMEN, DATE_EXAMEN FROM EXAMENS";
    qDebug() << "Query:" << queryStr;

    m_examenModel->setQuery(queryStr);

    if (m_examenModel->lastError().isValid()) {
        qDebug() << "SQL Error:" << m_examenModel->lastError().text();
    } else {
        qDebug() << "Query successful. Rows:" << m_examenModel->rowCount();
    }

    qDebug() << "Model address:" << m_examenModel;
    qDebug() << "=== afficherExamen completed ===";
    return m_examenModel;
}



// Ajouter un examen
bool Examen::ajouterExamen() {
    QSqlQuery query;
    query.prepare("INSERT INTO EXAMENS ( TYPE_EXAMEN, STATUT_EXAMEN, NIVEAU_EXAMEN, "
                  "MATIERE_EXAMEN, ENONCE_EXAMEN, DUREE_EXAMEN, DATE_EXAMEN) "
                  "VALUES ( :type_examen, :statut_examen, :niveau_examen, "
                  ":matiere_examen, :enonce_examen, :duree_examen, :date_examen)");

    query.bindValue(":type_examen", type_examen);
    query.bindValue(":statut_examen", statut_examen);
    query.bindValue(":niveau_examen", niveau_examen);
    query.bindValue(":matiere_examen", matiere_examen);
    query.bindValue(":enonce_examen", enonce_examen);
    query.bindValue(":duree_examen", duree_examen);
    query.bindValue(":date_examen", date_examen);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'ajout: " << query.lastError().text();
        return false;
    }

    return true;
}


// Modifier un examen
bool Examen::modifierExamen(QString id) {
    QSqlQuery query;
    query.prepare("UPDATE EXAMENS SET TYPE_EXAMEN = :type_examen, STATUT_EXAMEN = :statut_examen, "
                  "NIVEAU_EXAMEN = :niveau_examen, MATIERE_EXAMEN = :matiere_examen, "
                  "ENONCE_EXAMEN = :enonce_examen, DUREE_EXAMEN = :duree_examen, DATE_EXAMEN = :date_examen "
                  "WHERE ID_EXAMEN = :id_examen");
    query.bindValue(":id_examen", id);
    query.bindValue(":type_examen", type_examen);
    query.bindValue(":statut_examen", statut_examen);
    query.bindValue(":niveau_examen", niveau_examen);
    query.bindValue(":matiere_examen", matiere_examen);
    query.bindValue(":enonce_examen", enonce_examen);
    query.bindValue(":duree_examen", duree_examen);
    query.bindValue(":date_examen", date_examen);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la modification: " << query.lastError().text();
        return false;
    }

    return true;
}

// Supprimer un examen
bool Examen::supprimerExamen(QString id) {
    QSqlQuery query;
    query.prepare("DELETE FROM EXAMENS WHERE ID_EXAMEN = :id_examen");
    query.bindValue(":id_examen", id);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la suppression: " << query.lastError().text();
        return false;
    }

    return true;
}


QByteArray Examen::getPdfDataById(const QString &id)
{
    QSqlQuery query;
    query.prepare("SELECT ENONCE_EXAMEN FROM EXAMENS WHERE ID_EXAMEN = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        return query.value("ENONCE_EXAMEN").toByteArray();
    } else {
        qDebug() << "Failed to retrieve PDF data for exam ID:" << id;
        return QByteArray();
    }
}

