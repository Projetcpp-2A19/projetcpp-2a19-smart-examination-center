#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setColumnCount(7); // 7 colonnes pour les informations du candidat
    QStringList headers = {"Code", "Nom", "Prénom", "CIN", "Adresse", "NumTel", "Niveau"};
    ui->tableView->setHorizontalHeaderLabels(headers);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Ajouter un candidat et l'afficher dans le tableau
void MainWindow::on_AjButton_5_clicked()
{
    QString nom = ui->lineNom->text();
    QString prenom = ui->linePrenom->text();
    int code = ui->lineCode->text().toInt();
    int cin = ui->lineCIN->text().toInt();
    QString adresse = ui->lineAdresse->text();
    int numTel = ui->lineNumTel->text().toInt();
    QListWidgetItem *item = ui->comboNiveau->currentItem();
    QString niveau = (item) ? item->text() : "";  // Récupérer la valeur sélectionnée

    Candidat c(nom, prenom, code, cin, adresse, numTel, niveau);
    if (c.ajouter()) {
        QMessageBox::information(this, "Succès", "Candidat ajouté avec succès !");

        // Ajouter le candidat au QTableWidget
        int rowCount = ui->tableView->rowCount();
        ui->tableView->insertRow(rowCount); // Ajouter une nouvelle ligne

        ui->tableView->setItem(rowCount, 0, new QTableWidgetItem(QString::number(c.getCode())));
        ui->tableView->setItem(rowCount, 1, new QTableWidgetItem(c.getNom()));
        ui->tableView->setItem(rowCount, 2, new QTableWidgetItem(c.getPrenom()));
        ui->tableView->setItem(rowCount, 3, new QTableWidgetItem(QString::number(c.getCIN())));
        ui->tableView->setItem(rowCount, 4, new QTableWidgetItem(c.getAdresse()));
        ui->tableView->setItem(rowCount, 5, new QTableWidgetItem(QString::number(c.getNumTel())));
        ui->tableView->setItem(rowCount, 6, new QTableWidgetItem(c.getNiveau()));

    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout du candidat.");
    }
}
