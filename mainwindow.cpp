#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "equipement.h"
#include <QDebug>
//#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
}

MainWindow::~MainWindow()
{
    delete ui;
}
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
void MainWindow::on_examBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_supBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_eqBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}


void MainWindow::on_fourBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_candBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_etaBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}




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


// 📌 Ajouter un équipement
void MainWindow::ajouterEquipement()
{
    Equipement e(0, "Ordinateur", "Électronique", "Disponible", 10);
    if (e.ajouter()) {
        qDebug() << "Équipement ajouté avec succès.";
        afficherEquipements(); // Mettre à jour l'affichage
    } else {
        qDebug() << "Erreur lors de l'ajout.";
    }
}

// 📌 Afficher les équipements
void MainWindow::afficherEquipements() {
    Equipement e;
    QSqlQueryModel *model = e.afficher();

    // Vérifier si le modèle a des données
    if (!model) {
        qDebug() << "Erreur: Le modèle est vide.";
        return;
    }

    // Définir le nombre de lignes et de colonnes
    ui->tableView->setRowCount(model->rowCount());
    ui->tableView->setColumnCount(model->columnCount());

    // Ajouter les en-têtes de colonnes (si nécessaire)
    ui->tableView->setHorizontalHeaderLabels({ "Nom", "Type", "Statut", "Quantité"});

    // Remplir le QTableWidget avec les données du modèle
    for (int i = 0; i < model->rowCount(); i++) {
        for (int j = 0; j < model->columnCount(); j++) {
            QString data = model->data(model->index(i, j)).toString();
            ui->tableView->setItem(i, j, new QTableWidgetItem(data));
        }
    }
}


// 📌 Modifier un équipement
void MainWindow::modifierEquipement()
{
    Equipement e(1, "Imprimante", "Bureau", "En panne", 5);
    if (e.modifier(1)) {
        qDebug() << "Équipement modifié avec succès.";
        afficherEquipements(); // Rafraîchir l'affichage
    } else {
        qDebug() << "Erreur lors de la modification.";
    }
}

// 📌 Supprimer un équipement
void MainWindow::supprimerEquipement()
{
    Equipement e;
    if (e.supprimer(1)) {
        qDebug() << "Équipement supprimé.";
        afficherEquipements(); // Rafraîchir l'affichage
    } else {
        qDebug() << "Erreur lors de la suppression.";
    }
}
