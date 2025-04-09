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
#include <QSqlRecord>
#include <QDate>
#include <QPdfWriter>
#include <QPainter>
#include <QSqlQuery>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QVBoxLayout>


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

    connect(ui->examButton_2, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget_3->setCurrentWidget(ui->PageStatExam);
        loadExamStatistics();  // Load stats when button is clicked
    });
    if (!ui->ExamChartContainer->layout()) {
        ui->ExamChartContainer->setLayout(new QVBoxLayout());
    }
    //Recherche
    // Initialize the model
    Examen examen;
    yourExamModel = examen.afficher();

    proxyModel = new ExamenFilterProxyModel(this);
    proxyModel->setSourceModel(yourExamModel);
    ui->ListeExamensTab->setModel(proxyModel);

    // Connecte les filtres
    connect(ui->SearchBarExamen, &QLineEdit::textChanged, proxyModel, &ExamenFilterProxyModel::setMatiereFilter);
    connect(ui->filterExam, &QDateEdit::dateChanged, proxyModel, &ExamenFilterProxyModel::setDateFilter);
    connect(ui->pdfExambtn, &QPushButton::clicked, this, &MainWindow::on_pdfExambtn_clicked);


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
    qDebug() << "onExamSelected slot triggered.";

    if (!index.isValid()) {
        qDebug() << "Invalid index!";
        return;
    }

    // Get the proxy model
    QSortFilterProxyModel *proxyModel = qobject_cast<QSortFilterProxyModel*>(ui->ListeExamensTab->model());
    if (!proxyModel) {
        qDebug() << "Proxy model is not valid!";
        return;
    }

    // Get the source model (QSqlQueryModel)
    QSqlQueryModel *sourceModel = qobject_cast<QSqlQueryModel*>(proxyModel->sourceModel());
    if (!sourceModel) {
        qDebug() << "Source model is not valid!";
        return;
    }

    // Map the index to the source model
    QModelIndex sourceIndex = proxyModel->mapToSource(index);
    int row = sourceIndex.row();

    // Retrieve data from the selected row
    QString id = sourceModel->data(sourceModel->index(row, 0)).toString();          // ID
    QString matiere = sourceModel->data(sourceModel->index(row, 1)).toString();    // Matiere
    QString type = sourceModel->data(sourceModel->index(row, 2)).toString();        // Type
    QString statut = sourceModel->data(sourceModel->index(row, 3)).toString();     // Statut
    QString niveau = sourceModel->data(sourceModel->index(row, 4)).toString();     // Niveau
    QString duree = sourceModel->data(sourceModel->index(row, 5)).toString();      // Duree
    QDate date = sourceModel->data(sourceModel->index(row, 6)).toDate();           // Date

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
    pdfData = examen.getPdfDataById(id);
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

void MainWindow::on_examButton_2_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(0);
}


void MainWindow::on_supButton_2_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(1);
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

    // Validate that 'matiere' contains only letters (including accented ones and spaces)
    QRegularExpression regex("^[a-zA-ZÀ-ÿ\\s]+$");
    if (!regex.match(matiere).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le champ 'Matière' ne doit contenir que des lettres.");
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

void MainWindow::on_pdfExambtn_clicked()
{
    // Configuration initiale du PDF
    QString fileName = QFileDialog::getSaveFileName(this, "Enregistrer le PDF", "", "Fichiers PDF (*.pdf)");
    if (fileName.isEmpty()) return;

    QPdfWriter pdfWriter(fileName);
    pdfWriter.setPageSize(QPageSize::A4);
    pdfWriter.setResolution(300);

    QPainter painter(&pdfWriter);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setRenderHint(QPainter::TextAntialiasing, true);

    if (!painter.isActive()) {
        QMessageBox::critical(this, "Erreur", "Impossible de créer le PDF !");
        return;
    }

    // Paramètres de mise en page améliorés
    const int margin = 50; // Marge légèrement augmentée
    const int startX = margin;
    int startY = 100;
    const int rowHeight = 40; // Hauteur de ligne réduite
    const int pageWidth = pdfWriter.width() - 2 * margin;

    // Titre du document avec style amélioré
    painter.setFont(QFont("Arial", 18, QFont::Bold));
    painter.setPen(QColor(50, 50, 50)); // Couleur de texte plus douce
    painter.drawText(startX, startY - 70, "Liste de Tous les Examens");

    // Configuration des colonnes
    QStringList headers = {"Matière", "Type", "Niveau", "Statut", "Durée", "Date"};
    QVector<int> columnWidths = {
        static_cast<int>(pageWidth * 0.25),
        static_cast<int>(pageWidth * 0.15),
        static_cast<int>(pageWidth * 0.12),
        static_cast<int>(pageWidth * 0.13),
        static_cast<int>(pageWidth * 0.15),
        static_cast<int>(pageWidth * 0.15)
    };

    auto parseDate = [](const QVariant& dateValue) -> QString {
        if (dateValue.isNull() || !dateValue.isValid()) return "N/A";

        // 1. Si c'est déjà un QDateTime (contient date+heure)
        if (dateValue.typeId() == QMetaType::QDateTime) {
            return dateValue.toDateTime().date().toString("yyyy-MM-dd");
        }

        // 2. Si c'est un QDate (date seule)
        if (dateValue.typeId() == QMetaType::QDate) {
            return dateValue.toDate().toString("yyyy-MM-dd");
        }

        // 3. Si c'est un nombre (année seule)
        if (dateValue.canConvert<int>()) {
            int year = dateValue.toInt();
            if (year > 1000 && year < 3000) {
                return QString("%1-01-01").arg(year); // Format ISO avec jour/mois par défaut
            }
        }

        // 4. Traitement des chaînes de caractères
        QString dateStr = dateValue.toString().trimmed();

        // Supprimer la partie heure si elle existe (format "2000-01-01 00:00:00")
        dateStr = dateStr.split(" ").first();

        // Liste des formats de date à essayer
        QVector<QString> formats = {
            "yyyy-MM-dd",    // Format ISO (2000-01-01)
            "dd/MM/yyyy",    // Format français (01/01/2000)
            "dd/MM/yy",      // Format court (01/01/00)
            "MM/dd/yyyy",    // Format américain
            "yyyy"           // Année seule
        };

        for (const QString& format : formats) {
            QDate date = QDate::fromString(dateStr, format);
            if (date.isValid()) {
                // Correction pour les années sur 2 chiffres
                if (format == "dd/MM/yy" && date.year() < 100) {
                    date = date.addYears(2000 - (date.year() % 100));
                }
                return date.toString("yyyy-MM-dd");
            }
        }

        // Si aucun format ne correspond, retourner la valeur originale (pour débogage)
        return dateStr;
    };

    // Police plus lisible pour le tableau
    QFont tableFont("Arial", 9); // Taille réduite à 9
    QFont headerFont("Arial", 10, QFont::Bold); // En-têtes légèrement plus grands

    // Première passe: calcul des largeurs de colonnes
    QSqlQuery query;
    if (query.exec("SELECT matiere_examen, type_examen, niveau_examen, statut_examen, duree_examen, date_examen FROM examens")) {
        painter.setFont(tableFont);

        while (query.next()) {
            for (int col = 0; col < headers.size(); ++col) {
                QString data = query.value(col).toString();
                if (col == 5) data = parseDate(data);

                int textWidth = painter.fontMetrics().horizontalAdvance(data) + 20; // Marge réduite
                if (textWidth > columnWidths[col]) {
                    columnWidths[col] = qMin(textWidth, static_cast<int>(pageWidth * 0.3));
                }
            }
        }
    } else {
        qDebug() << "Erreur requête:" << query.lastError().text();
        return;
    }

    // Calcul des positions des colonnes
    QVector<int> columnPositions(headers.size());
    columnPositions[0] = startX;
    for (int i = 1; i < headers.size(); ++i) {
        columnPositions[i] = columnPositions[i - 1] + columnWidths[i - 1];
    }

    // Dessin des en-têtes avec style amélioré
    QColor headerColor(70, 130, 180); // Bleu plus doux
    QColor headerTextColor = Qt::white;

    painter.setFont(headerFont);
    painter.setBrush(headerColor);
    painter.setPen(QPen(headerColor.darker(120), 0.5));

    for (int col = 0; col < headers.size(); ++col) {
        QRect headerRect(columnPositions[col], startY, columnWidths[col], rowHeight);
        painter.drawRect(headerRect);
        painter.setPen(headerTextColor);
        painter.drawText(headerRect, Qt::AlignCenter, headers[col]);
        painter.setPen(QPen(headerColor.darker(120), 0.5));
    }

    startY += rowHeight;

    // Dessin des données avec style amélioré
    painter.setFont(tableFont);
    if (!query.exec("SELECT matiere_examen, type_examen, niveau_examen, statut_examen, duree_examen, date_examen FROM examens")) {
        qDebug() << "Erreur requête:" << query.lastError().text();
        return;
    }

    int rowNum = 0;
    while (query.next()) {
        // Couleurs alternées plus subtiles
        QColor rowColor = (rowNum % 2 == 0) ? QColor(248, 248, 248) : Qt::white;
        QColor borderColor(220, 220, 220);

        painter.setBrush(rowColor);
        painter.setPen(QPen(borderColor, 0.5));

        for (int col = 0; col < headers.size(); ++col) {
            QString data = query.value(col).toString();
            if (col == 5) data = parseDate(data);

            QRect cellRect(columnPositions[col], startY, columnWidths[col], rowHeight);
            painter.drawRect(cellRect);
            painter.setPen(QColor(60, 60, 60)); // Texte plus doux
            painter.drawText(cellRect.adjusted(8, 0, -8, 0),
                             Qt::AlignLeft | Qt::AlignVCenter,
                             painter.fontMetrics().elidedText(data, Qt::ElideRight, cellRect.width() - 16));
            painter.setPen(QPen(borderColor, 0.5));
        }

        startY += rowHeight;
        rowNum++;

        // Gestion du saut de page avec réaffichage des en-têtes
        if (startY > pdfWriter.height() - margin - rowHeight) {
            pdfWriter.newPage();
            startY = 100;

            // Réafficher les en-têtes
            painter.setFont(headerFont);
            painter.setBrush(headerColor);
            painter.setPen(QPen(headerColor.darker(120), 0.5));

            for (int col = 0; col < headers.size(); ++col) {
                QRect headerRect(columnPositions[col], startY - rowHeight, columnWidths[col], rowHeight);
                painter.drawRect(headerRect);
                painter.setPen(headerTextColor);
                painter.drawText(headerRect, Qt::AlignCenter, headers[col]);
                painter.setPen(QPen(headerColor.darker(120), 0.5));
            }
        }
    }

    painter.end();
    QMessageBox::information(this, "Succès", "Le PDF a été généré avec succès !");
}

/*
void MainWindow::on_pdfExambtn_clicked()
{
    // Configuration initiale du PDF
    QString fileName = QFileDialog::getSaveFileName(this, "Enregistrer le PDF", "", "Fichiers PDF (*.pdf)");
    if (fileName.isEmpty()) return;

    QPdfWriter pdfWriter(fileName);
    pdfWriter.setPageSize(QPageSize::A4);
    pdfWriter.setResolution(300);

    QPainter painter(&pdfWriter);
    painter.setRenderHint(QPainter::Antialiasing);

    if (!painter.isActive()) {
        QMessageBox::critical(this, "Erreur", "Impossible de créer le PDF !");
        return;
    }

    // Paramètres de mise en page
    const int margin = 40;
    const int startX = margin;
    int startY = 100;
    const int rowHeight = 50;
    const int pageWidth = pdfWriter.width() - 2 * margin;

    // Titre du document
    painter.setFont(QFont("Arial", 20, QFont::Bold));
    painter.drawText(startX, startY - 70, "Liste de Tous les Examens");

    // Configuration des colonnes
    QStringList headers = {"Matière", "Type", "Niveau", "Statut", "Durée", "Date"};
    QVector<int> columnWidths = {
        static_cast<int>(pageWidth * 0.25),  // Matière
        static_cast<int>(pageWidth * 0.15),  // Type
        static_cast<int>(pageWidth * 0.15),  // Niveau
        static_cast<int>(pageWidth * 0.15),  // Statut
        static_cast<int>(pageWidth * 0.15),  // Durée
        static_cast<int>(pageWidth * 0.15)   // Date
    };

    auto parseDate = [](const QVariant& dateValue) -> QString {
        if (dateValue.isNull() || !dateValue.isValid()) return "N/A";

        // 1. Si c'est déjà un QDateTime (contient date+heure)
        if (dateValue.typeId() == QMetaType::QDateTime) {
            return dateValue.toDateTime().date().toString("yyyy-MM-dd");
        }

        // 2. Si c'est un QDate (date seule)
        if (dateValue.typeId() == QMetaType::QDate) {
            return dateValue.toDate().toString("yyyy-MM-dd");
        }

        // 3. Si c'est un nombre (année seule)
        if (dateValue.canConvert<int>()) {
            int year = dateValue.toInt();
            if (year > 1000 && year < 3000) {
                return QString("%1-01-01").arg(year); // Format ISO avec jour/mois par défaut
            }
        }

        // 4. Traitement des chaînes de caractères
        QString dateStr = dateValue.toString().trimmed();

        // Supprimer la partie heure si elle existe (format "2000-01-01 00:00:00")
        dateStr = dateStr.split(" ").first();

        // Liste des formats de date à essayer
        QVector<QString> formats = {
            "yyyy-MM-dd",    // Format ISO (2000-01-01)
            "dd/MM/yyyy",    // Format français (01/01/2000)
            "dd/MM/yy",      // Format court (01/01/00)
            "MM/dd/yyyy",    // Format américain
            "yyyy"           // Année seule
        };

        for (const QString& format : formats) {
            QDate date = QDate::fromString(dateStr, format);
            if (date.isValid()) {
                // Correction pour les années sur 2 chiffres
                if (format == "dd/MM/yy" && date.year() < 100) {
                    date = date.addYears(2000 - (date.year() % 100));
                }
                return date.toString("yyyy-MM-dd");
            }
        }

        // Si aucun format ne correspond, retourner la valeur originale (pour débogage)
        return dateStr;
    };
    // Première passe: calcul des largeurs de colonnes
    QSqlQuery query;
    if (query.exec("SELECT matiere_examen, type_examen, niveau_examen, statut_examen, duree_examen, date_examen FROM examens")) {
        painter.setFont(QFont("Arial", 12));

        while (query.next()) {
            for (int col = 0; col < headers.size(); ++col) {
                QString data = query.value(col).toString();

                // Traitement spécial pour les dates
                if (col == 5) data = parseDate(data);

                int textWidth = painter.fontMetrics().horizontalAdvance(data) + 30;
                if (textWidth > columnWidths[col]) {
                    columnWidths[col] = qMin(textWidth, pageWidth / 2);
                }
            }
        }
    } else {
        qDebug() << "Erreur requête:" << query.lastError().text();
        return;
    }

    // Ajustement des largeurs de colonnes
    int totalWidth = std::accumulate(columnWidths.begin(), columnWidths.end(), 0);
    if (totalWidth < pageWidth) {
        float ratio = static_cast<float>(pageWidth) / totalWidth;
        for (int& width : columnWidths) {
            width = static_cast<int>(width * ratio);
        }
    }

    // Calcul des positions des colonnes
    QVector<int> columnPositions(headers.size());
    columnPositions[0] = startX;
    for (int i = 1; i < headers.size(); ++i) {
        columnPositions[i] = columnPositions[i - 1] + columnWidths[i - 1];
    }

    // Dessin des en-têtes
    painter.setFont(QFont("Arial", 14, QFont::Bold));
    QColor headerColor(0, 102, 204);
    painter.setBrush(headerColor);
    painter.setPen(Qt::white);

    for (int col = 0; col < headers.size(); ++col) {
        painter.drawRect(columnPositions[col], startY, columnWidths[col], rowHeight);
        painter.drawText(columnPositions[col], startY, columnWidths[col], rowHeight,
                         Qt::AlignCenter, headers[col]);
    }

    startY += rowHeight;

    // Dessin des données
    painter.setFont(QFont("Arial", 12));
    if (!query.exec("SELECT matiere_examen, type_examen, niveau_examen, statut_examen, duree_examen, date_examen FROM examens")) {
        qDebug() << "Erreur requête:" << query.lastError().text();
        return;
    }

    int rowNum = 0;
    while (query.next()) {
        // Alternance des couleurs de ligne
        QColor rowColor = (rowNum % 2 == 0) ? QColor(240, 240, 240) : Qt::white;
        painter.setBrush(rowColor);
        painter.setPen(Qt::black);

        for (int col = 0; col < headers.size(); ++col) {
            QString data = query.value(col).toString();

            // Traitement spécial pour les dates
            if (col == 5) data = parseDate(data);

            painter.drawRect(columnPositions[col], startY, columnWidths[col], rowHeight);
            painter.drawText(columnPositions[col] + 10, startY, columnWidths[col] - 20, rowHeight,
                             Qt::AlignLeft | Qt::AlignVCenter, data);
        }

        startY += rowHeight;
        rowNum++;

        // Gestion du saut de page
        if (startY > pdfWriter.height() - margin - rowHeight) {
            pdfWriter.newPage();
            startY = 100;

            // Réafficher les en-têtes
            painter.setFont(QFont("Arial", 14, QFont::Bold));
            painter.setBrush(headerColor);
            painter.setPen(Qt::white);

            for (int col = 0; col < headers.size(); ++col) {
                painter.drawRect(columnPositions[col], startY - rowHeight, columnWidths[col], rowHeight);
                painter.drawText(columnPositions[col], startY - rowHeight, columnWidths[col], rowHeight,
                                 Qt::AlignCenter, headers[col]);
            }
        }
    }

    painter.end();
    QMessageBox::information(this, "Succès", "Le PDF a été généré avec succès !");
}*/




void MainWindow::loadExamStatistics()
{
    if (!ui->ExamChartContainer) {
        qCritical() << "Chart container not initialized!";
        return;
    }

    QMap<QString, int> statusCounts = getExamStatusCounts();
    if (statusCounts.isEmpty()) {
        QMessageBox::information(this, "Information", "Aucune donnée à afficher");
        return;
    }

    showChartInPage(statusCounts);
}

// Helper function to get data
QMap<QString, int> MainWindow::getExamStatusCounts()
{
    QMap<QString, int> counts;

    QSqlQuery query("SELECT statut_examen, COUNT(*) as count FROM EXAMENS GROUP BY statut_examen");
    while (query.next()) {
        counts.insert(query.value("statut_examen").toString(),
                      query.value("count").toInt());
    }

    if (counts.isEmpty()) {
        QMessageBox::information(this, "Statistiques", "Aucun examen trouvé");
    }

    return counts;
}

void MainWindow::clearChartWidget()
{
    if (!ui->ExamChartContainer) {
        qWarning() << "Chart container is null!";
        return;
    }

    QLayout* layout = ui->ExamChartContainer->layout();
    if (!layout) return;

    while (QLayoutItem* item = layout->takeAt(0)) {
        if (item->widget()) {
            item->widget()->deleteLater();
        }
        delete item;
    }
}

void MainWindow::showChartInPage(const QMap<QString, int>& statusCounts)
{
    clearChartWidget();

    if (!ui->ExamChartContainer->layout()) {
        ui->ExamChartContainer->setLayout(new QVBoxLayout());
    }

    // First calculate total sum of all exams
    int totalExams = 0;
    for (auto it = statusCounts.begin(); it != statusCounts.end(); ++it) {
        totalExams += it.value();
    }

    // Only proceed if we have exams
    if (totalExams == 0) {
        QMessageBox::information(this, "Information", "Aucun examen trouvé");
        return;
    }

    QPieSeries *series = new QPieSeries();

    // Add data with correct percentages
    for (auto it = statusCounts.begin(); it != statusCounts.end(); ++it) {
        double percentage = (100.0 * it.value()) / totalExams;
        QPieSlice *slice = series->append(it.key(), it.value());
        slice->setLabel(QString("%1\n%2 examens\n%3%")
                            .arg(it.key())
                            .arg(it.value())
                            .arg(percentage, 0, 'f', 1));
        slice->setLabelVisible();
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des examens par statut");
    chart->legend()->setAlignment(Qt::AlignRight);
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    ui->ExamChartContainer->layout()->addWidget(chartView);

    // Optional refresh button
    QPushButton *refreshBtn = new QPushButton("Actualiser");
    connect(refreshBtn, &QPushButton::clicked, this, &MainWindow::loadExamStatistics);
    ui->ExamChartContainer->layout()->addWidget(refreshBtn);
}



