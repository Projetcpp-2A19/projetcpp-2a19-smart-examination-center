#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "examen.h"
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QDebug>
#include <QDesktopServices>
#include <QLineEdit>
#include <QStandardItemModel>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), currentLineEdit(nullptr)
{
    ui->setupUi(this);

    // Set placeholder text for the subject input field
    ui->SearchBarExamen->setPlaceholderText("math, physique...");

    // Debugging message to confirm constructor execution
    qDebug() << "MainWindow constructor reached!";

    // Connect buttons to their respective slots
    connect(ui->InsertExamPdf_3, &QPushButton::clicked, this, &MainWindow::handleInsertExamPdf);
    connect(ui->SuppExamButton, &QPushButton::clicked, this, &MainWindow::handleSuppExam);
    connect(ui->ModifExamConfirm, &QPushButton::clicked, this, &MainWindow::handleModifExamConfirm);
    connect(ui->viewPdfButton, &QPushButton::clicked, this, &MainWindow::onViewPdfButtonClicked);

    connect(ui->ListeExamensTab, &QTableView::clicked, this, &MainWindow::onExamSelected);
    qDebug() << "Connected QTableView clicked signal.";


    //speech to text
    speechToText = new SpeechToText(this);
    connect(speechToText, &SpeechToText::textRecognized, this, &MainWindow::onSpeechTextRecognized);

    // Connect buttons to their respective slots
    connect(ui->MatiereSpeech, &QPushButton::clicked, this, &MainWindow::onMatiereSpeechClicked);
    connect(ui->NiveauSpeech, &QPushButton::clicked, this, &MainWindow::onNiveauSpeechClicked);
    connect(ui->DureeSpeech, &QPushButton::clicked, this, &MainWindow::onDureeSpeechClicked);

    //Recherche
    // Initialize the model
    Examen examen;  // Assuming Examen has a method to fetch data
    yourExamModel = examen.afficher();  // Get the model from afficher()
    proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(yourExamModel); // Assuming you already have a model for the exams table
    proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive); // Case-insensitive search
    proxyModel->setFilterKeyColumn(1); // Column index of "matière" in your model

    ui->ListeExamensTab->setModel(proxyModel);

    // Connect the search bar signal to the filter update function
    connect(ui->SearchBarExamen, &QLineEdit::textChanged, this, &MainWindow::filterExams);

    //filter by date
    connect(ui->filterExam, &QDateEdit::dateChanged, this, &MainWindow::filtrerParDate);

    // Configure table selection behavior
    ui->ListeExamensTab->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->ListeExamensTab->setSelectionBehavior(QAbstractItemView::SelectRows);
}


MainWindow::~MainWindow()
{
    delete speechToText;
    delete ui;
}

void MainWindow::onMatiereSpeechClicked()
{
    currentLineEdit = ui->lineEdit_16; // Point to the "matiere" field
    speechToText->startListening();

}

void MainWindow::onNiveauSpeechClicked()
{
    currentLineEdit = ui->lineEdit_18; // Point to the "niveau" field
    speechToText->startListening();
}

void MainWindow::onDureeSpeechClicked()
{
    currentLineEdit = ui->lineEdit_20; // Point to the "duree" field
    speechToText->startListening();
}
void MainWindow::onSpeechTextRecognized(const QString &text)
{
    if (currentLineEdit) {
        qDebug() << "Updating QLineEdit with text:" << text; // Debug: Print text being set
        currentLineEdit->setText(text); // Populate the corresponding field
    } else {
        qDebug() << "currentLineEdit is null!"; // Debug: Check if currentLineEdit is set
    }
}

void MainWindow::handleInsertExamPdf()
{
    qDebug() << "handleInsertExamPdf() called";

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

void MainWindow::handleSuppExam()
{
    qDebug() << "handleSuppExam() called";

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

void MainWindow::handleModifExamConfirm()
{
    qDebug() << "handleModifExamConfirm() called";

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

    // Check if a PDF file was selected (only if the user wants to update it)
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

    // Retrieve data from the selected row (in the new order)
    QString id = model->data(model->index(row, 0)).toString();          // ID
    QString matiere = model->data(model->index(row, 1)).toString();    // Matiere
    QString type = model->data(model->index(row, 2)).toString();       // Type
    QString statut = model->data(model->index(row, 3)).toString();     // Statut
    QString niveau = model->data(model->index(row, 4)).toString();     // Niveau
    QString duree = model->data(model->index(row, 5)).toString();      // Duree
    QDate date = model->data(model->index(row, 6)).toDate();          // Date

    // Debug: Print the retrieved data
    qDebug() << "Selected Exam Data:";
    qDebug() << "ID:" << id;
    qDebug() << "Matière:" << matiere;
    qDebug() << "Type:" << type;
    qDebug() << "Statut:" << statut;
    qDebug() << "Niveau:" << niveau;
    qDebug() << "Durée:" << duree;
    qDebug() << "Date:" << date.toString("yyyy-MM-dd");

    // Populate the modify inputs
    ui->lineEdit_16->setText(matiere);
    ui->lineEdit_18->setText(niveau);
    ui->lineEdit_20->setText(duree);
    ui->TypeExamenChoix->setCurrentText(type);
    ui->StatutExamenChoix->setCurrentText(statut);
    ui->dateExamenChoix->setDate(date);

    // Retrieve the PDF data for the selected exam from the database
    Examen examen;
    pdfData = examen.getPdfDataById(id); // Assuming you have a method to get PDF data by ID
    ui->stackedWidget_2->setCurrentIndex(1);

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
    clearForm();
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


void MainWindow::refreshExamenTable()
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qDebug() << "Database is not open!";
        return;
    }

    Examen examen;
    QSqlQueryModel *model = examen.afficher();

    if (!model) {
        qDebug() << "Model is null!";
        return;
    }

    proxyModel->setSourceModel(model);
    ui->ListeExamensTab->setModel(proxyModel);

    model->setHeaderData(0, Qt::Horizontal, tr("ID Examen"));
    model->setHeaderData(1, Qt::Horizontal, tr("Matière Examen"));
    model->setHeaderData(2, Qt::Horizontal, tr("Type Examen"));
    model->setHeaderData(3, Qt::Horizontal, tr("Statut Examen"));
    model->setHeaderData(4, Qt::Horizontal, tr("Niveau Examen"));
    model->setHeaderData(5, Qt::Horizontal, tr("Durée Examen"));
    model->setHeaderData(6, Qt::Horizontal, tr("Date Examen"));

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

void MainWindow::onViewPdfButtonClicked()
{
    // Get the selected row
    QModelIndexList selectedRows = ui->ListeExamensTab->selectionModel()->selectedRows();
    if (selectedRows.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un examen pour voir le PDF.");
        return;
    }

    // Get the selected exam ID
    int row = selectedRows.first().row();
    QString id = ui->ListeExamensTab->model()->data(ui->ListeExamensTab->model()->index(row, 0)).toString();

    // Fetch the PDF data
    Examen examen;
    QByteArray pdfData = examen.getPdfDataById(id);

    if (pdfData.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Aucun PDF trouvé pour cet examen.");
        return;
    }

    // Save the PDF data to a temporary file
    QString tempFilePath = QDir::tempPath() + "/exam_" + id + ".pdf";
    QFile tempFile(tempFilePath);
    if (tempFile.open(QIODevice::WriteOnly)) {
        tempFile.write(pdfData);
        tempFile.close();
    } else {
        QMessageBox::critical(this, "Erreur", "Impossible de créer un fichier temporaire pour le PDF.");
        return;
    }

    // Open the PDF file with the default viewer
    QDesktopServices::openUrl(QUrl::fromLocalFile(tempFilePath));
}

void MainWindow::filterExams(const QString &searchText)
{
    proxyModel->setFilterFixedString(searchText);
}


void MainWindow::filtrerParDate(const QDate &date)
{
    qDebug() << "Filtering exams for date:" << date.toString("yyyy-MM-dd");

    // Assuming that "Examen" class has a method to filter exams by date (modifying the query)
    Examen examen;
    QSqlQueryModel* filteredModel = examen.filtrerParDate(date);

    if (filteredModel) {
        qDebug() << "Number of exams found:" << filteredModel->rowCount();

        // Now update the proxy model with the filtered data
        proxyModel->setSourceModel(filteredModel);
        ui->ListeExamensTab->setModel(proxyModel);

        // Set column headers for the filtered model
        filteredModel->setHeaderData(0, Qt::Horizontal, tr("ID Examen"));
        filteredModel->setHeaderData(1, Qt::Horizontal, tr("Matière Examen"));
        filteredModel->setHeaderData(2, Qt::Horizontal, tr("Type Examen"));
        filteredModel->setHeaderData(3, Qt::Horizontal, tr("Statut Examen"));
        filteredModel->setHeaderData(4, Qt::Horizontal, tr("Niveau Examen"));
        filteredModel->setHeaderData(5, Qt::Horizontal, tr("Durée Examen"));
        filteredModel->setHeaderData(6, Qt::Horizontal, tr("Date Examen"));

        // Resize columns to fit content
        ui->ListeExamensTab->resizeColumnsToContents();
    } else {
        qDebug() << "No exams found for the specified date.";
        QMessageBox::warning(this, "Erreur", "Aucun examen trouvé pour la date spécifiée.");
    }
}
