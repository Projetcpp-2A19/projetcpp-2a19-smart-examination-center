#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "examen.h"
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initialize the UI elements
    ui->lineEdit_2->setPlaceholderText("math,physique...");

    // Debugging to check if constructor is called
    qDebug() << "MainWindow constructor reached!";

    // Connect the InsertExamPdf_3 button to its slot
    connect(ui->InsertExamPdf_3, &QPushButton::clicked, this, &MainWindow::on_InsertExamPdf_3_clicked);
 connect(ui->SuppExamButton, &QPushButton::clicked, this, &MainWindow::on_SuppExamButton_clicked);
    // Connect the QTableView's clicked signal to the slot
    bool connectionSuccessful = connect(ui->ListeExamensTab, &QTableView::clicked, this, &MainWindow::onExamSelected);

    if (connectionSuccessful) {
        qDebug() << "Connection to clicked signal successful.";
    } else {
        qDebug() << "Failed to connect to clicked signal.";
    }

    // Connect the Modify Confirm button to its slot
    connect(ui->ModifExamConfirm, &QPushButton::clicked, this, &MainWindow::on_ModifExamConfirm_clicked);

    // Refresh the exam table at startup
    refreshExamenTable();

    // Set the selection mode and behavior for the table
    ui->ListeExamensTab->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->ListeExamensTab->setSelectionBehavior(QAbstractItemView::SelectRows);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onExamSelected(const QModelIndex &index)
{
    qDebug() << "Selection changed signal received.";

    // Get the selected row
    int row = index.row();
    qDebug() << "Selected row:" << row;

    // Get the model
    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(ui->ListeExamensTab->model());
    if (!model) {
        qDebug() << "Model is not valid!";
        return;
    }

    // Retrieve data from the selected row
    QString id = model->data(model->index(row, 0)).toString(); // ID_EXAMEN
    QString type = model->data(model->index(row, 1)).toString(); // TYPE_EXAMEN
    QString statut = model->data(model->index(row, 2)).toString(); // STATUT_EXAMEN
    QString niveau = model->data(model->index(row, 3)).toString(); // NIVEAU_EXAMEN
    QString matiere = model->data(model->index(row, 4)).toString(); // MATIERE_EXAMEN
    QString duree = model->data(model->index(row, 5)).toString(); // DUREE_EXAMEN
    QDate date = model->data(model->index(row, 6)).toDate(); // DATE_EXAMEN

    // Debug: Print the retrieved data
    qDebug() << "Selected Exam Data:";
    qDebug() << "ID:" << id;
    qDebug() << "Type:" << type;
    qDebug() << "Statut:" << statut;
    qDebug() << "Niveau:" << niveau;
    qDebug() << "Matière:" << matiere;
    qDebug() << "Durée:" << duree;
    qDebug() << "Date:" << date.toString("yyyy-MM-dd");

    // Populate the modify inputs
    ui->lineEdit_16->setText(matiere);
    ui->lineEdit_18->setText(niveau);
    ui->lineEdit_20->setText(duree);
    ui->TypeExamenChoix->setCurrentText(type);
    ui->StatutExamenChoix->setCurrentText(statut);
    ui->dateExamenChoix->setDate(date);

    // Store the selected exam ID for later use (e.g., in the modify function)
    selectedExamId = id;
}

// Navigation buttons
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
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_FourButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_candButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_etaButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_homeBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

// Exam-related buttons
void MainWindow::on_AjExamButton_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_ModExamButton_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);

}

void MainWindow::on_statButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_AddExamConfirm_3_clicked()
{
    // Read values from the input fields
    QString matiere = ui->lineEdit_16->text();
    QString niveau = ui->lineEdit_18->text();
    QString duree = ui->lineEdit_20->text();
    QString type = ui->TypeExamenChoix->currentText();
    QString statut = ui->StatutExamenChoix->currentText();
    QDate date = ui->dateExamenChoix->date();

    // Validate the inputs
    if (matiere.isEmpty() || niveau.isEmpty() || duree.isEmpty() || type.isEmpty() || statut.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs !");
        return;
    }

    // Check if a PDF file was selected
    if (pdfData.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un fichier PDF !");
        return;
    }

    // Create an Examen object and set its properties
    Examen e(type, statut, niveau, matiere, pdfData, duree, date);

    // Add the exam to the database
    if (e.ajouter()) {
        QMessageBox::information(this, "Succès", "Examen ajouté avec succès !");
        refreshExamenTable(); // Refresh the exam table
        clearForm();          // Clear the form
        pdfData.clear();      // Clear the PDF data for the next exam
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout de l'examen.");
    }
}

void MainWindow::on_InsertExamPdf_3_clicked()
{
    // Open a file dialog to select a PDF file
    QString filePath = QFileDialog::getOpenFileName(this, "Sélectionner un fichier PDF", "", "PDF Files (*.pdf)");

    if (!filePath.isEmpty()) {
        QFile file(filePath);

        // Open the file in read-only mode
        if (file.open(QIODevice::ReadOnly)) {
            // Read the file data into the QByteArray member variable
            pdfData = file.readAll();
            file.close();

            // Notify the user that the file was loaded successfully
            QMessageBox::information(this, "Succès", "Fichier PDF chargé avec succès !");
        } else {
            // Notify the user if the file could not be opened
            QMessageBox::critical(this, "Erreur", "Impossible d'ouvrir le fichier PDF.");
        }
    }
}
void MainWindow::refreshExamenTable()
{
    // Check if the database is open
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qDebug() << "Database is not open!";
        return;
    }

    // Create an Examen object
    Examen examen;

    // Get the model from the afficher() method
    QSqlQueryModel *model = examen.afficher();

    // Debug: Check if the model is valid
    if (!model) {
        qDebug() << "Model is null!";
        return;
    }

    // Set the model for the QTableView
    ui->ListeExamensTab->setModel(model);

    // Debug: Check if the model is set correctly
    if (ui->ListeExamensTab->model() == model) {
        qDebug() << "Model set successfully.";
    } else {
        qDebug() << "Failed to set model.";
    }

    // Set column headers
    model->setHeaderData(0, Qt::Horizontal, tr("ID Examen"));
    model->setHeaderData(1, Qt::Horizontal, tr("Type Examen"));
    model->setHeaderData(2, Qt::Horizontal, tr("Statut Examen"));
    model->setHeaderData(3, Qt::Horizontal, tr("Niveau Examen"));
    model->setHeaderData(4, Qt::Horizontal, tr("Matière Examen"));
    model->setHeaderData(5, Qt::Horizontal, tr("Durée Examen"));
    model->setHeaderData(6, Qt::Horizontal, tr("Date Examen"));

    // Resize columns to fit content
    ui->ListeExamensTab->resizeColumnsToContents();
}

void MainWindow::clearForm()
{
    // Clear all input fields
    ui->lineEdit_16->clear();
    ui->lineEdit_18->clear();
    ui->lineEdit_20->clear();
    ui->TypeExamenChoix->setCurrentIndex(0);
    ui->StatutExamenChoix->setCurrentIndex(0);
    ui->dateExamenChoix->setDate(QDate::currentDate());
}

void MainWindow::on_pushButton_2_clicked()
{
    refreshExamenTable();
}


void MainWindow::on_ModifExamConfirm_clicked()
{
    QString matiere = ui->lineEdit_16->text();
    QString niveau = ui->lineEdit_18->text();
    QString duree = ui->lineEdit_20->text();
    QString type = ui->TypeExamenChoix->currentText();
    QString statut = ui->StatutExamenChoix->currentText();
    QDate date = ui->dateExamenChoix->date();

    // Validate the inputs
    if (matiere.isEmpty() || niveau.isEmpty() || duree.isEmpty() || type.isEmpty() || statut.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs !");
        return;
    }

    // Check if a PDF file was selected
    if (pdfData.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un fichier PDF !");
        return;
    }

    // Create an Examen object and set its properties
    Examen e(type, statut, niveau, matiere, pdfData, duree, date);

    // Modify the exam in the database
    if (e.modifier(selectedExamId)) {
        QMessageBox::information(this, "Succès", "Examen modifié avec succès !");
        refreshExamenTable(); // Refresh the exam table
        clearForm();          // Clear the form
        pdfData.clear();      // Clear the PDF data for the next exam
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification de l'examen.");
    }
}


void MainWindow::on_SuppExamButton_clicked()
{
    // Check if an exam is selected
    if (selectedExamId.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un examen à supprimer !");
        return;
    }

    // Ask for confirmation before deleting
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation", "Êtes-vous sûr de vouloir supprimer cet examen ?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        // Create an Examen object and call the supprimer method
        Examen examen;
        if (examen.supprimer(selectedExamId)) {
            QMessageBox::information(this, "Succès", "Examen supprimé avec succès !");
            refreshExamenTable(); // Refresh the table to reflect the deletion
            selectedExamId.clear(); // Clear the selected exam ID
        } else {
            QMessageBox::critical(this, "Erreur", "Échec de la suppression de l'examen.");
        }
    }
}

