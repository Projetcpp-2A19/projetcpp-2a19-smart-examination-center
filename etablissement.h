#ifndef ETABLISSEMENT_H
#define ETABLISSEMENT_H

#include <QString>

class Etablissement {
private:
    int id_eta;
    QString nom_eta;
    QString type;
    QString ville;
    QString gouvernorat;
    QString directeur;
    int nb_salles;

public:
    Etablissement(int id_eta = 0, const QString& nom_eta = "", const QString& type = "",
                  const QString& ville = "", const QString& gouvernorat = "",
                  const QString& directeur = "", int nb_salles = 0);

    int getIdEta() const;
    QString getNomEta() const;
    QString getType() const;
    QString getVille() const;
    QString getGouvernorat() const;
    QString getDirecteur() const;
    int getNbSalles() const;

    void setNomEta(const QString& nom_eta);
    void setType(const QString& type);
    void setVille(const QString& ville);
    void setGouvernorat(const QString& gouvernorat);
    void setDirecteur(const QString& directeur);
    void setNbSalles(int nb_salles);

    QString afficherDetails() const;
};

#endif // ETABLISSEMENT_H
