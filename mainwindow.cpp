#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "fournisseurs.h"
#include <QMessageBox>
#include <QSqlError>  // Assurez-vous que cette inclusion est présente
#include <QSqlQueryModel>
#include <QRegularExpression>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = new QSqlQueryModel();  // Initialisation du modèle

    updateTableView();
    connect(ui->Ajbtn, &QPushButton::clicked, this, &MainWindow::handleAddFournisseur);
    connect(ui->suppButton, &QPushButton::clicked, this, &MainWindow::handleDeleteFournisseur);





}

MainWindow::~MainWindow()
{
    delete ui;
}

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
    ui->stackedWidget->setCurrentIndex(8);
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
    ui->stackedWidget->setCurrentIndex(2);
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



/*void MainWindow::handleAddFournisseur() {
    Fournisseur fournisseur(ui->Nom->text(), ui->ADRESSE->text(), ui->Email->text(),
                            ui->NumTel->text(), ui->TypeService->text());

    if (fournisseur.ajouter()) {
        QMessageBox::information(this, "Succès", "Fournisseur ajouté avec succès !");



    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de l'ajout du fournisseur: " + fournisseur.getLastError().text());
    }
}*/


// ✅ Mettre à jour la table des fournisseurs
void MainWindow::updateTableView() {
    qDebug() << "📊 Mise à jour du tableau...";

    // 🔹 Utiliser la fonction `afficher()` de `Fournisseur`
    model = Fournisseur().afficher();

    if (!model) {
        qDebug() << "❌ Erreur : Modèle SQL non valide";
        return;
    }

    if (model->rowCount() == 0) {
        qDebug() << "⚠️ Aucun fournisseur trouvé dans la base de données.";
    } else {
        qDebug() << "✅ Nombre de fournisseurs récupérés : " << model->rowCount();
    }

    ui->tableFourn->setModel(model);
    actualiserTableView();
}

// ✅ Ajuster automatiquement la taille du tableau
void MainWindow::actualiserTableView() {
    ui->tableFourn->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableFourn->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

// ✅ Ajouter un fournisseur
void MainWindow::handleAddFournisseur() {
    // 🔹 Récupérer les valeurs saisies
    QString nom = ui->Nom->text().trimmed();
    QString adresse = ui->ADRESSE->text().trimmed();
    QString email = ui->Email->text().trimmed();
    QString numTelStr = ui->NumTel->text().trimmed();
    QString typeService = ui->TypeService->text().trimmed();

    // 🔹 Vérifier que tous les champs sont remplis
    if (nom.isEmpty() || adresse.isEmpty() || email.isEmpty() || numTelStr.isEmpty() || typeService.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis.");
        return;
    }

    // 🔹 Vérification du numéro de téléphone (8 chiffres)
    QRegularExpression numTelRegex("^[0-9]{8}$");
    if (!numTelRegex.match(numTelStr).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le numéro de téléphone doit contenir exactement 8 chiffres.");
        return;
    }

    // 🔹 Vérification du format de l'email
    QRegularExpression emailRegex(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
    if (!emailRegex.match(email).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer une adresse e-mail valide.");
        return;
    }

    // 🔹 Conversion sécurisée du numéro de téléphone en entier
    int numTel = numTelStr.toInt();

    // 🔹 Création de l'objet Fournisseur avec les valeurs validées
    Fournisseur fournisseur(nom, adresse, email, numTel, typeService);

    // 🔹 Tenter d'ajouter le fournisseur
    if (fournisseur.ajouter()) {
        QMessageBox::information(this, "Succès", "Fournisseur ajouté avec succès !");
        updateTableView();  // 🔹 Rafraîchir la table après ajout
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de l'ajout du fournisseur: " + fournisseur.getLastError().text());
    }
}

void MainWindow::handleDeleteFournisseur() {
    // Vérifier si une ligne est sélectionnée
    QModelIndex index = ui->tableFourn->selectionModel()->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Suppression", "Veuillez sélectionner un fournisseur à supprimer !");
        return;
    }

    // Récupérer l'ID du fournisseur sélectionné (colonne 0 du tableau)
    QString idFournisseur = ui->tableFourn->model()->data(ui->tableFourn->model()->index(index.row(), 0)).toString();

    // Demander confirmation
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation", "Voulez-vous vraiment supprimer ce fournisseur ?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::No) return;

    // Supprimer le fournisseur
    Fournisseur fournisseur;
    if (fournisseur.supprimer(idFournisseur.toInt())) {
        QMessageBox::information(this, "Succès", "Fournisseur supprimé avec succès !");

        // 🔹 Met à jour l'affichage après suppression
        updateTableView();

    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression du fournisseur.");
    }
}


//modification
// Fonction du bouton Modifier
void MainWindow::on_ModButton_clicked() {
    // Vérifier si une ligne est sélectionnée
    QModelIndex index = ui->tableFourn->selectionModel()->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, tr("Modification"), tr("Veuillez sélectionner un fournisseur à modifier."));
        return;
    }

    // 🔹 Récupérer les valeurs actuelles du fournisseur sélectionné
    currentId = ui->tableFourn->model()->data(ui->tableFourn->model()->index(index.row(), 0)).toString();
    originalNom = ui->tableFourn->model()->data(ui->tableFourn->model()->index(index.row(), 1)).toString();
    originalNumTel = ui->tableFourn->model()->data(ui->tableFourn->model()->index(index.row(), 2)).toInt(); // ✅ numTel en int
    originalEmail = ui->tableFourn->model()->data(ui->tableFourn->model()->index(index.row(), 3)).toString();
    originalAdresse = ui->tableFourn->model()->data(ui->tableFourn->model()->index(index.row(), 4)).toString();
    originalTypeService = ui->tableFourn->model()->data(ui->tableFourn->model()->index(index.row(), 5)).toString();

    // 🔹 Afficher les valeurs dans les champs du formulaire
    ui->Nom->setText(originalNom);
    ui->NumTel->setText(QString::number(originalNumTel)); // ✅ Convertir int en QString
    ui->Email->setText(originalEmail);
    ui->ADRESSE->setText(originalAdresse);
    ui->TypeService->setText(originalTypeService);

    modificationInProgress = true; // Définir le flag quand la modification commence
}

void MainWindow::on_SaveMod_clicked() {
    if (!modificationInProgress) {
        QMessageBox::warning(this, "Erreur", "Veuillez d'abord sélectionner un fournisseur à modifier.");
        return;
    }

    Fournisseur f(currentId, ui->Nom->text(), ui->ADRESSE->text(), ui->Email->text(),
                  ui->NumTel->text().toInt(), ui->TypeService->text());

    if (f.modifier(currentId)) {
        QMessageBox::information(this, "Modification", "Fournisseur modifié avec succès !");
        updateTableView();
        modificationInProgress = false;
    } else {
        QMessageBox::critical(this, "Erreur", "La modification a échoué.");
    }
}
