#ifndef EXAMEN_H
#define EXAMEN_H

#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>

class Examen {
private:
    QString id_examen; // VARCHAR2(10)
    QString type_examen; // VARCHAR2(10)
    QString statut_examen; // VARCHAR2(10)
    QString niveau_examen; // VARCHAR2(5)
    QString matiere_examen; // VARCHAR2(10)
    QByteArray enonce_examen; // BLOB
    QString duree_examen; // VARCHAR2(5)
    QDate date_examen; // DATE
    //QSqlQueryModel *m_examenModel = nullptr;  // instead of just 'model'

public:
    // Constructeurs
    Examen();
    Examen( QString, QString, QString, QString, QByteArray, QString, QDate);

    // Getters
    QString getIdExamen() const;
    QString getTypeExamen() const;
    QString getStatutExamen() const;
    QString getNiveauExamen() const;
    QString getMatiereExamen() const;
    QByteArray getEnonceExamen() const;
    QString getDureeExamen() const;
    QDate getDateExamen() const;

    // Setters
    void setIdExamen(QString);
    void setTypeExamen(QString);
    void setStatutExamen(QString);
    void setNiveauExamen(QString);
    void setMatiereExamen(QString);
    void setEnonceExamen(QByteArray);
    void setDureeExamen(QString);
    void setDateExamen(QDate);
    QByteArray getPdfDataById(const QString &id);

    // Opérations CRUD
    bool ajouterExamen();
    bool modifierExamen(QString);
    bool supprimerExamen(QString);
    QSqlQueryModel *afficherExamen();

};


#endif // EXAMEN_H
