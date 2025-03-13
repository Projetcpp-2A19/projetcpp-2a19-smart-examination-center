#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMouseEvent>  // For detecting mouse events
#include <QPushButton>
#include <QHBoxLayout>
#include <QWidget>
#include "Superviseur.h"
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QDebug>
#include <QSqlError>  // Ajoute cette ligne pour inclure QSqlError
#include <QInputDialog>
#include <QTimer>
#include <QString>
//#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //ui->tableView1->setModel(Etmp.afficher()); // Remplace tableWidget1 par tableView
    // Affichage direct du tableView1 au démarrage
    //SSupprimer
    connect(ui->BinSuperbtn, &QPushButton::clicked, this, &MainWindow::on_BinSuperbtn_clicked);
    connect(ui->SaveMod, &QPushButton::clicked, this, &MainWindow::on_SaveMod_clicked);


    ui->lineEdit1->setPlaceholderText("Rechercher...");
    connect(ui->closeBtn, &QPushButton::clicked, this, &MainWindow::close);
    connect(ui->closeBtn, &QPushButton::clicked, this, &MainWindow::close);
    ui->labelNotification1->setTextInteractionFlags(Qt::TextBrowserInteraction);

    /*ui->scrollArea->setVisible(false);
     ui->scrollArea->raise();
    // Toujours afficher la barre de scroll verticale
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
     ui->scrollAreaWidgetContents->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);


    // Connexion du bouton pour afficher les notifications
     connect(ui->notifBtn, &QPushButton::clicked, this, &MainWindow::showNotifications);*/
    // Initialiser le modèle
   }

MainWindow::~MainWindow()
{
    delete ui;
    delete model;
}
// Charger les données existantes dans le tableView1

//Start showNotif
/*void MainWindow::showNotifications()
{
    // Affiche ou masque la fenêtre de notifications
    if (ui->scrollArea->isVisible()) {
        ui->scrollArea->hide();  // Masquer la fenêtre de notifications
    } else {
        ui->scrollArea->show();  // Afficher la fenêtre de notifications
        ui->scrollArea->raise();  // S'assurer que la fenêtre est bien visible

    }
}
// ✅ Fermer la fenêtre en cliquant en dehors
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (ui->scrollArea->isVisible() &&!ui->scrollArea->geometry().contains(event->pos())) {
        ui->scrollArea->hide();
    }
    QMainWindow::mousePressEvent(event);
}
void MainWindow::on_linkActivated(const QString &link)
{
    // Change the popup content based on the link clicked
    LabelNotificationContent->setText("Détails de " + link);
    popupNotification->show();
}*/
//end showNotif

void MainWindow::on_examButton_clicked()
{
   ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_supButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}



void MainWindow::on_eqButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}



void MainWindow::on_FourButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_candButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}


void MainWindow::on_etaButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}






void MainWindow::on_homeBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_AffButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_AjButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_ModButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_SuppButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_AffButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_AjButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_ModButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_SuppButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}



void MainWindow::on_AffButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_AjButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_ModButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_SuppButton_3_clicked()
{
   ui->stackedWidget->setCurrentIndex(5);
}


void MainWindow::on_AffButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_AjButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_ModButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_SuppButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}


void MainWindow::on_notifBtn_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);
}





void MainWindow::on_EvalAssist_clicked()
{
     ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::updateTableView()
{
    ui->tableView1->setModel(S.afficher());
    actualiserTableView();
}
void MainWindow::actualiserTableView()
{
    // Mettre à jour le modèle de tableView1 avec les nouvelles données
    ui->tableView1->setModel(S.afficher());

    // Ajuster la largeur des colonnes pour occuper tout l'espace disponible
    ui->tableView1->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Ajuster la hauteur des lignes automatiquement
    ui->tableView1->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}
//AJOUTER
void MainWindow::on_Ajbtn_clicked()
{
    QString id = ui->IDLineEdit->text().trimmed();
    QString cinStr = ui->CINLineEdit->text().trimmed();
    QString statut = ui->StatutlineEdit->text().trimmed();
    QString poste = ui->PostLineEdit->text().trimmed();
    QString prenom = ui->PrenLineEdit->text().trimmed();
    QString nom = ui->NomLineEdit->text().trimmed();
    QString numTelStr = ui->TlfLineEdit->text().trimmed();
    QString email = ui->EmailLineEdit->text().trimmed();

    // Vérification des champs obligatoires
    if (id.isEmpty() || cinStr.isEmpty() || statut.isEmpty() || poste.isEmpty() ||
        prenom.isEmpty() || nom.isEmpty() || numTelStr.isEmpty() || email.isEmpty()) {
        QMessageBox::warning(this, "Champs vides", "Tous les champs sont obligatoires !");
        return;
    }

    // Vérification que CIN et Numéro de téléphone sont des nombres de 8 chiffres
    QRegularExpression regex("\\d{8}");
    if (!regex.match(cinStr).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le CIN doit contenir exactement 8 chiffres !");
        return;
    }
    if (!regex.match(numTelStr).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le numéro de téléphone doit contenir exactement 8 chiffres !");
        return;
    }

    // Vérification de l'email avec une regex
    QRegularExpression emailRegex("^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\\.[a-zA-Z0-9-.]+$");
    if (!emailRegex.match(email).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "Adresse email invalide !");
        return;
    }

    // Conversion après validation
    int cin = cinStr.toInt();
    int numTel = numTelStr.toInt();

    // Création et ajout du superviseur
    Superviseur S(id, cin, statut, poste, prenom, nom, numTel, email);
    if (S.ajouter()) {
        QMessageBox::information(this, "Succès", "Superviseur ajouté avec succès !");
        ui->tableView1->setModel(S.afficher()); // Rafraîchir l'affichage
        actualiserTableView(); // Si nécessaire
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout du superviseur.");
    }
}

//Fonction Supprimer

void MainWindow::on_BinSuperbtn_clicked() {
    QModelIndex index = ui->tableView1->selectionModel()->currentIndex();
    qDebug() << "Index avant suppression valide ? " << index.isValid();

    if (!index.isValid()) {
        QMessageBox::warning(this, "Suppression", "Veuillez sélectionner un superviseur à supprimer.");
        return;
    }

    QString id = ui->tableView1->model()->data(index).toString();
    qDebug() << "ID récupéré : " << id;

    if (id.isEmpty()) {
        QMessageBox::critical(this, "Erreur", "ID invalide.");
        return;
    }

    if (S.supprimer(id)) {
        QMessageBox::information(this, "Succès", "Superviseur supprimé avec succès !");

        // ✅ Désactiver temporairement la sélection pour éviter un état incohérent
        ui->tableView1->selectionModel()->clearSelection();

        // ✅ Attendre une courte durée avant de recharger le modèle (évite les erreurs de mise à jour)
        QTimer::singleShot(100, this, [=]() {
            QAbstractItemModel *newModel = S.afficher();
            if (newModel) {
                ui->tableView1->setModel(newModel);
                qDebug() << "Table mise à jour après suppression.";
            } else {
                QMessageBox::critical(this, "Erreur", "Impossible d'afficher les données.");
            }
        });

    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression.");
    }
}







// Fonction du bouton Modifier
void MainWindow::on_Modbtn_clicked() {
    // Vérifier si une ligne est sélectionnée
    QModelIndex index = ui->tableView1->selectionModel()->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, tr("Modification"), tr("Veuillez sélectionner un superviseur à modifier."));
        return;
    }

    // Récupérer les valeurs actuelles du superviseur sélectionné
    currentId = ui->tableView1->model()->data(ui->tableView1->model()->index(index.row(), 0)).toString();
    originalCin = ui->tableView1->model()->data(ui->tableView1->model()->index(index.row(), 1)).toInt();
    originalStatut = ui->tableView1->model()->data(ui->tableView1->model()->index(index.row(), 2)).toString();
    originalPoste = ui->tableView1->model()->data(ui->tableView1->model()->index(index.row(), 3)).toString();
    originalPrenom = ui->tableView1->model()->data(ui->tableView1->model()->index(index.row(), 4)).toString();
    originalNom = ui->tableView1->model()->data(ui->tableView1->model()->index(index.row(), 5)).toString();
    originalTel = ui->tableView1->model()->data(ui->tableView1->model()->index(index.row(), 6)).toInt();
    originalEmail = ui->tableView1->model()->data(ui->tableView1->model()->index(index.row(), 7)).toString();

    // Afficher les valeurs dans les champs du formulaire
    ui->CINLineEdit->setText(QString::number(originalCin));
    ui->StatutlineEdit->setText(originalStatut);
    ui->PostLineEdit->setText(originalPoste);
    ui->PrenLineEdit->setText(originalPrenom);
    ui->NomLineEdit->setText(originalNom);
    ui->TlfLineEdit->setText(QString::number(originalTel));
    ui->EmailLineEdit->setText(originalEmail);

    modificationInProgress = true; // Définir le flag quand la modification commence
}

void MainWindow::on_SaveMod_clicked() {
    if (!modificationInProgress) {
        QMessageBox::warning(this, tr("Erreur"), tr("Veuillez d'abord sélectionner un superviseur à modifier en cliquant sur 'Modifier'."));
        return;
    }

    //QString newId = currentId; // Utiliser l'ID du superviseur sélectionné
    int newCin = ui->CINLineEdit->text().toInt();
    QString newStatut = ui->StatutlineEdit->text();
    QString newPoste = ui->PostLineEdit->text();
    QString newPrenom = ui->PrenLineEdit->text();
    QString newNom = ui->NomLineEdit->text();
    int newNumTel = ui->TlfLineEdit->text().toInt();
    QString newEmail = ui->EmailLineEdit->text();
    //verifier si aucaun changment efectue
    if (newCin == originalCin && newStatut == originalStatut &&
        newPoste == originalPoste && newPrenom == originalPrenom &&
        newNom == originalNom && newNumTel == originalTel &&
        newEmail == originalEmail){
        QMessageBox::information(this, tr("Modification"), tr("Aucune modification apportée."));
        return;
    }

    // Vérification des champs vides
    if (newStatut.isEmpty() || newPoste.isEmpty() || newPrenom.isEmpty() ||
        newNom.isEmpty() || newEmail.isEmpty()) {
        QMessageBox::warning(this, "Modification", "Tous les champs doivent être remplis.");
        return;
    }

    // Vérification de la validité du CIN et du numéro de téléphone
    if (QString::number(newCin).length() != 8) {
        QMessageBox::warning(this, "Erreur", "Le CIN doit contenir exactement 8 chiffres.");
        return;
    }
    if (QString::number(newNumTel).length() != 8) {
        QMessageBox::warning(this, "Erreur", "Le numéro de téléphone doit contenir exactement 8 chiffres.");
        return;
    }

    // Vérification du format de l'email
    if (!newEmail.contains("@") || !newEmail.contains(".")) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un email valide.");
        return;
    }

    // Création de l'objet Superviseur avec les nouvelles valeurs
    Superviseur s(currentId, newCin, newStatut, newPoste, newPrenom, newNom, newNumTel, newEmail );

    // Modifier l'entrée dans la base de données
    if (s.modifier(currentId)) {
        QMessageBox::information(this, "Modification", "Superviseur modifié avec succès !");
        ui->tableView1->setModel(s.afficher());
        modificationInProgress = false;
    } else {
        QMessageBox::critical(this, "Erreur", "La modification a échoué.");
    }
}
