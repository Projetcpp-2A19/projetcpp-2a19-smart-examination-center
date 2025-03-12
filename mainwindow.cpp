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
}

void MainWindow::on_Ajbtn_clicked()
{
    QString id = ui->IDLineEdit->text();
    int cin = ui->CINLineEdit->text().toInt();
    QString statut = ui->StatutlineEdit->text();
    QString poste = ui->PostLineEdit->text();
    QString prenom = ui->PrenLineEdit->text();
    QString nom = ui->NomLineEdit->text();
    int numTel = ui->TlfLineEdit->text().toInt();
    QString email = ui->EmailLineEdit->text();

    Superviseur S(id, cin, statut, poste, prenom, nom, numTel, email);

    if (S.ajouter())
    {
        QMessageBox::information(this, "Succès", "Superviseur ajouté avec succès !");
// Mettre à jour le tableView1 après l'ajout
        // Met à jour l'affichage après l'ajout
        ui->tableView1->setModel(S.afficher());
    }
    else
    {
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
    currentCin = ui->tableView1->model()->data(ui->tableView1->model()->index(index.row(), 1)).toInt();
    currentStatut = ui->tableView1->model()->data(ui->tableView1->model()->index(index.row(), 2)).toString();
    currentPoste = ui->tableView1->model()->data(ui->tableView1->model()->index(index.row(), 3)).toString();
    currentPrenom = ui->tableView1->model()->data(ui->tableView1->model()->index(index.row(), 4)).toString();
    currentNom = ui->tableView1->model()->data(ui->tableView1->model()->index(index.row(), 5)).toString();
    currentnumTel = ui->tableView1->model()->data(ui->tableView1->model()->index(index.row(), 6)).toInt();
    currentEmail = ui->tableView1->model()->data(ui->tableView1->model()->index(index.row(), 7)).toString();

    // Afficher les valeurs dans les champs du formulaire
    ui->CINLineEdit->setText(QString::number(currentCin));
    ui->StatutlineEdit->setText(currentStatut);
    ui->PostLineEdit->setText(currentPoste);
    ui->PrenLineEdit->setText(currentPrenom);
    ui->NomLineEdit->setText(currentNom);
    ui->TlfLineEdit->setText(QString::number(currentnumTel));
    ui->EmailLineEdit->setText(currentEmail);
}

// Fonction du bouton Enregistrer
void MainWindow::on_SaveMod_clicked() {
    // Récupérer les nouvelles valeurs du formulaire
    int newCin = ui->CINLineEdit->text().toInt();
    QString newStatut = ui->StatutlineEdit->text();
    QString newPoste = ui->PostLineEdit->text();
    QString newPrenom = ui->PrenLineEdit->text();
    QString newNom = ui->NomLineEdit->text();
    int newNumTel = ui->TlfLineEdit->text().toInt();
    QString newEmail = ui->EmailLineEdit->text();

    // Vérification des champs vides
    if (newStatut.isEmpty() || newPoste.isEmpty() || newPrenom.isEmpty() || newNom.isEmpty() || newEmail.isEmpty()) {
        QMessageBox::warning(this, "Modification", "Tous les champs doivent être remplis.");
        return;
    }

    // Créer un objet superviseur avec les nouvelles valeurs
    Superviseur s(currentId, newCin, newStatut, newPoste, newPrenom, newNom, newNumTel, newEmail);

    // Modifier l'entrée dans la base de données
    if (s.modifier()) {
        QMessageBox::information(this, "Modification", "Superviseur modifié avec succès !");
        ui->tableView1->setModel(s.afficher()); // Rafraîchir la table
    } else {
        QMessageBox::critical(this, "Erreur", "La modification a échoué.");
    }
}
