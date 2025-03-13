#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMouseEvent>  // For detecting mouse events
#include <QPushButton>
#include <QHBoxLayout>
#include <QWidget>
#include "Etablissement.h"
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QDebug>
#include <QSqlError>  // Ajoute cette ligne pour inclure QSqlError
#include <QInputDialog>
#include <QTimer>

// Constructeur
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initialiser le modèle pour afficher les établissements
    ui->tableView1->setModel(E.afficher());

    // Configurer le placeholder pour la recherche
    ui->lineEdit->setPlaceholderText("Rechercher...");

    // Connexion des boutons
    connect(ui->closeBtn, &QPushButton::clicked, this, &MainWindow::close);
    connect(ui->BinSuperbtn, &QPushButton::clicked, this, &MainWindow::on_BinSuperbtn_clicked);
}

// Destructeur
MainWindow::~MainWindow()
{
    delete ui;
    delete model; // Supprimer le modèle pour éviter les fuites de mémoire
}

// Mettre à jour le tableau des établissements
void MainWindow::updateTableView()
{
    ui->tableView1->setModel(E.afficher());
}

// Ajouter un établissement
void MainWindow::on_Ajbtn_clicked()
{
    // Récupérer les valeurs des champs de saisie
    QString id = ui->idEtablissementLineEdit->text();
    QString gouvernorat = ui->gouvernoratLineEdit->text();
    QString type = ui->typeLineEdit->text();
    QString directeur = ui->directeurLineEdit->text();
    QString nom = ui->nomLineEdit->text();
    int nombreSalle = ui->nombreSalleLineEdit->text().toInt();
    QString ville = ui->villeLineEdit->text();

    // Vérifier que tous les champs sont remplis
    if (id.isEmpty() || gouvernorat.isEmpty() || type.isEmpty() || directeur.isEmpty() || nom.isEmpty() || ville.isEmpty())
    {
        QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis.");
        return;
    }

    // Créer un objet Etablissement
    Etablissement E(id, gouvernorat, type, directeur, nom, nombreSalle, ville);

    // Ajouter l'établissement à la base de données
    if (E.ajouter())
    {
        QMessageBox::information(this, "Succès", "Établissement ajouté avec succès !");
        updateTableView();  // Mettre à jour le tableau
    }
    else
    {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout de l'établissement.");
    }
}

// Supprimer un établissement
void MainWindow::on_BinSuperbtn_clicked()
{
    // Récupérer l'index de la ligne sélectionnée dans le tableau
    QModelIndex index = ui->tableView1->selectionModel()->currentIndex();
    if (!index.isValid())
    {
        QMessageBox::warning(this, "Suppression", "Veuillez sélectionner un établissement à supprimer.");
        return;
    }

    // Récupérer l'ID de l'établissement sélectionné
    QString id = ui->tableView1->model()->data(index).toString();

    // Supprimer l'établissement de la base de données
    if (E.supprimer(id))
    {
        QMessageBox::information(this, "Succès", "Établissement supprimé avec succès !");
        updateTableView();  // Mettre à jour le tableau
    }
    else
    {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression.");
    }
}

// Modifier un établissement
void MainWindow::on_Modbtn_clicked()
{
    // Récupérer l'index de la ligne sélectionnée dans le tableau
    QModelIndex index = ui->tableView1->selectionModel()->currentIndex();
    if (!index.isValid())
    {
        QMessageBox::warning(this, "Modification", "Veuillez sélectionner un établissement à modifier.");
        return;
    }

    // Récupérer l'ID de l'établissement sélectionné
    QString id = ui->tableView1->model()->data(index).toString();

    // Remplir les champs de saisie avec les données de l'établissement sélectionné
    E.setId(id);
    ui->idEtablissementLineEdit->setText(id);
    ui->gouvernoratLineEdit->setText(E.getGouvernorat());
    ui->typeLineEdit->setText(E.getType());
    ui->directeurLineEdit->setText(E.getDirecteur());
    ui->nomLineEdit->setText(E.getNom());
    ui->nombreSalleLineEdit->setText(QString::number(E.getNombreSalle()));
    ui->villeLineEdit->setText(E.getVille());
}

// Sauvegarder les modifications
void MainWindow::on_SaveMod_clicked()
{
    // Récupérer les nouvelles valeurs des champs de saisie
    QString id = ui->idEtablissementLineEdit->text();
    QString gouvernorat = ui->gouvernoratLineEdit->text();
    QString type = ui->typeLineEdit->text();
    QString directeur = ui->directeurLineEdit->text();
    QString nom = ui->nomLineEdit->text();
    int nombreSalle = ui->nombreSalleLineEdit->text().toInt();
    QString ville = ui->villeLineEdit->text();

    // Vérifier que tous les champs sont remplis
    if (id.isEmpty() || gouvernorat.isEmpty() || type.isEmpty() || directeur.isEmpty() || nom.isEmpty() || ville.isEmpty())
    {
        QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis.");
        return;
    }

    // Mettre à jour les données de l'établissement
    E.setId(id);
    E.setGouvernorat(gouvernorat);
    E.setType(type);
    E.setDirecteur(directeur);
    E.setNom(nom);
    E.setNombreSalle(nombreSalle);
    E.setVille(ville);

    // Modifier l'établissement dans la base de données
    if (E.modifier())
    {
        QMessageBox::information(this, "Succès", "Établissement modifié avec succès !");
        updateTableView();  // Mettre à jour le tableau
    }
    else
    {
        QMessageBox::critical(this, "Erreur", "Échec de la modification.");
    }
}

// Navigation dans l'interface
void MainWindow::on_examButton_clicked() { ui->stackedWidget->setCurrentIndex(1); }
void MainWindow::on_supButton_clicked() { ui->stackedWidget->setCurrentIndex(2); }
void MainWindow::on_eqButton_clicked() { ui->stackedWidget->setCurrentIndex(5); }
void MainWindow::on_FourButton_clicked() { ui->stackedWidget->setCurrentIndex(6); }
void MainWindow::on_candButton_clicked() { ui->stackedWidget->setCurrentIndex(7); }
void MainWindow::on_etaButton_clicked() { ui->stackedWidget->setCurrentIndex(8); }
void MainWindow::on_homeBtn_clicked() { ui->stackedWidget->setCurrentIndex(0); }
void MainWindow::on_notifBtn_clicked() { ui->stackedWidget->setCurrentIndex(3); }
void MainWindow::on_EvalAssist_clicked() { ui->stackedWidget->setCurrentIndex(5); }
