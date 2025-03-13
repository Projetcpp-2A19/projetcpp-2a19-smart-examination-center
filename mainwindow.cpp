#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "candidat.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    afficherCandidats(); // Charger les candidats au démarrage
}

MainWindow::~MainWindow()
{
    delete ui;
}
bool MainWindow::verifierSaisie(QString code, QString prenom, int cin, QString adresse, QString nom, int numTel)
{
    // Vérification du code : 4 chiffres non successifs
    QRegularExpression regexCode("^(?!.*(012|123|234|345|456|567|678|789|987|876|765|654|543|432|321|210))\\d{4}$");
    if (!regexCode.match(code).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le code doit contenir 4 chiffres non successifs.");
        return false;
    }

    // Vérification du CIN : Uniquement chiffres
    if (cin <= 0) {
        QMessageBox::warning(this, "Erreur de saisie", "Le CIN doit être un entier positif.");
        return false;
    }

    // Vérification du Nom et Prénom : Uniquement lettres
    QRegularExpression regexNomPrenom("^[a-zA-ZÀ-ÿ\\s]+$");
    if (!regexNomPrenom.match(nom).hasMatch() || !regexNomPrenom.match(prenom).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le nom et le prénom doivent contenir uniquement des lettres.");
        return false;
    }

    // Vérification du numéro de téléphone : 8 chiffres uniquement
    QRegularExpression regexNumTel("^\\d{8}$");
    if (!regexNumTel.match(QString::number(numTel)).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le numéro de téléphone doit contenir exactement 8 chiffres.");
        return false;
    }

    // Vérification de l'adresse : Non vide
    if (adresse.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "L'adresse ne peut pas être vide.");
        return false;
    }

    return true;
}

void MainWindow::on_AjButton_5_clicked()
{
    QString code = ui->lineCode->text();
    QString prenom = ui->linePrenom->text();
    int cin = ui->lineCIN->text().toInt();
    QString adresse = ui->lineAdresse->text();
    QString nom = ui->lineNom->text();
    int numTel = ui->lineNumTel->text().toInt();
    QString niveau = ui->comboNiveau->currentItem()->text();
    QByteArray photo; // Gestion de la photo plus tard

    // Vérifier la saisie avant d'ajouter
    if (!verifierSaisie(code, prenom, cin, adresse, nom, numTel)) {
        return; // Arrêter l'ajout si la saisie est invalide
    }

    Candidat candidat(code, prenom, cin, adresse, nom, numTel, niveau, photo);
    if (candidat.ajouter()) {
        QMessageBox::information(this, "Succès", "Candidat ajouté avec succès.");
        afficherCandidats();  // Mettre à jour la table
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout du candidat.");
    }
}



void MainWindow::afficherCandidats()
{
    QSqlQuery query;
    query.exec("SELECT CODE_CANDIDAT, PRENOM_CANDIDAT, CIN_CANDIDAT, ADRESSE_CANDIDAT, NOM_CANDIDAT, NUMTEL_CANDIDAT, NIVEAU_CANDIDAT FROM CANDIDAT");

    ui->tableView->clear();  // Effacer les anciennes données
    ui->tableView->setRowCount(0);
    ui->tableView->setColumnCount(7);  // Nombre de colonnes correspondant aux champs

    // Définir les en-têtes de colonnes
    QStringList labels = {"Code", "Prénom", "CIN", "Adresse", "Nom", "NumTel", "Niveau"};
    ui->tableView->setHorizontalHeaderLabels(labels);

    int row = 0;
    while (query.next()) {
        ui->tableView->insertRow(row);
        for (int col = 0; col < 7; col++) {
            ui->tableView->setItem(row, col, new QTableWidgetItem(query.value(col).toString()));
        }
        row++;
    }
}


void MainWindow::on_btnSupprimer_clicked()
{
    QString code = ui->lineCode->text();

    if (code.isEmpty()) {
        QMessageBox::warning(this, "Attention", "Veuillez entrer un code valide !");
        return;
    }

    // Boîte de confirmation avant suppression
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation", "Voulez-vous vraiment supprimer ce candidat ?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::No) {
        return;
    }

    Candidat c(code, "", 0, "", "", 0, "", QByteArray());
    if (c.supprimer(code)) {
        QMessageBox::information(this, "Succès", "Candidat supprimé.");
        afficherCandidats();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression.");
    }
}

void MainWindow::on_ModButton_5_clicked()
{
    QString code = ui->lineCode->text();
    QString prenom = ui->linePrenom->text();
    int cin = ui->lineCIN->text().toInt();
    QString adresse = ui->lineAdresse->text();
    QString nom = ui->lineNom->text();
    int numTel = ui->lineNumTel->text().toInt();
    QString niveau = ui->comboNiveau->currentItem()->text();
    QByteArray photo; // À compléter avec un fichier image

    if (code.isEmpty()) {
        QMessageBox::warning(this, "Attention", "Veuillez entrer un code valide !");
        return;
    }

    Candidat c(code, prenom, cin, adresse, nom, numTel, niveau, photo);
    if (c.modifier(code, prenom, cin, adresse, nom, numTel, niveau, photo)) {
        QMessageBox::information(this, "Succès", "Candidat modifié avec succès.");
        afficherCandidats();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification.");
    }
}
void MainWindow::on_lineCode_textChanged(const QString &code)
{
    if (code.isEmpty()) return; // Ne rien faire si le champ est vide

    Candidat c;
    if (c.chercherCandidat(code)) {
        ui->linePrenom->setText(c.getPrenom());
        ui->lineCIN->setText(QString::number(c.getCin()));
        ui->lineAdresse->setText(c.getAdresse());
        ui->lineNom->setText(c.getNom());
        ui->lineNumTel->setText(QString::number(c.getNumTel()));
        QList<QListWidgetItem *> items = ui->comboNiveau->findItems(c.getNiveau(), Qt::MatchExactly);
        if (!items.isEmpty()) {
            ui->comboNiveau->setCurrentItem(items.first());
        }
    } else {
        // Si aucun candidat trouvé, vider les champs
        ui->linePrenom->clear();
        ui->lineCIN->clear();
        ui->lineAdresse->clear();
        ui->lineNom->clear();
        ui->lineNumTel->clear();
        ui->comboNiveau->setCurrentRow(0);
    }
}

