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

//#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //ui->tableView1->setModel(Etmp.afficher()); // Remplace tableWidget1 par tableView
    // Affichage direct du tableau au démarrage

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
// Charger les données existantes dans le tableau

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
// Mettre à jour le tableau après l'ajout
        // Met à jour l'affichage après l'ajout
        ui->tableView1->setModel(S.afficher());
    }
    else
    {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout du superviseur.");
    }
}
// Sauvegarde les modifications en base de données
void MainWindow::on_Modbtn_clicked() {
    if (model) {
        if (model->submitAll()) {
            qDebug() << "Modifications enregistrées avec succès.";
        } else {
            qDebug() << "Erreur lors de l'enregistrement:" << model->lastError().text();
        }
    } else {
        qDebug() << "Erreur : Le modèle est nul.";
    }
}


// Initialiser le modèle dans le constructeur de la fenêtre
// mainwindow.cpp

void MainWindow::initialiserTableView()
{
    // Initialisation du modèle QSqlTableModel
    model = new QSqlTableModel(this);
    model->setTable("Superviseurs");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    // Configuration du QTableView
    // Configuration du QTableView
    ui->tableView1->setModel(model);
    ui->tableView1->setSelectionBehavior(QAbstractItemView::SelectItems);
    ui->tableView1->setEditTriggers(QAbstractItemView::AllEditTriggers);
    // Connexion du signal clicked du QTableView
   // connect(ui->tableView1, &QTableView::clicked, this, &MainWindow::onTableViewClicked);

    // Connexion du bouton "Modbtn" au slot de sauvegarde
    connect(ui->Modbtn, &QPushButton::clicked, this, &MainWindow::on_Modbtn_clicked);
}
/*void MainWindow::onTableViewClicked(const QModelIndex &index)
{
    ui->tableView1->edit(index);
}*/
