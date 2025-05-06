#include "mainwindow.h"
#include "./ui_mainwindow.h"

// ==================== Project Headers ====================
#include "Superviseur.h"
#include "examen.h"
#include "fournisseurs.h"
#include "Etablissement.h"
#include "equipement.h"
#include "arduino.h"
#include "panoramicviewer.h"
#include "candidat.h"
#include "qrcodegen.hpp"

// ==================== SimpleMail Library ====================
#include "simple-mail/src/server.h"
#include "simple-mail/src/serverreply.h"
#include "simple-mail/src/mimetext.h"
#include "simple-mail/src/mimemessage.h"
#include "simple-mail/src/emailaddress.h"

// ==================== Qt Core ====================
#include <QDate>
#include <QDebug>
#include <QBuffer>
#include <QDir>
#include <QProcess>
#include <QStandardPaths>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <cstdlib>  // Pour rand(), srand()
#include <ctime>    // Pour time()

// ==================== Qt Widgets ====================
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QFileDialog>
#include <QInputDialog>
#include <QLabel>

// ==================== Qt GUI ====================
#include <QPixmap>
#include <QImage>
#include <QPainter>
#include <QDesktopServices>
#include <QUrl>
#include <QMouseEvent>

// ==================== Qt Text & Printing ====================
#include <QPdfWriter>
#include <QPrinter>
#include <QTextStream>
#include <QTextDocument>
#include <QTextCursor>
#include <QTextTable>

// ==================== Qt SQL ====================
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlError>

// ==================== Qt Charts ====================
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QPieSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLineSeries>

// ==================== Qt Serial Communication ====================
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QByteArray>

// ==================== Qt Models ====================
#include <QStandardItemModel>

// ==================== Qt Network ====================
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QSslError>
#include <QSslSocket>

// ==================== Qt Quick ====================
#include <QtQuick/QQuickImageProvider>


using namespace qrcodegen;

using qrcodegen::QrCode;
using qrcodegen::QrSegment;

using namespace SimpleMail;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) ,
    networkManager(new QNetworkAccessManager(this)) , codeBuffer(), currentLineEdit(nullptr)

{
    ui->setupUi(this);
    ui->lineEdit_2->setPlaceholderText("L'adresse e-mail du destinataire");
    ui->lineEdit_3->setPlaceholderText("L'objet de l'email");
    ui->textEdit->setPlaceholderText("Le contenu de votre message...");
    ui->lineEditRech_4->setPlaceholderText("Recherche par ID...");
    ui->searchDirector_2->setPlaceholderText("Recherche par directeur...");
    ui->RechSuperviseur->setPlaceholderText("Rechercher par ID...");
    ui->NumTelSup->setPlaceholderText("Numéro Téléphone...");
    ui->SearchBarExamen->setPlaceholderText("math, physique...");
    ui->chatInput->setPlaceholderText("Besoin d'aide?");
    ui->lineCODECandRech->setPlaceholderText("Recherche Par ID..");
    ui->lineCodecc->setPlaceholderText("Code Convocation..");
    ui->idInputLineEdit->setPlaceholderText("ID quantité modifiée");

    connect(ui->BinSuperbtn, &QPushButton::clicked, this, &MainWindow::on_BinSuperbtn_clicked);
    connect(ui->SaveMod, &QPushButton::clicked, this, &MainWindow::on_SaveMod_clicked);

    connect(ui->closeBtn, &QPushButton::clicked, this, &MainWindow::close);
    connect(ui->closeBtn, &QPushButton::clicked, this, &MainWindow::close);
    // Connexion du bouton de recherche
    connect(ui->rechBtn_2, &QPushButton::clicked, this, &MainWindow::rechercherSuperviseur);
   // connect(ui->TriButton, &QPushButton::clicked, this, &MainWindow::onTriButtonClicked);
    connect(ui->TriButton, SIGNAL(clicked()), this, SLOT(onTriButtonClicked()));
    connect(ui->ReMod, SIGNAL(clicked()), this, SLOT(resetTableView()));
    // Connecter le bouton d'envoi avec le slot

    connect(ui->sendButton, &QPushButton::clicked, this, &MainWindow::handleChatCommand);
    connect(ui->chatInput, &QLineEdit::returnPressed, this, &MainWindow::handleChatCommand);

    //IMEN

    // Connect buttons to their respective slots
    connect(ui->InsertExamPdf_3, &QPushButton::clicked, this, &MainWindow::handleInsertExamPdf);
    connect(ui->SuppExamButton, &QPushButton::clicked, this, &MainWindow::handleSuppExam);
    connect(ui->ModifExamConfirm, &QPushButton::clicked, this, &MainWindow::handleModifExamConfirm);
    connect(ui->viewPdfButton, &QPushButton::clicked, this, &MainWindow::onViewPdfButtonClicked);

    connect(ui->ListeExamensTab, &QTableView::clicked, this, &MainWindow::onExamSelected);
    qDebug() << "Connected QTableView clicked signal.";

    //speech to text
    speechToText = new SpeechToText(this);
    bool isConnected = connect(speechToText, &SpeechToText::textRecognized,
                               this, &MainWindow::onSpeechTextRecognized);
    qDebug() << "textRecognized connection:" << isConnected;

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

    m_proxyModel = new ExamenFilterProxyModel(this);
    Examen examen;
    m_examenDisplayModel = examen.afficherExamen();
    m_proxyModel->setSourceModel(m_examenDisplayModel);
    ui->ListeExamensTab->setModel(m_proxyModel);

    // Connecte les filtres
    connect(ui->SearchBarExamen, &QLineEdit::textChanged, m_proxyModel, &ExamenFilterProxyModel::setMatiereFilter);
    connect(ui->filterExam, &QDateEdit::dateChanged, m_proxyModel, &ExamenFilterProxyModel::setDateFilter);
    connect(ui->pdfExambtn, &QPushButton::clicked, this, &MainWindow::on_pdfExambtn_clicked);


    // Configure table selection behavior
    ui->ListeExamensTab->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->ListeExamensTab->setSelectionBehavior(QAbstractItemView::SelectRows);


    //DAH
    //verifierEtEnvoyerCode();

    model_Fourn = new QSqlQueryModel();  // Initialisation du modèle
    updateTableView_Fourn();
    connect(ui->suppButton, &QPushButton::clicked, this, &MainWindow::handleDeleteFournisseur);

    connect(arduino.getSerial(), &QSerialPort::readyRead, this, &MainWindow::handleArduinoCandidateVerification);

    //etablissement
    ui->tableView_Eta->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);     // Connexions existantes...
    connect(ui->closeBtn, &QPushButton::clicked, this, &MainWindow::close);
    connect(ui->Binetabtn, &QPushButton::clicked, this, &MainWindow::on_Binetabtn_clicked);

    // Nouvelle connexion pour le bouton Nouveau
    connect(ui->neweta, &QPushButton::clicked, this, &MainWindow::on_neweta_clicked);

    connect(ui->sortGovernorateBtn, &QPushButton::clicked,this, &MainWindow::on_sortGovernorateBtn_clicked);

    // Connexion pour l'export PDF
    connect(ui->exportPdfBtn_2, &QPushButton::clicked,this, &MainWindow::on_exportPdfBtn_2_clicked);



    connect(ui->tableView_Eta, &QTableView::clicked, this, &MainWindow::on_tableView_Eta_clicked);
    updatetableView_Eta();

    // Initialiser les stats
    setupGovernorateStats();

    //Lou
    afficherCandidats(); // Charger les candidats au démarrage




    // Connect first Arduino (RFID)
    int ret1 = A2.connect_arduino("COM8"); // Replace with your actual port
    handleArduinoConnection(ret1, &A, SLOT(updateSerialData()));

    // Connect second Arduino (quantity management)
    int ret2 = A.connect_arduino("COM10"); // Replace with your actual port
    handleArduinoConnection(ret2, &A2, SLOT(readSerialData()));



    //Akrem
    connect(ui->ModifEquip, &QPushButton::clicked, this, &MainWindow::on_ModifEquip_clicked);
    ui->recherche->setPlaceholderText("ID ..");
    afficherEquipements();
}


MainWindow::~MainWindow() {
    delete ui;
    delete speechToText;
    if (serial->isOpen())
        serial->close();
}

void MainWindow::handleArduinoConnection(int ret, Arduino* arduino, const char* slot)
{
    switch(ret) {
    case 0:
        qDebug() << arduino->getarduino_port_name() << "connected successfully";
        connect(arduino->getserial(), SIGNAL(readyRead()), this, slot);
        break;
    case 1:
        qDebug() << "Arduino detected but not connected on" << arduino->getarduino_port_name();
        break;
    case -1:
        qDebug() << "Arduino not available on" << arduino->getarduino_port_name();
        break;
    }
}



void MainWindow::on_examButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    refreshExamenTable();
}


void MainWindow::on_supButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}



void MainWindow::on_eqButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    afficherEquipements();

}



void MainWindow::on_FourButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    actualiserTableView_Fourn();
    updateTableView_Fourn();
}


void MainWindow::on_candButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
    afficherCandidats();

}


void MainWindow::on_etaButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
    updatetableView_Eta();
}


void MainWindow::on_homeBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
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
    QString statut = ui->StatutComboBox->currentText().trimmed();

    QString poste = ui->PostLineEdit->text().trimmed();
    QString prenom = ui->PrenLineEdit->text().trimmed();
    QString nom = ui->NomLineEdit->text().trimmed();
    QString numTelStr = ui->TlfLineEdit->text().trimmed();
    QString email = ui->EmailLineEdit->text().trimmed();

    // Récupère la zone depuis le ComboBox et pas depuis NomLineEdit
    QString zone = ui->ZoneLineEdit->text().trimmed();

    // Vérification des champs obligatoires
    if (id.isEmpty() || cinStr.isEmpty() || statut.isEmpty() || poste.isEmpty() ||
        prenom.isEmpty() || nom.isEmpty() || numTelStr.isEmpty() || email.isEmpty() || zone.isEmpty()) {
        QMessageBox::warning(this, "Champs vides", "Tous les champs sont obligatoires !");
        return;
    }

    // Vérification que CIN et Numéro de téléphone sont des nombres de 8 chiffres
    QRegularExpression regex("\\d{6}");
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


    // Création et ajout du superviseur
    Superviseur S(id, cin, statut, poste, prenom, nom, numTelStr, email, zone);
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
    originalTel = ui->tableView1->model()->data(ui->tableView1->model()->index(index.row(), 6)).toString();
    originalEmail = ui->tableView1->model()->data(ui->tableView1->model()->index(index.row(), 7)).toString();
    originalZone = ui->tableView1->model()->data(ui->tableView1->model()->index(index.row(), 8)).toString();  // Récupérer la zone

    // Afficher les valeurs dans les champs du formulaire
    ui->CINLineEdit->setText(QString::number(originalCin));
    ui->StatutComboBox->setCurrentText(originalStatut);

    ui->PostLineEdit->setText(originalPoste);
    ui->PrenLineEdit->setText(originalPrenom);
    ui->NomLineEdit->setText(originalNom);
    ui->TlfLineEdit->setText(originalTel);
    ui->EmailLineEdit->setText(originalEmail);
    ui->ZoneLineEdit->setText(originalZone);  // Afficher la zone dans le champ approprié

    modificationInProgress = true; // Définir le flag quand la modification commence
}



void MainWindow::on_SaveMod_clicked() {
    if (!modificationInProgress) {
        QMessageBox::warning(this, tr("Erreur"), tr("Veuillez d'abord sélectionner un superviseur à modifier en cliquant sur 'Modifier'."));
        return;
    }

    // Récupérer les nouvelles valeurs
    int newCin = ui->CINLineEdit->text().toInt();
    QString newStatut = ui->StatutComboBox->currentText();

    QString newPoste = ui->PostLineEdit->text();
    QString newPrenom = ui->PrenLineEdit->text();
    QString newNom = ui->NomLineEdit->text();
    QString newNumTel = ui->TlfLineEdit->text();
    QString newEmail = ui->EmailLineEdit->text();
    QString newZone = ui->ZoneLineEdit->text();  // Récupérer la nouvelle zone

    // Vérifier si aucun changement n'a été effectué
    if (newCin == originalCin && newStatut == originalStatut &&
        newPoste == originalPoste && newPrenom == originalPrenom &&
        newNom == originalNom && newNumTel == originalTel &&
        newEmail == originalEmail && newZone == originalZone) {
        QMessageBox::information(this, tr("Modification"), tr("Aucune modification apportée."));
        return;
    }

    // Vérification des champs vides
    if (newStatut.isEmpty() || newPoste.isEmpty() || newPrenom.isEmpty() ||
        newNom.isEmpty() || newEmail.isEmpty() || newZone.isEmpty()) {  // Vérifier si la zone est vide
        QMessageBox::warning(this, "Modification", "Tous les champs doivent être remplis.");
        return;
    }

    // Vérification de la validité du CIN et du numéro de téléphone
    if (QString::number(newCin).length() != 6) {
        QMessageBox::warning(this, "Erreur", "Le CIN doit contenir exactement 6 chiffres.");
        return;
    }
    QRegularExpression re("^\\d{8}$"); // exactly 8 digits
    if (!re.match(newNumTel).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le numéro de téléphone doit contenir exactement 8 chiffres.");
        return;
    }


    // Vérification du format de l'email
    if (!newEmail.contains("@") || !newEmail.contains(".")) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un email valide.");
        return;
    }

    // Création de l'objet Superviseur avec les nouvelles valeurs, y compris la zone
    Superviseur s(currentId, newCin, newStatut, newPoste, newPrenom, newNom, newNumTel, newEmail, newZone);

    // Modifier l'entrée dans la base de données
    if (s.modifier(currentId)) {
        QMessageBox::information(this, "Modification", "Superviseur modifié avec succès !");
        ui->tableView1->setModel(s.afficher());  // Actualiser la table avec les nouvelles données
        modificationInProgress = false;
    } else {
        QMessageBox::critical(this, "Erreur", "La modification a échoué.");
    }
}

// Fonction pour rechercher un superviseur par ID
void MainWindow::rechercherSuperviseur()
{
    QString idRecherche = ui->RechSuperviseur->text();  // L'ID entré par l'utilisateur

    if (idRecherche.isEmpty()) {
        // Si l'utilisateur n'a pas entré d'ID, afficher un avertissement
        QMessageBox::warning(this, "Avertissement", "Veuillez entrer un ID !");
        return;
    }

    // Appel à la méthode rechercherParID pour effectuer la recherche
    QSqlQueryModel *model = S.rechercherParID(idRecherche);  // On passe un QString à la méthode

    if (model && model->rowCount() > 0) {
        // Si des résultats sont trouvés, les afficher dans tableView1
        ui->tableView1->setModel(model);
    } else {
        // Sinon, afficher un message d'information
        QMessageBox::information(this, "Résultat", "Aucun superviseur trouvé !");
    }
}

// Slot pour trier les superviseurs par ordre alphabétique
void MainWindow::onTriButtonClicked()
{
    QSqlQueryModel* model = S.trierNoms(); // Appel de la fonction de tri

    if (model) {
        ui->tableView1->setModel(model); // Mise à jour de l'affichage
        qDebug() << "TableView mise à jour avec le tri par noms.";

        // Vérifier le nombre de lignes retournées
        qDebug() << "Nombre de superviseurs après tri :" << model->rowCount();

        if (model->rowCount() == 0) {
            qDebug() << "Aucun superviseur trouvé après tri.";
        }
    } else {
        qDebug() << "Erreur : Impossible de mettre à jour TableView après tri.";
    }
}

//Re
void MainWindow::resetTableView()
{
    QSqlQueryModel* model = S.afficher(); // Récupérer les données originales

    if (model) {
        ui->tableView1->setModel(model); // Mettre à jour le tableau avec les données initiales
        qDebug() << "TableView réinitialisé aux valeurs d'origine.";
    } else {
        qDebug() << "❌ Erreur : Impossible de réinitialiser TableView.";
    }
}
//stat
void MainWindow::showStatistiques() {
    qDebug() << ":bar_chart: Updating Equipment Type Statistics...";

    if (!ui->chartContainerType) {
        qDebug() << ":x: ERROR: chartContainerType is NULL!";
        return;
    }

    // Clear existing layout content
    if (ui->chartContainerType->layout()) {
        QLayout *layout = ui->chartContainerType->layout();
        while (QLayoutItem *item = layout->takeAt(0)) {
            if (QWidget *widget = item->widget()) {
                widget->deleteLater();
            }
            delete item;
        }
    } else {
        ui->chartContainerType->setLayout(new QVBoxLayout());
    }

    // Create pie chart series
    QPieSeries *pieSeries = new QPieSeries();
    QMap<QString, int> statsType = S.getStatistiquesParZone();

    int total = 0;
    for (auto it = statsType.begin(); it != statsType.end(); ++it) {
        total += it.value();
    }

    if (statsType.isEmpty()) {
        qDebug() << ":warning: WARNING: No data found for equipment types!";
    } else {
        for (auto it = statsType.begin(); it != statsType.end(); ++it) {
            double percentage = (total > 0) ? (it.value() * 100.0 / total) : 0;

            QPieSlice *slice = pieSeries->append(it.key(), it.value());

            slice->setLabel(QString("%1: %2%").arg(it.key()).arg(percentage, 0, 'f', 1));
            slice->setLabelVisible(true);

            // Hover effect (explode + font animation)
            connect(slice, &QPieSlice::hovered, [slice](bool hovered) {
                slice->setExploded(hovered);
                slice->setLabelFont(QFont("Arial", hovered ? 12 : 10, hovered ? QFont::Bold : QFont::Normal));
            });
        }
    }

    QChart *pieChart = new QChart();
    pieChart->addSeries(pieSeries);
    pieChart->setTitle("Répartition des équipements par type");
    pieChart->legend()->setVisible(true);
    pieChart->legend()->setAlignment(Qt::AlignRight);

    // 💫 Animation fluide !
    pieChart->setAnimationOptions(QChart::AllAnimations);

    QChartView *chartView = new QChartView(pieChart);
    chartView->setRenderHint(QPainter::Antialiasing);

    ui->chartContainerType->layout()->addWidget(chartView);

    qDebug() << ":white_check_mark: Type Statistics Updated Successfully!";
}

//pdf
void MainWindow::on_pdfSuperbtn_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Enregistrer PDF", "", "*.pdf");
    if (fileName.isEmpty())
        return;

    QPdfWriter pdfWriter(fileName);
    pdfWriter.setPageSize(QPageSize::A4);
    pdfWriter.setResolution(300);
    QPainter painter(&pdfWriter);
    painter.setRenderHint(QPainter::Antialiasing);

    int margin = 50;
    int startX = margin;
    int startY = 120;
    int rowHeight = 40;
    int headerRowHeight = 60;  // Plus d’espace pour les en-têtes

    // 🔵 TITRE
    painter.setFont(QFont("Arial", 18, QFont::Bold));
    painter.drawText(startX, startY - 50, "Liste des Superviseurs");

    // 🔵 EN-TÊTES À AFFICHER
    QStringList headers = {"ID", "CIN", "Email", "NumTel", "Zone"};
    QVector<int> columnWidths(headers.size(), 100);
    QSqlQuery query;

    // Requête avec les colonnes ciblées
    QString queryStr = "SELECT ID_SUPERVISEUR, CIN_SUPERVISEUR, EMAIL_SUPERVISEUR, NUMTEL_SUPERVISEUR, ZONE_SUPERVISEUR FROM superviseurs";

    if (query.exec(queryStr)) {
        while (query.next()) {
            for (int col = 0; col < headers.size(); ++col) {
                QString data = query.value(col).toString();
                int cellWidth = painter.fontMetrics().horizontalAdvance(data) + 20;
                columnWidths[col] = qMax(columnWidths[col], cellWidth);
            }
        }
    } else {
        qDebug() << "Erreur requête:" << query.lastError().text();
        return;
    }

    // Calculer les positions X cumulées
    QVector<int> columnPositions(headers.size());
    columnPositions[0] = startX;
    for (int i = 1; i < headers.size(); ++i) {
        columnPositions[i] = columnPositions[i - 1] + columnWidths[i - 1];
    }

    // 🟢 DESSINER LES EN-TÊTES
    painter.setFont(QFont("Arial", 12, QFont::Bold));
    QColor headerColor(0, 102, 204);
    painter.setBrush(headerColor);
    painter.setPen(Qt::white);

    for (int col = 0; col < headers.size(); ++col) {
        int x = columnPositions[col];
        int w = columnWidths[col];
        painter.drawRect(x, startY, w, headerRowHeight);

        // Centrer le texte verticalement avec un décalage vers le bas
        int textWidth = painter.fontMetrics().horizontalAdvance(headers[col]);
        int textHeight = painter.fontMetrics().height();
        int textY = startY + (headerRowHeight + textHeight) / 2 - 10;

        painter.drawText(x + (w - textWidth) / 2, textY, headers[col]);
    }

    startY += headerRowHeight;

    // 🟢 DESSINER LES DONNÉES
    painter.setFont(QFont("Arial", 10));
    if (!query.exec(queryStr)) {
        qDebug() << "Erreur requête:" << query.lastError().text();
        return;
    }

    int rowNum = 0;
    while (query.next()) {
        QColor rowColor = (rowNum % 2 == 0) ? QColor(240, 240, 240) : QColor(255, 255, 255);
        painter.setBrush(rowColor);
        painter.setPen(Qt::black);

        for (int col = 0; col < headers.size(); ++col) {
            QString data = query.value(col).toString();
            int x = columnPositions[col];
            int w = columnWidths[col];
            int y = startY;

            painter.drawRect(x, y, w, rowHeight);

            int textWidth = painter.fontMetrics().horizontalAdvance(data);
            int textHeight = painter.fontMetrics().height();
            painter.drawText(x + (w - textWidth) / 2, y + (rowHeight + textHeight) / 2 - 4, data);
        }

        startY += rowHeight;
        rowNum++;

        // 🔴 Saut de page
        if (startY > pdfWriter.height() - margin) {
            pdfWriter.newPage();
            startY = 100;
        }
    }

    painter.end();
}

//sms
void MainWindow::envoyerRappelExamenSuperviseur() {
    qDebug() << "[DEBUG] Début de la fonction envoyerRappelExamenSuperviseur";

    QSqlQuery query;
    QString sql = "SELECT s.numtel_superviseur, e.date_examen, e.duree_examen, et.nom_etablissement "
                  "FROM EXAMENS e, ETABLISSEMENT et, SUPERVISEURS s, AFFECTER a, SUPERVISE sp "
                  "WHERE e.id_examen = sp.id_examen AND s.id_superviseur = sp.id_superviseur "
                  "AND s.id_superviseur = a.id_superviseur AND et.ID_ETABLISSEMENT = a.ID_ETABLISSEMENT";

    query.prepare(sql);
    qDebug() << "[DEBUG] Requête SQL préparée : " << sql;

    if (!query.exec()) {
        qDebug() << "[ERREUR SQL] Échec de récupération des examens : " << query.lastError().text();
        QMessageBox::warning(this, "Erreur", "Échec de récupération des examens : " + query.lastError().text());
        return;
    }

    QString accountSID = "ACee5ebb535e9033421f9370e128932b60";
    QString authToken = "7dc4cd519b4021756e199c08ade5ec88";
    QString twilioNumber = "+12202153672";

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    int smsEnvoyes = 0;
    int totalSuperviseurs = 0;

    while (query.next()) {
        totalSuperviseurs++;
        QString phoneNumber = query.value(0).toString().trimmed();
        QString dateExam = query.value(1).toDate().toString("dd/MM/yyyy");
        QString dureeExam = query.value(2).toString();
        QString nomEtablissement = query.value(3).toString();

        qDebug() << "[DEBUG] Superviseur #" << totalSuperviseurs
                 << " - Téléphone:" << phoneNumber
                 << ", Date examen:" << dateExam
                 << ", Durée:" << dureeExam
                 << ", Établissement:" << nomEtablissement;

        if (phoneNumber.length() != 8) {
            qDebug() << "[AVERTISSEMENT] Numéro de téléphone invalide ignoré : " << phoneNumber;
            continue;
        }

        QString message = "Rappel : Vous avez un examen le " + dateExam +
                          " d'une durée de " + dureeExam +
                          " à l'établissement " + nomEtablissement + ".";

        qDebug() << "[DEBUG] Message à envoyer : " << message;

        QNetworkRequest request(QUrl("https://api.twilio.com/2010-04-01/Accounts/" + accountSID + "/Messages.json"));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

        QUrlQuery params;
        params.addQueryItem("To", "+216" + phoneNumber);
        params.addQueryItem("From", twilioNumber);
        params.addQueryItem("Body", message);

        QByteArray postData = params.query().toUtf8();
        request.setRawHeader("Authorization", "Basic " + QByteArray(QString(accountSID + ":" + authToken).toUtf8()).toBase64());

        QNetworkReply *reply = manager->post(request, postData);

        connect(reply, &QNetworkReply::finished, [reply, &smsEnvoyes]() {
            if (reply->error() == QNetworkReply::NoError) {
                qDebug() << "[SUCCÈS] SMS envoyé avec succès.";
                smsEnvoyes++;
            } else {
                qDebug() << "[ERREUR TWILIO] Échec d'envoi du SMS : " << reply->errorString();
                qDebug() << "[ERREUR TWILIO] Contenu brut de la réponse : " << reply->readAll();
            }
            reply->deleteLater();
        });
    }

    qDebug() << "[DEBUG] Total superviseurs trouvés : " << totalSuperviseurs;
    qDebug() << "[DEBUG] Fonction envoyerRappelExamenSuperviseur terminée.";
}

void MainWindow::on_btnEnvoyerSMS_clicked() {
    envoyerRappelExamenSuperviseur();
}


//ChatBot

void MainWindow::handleChatCommand() {
    QString command = ui->chatInput->text().trimmed();
    if (command.isEmpty()) return;

    addToChat(command, true);
    ui->chatInput->clear();

    QStringList parts = command.split(" ", Qt::SkipEmptyParts);
    if (parts.isEmpty()) return;

    QString action = parts[0].toLower();

    if (action == "ajouter" || action == "add") {
        processAddCommand(parts);
    }
    else if (action == "supprimer" || action == "delete") {
        processDeleteCommand(parts);
    }
    else if (action == "modifier" || action == "update") {
        if (parts.size() == 2 && !parts[1].contains("=") && parts[1].toInt()) {
            processPreUpdateCommand(parts); // Préremplissage
        } else {
            processFlexibleUpdateCommand(parts); // Modification ciblée
        }
    }
    else if (action == "aide" || action == "help") {
        showHelp();
    }
    else {
        addToChat("❓ Commande non reconnue. Tapez 'aide' pour voir les commandes disponibles.");
    }
}

void MainWindow::processPreUpdateCommand(const QStringList &parts) {
    if (parts.size() < 2) {
        addToChat("Format invalide. Utilisez : modifier [CIN]");
        return;
    }

    bool ok;
    int cin = parts[1].toInt(&ok);
    if (!ok) {
        addToChat("CIN invalide.");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM superviseur WHERE cin = :cin");
    query.bindValue(":cin", cin);

    if (query.exec() && query.next()) {
        QString originalStatut = query.value("statut").toString();
        QString originalPoste = query.value("post").toString();
        QString originalPrenom = query.value("prenom").toString();
        QString originalNom = query.value("nom").toString();
        QString originalTel = query.value("tel").toString();
        QString originalEmail = query.value("email").toString();
        QString originalZone = query.value("zone").toString();

        // Affichage dans les champs de l'interface
        ui->CINLineEdit->setText(QString::number(cin));
        ui->StatutComboBox->setCurrentText(originalStatut);

        ui->PostLineEdit->setText(originalPoste);
        ui->PrenLineEdit->setText(originalPrenom);
        ui->NomLineEdit->setText(originalNom);
        ui->TlfLineEdit->setText(originalTel);
        ui->EmailLineEdit->setText(originalEmail);
        ui->ZoneLineEdit->setText(originalZone);

        addToChat("Champs préremplis pour le superviseur CIN " + QString::number(cin));
    } else {
        addToChat("Aucun superviseur trouvé avec le CIN " + QString::number(cin));
    }
}

void MainWindow::processFlexibleUpdateCommand(const QStringList &parts) {
    if (parts.size() < 2) {
        addToChat("❌ Utilisation : modifier cin=... champ1=... champ2=...");
        return;
    }

    QString cinValue;
    QMap<QString, QString> updates;

    // Extraction des champs clé=valeur
    for (const QString &part : parts.mid(1)) {
        auto keyValue = part.split("=");
        if (keyValue.size() != 2) continue;

        QString key = keyValue[0].trimmed().toLower();
        QString value = keyValue[1].trimmed();

        if (key == "cin") cinValue = value;
        else updates[key] = value;
    }

    if (cinValue.isEmpty() || updates.isEmpty()) {
        addToChat("❌ CIN manquant ou aucun champ à modifier.");
        return;
    }

    // Vérification du type du CIN (doit être numérique)
    bool ok;
    int cin = cinValue.toInt(&ok);
    if (!ok) {
        addToChat("❌ CIN invalide.");
        return;
    }

    // Construction dynamique de la requête SQL
    QStringList setParts;
    for (const QString &key : updates.keys()) {
        setParts << key + " = :" + key;
    }

    QString sql = "UPDATE superviseur SET " + setParts.join(", ") + " WHERE cin = :cin";
    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":cin", cin);

    for (auto it = updates.constBegin(); it != updates.constEnd(); ++it) {
        query.bindValue(":" + it.key(), it.value());
    }

    qDebug() << "Exécution de la requête SQL : " << query.executedQuery(); // Debugging de la requête

    if (query.exec()) {
        addToChat("✅ Modification effectuée avec succès.");
        refreshTableView();
    } else {
        addToChat("❌ Erreur SQL : " + query.lastError().text());
    }
}



void MainWindow::processAddCommand(const QStringList &parts) {
    QMap<QString, QString> data;

    // Traitement de chaque couple clé=valeur
    for (const QString &part : parts.mid(1)) {
        QStringList kv = part.split("=");
        if (kv.size() == 2) {
            data[kv[0].trimmed().toLower()] = kv[1].trimmed();
        }
    }

    // Champs requis
    QStringList required = {"id", "cin", "statut", "poste", "prenom", "nom", "tel", "email", "zone"};
    for (const QString &key : required) {
        if (!data.contains(key)) {
            addToChat("❌ Champ manquant : " + key);
            return;
        }
    }

    // Vérification que les champs numériques sont valides
    bool ok;
    int id = data["id"].toInt(&ok);
    if (!ok) {
        addToChat("❌ ID doit être un entier.");
        return;
    }

    int cin = data["cin"].toInt(&ok);
    if (!ok || data["cin"].length() != 6) {
        addToChat("❌ CIN doit être un entier de 6 chiffres.");
        return;
    }

    int tel = data["tel"].toInt(&ok);
    if (!ok || data["tel"].length() != 6) {
        addToChat("❌ Téléphone doit être un entier de 6 chiffres.");
        return;
    }

    // Vérification email
    QRegularExpression emailRegex("^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\\.[a-zA-Z0-9-.]+$");
    if (!emailRegex.match(data["email"]).hasMatch()) {
        addToChat("❌ Email invalide.");
        return;
    }

    // Création et insertion
    Superviseur S(
        data["id"],
        data["cin"].toInt(),
        data["statut"],
        data["poste"],
        data["prenom"],
        data["nom"],
        data["tel"],
        data["email"],
        data["zone"]
        );

    if (S.ajouter()) {
        addToChat("✅ Superviseur ajouté avec succès !");
        refreshTableView();
    } else {
        addToChat("❌ Échec de l'ajout.");
    }
}


void MainWindow::processDeleteCommand(const QStringList &parts) {
    if (parts.size() < 2) {
        addToChat("Format incorrect. Usage: supprimer [ID]");
        return;
    }

    QString id = parts[1];
    if (S.supprimer(id)) {
        addToChat("Superviseur supprimé avec succès !");
        refreshTableView();
    } else {
        addToChat("Échec de la suppression. Vérifiez l'ID.");
    }
}

void MainWindow::processUpdateCommand(const QStringList &parts) {
    if (parts.size() < 10) {
        addToChat("Format incorrect. Usage: modifier [ID] [CIN] [Statut] [Poste] [Prénom] [Nom] [Téléphone] [Email] [Zone]");
        return;
    }

    QString id = parts[1];
    // ... (validation similaire à processAddCommand)

    // Créer l'objet Superviseur et appeler modifier()
    if (S.modifier(id)) {
        addToChat("Superviseur modifié avec succès !");
        refreshTableView();
    } else {
        addToChat("Échec de la modification.");
    }
}

void MainWindow::showHelp() {
    QString helpText = "📘 Commandes disponibles :\n"
                       "- ajouter id=... cin=... statut=... poste=... prenom=... nom=... tel=... email=... zone=...\n"
                       "- supprimer [ID]\n"
                       "- modifier [ID] → préremplit les champs depuis la base\n"
                       "- modifier id=... champ1=... champ2=... (modification ciblée)\n"
                       "- aide / help : Affiche cette aide";
    addToChat(helpText);
}


void MainWindow::refreshTableView() {
    ui->tableView1->setModel(S.afficher());
    actualiserTableView();
}

void MainWindow::addToChat(const QString &message, bool isUser) {
    QString formatted = isUser ? "Vous: " + message : "Bot: " + message;
    ui->chatDisplay->append(formatted);
}



void MainWindow::on_examButton_2_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(0);

}


void MainWindow::on_supButton_2_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(1);
    showStatistiques();


}


//IMEN:


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
        if (examen.supprimerExamen(selectedExamId)) {
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
    QString matiere = ui->MatiereCase->text();
    QString niveau = ui->NiveauCase->text();
    QString duree = ui->DureeCase->text();
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
    if (e.modifierExamen(selectedExamId)) {
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
    QSortFilterProxyModel *m_proxyModel = qobject_cast<QSortFilterProxyModel*>(ui->ListeExamensTab->model());
    if (!m_proxyModel) {
        qDebug() << "Proxy model is not valid!";
        return;
    }

    // Get the source model (QSqlQueryModel)
    QSqlQueryModel *sourceModel = qobject_cast<QSqlQueryModel*>(m_proxyModel->sourceModel());
    if (!sourceModel) {
        qDebug() << "Source model is not valid!";
        return;
    }

    // Map the index to the source model
    QModelIndex sourceIndex = m_proxyModel->mapToSource(index);
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
    ui->MatiereCase->setText(matiere);
    ui->NiveauCase->setText(niveau);
    ui->DureeCase->setText(duree);
    ui->TypeExamenChoix->setCurrentText(type);
    ui->StatutExamenChoix->setCurrentText(statut);
    ui->dateExamenChoix->setDate(date);

    // Retrieve the PDF data for the selected exam from the database
    Examen examen;
    pdfData = examen.getPdfDataById(id);
    ui->stackedWidget_2->setCurrentIndex(1);

    selectedExamId = id;
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


void MainWindow::on_AddExamConfirm_3_clicked()
{
    // Read values from the input fields
    QString matiere = ui->MatiereCase->text();
    QString niveau = ui->NiveauCase->text();
    QString duree = ui->DureeCase->text();
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
    if (e.ajouterExamen()) {
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
    qDebug() << "=== Starting refreshExamenTable ===";

    // 1. Check database connection
    QSqlDatabase db = QSqlDatabase::database();
    qDebug() << "Database connection:" << db.isOpen();
    if (!db.isOpen()) {
        qDebug() << "Database is not open!";
        QMessageBox::warning(this, tr("Erreur"), tr("La connexion à la base de données est perdue."));
        return;
    }

    // 2. Ensure proxy model exists
    if (!m_proxyModel) {
        qDebug() << "Recreating proxy model...";
        m_proxyModel = new ExamenFilterProxyModel(this);

        // Reconnect signals
        connect(ui->SearchBarExamen, &QLineEdit::textChanged,
                m_proxyModel, &ExamenFilterProxyModel::setMatiereFilter);
        connect(ui->filterExam, &QDateEdit::dateChanged,
                m_proxyModel, &ExamenFilterProxyModel::setDateFilter);
    }

    // 3. Create and populate model
    qDebug() << "Creating Examen object...";
    Examen examen;

    qDebug() << "Calling afficherExamen()...";
    QSqlQueryModel *m_examenDisplayModel = examen.afficherExamen();
    qDebug() << "Model address:" << m_examenDisplayModel;

    if (!m_examenDisplayModel) {
        qDebug() << "Model is null!";
        QMessageBox::warning(this, tr("Erreur"), tr("Impossible de charger les données des examens."));
        return;
    }

    // 4. Verify proxy model
    qDebug() << "Proxy model address:" << m_proxyModel;
    if (!m_proxyModel) {
        qDebug() << "Proxy model is null!";
        return;
    }

    // 5. Set up models and view
    qDebug() << "Setting source model...";
    m_proxyModel->setSourceModel(m_examenDisplayModel);

    qDebug() << "Setting table model...";
    ui->ListeExamensTab->setModel(m_proxyModel);

    // 6. Set proper header names (FIXED THIS PART)
    qDebug() << "Setting header data...";
    m_examenDisplayModel->setHeaderData(0, Qt::Horizontal, tr("ID Examen"));
    m_examenDisplayModel->setHeaderData(1, Qt::Horizontal, tr("Matière Examen"));
    m_examenDisplayModel->setHeaderData(2, Qt::Horizontal, tr("Type Examen"));
    m_examenDisplayModel->setHeaderData(3, Qt::Horizontal, tr("Statut Examen"));
    m_examenDisplayModel->setHeaderData(4, Qt::Horizontal, tr("Niveau Examen"));
    m_examenDisplayModel->setHeaderData(5, Qt::Horizontal, tr("Durée Examen"));
    m_examenDisplayModel->setHeaderData(6, Qt::Horizontal, tr("Date Examen"));

    // 7. Configure table view
    qDebug() << "Resizing columns...";
    ui->ListeExamensTab->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    ui->ListeExamensTab->resizeColumnsToContents();
    ui->ListeExamensTab->horizontalHeader()->setStretchLastSection(true);

    qDebug() << "=== refreshExamenTable completed ===";
}
void MainWindow::clearForm()
{
    // Clear all input fields
    ui->MatiereCase->clear();
    ui->NiveauCase->clear();
    ui->DureeCase->clear();
    ui->TypeExamenChoix->setCurrentIndex(0);
    ui->StatutExamenChoix->setCurrentIndex(0);
    ui->dateExamenChoix->setDate(QDate::currentDate());
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




void MainWindow::loadExamStatistics()
{
    qDebug() << ":bar_chart: Updating Exam Status Statistics...";

    // Vérifie si le conteneur existe
    if (!ui->ExamChartContainer) {
        qDebug() << ":x: ERROR: ExamChartContainer is NULL!";
        return;
    }

    // Nettoyage de l'ancien contenu
    if (ui->ExamChartContainer->layout()) {
        QLayout *layout = ui->ExamChartContainer->layout();
        while (QLayoutItem *item = layout->takeAt(0)) {
            if (QWidget *widget = item->widget()) {
                widget->deleteLater();
            }
            delete item;
        }
    } else {
        ui->ExamChartContainer->setLayout(new QVBoxLayout());
    }

    QMap<QString, int> statusCounts = getExamStatusCounts();

    if (statusCounts.isEmpty()) {
        qDebug() << ":warning: WARNING: No exam data to display!";
        QLabel *label = new QLabel("Aucune donnée à afficher");
        ui->ExamChartContainer->layout()->addWidget(label);
        return;
    }

    // Création de la série pour le pie chart
    QPieSeries *series = new QPieSeries();
    int total = 0;
    for (int value : statusCounts.values()) {
        total += value;
    }

    for (auto it = statusCounts.begin(); it != statusCounts.end(); ++it) {
        double percentage = (total > 0) ? (it.value() * 100.0 / total) : 0;
        QPieSlice *slice = series->append(it.key(), it.value());

        slice->setLabel(QString("%1: %2%").arg(it.key()).arg(percentage, 0, 'f', 1));
        slice->setLabelVisible(true);

        connect(slice, &QPieSlice::hovered, [slice](bool hovered) {
            slice->setExploded(hovered);
            slice->setLabelFont(QFont("Arial", hovered ? 12 : 10, hovered ? QFont::Bold : QFont::Normal));
        });
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques des examens par statut");
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight);
    chart->setAnimationOptions(QChart::AllAnimations); // Animation fluide

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    ui->ExamChartContainer->layout()->addWidget(chartView);

    qDebug() << ":white_check_mark: Exam Statistics Updated Successfully!";
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
    chart->setAnimationOptions(QChart::AllAnimations);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    ui->ExamChartContainer->layout()->addWidget(chartView);


}

//ARDUINO IMEN

/*void MainWindow::onSerialData() {
    buffer.append(serial->readAll());
    int idx;
    while ((idx = buffer.indexOf('\n')) != -1) {
        QByteArray line = buffer.left(idx).trimmed();
        buffer.remove(0, idx + 1);

        if (line.startsWith("NUM:")) {
            // build up buffer, max length CODE_LENGTH
            if (codeBuffer.length() < CODE_LENGTH) {
                QString num = QString::fromUtf8(line.mid(4));
                codeBuffer.append(num);
                qDebug() << "Code:" << codeBuffer;
            }
        }
        else if (line == "CLEARED") {
            codeBuffer.clear();
            qDebug() << "Entry cleared";
        }
        else if (line.startsWith("CODE:")) {
            // '#' pressed: verify only if correct length
            if (codeBuffer.length() == CODE_LENGTH) {
                QSqlDatabase db = QSqlDatabase::database();
                QSqlQuery query(db);
                query.prepare("SELECT COUNT(*) FROM candidat WHERE code_candidat = :code");
                query.bindValue(":code", codeBuffer);
                if (!query.exec()) {
                    qCritical() << "DB query error:" << query.lastError().text();
                } else if (query.next() && query.value(0).toInt() > 0) {
                    qDebug() << "Candidate verified";
                } else {
                    qDebug() << "Candidate doesn't exist";
                }
            } else {
                qDebug() << "Enter exactly" << CODE_LENGTH << "digits before verify.";
            }
            codeBuffer.clear();
        }
    }
}*/



void MainWindow::onMatiereSpeechClicked()
{
    qDebug() << "=== Matiere Speech Button Clicked ===";
    qDebug() << "Setting currentLineEdit to MatiereCase:" << ui->MatiereCase;
    currentLineEdit = ui->MatiereCase;

    qDebug() << "Starting speech recognition...";
    speechToText->startListening();
    qDebug() << "Speech recognition started for Matiere";
}

void MainWindow::onNiveauSpeechClicked()
{
    qDebug() << "=== Niveau Speech Button Clicked ===";
    qDebug() << "Setting currentLineEdit to NiveauCase:" << ui->NiveauCase;
    currentLineEdit = ui->NiveauCase;

    qDebug() << "Starting speech recognition...";
    speechToText->startListening();
    qDebug() << "Speech recognition started for Niveau";
}

void MainWindow::onDureeSpeechClicked()
{
    qDebug() << "=== Duree Speech Button Clicked ===";
    qDebug() << "Setting currentLineEdit to DureeCase:" << ui->DureeCase;
    currentLineEdit = ui->DureeCase;

    qDebug() << "Starting speech recognition...";
    speechToText->startListening();
    qDebug() << "Speech recognition started for Duree";
}

void MainWindow::onSpeechTextRecognized(const QString &text)
{
    qDebug() << "\n=== Speech Recognized ===";
    qDebug() << "Raw text received:" << text;
    qDebug() << "Current line edit pointer:" << currentLineEdit;
    qDebug() << "Current line edit object name:" << (currentLineEdit ? currentLineEdit->objectName() : "NULL");

    if (currentLineEdit) {
        qDebug() << "Previous text in field:" << currentLineEdit->text();
        qDebug() << "Setting new text:" << text;

        currentLineEdit->setText(text);
        qDebug() << "Text after setting:" << currentLineEdit->text();

        // Force UI update
        currentLineEdit->repaint();
        qApp->processEvents();
        qDebug() << "UI update forced";
    } else {
        qDebug() << "ERROR: currentLineEdit is null!";
        qDebug() << "Available line edits:";
        qDebug() << "MatiereCase:" << ui->MatiereCase;
        qDebug() << "NiveauCase:" << ui->NiveauCase;
        qDebug() << "DureeCase:" << ui->DureeCase;
    }
    qDebug() << "=== Recognition Handling Complete ===\n";
}

void MainWindow::on_listexamensbutton_clicked()
{
    qDebug() << "listexamensbutton clicked - starting refresh";
    try {
        refreshExamenTable();
    } catch (const std::exception &e) {
        qCritical() << "Exception:" << e.what();
    } catch (...) {
        qCritical() << "Unknown exception occurred";
    }
    qDebug() << "listexamensbutton click handling completed";
}


void MainWindow::on_statButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

//DAH

// Mettre à jour la table des fournisseurs
void MainWindow::updateTableView_Fourn() {
    qDebug() << "📊 Mise à jour du tableau...";

    // 🔹 Utiliser la fonction `afficher()` de `Fournisseur`
    model_Fourn = Fournisseur().afficherFourn();

    if (!model_Fourn) {
        qDebug() << "❌ Erreur : Modèle SQL non valide";
        return;
    }

    if (model_Fourn->rowCount() == 0) {
        qDebug() << "⚠️ Aucun fournisseur trouvé dans la base de données.";
    } else {
        qDebug() << "✅ Nombre de fournisseurs récupérés : " << model_Fourn->rowCount();
    }

    ui->tableFourn->setModel(model_Fourn);
    actualiserTableView_Fourn();
}

// ✅ Ajuster automatiquement la taille du tableau
void MainWindow::actualiserTableView_Fourn() {
    ui->tableFourn->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableFourn->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
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
    if (fournisseur.supprimerFourn(idFournisseur.toInt())) {
        QMessageBox::information(this, "Succès", "Fournisseur supprimé avec succès !");

        // 🔹 Met à jour l'affichage après suppression
        updateTableView_Fourn();

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
    currentIdFourn = ui->tableFourn->model()->data(ui->tableFourn->model()->index(index.row(), 0)).toString();
    originalNomFourn = ui->tableFourn->model()->data(ui->tableFourn->model()->index(index.row(), 1)).toString();
    originalNumTelFourn = ui->tableFourn->model()->data(ui->tableFourn->model()->index(index.row(), 2)).toInt(); // ✅ numTel en int
    originalEmailFourn = ui->tableFourn->model()->data(ui->tableFourn->model()->index(index.row(), 3)).toString();
    originalAdresseFourn = ui->tableFourn->model()->data(ui->tableFourn->model()->index(index.row(), 4)).toString();
    originalTypeServiceFourn = ui->tableFourn->model()->data(ui->tableFourn->model()->index(index.row(), 5)).toString();

    // 🔹 Afficher les valeurs dans les champs du formulaire
    ui->Nom->setText(originalNomFourn);
    ui->NumTel->setText(QString::number(originalNumTelFourn)); // ✅ Convertir int en QString
    ui->Email->setText(originalEmailFourn);
    ui->ADRESSE->setText(originalAdresseFourn);
    ui->TypeService->setText(originalTypeServiceFourn);

    modificationInProgressFourn = true; // Définir le flag quand la modification commence
}

void MainWindow::on_SaveMod_2_clicked() {
    if (!modificationInProgressFourn) {
        QMessageBox::warning(this, "Erreur", "Veuillez d'abord sélectionner un fournisseur à modifier.");
        return;
    }

    QString nom = ui->Nom->text().trimmed();
    QString adresse = ui->ADRESSE->text().trimmed();
    QString email = ui->Email->text().trimmed();
    int numTel = ui->NumTel->text().toInt();
    QString typeService = ui->TypeService->text().trimmed().toLower();

    // Vérification du type de service
    if (typeService != "informatique" && typeService != "bureautique" && typeService != "maintenance") {
        QMessageBox::warning(this, "Erreur", "Le type de service doit être : Informatique, Bureautique ou Maintenance.");
        return;
    }

    // Capitaliser la première lettre (optionnel)
    typeService[0] = typeService[0].toUpper();

    Fournisseur f(currentIdFourn, nom, adresse, email, numTel, typeService);

    if (f.modifierFourn(currentIdFourn)) {
        QMessageBox::information(this, "Modification", "Fournisseur modifié avec succès !");
        updateTableView_Fourn();
        modificationInProgressFourn = false;
    } else {
        QMessageBox::critical(this, "Erreur", "La modification a échoué.");
    }
}


void MainWindow::on_rechBtn_5_clicked()
{
    QString id = ui->lineEditRech_4->text().trimmed();

    if (id.isEmpty()) {
        QMessageBox::warning(this, "Recherche", "Veuillez entrer un ID !");
        return;
    }

    QSqlQueryModel *searchModel = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * FROM FOURNISSEURS WHERE ID_FOURNISSEUR = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur SQL", "Échec de la requête : " + query.lastError().text());
        return;
    }

    searchModel->setQuery(std::move(query));
    ui->tableFourn->setModel(searchModel);
    ui->tableFourn->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableFourn->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}


void MainWindow::on_EnvBtn_clicked()
{
    qDebug() << "➡️ Début de l'envoi de l'email via cURL...";

    QString sender = "ddahmeni2.dali@gmail.com";
    QString password = "kbge ylvc ckpl ykmg";
    QString recipient = ui->lineEdit_2->text();
    QString subject = ui->lineEdit_3->text();
    QString body = ui->textEdit->toPlainText();

    // Création du fichier email temporaire
    QString emailFilePath = QCoreApplication::applicationDirPath() + "/email.txt";
    QFile file(emailFilePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << "From: \"Smart Examination Center\" <" << sender << ">\n";
        out << "To: <" << recipient << ">\n";
        out << "Subject: " << subject << "\n\n";
        out << body << "\n";
        file.close();
    } else {
        QMessageBox::critical(this, "Erreur", "Impossible de créer le fichier email.");
        return;
    }

    // Préparation de la commande curl avec paramètres SSL/TLS mis à jour
    QStringList arguments;
    arguments << "--url" << "smtps://smtp.gmail.com:465"
              << "--ssl-reqd"
              << "--mail-from" << sender
              << "--mail-rcpt" << recipient
              << "--user" << sender + ":" + password
              << "--upload-file" << emailFilePath
              << "--insecure" // Ajouté pour contourner temporairement la vérification SSL
              << "--tlsv1.2"; // Force l'utilisation de TLS 1.2

    QProcess *curl = new QProcess(this);
    curl->start("curl", arguments);

    connect(curl, &QProcess::readyReadStandardOutput, [=]() {
        qDebug() << "📤 Réponse curl :" << curl->readAllStandardOutput();
    });

    connect(curl, &QProcess::readyReadStandardError, [=]() {
        qDebug() << "⚠️ Erreur curl :" << curl->readAllStandardError();
    });

    connect(curl, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
            [=](int exitCode, QProcess::ExitStatus status) {
                if (exitCode == 0) {
                    QMessageBox::information(this, "Succès", "📧 Email envoyé avec succès ");
                    // Enregistrement dans la base de données
                    QSqlQuery insertQuery;
                    insertQuery.prepare("INSERT INTO EMAILS (DESTINATAIRE, SUJET, CONTENU) "
                                        "VALUES (:destinataire, :sujet, :contenu)");

                    insertQuery.bindValue(":destinataire", ui->lineEdit_2->text());
                    insertQuery.bindValue(":sujet", ui->lineEdit_3->text());
                    insertQuery.bindValue(":contenu", ui->textEdit->toPlainText());

                    if (!insertQuery.exec()) {
                        qDebug() << "❌ Échec insertion Oracle : " << insertQuery.lastError().text();
                    } else {
                        qDebug() << "✅ Email enregistré dans la table EMAILS.";
                    }
                } else {
                    QMessageBox::critical(this, "Erreur", "Échec de l'envoi de l'email. Code: " + QString::number(exitCode));
                }
                curl->deleteLater();
            });
}




void MainWindow::on_btnAfficherTout_clicked()
{
    updateTableView_Fourn();
}


void MainWindow::on_btnTrierNom_clicked()
{
    QSqlQueryModel *triModel = new QSqlQueryModel();

    triModel->setQuery("SELECT * FROM fournisseurs ORDER BY NOM_FOURNISSEUR ASC");

    if (triModel->lastError().isValid()) {
        QMessageBox::critical(this, "Erreur SQL", triModel->lastError().text());
        return;
    }

    ui->tableFourn->setModel(triModel);
    model_Fourn = triModel;

    actualiserTableView_Fourn();
}



void MainWindow::on_pdfBtn_4_clicked() {
    QString fileName = QFileDialog::getSaveFileName(this, "Enregistrer en PDF", "", "Fichiers PDF (*.pdf)");
    if (fileName.isEmpty())
        return;

    QPdfWriter writer(fileName);
    writer.setPageSize(QPageSize(QPageSize::A4));
    writer.setResolution(300);  // haute qualité

    QTextDocument doc;

    QString html;

    // Logo centré
    html += "<div align='center'><img src=':/img/logo.png' width='120'/></div>";

    // Titre
    html += "<h1 align='center' style='color:#2C3E50;'>Liste des Fournisseurs</h1>";

    // CSS stylé pour grandir les éléments
    html += R"(
    <style>
        table {
            width: 95%;
            border-collapse: collapse;
            font-size: 18px;
            margin: 20px auto;
        }
        th, td {
            border: 1px solid #000;
            padding: 12px;
            text-align: center;
        }
        th {
            background-color: #dfeaf5;
            color: #2C3E50;
            font-weight: bold;
        }
        tr:nth-child(even) {
            background-color: #f8f8f8;
        }
    </style>
    )";

    // En-tête du tableau
    html += "<table>";
    html += "<tr><th>ID</th><th>Nom</th><th>Téléphone</th><th>Email</th><th>Adresse</th><th>Type de service</th></tr>";

    // Contenu
    for (int row = 0; row < ui->tableFourn->model()->rowCount(); ++row) {
        html += "<tr>";
        for (int col = 0; col < ui->tableFourn->model()->columnCount(); ++col) {
            QString data = ui->tableFourn->model()->data(ui->tableFourn->model()->index(row, col)).toString();
            html += "<td>" + data.toHtmlEscaped() + "</td>";
        }
        html += "</tr>";
    }
    html += "</table>";

    doc.setHtml(html);
    doc.setPageSize(QSizeF(writer.width(), writer.height()));  // adapte à la page

    QPainter painter(&writer);
    doc.drawContents(&painter);
    painter.end();

    QMessageBox::information(this, "PDF", "✅ Le fichier PDF a été généré avec succès !");
    QDesktopServices::openUrl(QUrl::fromLocalFile(fileName));
}


//statDah
void MainWindow::showStatistiques_Fourn(const QString& critere) {

        qDebug() << ":bar_chart: Updating Fournisseur Statistics for" << critere;

        if (!ui->ContainerFourn) {
            qDebug() << ":x: ContainerFourn is NULL!";
            return;
        }

        QLayout *layout = ui->ContainerFourn->layout();
        if (!layout) {
            layout = new QVBoxLayout(ui->ContainerFourn);
            layout->setContentsMargins(0, 0, 0, 0);
            ui->ContainerFourn->setLayout(layout);
        }

        while (QLayoutItem *item = layout->takeAt(0)) {
            if (QWidget *widget = item->widget()) {
                widget->deleteLater();
            }
            delete item;
        }

        Fournisseur f;
        QMap<QString, int> stats;

        if (critere == "Type de Service") {
            stats = f.getStatistiquesParTypeService();
        } else if (critere == "Adresse") {
            stats = f.getStatistiquesParAdresse();
        } else {
            QLabel *label = new QLabel("Critère non reconnu.");
            layout->addWidget(label);
            return;
        }

        if (stats.isEmpty()) {
            QLabel *label = new QLabel("Aucune donnée disponible pour ce critère.");
            layout->addWidget(label);
            return;
        }

        QPieSeries *pieSeries = new QPieSeries();
        int total = 0;
        for (const auto &count : stats.values()) {
            total += count;
        }

        for (auto it = stats.begin(); it != stats.end(); ++it) {
            double percentage = (total > 0) ? (it.value() * 100.0 / total) : 0;
            QPieSlice *slice = pieSeries->append(it.key(), it.value());
            slice->setLabel(QString("%1: %2%").arg(it.key()).arg(percentage, 0, 'f', 1));
            slice->setLabelVisible(true);
            connect(slice, &QPieSlice::hovered, [slice](bool hovered) {
                slice->setExploded(hovered);
                slice->setLabelFont(QFont("Arial", hovered ? 12 : 10, hovered ? QFont::Bold : QFont::Normal));
            });
        }

        QChart *chart = new QChart();
        chart->addSeries(pieSeries);
        chart->setTitle("Répartition par " + critere);
        chart->setTheme(QChart::ChartThemeLight);

        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        chartView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

        layout->addWidget(chartView);
        qDebug() << ":white_check_mark: Statistiques affichées pour :" << critere;


}


//ARDUINO DAH

/*void MainWindow::verifierEtEnvoyerCode()
{
    QString code = QInputDialog::getText(this, "Code Candidat", "Entrez le code candidat (10 chiffres) :");

    if (code.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "⚠️ Aucun code saisi.");
        return;
    }

    // Vérifie que le code est exactement 10 chiffres
    QRegularExpression regex("^\\d{10}$");
    if (!regex.match(code).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "❌ Le code doit contenir exactement 10 chiffres.");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT nom_candidat, prenom_candidat FROM CANDIDAT WHERE code_candidat = :code");
    query.bindValue(":code", code);

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur SQL", query.lastError().text());
        return;
    }

    QString message;

    if (!query.next()) {
        // Candidat introuvable ➔ envoyer INTROUVABLE propre
        message = "INTROUVABLE;";
    } else {
        QString nom = query.value(0).toString().simplified();
        QString prenom = query.value(1).toString().simplified();
        message = nom + ";" + prenom;
    }

    // Vérifie que COM5 est disponible
    bool portTrouve = false;
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        if (info.portName() == "COM5") {
            portTrouve = true;
            break;
        }
    }

    if (!portTrouve) {
        QMessageBox::critical(this, "Erreur", "❌ Arduino non détecté sur COM5.");
        return;
    }

    // Envoi via port série
    QSerialPort serial;
    serial.setPortName("COM5");
    serial.setBaudRate(QSerialPort::Baud9600);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);

    if (!serial.open(QIODevice::WriteOnly)) {
        QMessageBox::critical(this, "Erreur Port", "❌ Impossible d’ouvrir COM5 : " + serial.errorString());
        return;
    }

    // ✅ Nettoyage et envoi
    message = message.trimmed();
    serial.write(message.toUtf8() + '\n');
    serial.flush();
    serial.close();

    QMessageBox::information(this, "Succès", "📤 Message envoyé à l’Arduino : " + message);
}*/


//etablissement

void MainWindow::updatetableView_Eta()
{
    QSqlQueryModel *model_Eta = Etablissement().afficherEta();
    ui->tableView_Eta->setModel(model_Eta);
    ui->tableView_Eta->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}


void MainWindow::on_Ajteta_3_clicked()
{
    // Récupérer les valeurs des champs de saisie
    QString id = ui->idEtablissementLineEdit_3->text();
    QString gouvernorat = ui->gouvernoratLineEdit_3->text();
    QString type = ui->typeLineEdit_3->currentText();
    QString directeur = ui->directeurLineEdit_3->text();
    QString nom = ui->nomLineEdit_3->text();
    int nombreSalle = ui->nombreSalleLineEdit_3->text().toInt();
    QString ville = ui->villeLineEdit_3->text();
    QString adresse = ui->adresseLineEdit_3->text(); // Nouveau champ
    QString id_superviseur = ui->idSuperviseurLineEdit_3->text();
    QString id_equipement = ui->idEquipementLineEdit_3->text();

    // Vérifier que tous les champs sont remplis
    if (id.isEmpty() || gouvernorat.isEmpty() || type.isEmpty() || directeur.isEmpty() ||
        nom.isEmpty() || ville.isEmpty() || adresse.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis.");
        return;
    }
    if (nombreSalle <= 0)
    {
        QMessageBox::warning(this, "Erreur", "Le nombre de salles doit être supérieur à 0.");
        ui->nombreSalleLineEdit_3->setFocus();
        return;
    }

    // Créer un objet Etablissement
    Etablissement E(id, gouvernorat, type, directeur, nom, nombreSalle, ville, adresse,
                    selectedImagePath, id_superviseur, id_equipement);

    // Ajouter l'établissement à la base de données
    if (E.ajouterEta())
    {
        QMessageBox::information(this, "Succès", "Établissement ajouté avec succès !");
        updatetableView_Eta();  // Mettre à jour le tableau
    }
    else
    {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout de l'établissement.");
    }
}

// Supprimer un établissement
void MainWindow::on_Binetabtn_clicked()
{
    // Récupérer l'index de la ligne sélectionnée dans le tableau
    QModelIndex index = ui->tableView_Eta->selectionModel()->currentIndex();
    if (!index.isValid())
    {
        QMessageBox::warning(this, "Suppression", "Veuillez sélectionner un établissement à supprimer.");
        return;
    }

    // Récupérer l'ID de l'établissement sélectionné
    QString id = ui->tableView_Eta->model()->data(index).toString();

    // Supprimer l'établissement de la base de données
    if (E.supprimerEta(id))
    {
        QMessageBox::information(this, "Succès", "Établissement supprimé avec succès !");
        updatetableView_Eta();  // Mettre à jour le tableau
    }
    else
    {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression.");
    }
}

void MainWindow::on_Modeta_clicked() {
    QModelIndex index = ui->tableView_Eta->selectionModel()->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Modification", "Veuillez sélectionner un établissement à modifier.");
        return;
    }

    QSqlQueryModel *model_Eta = qobject_cast<QSqlQueryModel*>(ui->tableView_Eta->model());
    if (!model_Eta) return;

    int row = index.row();
    currentIdEta = model_Eta->data(model_Eta->index(row, 0)).toString();
    currentGouvernoratEta = model_Eta->data(model_Eta->index(row, 1)).toString();
    currentTypeEta = model_Eta->data(model_Eta->index(row, 2)).toString();
    currentDirecteurEta = model_Eta->data(model_Eta->index(row, 3)).toString();
    currentNomEta = model_Eta->data(model_Eta->index(row, 4)).toString();
    currentNbSEta = model_Eta->data(model_Eta->index(row, 5)).toInt(); // Utilisez currentNbSEta
    currentVilleEta = model_Eta->data(model_Eta->index(row, 6)).toString();
    currentAdresseEta = model_Eta->data(model_Eta->index(row, 7)).toString();
    currentIdSuperviseurEta = model_Eta->data(model_Eta->index(row, 9)).toString();
    currentIdEquipementEta = model_Eta->data(model_Eta->index(row, 10)).toString();

    ui->idEtablissementLineEdit_3->setText(currentIdEta);
    ui->gouvernoratLineEdit_3->setText(currentGouvernoratEta);
    ui->typeLineEdit_3->setCurrentText(currentTypeEta);
    ui->directeurLineEdit_3->setText(currentDirecteurEta);
    ui->nomLineEdit_3->setText(currentNomEta);
    ui->nombreSalleLineEdit_3->setText(QString::number(currentNbSEta));
    ui->villeLineEdit_3->setText(currentVilleEta);
    ui->adresseLineEdit_3->setText(currentAdresseEta);
    ui->idSuperviseurLineEdit_3->setText(currentIdSuperviseurEta);
    ui->idEquipementLineEdit_3->setText(currentIdEquipementEta);
}
// Sauvegarder les modifications
void MainWindow::on_Saveta_3_clicked()
{
    // Récupérer les nouvelles valeurs des champs de saisie
    QString id = ui->idEtablissementLineEdit_3->text();
    QString gouvernorat = ui->gouvernoratLineEdit_3->text();
    QString type = ui->typeLineEdit_3->currentText();
    QString directeur = ui->directeurLineEdit_3->text();
    QString nom = ui->nomLineEdit_3->text();
    int nombreSalle = ui->nombreSalleLineEdit_3->text().toInt();
    QString ville = ui->villeLineEdit_3->text();
    QString adresse = ui->adresseLineEdit_3->text();
    QString id_superviseur = ui->idSuperviseurLineEdit_3->text();
    QString id_equipement = ui->idEquipementLineEdit_3->text();

    // Vérifier que tous les champs sont remplis
    if (id.isEmpty() || gouvernorat.isEmpty() || type.isEmpty() || directeur.isEmpty() || nom.isEmpty() || ville.isEmpty())
    {
        QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis.");
        return;
    }
    if (nombreSalle <= 0)
    {
        QMessageBox::warning(this, "Erreur", "Le nombre de salles doit être supérieur à 0.");
        ui->nombreSalleLineEdit_3->setFocus();
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
    E.setAdresse(adresse);
    E.setImagePath(selectedImagePath);
    E.setIdSuperviseur(id_superviseur);
    E.setIdEquipement(id_equipement);
    // Modifier l'établissement dans la base de données
    if (E.modifierEta())
    {
        QMessageBox::information(this, "Succès", "Établissement modifié avec succès !");
        updatetableView_Eta();  // Mettre à jour le tableau
    }
    else
    {
        QMessageBox::critical(this, "Erreur", "Échec de la modification.");
    }
}
void MainWindow::on_neweta_clicked()
{
    // Vider tous les champs de saisie
    ui->idEtablissementLineEdit_3->clear();
    ui->gouvernoratLineEdit_3->clear();
    ui->typeLineEdit_3->setCurrentIndex(0);
    ui->directeurLineEdit_3->clear();
    ui->nomLineEdit_3->clear();
    ui->nombreSalleLineEdit_3->clear();
    ui->villeLineEdit_3->clear();
    ui->nombreSalleLineEdit_3->setText("1");
    ui->adresseLineEdit_3->clear();
    ui->idSuperviseurLineEdit_3->clear();
    ui->idEquipementLineEdit_3->clear();



    // Réinitialiser l'objet E (optionnel mais recommandé)
    E = Etablissement();

    // Donner le focus au premier champ pour une meilleure UX
    ui->idEtablissementLineEdit_3->setFocus();

}
void MainWindow::setupGovernorateStats()
{
    qDebug() << ":bar_chart: Updating Governorate Statistics...";

    // Vérifie si le conteneur est défini
    if (!ui->statsContainer) {
        qDebug() << ":x: ERROR: statsContainer is NULL!";
        return;
    }

    // Nettoyage de l'ancien contenu
    if (ui->statsContainer->layout()) {
        QLayout *layout = ui->statsContainer->layout();
        while (QLayoutItem *item = layout->takeAt(0)) {
            if (QWidget *widget = item->widget()) {
                widget->deleteLater();
            }
            delete item;
        }
    } else {
        ui->statsContainer->setLayout(new QVBoxLayout());
    }

    // Préparation de la requête SQL
    QSqlQuery query;
    query.prepare("SELECT GOUVERNORAT_ETABLISSEMENT, COUNT(*) FROM ETABLISSEMENT GROUP BY GOUVERNORAT_ETABLISSEMENT");

    if (!query.exec()) {
        qDebug() << ":x: ERROR while executing query:" << query.lastError().text();
        return;
    }

    QPieSeries *series = new QPieSeries();
    int total = 0;
    QList<QPair<QString, int>> data;

    // Collecte des données
    while (query.next()) {
        QString governorate = query.value(0).toString();
        int count = query.value(1).toInt();
        total += count;
        data.append(qMakePair(governorate, count));
    }

    if (data.isEmpty()) {
        qDebug() << ":warning: WARNING: No governorate data found!";
        QLabel *label = new QLabel("Aucune donnée à afficher");
        ui->statsContainer->layout()->addWidget(label);
        return;
    }

    // Ajout des tranches à la série
    for (const auto& pair : data) {
        double percentage = (total > 0) ? (pair.second * 100.0 / total) : 0;
        QPieSlice *slice = series->append(pair.first, pair.second);

        slice->setLabel(QString("%1: %2%").arg(pair.first).arg(percentage, 0, 'f', 1));
        slice->setLabelVisible(true);

        connect(slice, &QPieSlice::hovered, [slice](bool hovered) {
            slice->setExploded(hovered);
            slice->setLabelFont(QFont("Arial", hovered ? 12 : 10, hovered ? QFont::Bold : QFont::Normal));
        });
    }

    // Création du graphique
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des établissements par gouvernorat");
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight);
    chart->setAnimationOptions(QChart::AllAnimations);  // Animation fluide

    // Vue du graphique
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Ajout à l'interface
    ui->statsContainer->layout()->addWidget(chartView);

    qDebug() << ":white_check_mark: Governorate Statistics Updated Successfully!";
}


void MainWindow::on_tableView_Eta_clicked(const QModelIndex &index)
{
    // Vérifier si on a cliqué sur la colonne de l'image (colonne 8)
    if (index.column() == 8) {
        QString imagePath = ui->tableView_Eta->model()->data(index).toString();
        if (!imagePath.isEmpty()) {
            displayImage(imagePath);
        }
    }
}

// Méthode pour afficher l'image
void MainWindow::displayImage(const QString &imagePath)
{
    if (imagePath.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Aucune image sélectionnée");
        return;
    }

    Etablissement temp;
    temp.setImagePath(imagePath);

    if (temp.isPanoramic()) {
        PanoramicViewer viewer(imagePath, this);
        viewer.exec();
    } else {
        QDialog dialog(this);
        dialog.setWindowTitle("Image de l'établissement");
        QLabel label(&dialog);

        QPixmap pix(imagePath);
        if (pix.isNull()) {
            label.setText("Impossible de charger l'image");
        } else {
            label.setPixmap(pix.scaled(800, 600, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        }

        QVBoxLayout layout(&dialog);
        layout.addWidget(&label);
        dialog.setLayout(&layout);
        dialog.exec();
    }
}
void MainWindow::on_searchDirector_2_textChanged(const QString &text)
{
    QSqlQueryModel *model_Eta = new QSqlQueryModel();

    if (text.isEmpty()) {
        // Si le champ de recherche est vide, afficher tous les établissements
        model_Eta->setQuery("SELECT * FROM ETABLISSEMENT");
    } else {
        // Recherche avec filtre sur le directeur
        QSqlQuery query;
        query.prepare("SELECT * FROM ETABLISSEMENT WHERE DIRECTEUR_ETABLISSEMENT LIKE :directeur");
        query.bindValue(":directeur", "%" + text + "%");

        if (query.exec()) {
            model_Eta->setQuery(std::move(query));
        } else {
            qDebug() << "Erreur de recherche:" << query.lastError().text();
            return;
        }
    }

    // Définir les en-têtes comme dans Etablissement::afficher()
    model_Eta->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model_Eta->setHeaderData(1, Qt::Horizontal, QObject::tr("Gouvernorat"));
    model_Eta->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
    model_Eta->setHeaderData(3, Qt::Horizontal, QObject::tr("Directeur"));
    model_Eta->setHeaderData(4, Qt::Horizontal, QObject::tr("Nom"));
    model_Eta->setHeaderData(5, Qt::Horizontal, QObject::tr("Nombre de Salles"));
    model_Eta->setHeaderData(6, Qt::Horizontal, QObject::tr("Ville"));

    ui->tableView_Eta->setModel(model_Eta);
}


void MainWindow::on_sortGovernorateBtn_clicked()
{
    QSqlQueryModel *model_Eta = qobject_cast<QSqlQueryModel*>(ui->tableView_Eta->model());

    if (!model_Eta) {
        model_Eta = new QSqlQueryModel(this);
        model_Eta->setQuery("SELECT * FROM ETABLISSEMENT ORDER BY GOUVERNORAT_ETABLISSEMENT ASC");
    } else {
        // Si le modèle existe déjà, on le réutilise avec un nouveau tri
        model_Eta->setQuery("SELECT * FROM ETABLISSEMENT ORDER BY GOUVERNORAT_ETABLISSEMENT ASC",
                        QSqlDatabase::database());
    }

    // Définir les en-têtes
    model_Eta->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model_Eta->setHeaderData(1, Qt::Horizontal, tr("Gouvernorat"));
    model_Eta->setHeaderData(2, Qt::Horizontal, tr("Type"));
    model_Eta->setHeaderData(3, Qt::Horizontal, tr("Directeur"));
    model_Eta->setHeaderData(4, Qt::Horizontal, tr("Nom"));
    model_Eta->setHeaderData(5, Qt::Horizontal, tr("Nb Salles"));
    model_Eta->setHeaderData(6, Qt::Horizontal, tr("Ville"));
    model_Eta->setHeaderData(7, Qt::Horizontal, tr("Adresse"));


    ui->tableView_Eta->setModel(model_Eta);
}

void MainWindow::on_exportPdfBtn_2_clicked()
{
// Vérifier que le module printsupport est disponible
#ifndef QT_PRINTSUPPORT_LIB
    QMessageBox::warning(this, "Erreur", "La fonction d'export PDF nécessite le module Qt PrintSupport");
    return;
#endif

    QString fileName = QFileDialog::getSaveFileName(
        this,
        "Exporter en PDF",
        QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation),
        "Fichiers PDF (*.pdf)"
        );

    if (fileName.isEmpty()) {
        return;
    }

    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    QString html = "<h1>Liste des établissements</h1><table border='1'>";

    // En-têtes
    html += "<tr>";
    QSqlQueryModel *model_Eta = qobject_cast<QSqlQueryModel*>(ui->tableView_Eta->model());
    for (int col = 0; col < model_Eta->columnCount(); ++col) {
        html += "<th>" + model_Eta->headerData(col, Qt::Horizontal).toString() + "</th>";
    }
    html += "</tr>";

    // Données
    for (int row = 0; row < model_Eta->rowCount(); ++row) {
        html += "<tr>";
        for (int col = 0; col < model_Eta->columnCount(); ++col) {
            html += "<td>" + model_Eta->data(model_Eta->index(row, col)).toString() + "</td>";
        }
        html += "</tr>";
    }
    html += "</table>";

    doc.setHtml(html);
    doc.print(&printer);

    QMessageBox::information(this, "Export réussi",
                             "Le tableau a été exporté au format PDF avec succès !");
}





void MainWindow::on_mapsButton_clicked()
{
    if (!mapView) {
        mapView = new QQuickView;
        mapView->setSource(QUrl(QStringLiteral("qrc:/map.qml")));
        mapView->setResizeMode(QQuickView::SizeRootObjectToView);
        mapView->setColor(QColor(1, 121, 111));
        mapView->setWidth(800);
        mapView->setHeight(500);
        mapView->setTitle("Chercher une adresse");
    }

    mapView->show();
}

void MainWindow::on_selectImageBtn_3_clicked() {
    showImageSelectionDialog();
}

// Méthode pour afficher la boîte de dialogue de sélection d'image :
void MainWindow::showImageSelectionDialog() {
    QDialog dialog(this);
    dialog.setWindowTitle("Sélectionner une image");
    dialog.setFixedSize(600, 400);

    QVBoxLayout *layout = new QVBoxLayout(&dialog);

    // Liste des images disponibles dans les ressources
    QStringList imagePaths;
    QDirIterator it("C:/DossierIntegration/etablissements/", {"*.jpg", "*.png", "*.jpeg"}, QDir::Files);
    while (it.hasNext()) {
        imagePaths << it.next();
    }

    QListWidget *imageList = new QListWidget(&dialog);
    imageList->setViewMode(QListWidget::IconMode);
    imageList->setIconSize(QSize(100, 100));
    imageList->setResizeMode(QListWidget::Adjust);

    for (const QString &path : imagePaths) {
        QListWidgetItem *item = new QListWidgetItem(QIcon(path), QFileInfo(path).fileName());
        item->setData(Qt::UserRole, path);
        imageList->addItem(item);
    }

    layout->addWidget(imageList);

    QPushButton *selectButton = new QPushButton("Sélectionner", &dialog);
    connect(selectButton, &QPushButton::clicked, [&]() {
        QListWidgetItem *selectedItem = imageList->currentItem();
        if (selectedItem) {
            selectedImagePath = selectedItem->data(Qt::UserRole).toString();
            qDebug() << "Image sélectionnée :" << selectedImagePath;
        }
        dialog.close();
    });

    layout->addWidget(selectButton);
    dialog.exec();
}


void MainWindow::afficherImage(const QString &cheminImage)
{
    if(cheminImage.contains("_360")) {
        // Fenêtre 360°
        QDialog fenetre360(this);
        fenetre360.setWindowTitle("Vue 360°");
        fenetre360.resize(800, 400);

        QLabel *label = new QLabel(&fenetre360);
        QPixmap pixmap(cheminImage);
        if(pixmap.isNull()) {
            label->setText("Image non trouvée");
            fenetre360.exec();
            return;
        }

        // Variables pour le défilement
        int positionX = 0;
        //QPoint dernierPoint;

        // Fonction de mise à jour
        auto updateImage = [&]() {
            QPixmap partie = pixmap.copy(positionX, 0, 800, 400);
            label->setPixmap(partie.scaled(fenetre360.width(), fenetre360.height(),
                                           Qt::KeepAspectRatioByExpanding));
        };

        // Configuration initiale
        updateImage();

        // Gestion des événements simplifiée
        label->setMouseTracking(true);
        label->installEventFilter(this);

        fenetre360.exec();
    } else {
        // Image normale
        QDialog fenetreNormale(this);
        fenetreNormale.setWindowTitle("Image");
        QLabel *label = new QLabel(&fenetreNormale);
        QPixmap pix(cheminImage);
        label->setPixmap(pix.scaled(600, 600, Qt::KeepAspectRatio));
        fenetreNormale.exec();
    }
}
bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseMove) {
        if (QLabel *label = qobject_cast<QLabel*>(obj)) {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            static QPoint lastPos;
            int dx = mouseEvent->pos().x() - lastPos.x();
            lastPos = mouseEvent->pos();

            m_positionX = (m_positionX + dx) % m_currentPixmap.width();
            if(m_positionX < 0) m_positionX += m_currentPixmap.width();

            QPixmap visiblePart = m_currentPixmap.copy(m_positionX, 0, 800, 400);
            label->setPixmap(visiblePart.scaled(label->width(), label->height(),
                                                Qt::KeepAspectRatioByExpanding));
            return true;
        }
    }
    return QMainWindow::eventFilter(obj, event);
}

void MainWindow::on_etaButton_2_clicked()
{

        // Afficher la bonne page du stackedWidget
        ui->stackedWidget_3->setCurrentIndex(2);

        // Requête SQL pour récupérer les données
        QSqlQuery query;
        if (!query.exec("SELECT GOUVERNORAT_ETABLISSEMENT, COUNT(*) FROM ETABLISSEMENT GROUP BY GOUVERNORAT_ETABLISSEMENT")) {
            qDebug() << "Erreur lors de l'exécution de la requête:" << query.lastError().text();
            return;
        }

        // Préparer la série pour le pie chart
        QPieSeries *series = new QPieSeries();

        while (query.next()) {
            QString gouvernorat = query.value(0).toString();
            int count = query.value(1).toInt();
            QPieSlice *slice = series->append(gouvernorat + " (" + QString::number(count) + ")", count);
            slice->setLabelVisible();
        }

        // Créer le graphique
        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Répartition des établissements par gouvernorat");
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignRight);
        chart->setAnimationOptions(QChart::AllAnimations);

        // Créer la vue du graphique
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        // Ajouter le graphique dans le container prévu (ex: QFrame appelé statsContainer)
        if (ui->statsContainer) {
            QLayout *layout = ui->statsContainer->layout();
            if (!layout) {
                layout = new QVBoxLayout(ui->statsContainer);
            }

            // Nettoyer les anciens widgets du container
            QLayoutItem *child;
            while ((child = layout->takeAt(0)) != nullptr) {
                delete child->widget();
                delete child;
            }

            layout->addWidget(chartView);
        }
    }



void MainWindow::on_eqButton_2_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(5);
    afficherStatistiquesEquipements();

}

void MainWindow::on_FourButton_2_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(3);

    // Efface le contenu précédent SANS afficher de stats
    QLayout *layout = ui->ContainerFourn->layout();
    if (layout) {
        while (QLayoutItem *item = layout->takeAt(0)) {
            if (QWidget *widget = item->widget()) {
                widget->deleteLater();
            }
            delete item;
        }
    }
}


void MainWindow::on_candButton_2_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(4);
    // 1. Création d’un objet Candidat
    Candidat c;

    // 2. Récupération des statistiques depuis la base de données
    // Cette méthode retourne une requête avec (niveau, nombre de candidats)
    QSqlQuery query = c.statistiquesParNiveau();

    // 3. Création d'une série pour le graphique en camembert
    QPieSeries *series = new QPieSeries();

    // 4. Variables pour stocker les données et calculer le total
    int total = 0;
    QList<QPair<QString, int>> data; // Liste pour stocker les niveaux et leurs comptes

    // 5. Remplir la liste 'data' avec les résultats de la requête
    while (query.next()) {
        QString niveau = query.value(0).toString();  // Le niveau (ex : Bac, 9ème…)
        int nombre = query.value(1).toInt();         // Le nombre de candidats pour ce niveau
        data.append(qMakePair(niveau, nombre));      // Ajoute à la liste
        total += nombre;                             // Incrémente le total des candidats
    }

    // 6. Création des tranches du graphique avec les pourcentages
    for (const QPair<QString, int> &entry : data) {
        QString niveau = entry.first;
        int nombre = entry.second;

        // Calcul du pourcentage pour ce niveau
        qreal pourcentage = (double)nombre / total * 100;

        // Création du label (ex: "Bac: 35.0%")
        QString label = QString("%1: %2%").arg(niveau).arg(QString::number(pourcentage, 'f', 1));

        // Création d'une tranche avec le label et la valeur
        QPieSlice *slice = new QPieSlice(label, nombre);
        slice->setLabelVisible(true); // Affiche le texte sur le graphique

        series->append(slice); // Ajoute la tranche à la série
    }

    // 7. Création du graphique et ajout de la série
    QChart *chart = new QChart();
    chart->addSeries(series);

    // 8. Configuration du titre et de la légende
    chart->setTitle("Répartition des candidats par niveau (%)");
    chart->legend()->setAlignment(Qt::AlignRight); // Légende à droite

    // 9. Affichage du graphique dans le widget prévu (chartStats)
    ui->chartStats->setChart(chart);
    ui->chartStats->setRenderHint(QPainter::Antialiasing); // Pour des bords lisses
}


void MainWindow::on_Ajbtn_2_clicked()
{
    qDebug() << "handleAddFournisseur called";

    // 🔹 Récupérer les valeurs saisies
    QString nom = ui->Nom->text().trimmed();
    QString adresse = ui->ADRESSE->text().trimmed();
    QString email = ui->Email->text().trimmed();
    QString numTelStr = ui->NumTel->text().trimmed();
    QString typeService = ui->TypeService->text().trimmed().toLower();

    if (typeService != "informatique" && typeService != "bureautique" && typeService != "maintenance") {
        QMessageBox::warning(this, "Erreur", "Le type de service doit être : Informatique, Bureautique ou Maintenance.");
        return;
    }


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
    if (fournisseur.ajouterFourn()) {
        QMessageBox::information(this, "Succès", "Fournisseur ajouté avec succès !");
        updateTableView_Fourn();  // 🔹 Rafraîchir la table après ajout
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de l'ajout du fournisseur: " + fournisseur.getLastError().text());
    }
}



void MainWindow::on_ReMod_2_clicked()
{
    updatetableView_Eta();
}


void MainWindow::on_statTypeServ_clicked()
{
    showStatistiques_Fourn("Type de Service");
}


void MainWindow::on_statAdresse_clicked()
{
    showStatistiques_Fourn("Adresse");
}

//LOU

bool MainWindow::verifierSaisie(QString code, QString prenom, int cin, QString adresse, QString nom, int numTel)
{
    // Vérification du code : 4 chiffres non successifs
    QRegularExpression regexCode("^(?!.*(012|123|234|345|456|567|678|789|987|876|765|654|543|432|321|210))\\d{4}$");
    if (!regexCode.match(code).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le code doit contenir 4 chiffres non successifs.");
        return false;
    }

    // Vérification du CIN : Uniquement chiffres
    if (cin <= 0) {
        QMessageBox::warning(this, "Erreur de saisie", "Le CIN doit être un entier positif.");
        return false;
    }

    // Vérification du Nom et Prénom : Uniquement lettres
    QRegularExpression regexNomPrenom("^[a-zA-ZÀ-ÿ\\s]+$");
    if (!regexNomPrenom.match(nom).hasMatch() || !regexNomPrenom.match(prenom).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le nom et le prénom doivent contenir uniquement des lettres.");
        return false;
    }

    // Vérification du numéro de téléphone : 8 chiffres uniquement
    QRegularExpression regexNumTel("^\\d{8}$");
    if (!regexNumTel.match(QString::number(numTel)).hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le numéro de téléphone doit contenir exactement 8 chiffres.");
        return false;
    }

    // Vérification de l'adresse : Non vide
    if (adresse.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "L'adresse ne peut pas être vide.");
        return false;
    }

    return true;
}

void MainWindow::on_AjButton_5_clicked()
{
    QString code = ui->lineCode->text();
    QString prenom = ui->linePrenom->text();
    int cin = ui->lineCIN->text().toInt();
    QString adresse = ui->lineAdresse->text();
    QString nom = ui->lineNom->text();
    int numTel = ui->lineNumTel->text().toInt();
    QString niveau = ui->comboNiveau->currentItem()->text();
    QByteArray photo; // Gestion de la photo plus tard

    // Vérifier la saisie avant d'ajouter
    if (!verifierSaisie(code, prenom, cin, adresse, nom, numTel)) {
        return; // Arrêter l'ajout si la saisie est invalide
    }

    Candidat candidat(code, prenom, cin, adresse, nom, numTel, niveau, photo);
    if (candidat.ajouterCand()) {
        QMessageBox::information(this, "Succès", "Candidat ajouté avec succès.");
        afficherCandidats();  // Mettre à jour la table
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout du candidat.");
    }
}



void MainWindow::afficherCandidats()
{
    QSqlQuery query;
    query.exec("SELECT CODE_CANDIDAT, PRENOM_CANDIDAT, CIN_CANDIDAT, ADRESSE_CANDIDAT, NOM_CANDIDAT, NUMTEL_CANDIDAT, NIVEAU_CANDIDAT FROM CANDIDAT");

    ui->tableView->clearContents(); // Nettoyer le contenu (mais garder les headers)
    ui->tableView->setRowCount(0);  // Réinitialiser les lignes
    ui->tableView->setColumnCount(7);  // Assurer le bon nombre de colonnes

    // Définir les en-têtes de colonnes
    QStringList labels = {"Code", "Prénom", "CIN", "Adresse", "Nom", "NumTel", "Niveau"};
    ui->tableView->setHorizontalHeaderLabels(labels);

    int row = 0;
    while (query.next()) {
        ui->tableView->insertRow(row);
        for (int col = 0; col < 7; col++) {
            QTableWidgetItem* item = new QTableWidgetItem(query.value(col).toString());
            ui->tableView->setItem(row, col, item);
        }
        row++;
    }

    // Ajuster la taille des colonnes et lignes si besoin
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}


void MainWindow::on_btnSupprimer_clicked()
{
    QString code = ui->lineCode->text();

    if (code.isEmpty()) {
        QMessageBox::warning(this, "Attention", "Veuillez entrer un code valide !");
        return;
    }

    // Boîte de confirmation avant suppression
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation", "Voulez-vous vraiment supprimer ce candidat ?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::No) {
        return;
    }

    Candidat c(code, "", 0, "", "", 0, "", QByteArray());
    if (c.supprimerCand(code)) {
        QMessageBox::information(this, "Succès", "Candidat supprimé.");
        afficherCandidats();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression.");
    }
}

void MainWindow::on_ModButton_5_clicked()
{
    QString code = ui->lineCode->text();
    QString prenom = ui->linePrenom->text();
    int cin = ui->lineCIN->text().toInt();
    QString adresse = ui->lineAdresse->text();
    QString nom = ui->lineNom->text();
    int numTel = ui->lineNumTel->text().toInt();
    QString niveau = ui->comboNiveau->currentItem()->text();
    QByteArray photo; // À compléter avec un fichier image

    if (code.isEmpty()) {
        QMessageBox::warning(this, "Attention", "Veuillez entrer un code valide !");
        return;
    }

    Candidat c(code, prenom, cin, adresse, nom, numTel, niveau, photo);
    if (c.modifierCand(code, prenom, cin, adresse, nom, numTel, niveau, photo)) {
        QMessageBox::information(this, "Succès", "Candidat modifié avec succès.");
        afficherCandidats();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification.");
    }
}
void MainWindow::on_lineCode_textChanged(const QString &code)
{
    if (code.isEmpty()) return; // Ne rien faire si le champ est vide

    Candidat c;
    if (c.chercherCandidat(code)) {
        ui->linePrenom->setText(c.getPrenom());
        ui->lineCIN->setText(QString::number(c.getCin()));
        ui->lineAdresse->setText(c.getAdresse());
        ui->lineNom->setText(c.getNom());
        ui->lineNumTel->setText(QString::number(c.getNumTel()));
        QList<QListWidgetItem *> items = ui->comboNiveau->findItems(c.getNiveau(), Qt::MatchExactly);
        if (!items.isEmpty()) {
            ui->comboNiveau->setCurrentItem(items.first());
        }
    } else {
        // Si aucun candidat trouvé, vider les champs
        ui->linePrenom->clear();
        ui->lineCIN->clear();
        ui->lineAdresse->clear();
        ui->lineNom->clear();
        ui->lineNumTel->clear();
        ui->comboNiveau->setCurrentRow(0);
    }
}
void MainWindow::on_btnTrierNiveau_clicked()
{
    // 1. Récupération du niveau sélectionné depuis la comboBox
    QString niveau = ui->comboTriNiveau->currentText().trimmed();

    // 2. Vérifie si un niveau est sélectionné
    if (niveau.isEmpty()) {
        QMessageBox::warning(this, "Avertissement", "Veuillez sélectionner un niveau valide");
        return; // Arrête la fonction si rien n'est sélectionné
    }

    // 3. Prépare le tableau pour l'affichage (vide les anciennes données)
    ui->tableView->setUpdatesEnabled(false); // Empêche les rafraîchissements visuels pendant la mise à jour
    ui->tableView->clearContents();          // Supprime les anciennes cellules
    ui->tableView->setRowCount(0);           // Remet le nombre de lignes à zéro

    // 4. Préparation de la requête SQL avec tri par nom et prénom
    QSqlQuery query;
    query.prepare(
        "SELECT CODE_CANDIDAT, NOM_CANDIDAT, PRENOM_CANDIDAT, CIN_CANDIDAT, "
        "ADRESSE_CANDIDAT, NUMTEL_CANDIDAT, NIVEAU_CANDIDAT "
        "FROM CANDIDAT "
        "WHERE NIVEAU_CANDIDAT = :niveau "
        "ORDER BY NOM_CANDIDAT ASC, PRENOM_CANDIDAT ASC"
        );
    query.bindValue(":niveau", niveau); // Lie la valeur du niveau à la requête

    // Vérifie si la requête SQL s'exécute correctement
    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur",
                              "Erreur lors de la requête :\n" + query.lastError().text());
        ui->tableView->setUpdatesEnabled(true); // Réactive les mises à jour visuelles
        return; // Arrête la fonction
    }

    // 5. Parcourt les résultats de la requête et les ajoute au tableau
    while (query.next()) {
        int row = ui->tableView->rowCount();   // Numéro de la nouvelle ligne
        ui->tableView->insertRow(row);         // Insère une nouvelle ligne

        // Insère chaque champ (colonne) dans le tableau
        for (int col = 0; col < 7; ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
            item->setFlags(item->flags() & ~Qt::ItemIsEditable); // Rend les cellules non éditables
            ui->tableView->setItem(row, col, item);              // Place l'élément dans la cellule
        }
    }

    // 6. Réactive les mises à jour visuelles et ajuste la taille des colonnes
    ui->tableView->setUpdatesEnabled(true);
    ui->tableView->resizeColumnsToContents();

    // 7. Définit les en-têtes du tableau si ce n'est pas encore fait
    if (ui->tableView->horizontalHeader()->count() == 0) {
        QStringList headers = {"Code", "Nom", "Prénom", "CIN", "Adresse", "Téléphone", "Niveau"};
        ui->tableView->setHorizontalHeaderLabels(headers);
    }

    // 8. Affiche un message avec le nombre de candidats trouvés
    QMessageBox::information(this, "Succès",
                             QString("%1 candidats trouvés pour le niveau %2")
                                 .arg(ui->tableView->rowCount()).arg(niveau));
}

void MainWindow::on_btnRechercher_clicked()
{
    // 1. Récupération du code entré dans le champ de texte
    QString code = ui->lineCODECandRech->text();

    // 2. Vérifie si le champ est vide
    if (code.isEmpty()) {
        QMessageBox::warning(this, "Champ vide", "Veuillez entrer un code.");
        return; // Arrête la fonction si le champ est vide
    }

    // 3. Création d’un objet Candidat et exécution de la recherche dans la base
    Candidat c;
    QSqlQuery query = c.chercherParCodeDansTable(code); // Méthode qui retourne un QSqlQuery

    // 4. Nettoyage du tableau avant d’afficher les résultats
    ui->tableView->clearContents(); // Vide les cellules
    ui->tableView->setRowCount(0);  // Réinitialise le nombre de lignes

    // 5. Parcourt les résultats et remplit le tableau
    int row = 0; // Compteur de lignes
    while (query.next()) {
        ui->tableView->insertRow(row); // Insère une nouvelle ligne
        for (int col = 0; col < 7; col++) {
            // Crée un nouvel item avec la valeur de la colonne et l’ajoute à la cellule
            ui->tableView->setItem(row, col, new QTableWidgetItem(query.value(col).toString()));
        }
        row++; // Passe à la ligne suivante
    }

    // 6. Si aucun résultat trouvé, affiche un message
    if (row == 0) {
        QMessageBox::information(this, "Introuvable", "Aucun candidat trouvé avec ce code.");
    }
}



void MainWindow::on_btnpdf_clicked()
{
    // 1. Configuration du fichier
    QString filePath = QFileDialog::getSaveFileName(
        this,
        "Enregistrer la liste",
        QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/liste_candidats.pdf",
        "PDF Files (*.pdf)"
        );
    if (filePath.isEmpty()) return;

    // 2. Initialisation PDF
    QPdfWriter pdfWriter(filePath);
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));
    pdfWriter.setResolution(300);

    QPainter painter(&pdfWriter);
    if (!painter.isActive()) {
        QMessageBox::critical(this, "Erreur", "Échec de création du PDF");
        return;
    }

    // 3. Paramètres de mise en page
    const int margin = 40;
    const int pageWidth = pdfWriter.width() - 2*margin;
    int yPos = margin;
    const int rowHeight = 30;
    const int headerHeight = 35;

    // Configuration des colonnes
    struct Column {
        QString title;
        double width;
        Qt::Alignment alignment;
    };

    QVector<Column> columns = {
        {"Code", 0.15, Qt::AlignCenter},
        {"Nom", 0.25, Qt::AlignLeft},
        {"Prénom", 0.25, Qt::AlignLeft},
        {"CIN", 0.15, Qt::AlignRight},
        {"Téléphone", 0.10, Qt::AlignRight},
        {"Niveau", 0.10, Qt::AlignCenter}
    };

    // 4. En-tête principal
    painter.setFont(QFont("Arial", 18, QFont::Bold));
    painter.drawText(0, yPos, pdfWriter.width(), 50, Qt::AlignCenter, "LISTE DES CANDIDATS");
    yPos += 60;

    // 5. Fonction pour dessiner les en-têtes
    auto drawHeaders = [&]() {
        painter.setFont(QFont("Arial", 10, QFont::Bold));
        painter.setBrush(QColor(70, 130, 180)); // SteelBlue
        painter.setPen(Qt::white);

        int x = margin;
        for (const Column &col : columns) {
            int width = pageWidth * col.width;
            painter.drawRect(x, yPos, width, headerHeight);
            painter.drawText(x, yPos, width, headerHeight,
                             Qt::AlignCenter, col.title);
            x += width;
        }
        yPos += headerHeight;
    };

    // 6. Récupération des données
    QSqlQuery query("SELECT CODE_CANDIDAT, NOM_CANDIDAT, PRENOM_CANDIDAT, "
                    "CIN_CANDIDAT, NUMTEL_CANDIDAT, NIVEAU_CANDIDAT "
                    "FROM CANDIDAT ORDER BY NOM_CANDIDAT, PRENOM_CANDIDAT");

    // 7. Remplissage des données
    bool alternateRow = false;
    drawHeaders();
    painter.setFont(QFont("Arial", 9));
    painter.setPen(Qt::black);

    while (query.next()) {
        // Nouvelle page si nécessaire
        if (yPos > pdfWriter.height() - 100) {
            pdfWriter.newPage();
            yPos = margin;
            drawHeaders();
            alternateRow = false;
        }

        // Couleur alternative
        painter.setBrush(alternateRow ? QColor(240, 248, 255) : Qt::white); // AliceBlue alterné
        alternateRow = !alternateRow;

        // Dessin des cellules
        int x = margin;
        for (int i = 0; i < columns.size(); ++i) {
            int width = pageWidth * columns[i].width;
            painter.drawRect(x, yPos, width, rowHeight);

            // Texte avec padding et alignement spécifique
            painter.drawText(x + 5, yPos, width - 10, rowHeight,
                             columns[i].alignment | Qt::AlignVCenter,
                             query.value(i).toString());
            x += width;
        }
        yPos += rowHeight;
    }

    painter.end();
    QMessageBox::information(this, "Succès", "PDF généré avec succès");
}


QImage MainWindow::genererQRCodeImage(const QString &contenu, int pixelParModule)
{
    const QrCode qr = QrCode::encodeText(contenu.toUtf8().constData(), QrCode::Ecc::MEDIUM);

    const int size = qr.getSize();
    const int border = 4;
    const int imageSize = (size + border * 2) * pixelParModule;

    QImage image(imageSize, imageSize, QImage::Format_RGB32);
    image.fill(Qt::white);

    QPainter painter(&image);
    painter.setBrush(Qt::black);
    painter.setPen(Qt::NoPen);

    for (int y = 0; y < size; ++y) {
        for (int x = 0; x < size; ++x) {
            if (qr.getModule(x, y)) {
                QRect r((x + border) * pixelParModule, (y + border) * pixelParModule,
                        pixelParModule, pixelParModule);
                painter.drawRect(r);
            }
        }
    }

    return image;
}

bool MainWindow::genererConvocationPDF(const QString &codeCandidat)
{
    // Tu pourras implémenter cette fonction plus tard
    return false;
}

void MainWindow::on_btnConvocation_clicked()
{
    QString code = ui->lineCodecc->text().trimmed();
    if (code.isEmpty()) {
        QMessageBox::warning(this, "Champs vide", "Veuillez entrer un code candidat.");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT NOM_CANDIDAT, PRENOM_CANDIDAT, CIN_CANDIDAT, ADRESSE_CANDIDAT, NUMTEL_CANDIDAT, NIVEAU_CANDIDAT, PHOTO_CANDIDAT FROM CANDIDAT WHERE CODE_CANDIDAT = :code");
    query.bindValue(":code", code);

    if (!query.exec() || !query.next()) {
        QMessageBox::warning(this, "Erreur", "Candidat non trouvé.");
        return;
    }

    QString nom = query.value(0).toString();
    QString prenom = query.value(1).toString();
    QString cin = query.value(2).toString();
    QString adresse = query.value(3).toString();
    QString numtel = query.value(4).toString();
    QString niveau = query.value(5).toString();
    QByteArray photoData = query.value(6).toByteArray();

    QString contenuQR = QString("Candidat: %1 %2\nCIN: %3\nCode: %4\nExamen: Mathématique Centre 51 - 12/06/2025 - 8h - Durée : 3 heures")
                            .arg(nom, prenom, cin, code);

    // ✅ Appel corrigé de la fonction
    QImage qrImage = genererQRCodeImage(contenuQR, 6);  // 6 = taille de chaque module QR

    QByteArray qrBa;
    QBuffer qrBuffer(&qrBa);
    qrBuffer.open(QIODevice::WriteOnly);
    qrImage.save(&qrBuffer, "PNG");
    QString qrBase64 = QString::fromLatin1(qrBa.toBase64());

    QString photoBase64;
    if (!photoData.isEmpty()) {
        QImage image;
        image.loadFromData(photoData);
        QByteArray ba;
        QBuffer buffer(&ba);
        buffer.open(QIODevice::WriteOnly);
        image.save(&buffer, "PNG");
        photoBase64 = QString::fromLatin1(ba.toBase64());
    }

    QString convocation = QString(R"(
        <div style='font-family:Arial; padding:30px; background-color:#ffffff; color:#000000; border:2px solid #3498DB; border-radius:12px;'>
            <div style='text-align:center; margin-bottom:30px;'>
                <h3 style='margin:0;'>République Tunisienne</h3>
                <h3 style='margin:0;'>Ministère de l'Éducation</h3>
                <h2 style='margin-top:15px;'>Convocation Officielle à l'Examen</h2>
            </div>

            <hr style='margin-bottom:20px;' />

            <table style='width:100%;'>
                <tr>
                    <td style='vertical-align:top; width:60%;'>
                        <p><strong>Nom :</strong> %1</p>
                        <p><strong>Prénom :</strong> %2</p>
                        <p><strong>CIN :</strong> %3</p>
                        <p><strong>Adresse :</strong> %4</p>
                        <p><strong>Téléphone :</strong> %5</p>
                        <p><strong>Niveau :</strong> %6</p>
                    </td>
                    <td style='text-align:center;'>
                        %7<br/><br/>
                        <img src='data:image/png;base64,%8' width='150' height='150' style='border:1px solid #999;' />
                        <p style='font-size:11px; color:#555;'>QR Code d'identification</p>
                    </td>
                </tr>
            </table>

            <hr style='margin-top:30px;' />

            <div style='text-align:center; margin-top:20px;'>
                <p style='font-weight:bold;'>Bonne chance à tous les candidats !</p>
                <p style='font-style:italic; font-size:13px; margin:10px 50px;'>
                    “Croyez en vos rêves et ils se réaliseront peut-être. Croyez en vous et ils se réaliseront sûrement.”<br/>
                    – <strong>Martin Luther King</strong>
                </p>
            </div>
        </div>
    )").arg(nom, prenom, cin, adresse, numtel, niveau,
                                   photoBase64.isEmpty() ? "" : QString("<img src='data:image/png;base64,%1' width='150' height='150' style='border-radius:8px; border:1px solid #bbb;' />").arg(photoBase64),
                                   qrBase64);

    ui->textBrowsercc->setStyleSheet("background-color:#ffffff; color:#000000;");
    ui->textBrowsercc->setHtml(convocation);
}
//Akrem
void MainWindow::afficherEquipements() {
    Equipement e;
    QSqlQueryModel *modelEqui = e.afficherEquip();

    if (!modelEqui || modelEqui->rowCount() == 0) {
        qDebug() << "Aucun équipement à afficher.";
        return;
    }

    int rowCount = modelEqui->rowCount();
    int colCount = modelEqui->columnCount();

    // Réinitialiser le tableau
    ui->tableView_2->clear();
    ui->tableView_2->setRowCount(rowCount);
    ui->tableView_2->setColumnCount(colCount);

    // Définir les en-têtes
    QStringList headers;
    headers << "ID" << "Nom" << "Type" << "Statut" << "Quantité";
    ui->tableView_2->setHorizontalHeaderLabels(headers);

    // Remplir les données
    for (int i = 0; i < rowCount; ++i) {
        for (int j = 0; j < colCount; ++j) {
            QTableWidgetItem *item = new QTableWidgetItem(modelEqui->data(modelEqui->index(i, j)).toString());
            ui->tableView_2->setItem(i, j, item);
        }
    }

    // Ajuster les largeurs des colonnes
    ui->tableView_2->setColumnWidth(0, 50);   // ID
    ui->tableView_2->setColumnWidth(1, 100);  // Nom
    ui->tableView_2->setColumnWidth(2, 120);  // Type
    ui->tableView_2->setColumnWidth(3, 100);  // Statut
    ui->tableView_2->setColumnWidth(4, 80);   // Quantité

    // Option: redimensionner les colonnes selon le contenu
    // ui->tableWidget_2->resizeColumnsToContents();

    // Option: étirer la dernière colonne
    // ui->tableWidget_2->horizontalHeader()->setStretchLastSection(true);
}

#include <QInputDialog>
#include <QMessageBox>

void MainWindow::on_BinSuperbtn_2_clicked()
{
    // Prompt user to enter the equipment ID as an integer
    bool ok;
    int equipmentId = QInputDialog::getInt(this, "Supprimer un équipement",
                                           "Entrez l'ID de l'équipement à supprimer :",
                                           0, 0, 10000, 1, &ok);

    // Check if the user clicked OK and entered a valid ID
    if (ok && equipmentId > 0) {
        qDebug() << "ID de l'équipement saisi : " << equipmentId;

        // Create the Equipement object
        Equipement e;

        // Check if the equipment exists using SQL SELECT query
        QSqlQuery query;
        query.prepare("SELECT COUNT(*) FROM EQUIPEMENTS WHERE ID_EQUIPEMENT = :id");
        query.bindValue(":id", equipmentId);  // Bind as an integer

        if (!query.exec()) {
            //qDebug() << "Erreur lors de la vérification de l'existence de l'équipement:" << query.lastError();
            return;
        }

        query.next();
        int count = query.value(0).toInt();

        // If count is 0, equipment does not exist
        if (count == 0) {
            QMessageBox::warning(this, "Erreur", "L'équipement avec cet ID n'existe pas.");
            return;
        }

        // Try to delete the equipment
        if (e.supprimerEquip(equipmentId)) {
            qDebug() << "Équipement supprimé avec succès.";
            afficherEquipements(); // Refresh the display after deletion
            QMessageBox::information(this, "Succès", "L'équipement a été supprimé avec succès.");
        } else {
            qDebug() << "Erreur lors de la suppression.";
            QMessageBox::critical(this, "Erreur", "Une erreur s'est produite lors de la suppression de l'équipement.");
        }
    } else {
        qDebug() << "Aucun ID saisi ou ID invalide.";
    }
}


void MainWindow::on_Ajbtn_4_clicked()
{

        qDebug() << "Bouton 'Ajouter' cliqué.";

        // Input validation
        QString nom = ui->Nom_2->text().trimmed();
        qDebug() << "Nom saisi :" << nom;

        QListWidgetItem *selectedItem = ui->type->currentItem();
        if (!selectedItem) {
            QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un type d'équipement.");
            return;
        }

        QString type = selectedItem->text();
        qDebug() << "Type sélectionné :" << type;

        QString statut = ui->Status->text().trimmed();
        QString quantiteStr = ui->qte->text().trimmed();
        bool ok;
        int quantite = quantiteStr.toInt(&ok);

        if (nom.isEmpty() || statut.isEmpty() || quantiteStr.isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Tous les champs sont obligatoires.");
            return;
        }

        if (!ok || quantite <= 0) {
            QMessageBox::warning(this, "Erreur", "La quantité doit être un nombre entier positif.");
            return;
        }

        // Add equipment
        Equipement e(nom, type, statut, quantite);

        if (e.ajouterEquip()) {
            qDebug() << "Équipement ajouté avec succès.";

            // Clear and refresh the table
            ui->tableView_2->setRowCount(0);
            afficherEquipements(); // Reuse your existing display function

            QMessageBox::information(this, "Succès", "L'équipement a été ajouté avec succès.");
        } else {
            QMessageBox::critical(this, "Erreur", "Erreur lors de l'ajout de l'équipement.");
        }
}

//tri
void MainWindow::on_pushButton_2_clicked()
{

        Equipement e;
        QSqlQueryModel *modelEqui = e.trierParNom();

        if (!modelEqui || modelEqui->rowCount() == 0) {
            QMessageBox::information(this, "Aucun résultat", "Aucun équipement trouvé.");
            return;
        }

        // Clear and setup table
        ui->tableView_2->setRowCount(0);
        ui->tableView_2->setRowCount(modelEqui->rowCount());
        ui->tableView_2->setColumnCount(modelEqui->columnCount());

        // Set headers (adjust according to your actual columns)
        QStringList headers;
        headers << "ID" << "Nom" << "Type" << "Statut" << "Quantité";
        ui->tableView_2->setHorizontalHeaderLabels(headers);

        // Populate data
        for (int i = 0; i < modelEqui->rowCount(); i++) {
            for (int j = 0; j < modelEqui->columnCount(); j++) {
                QString data = modelEqui->data(modelEqui->index(i, j)).toString();
                ui->tableView_2->setItem(i, j, new QTableWidgetItem(data));
            }
        }

        // Adjust column widths
        ui->tableView_2->resizeColumnsToContents();

}

void MainWindow::on_pushButton_22_clicked()
{

        QString nomRecherche = ui->recherche->text().trimmed();
        Equipement e;
        QSqlQueryModel *modelEqui = e.rechercherParNom(nomRecherche);

        if (!modelEqui || modelEqui->rowCount() == 0) {
            QMessageBox::information(this, "Recherche", "Aucun résultat trouvé pour : " + nomRecherche);
            ui->tableView_2->setRowCount(0); // Clear table
            return;
        }

        // Clear and setup table
        ui->tableView_2->setRowCount(0);
        ui->tableView_2->setRowCount(modelEqui->rowCount());
        ui->tableView_2->setColumnCount(modelEqui->columnCount());

        // Set headers
        QStringList headers;
        headers << "ID" << "Nom" << "Type" << "Statut" << "Quantité";
        ui->tableView_2->setHorizontalHeaderLabels(headers);

        // Populate data
        for (int i = 0; i < modelEqui->rowCount(); ++i) {
            for (int j = 0; j < modelEqui->columnCount(); ++j) {
                QString data = modelEqui->data(modelEqui->index(i, j)).toString();
                ui->tableView_2->setItem(i, j, new QTableWidgetItem(data));
            }
        }

        // Adjust column widths
        ui->tableView_2->resizeColumnsToContents();

}


void MainWindow::genererRapportPDF()
{

        // Boîte de dialogue pour choisir l'emplacement d'enregistrement
        QString filePath = QFileDialog::getSaveFileName(this,
                                                        "Enregistrer le rapport PDF",
                                                        QDir::homePath() + "/rapport_equipements.pdf",
                                                        "Fichiers PDF (*.pdf)");

        if (filePath.isEmpty()) {
            QMessageBox::information(this, "Annulé", "L'opération a été annulée.");
            return;
        }

        QPdfWriter pdfWriter(filePath);
        pdfWriter.setPageSize(QPageSize(QPageSize::A4));
        pdfWriter.setResolution(300);
        QPainter painter(&pdfWriter);

        // Marges
        const int marginLeft = 40;
        const int marginTop = 50;
        const int pageWidth = pdfWriter.width() - 2 * marginLeft;

        painter.setFont(QFont("Arial", 20, QFont::Bold));
        painter.setPen(Qt::darkBlue);
        painter.drawText(marginLeft + 100, marginTop + 40, "SmartEval - Rapport des Équipements");

        // Ligne séparatrice
        painter.setPen(QPen(Qt::black, 2));
        painter.drawLine(marginLeft, marginTop + 100, marginLeft + pageWidth, marginTop + 100);

        // Titre tableau
        painter.setFont(QFont("Arial", 14, QFont::Bold));
        painter.drawText(marginLeft, marginTop + 130, "Liste des Équipements");

        // Coordonnées du tableau
        int y = marginTop + 160;
        int rowHeight = 45;

        QVector<int> columnWidths = {
            int(pageWidth * 0.10),  // ID
            int(pageWidth * 0.30),  // Nom
            int(pageWidth * 0.25),  // Type
            int(pageWidth * 0.15),  // Statut
            int(pageWidth * 0.20)   // Quantité
        };

        QStringList headers = {"ID", "Nom", "Type", "Statut", "Quantité"};

        painter.setFont(QFont("Arial", 11, QFont::Bold));
        painter.setPen(Qt::white);
        painter.setBrush(QColor("#2E86C1"));
        int x = marginLeft;
        for (int i = 0; i < headers.size(); ++i) {
            painter.drawRect(x, y, columnWidths[i], rowHeight);
            painter.drawText(x + 10, y + 30, headers[i]);
            x += columnWidths[i];
        }
        y += rowHeight;

        QSqlQuery query;
        if (!query.exec("SELECT ID_EQUIPEMENT, NOM_EQUIPEMENT, TYPE_EQUIPEMENT, STATUT_EQUIPEMENT, QUANTITE__EQUIPEMENT FROM EQUIPEMENTS ORDER BY ID_EQUIPEMENT")) {
            QMessageBox::critical(this, "Erreur SQL", "Impossible de récupérer les équipements: " + query.lastError().text());
            return;
        }

        painter.setFont(QFont("Arial", 10));
        bool isAlternate = false;
        while (query.next()) {
            x = marginLeft;
            painter.setPen(Qt::black);
            painter.setBrush(isAlternate ? QColor("#f5f6fa") : Qt::white);
            isAlternate = !isAlternate;

            for (int i = 0; i < headers.size(); ++i) {
                painter.drawRect(x, y, columnWidths[i], rowHeight);
                painter.drawText(x + 10, y + 28, query.value(i).toString());
                x += columnWidths[i];
            }

            y += rowHeight;

            if (y > pdfWriter.height() - 100) {
                pdfWriter.newPage();
                y = marginTop;
            }
        }

        painter.end();
        QMessageBox::information(this, "Succès", "Le rapport PDF a été généré avec succès !");

}

void MainWindow::on_pdfSuperbtn_2_clicked()
{
    genererRapportPDF();
}

void MainWindow::afficherStatistiquesEquipements()
{
    QSqlQuery query;
    if (!query.exec("SELECT TYPE_EQUIPEMENT, COUNT(*) FROM EQUIPEMENTS GROUP BY TYPE_EQUIPEMENT ORDER BY TYPE_EQUIPEMENT")) {
        QMessageBox::critical(this, "Erreur SQL", "Impossible de récupérer les statistiques des équipements : " + query.lastError().text());
        return;
    }

    QLineSeries *serie = new QLineSeries();
    int index = 0;
    while (query.next()) {
        int nombre = query.value(1).toInt();
        serie->append(index++, nombre);
    }

    QChart *chart = new QChart();
    chart->addSeries(serie);
    chart->setTitle("Courbe du nombre d'équipements par type");
    chart->createDefaultAxes();

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Nettoyer le contenu existant de l'ancien widget si nécessaire
    QLayout *oldLayout = ui->widgetStatEquipements->layout();
    if (oldLayout) {
        QLayoutItem *item;
        while ((item = oldLayout->takeAt(0)) != nullptr) {
            if (item->widget()) delete item->widget();
            delete item;
        }
        delete oldLayout;
    }

    // Ajouter le nouveau graphique dans le widget
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(chartView);
    ui->widgetStatEquipements->setLayout(layout);
}


void MainWindow::rechercheVocale()
{
    QProcess process;

    // Utilise un chemin correct avec des doubles antislashs ou des slashes normaux
    QString pythonScript = "C:/DossierIntegration/speech_to_textEqui.py";

    // Démarre le script Python
    process.start("python", QStringList() << pythonScript);

    if (!process.waitForStarted()) {
        qDebug() << "Erreur : impossible de démarrer le script Python";
        return;
    }

    // Attendre que le script termine
    if (!process.waitForFinished()) {
        qDebug() << "Erreur : le script Python ne s'est pas terminé correctement";
        return;
    }

    // Lire la sortie standard (le texte détecté)
    QString output = process.readAllStandardOutput().trimmed();
    qDebug() << "Texte détecté :" << output;

    // Mettre le texte dans le champ de recherche
    ui->recherche->setText(output);

    // Appeler la fonction de recherche
    on_pushButton_2_clicked();
}

void MainWindow::on_btnRechercheVocale_2_clicked(){
    rechercheVocale();
}





void MainWindow::on_ModifEquip_clicked()
{
    // Prompt user to enter the equipment ID for modification
    bool ok;
    int equipmentId = QInputDialog::getInt(this, "Modifier un équipement",
                                           "Entrez l'ID de l'équipement à modifier :",
                                           0, 0, 10000, 1, &ok);

    // Check if the user clicked OK and entered a valid ID
    if (ok && equipmentId > 0) {
        qDebug() << "ID de l'équipement saisi : " << equipmentId;

        // Create the Equipement object
        Equipement e;

        // Check if the equipment exists using SQL SELECT query
        QSqlQuery query;
        query.prepare("SELECT NOM_EQUIPEMENT, TYPE_EQUIPEMENT, STATUT_EQUIPEMENT, QUANTITE__EQUIPEMENT "
                      "FROM EQUIPEMENTS WHERE ID_EQUIPEMENT = :id");
        query.bindValue(":id", equipmentId);  // Bind as an integer

        if (!query.exec()) {
            //qDebug() << "Erreur lors de la vérification de l'existence de l'équipement:" << query.lastError();
            return;
        }

        // If the equipment exists, populate the form with the data
        if (query.next()) {
            // Populate the fields with the data from the query
            ui->Nom->setText(query.value(0).toString());
            QString type = query.value(1).toString();
            QList<QListWidgetItem *> items = ui->type->findItems(type, Qt::MatchExactly);
            if (!items.isEmpty()) {
                ui->type->setCurrentItem(items.first());  // Set the selected item
            }
            ui->Status->setText(query.value(2).toString());
            ui->qte->setText(query.value(3).toString());

            // Now modify the data once the user confirms the changes
            connect(ui->modifier, &QPushButton::clicked, this, [this, equipmentId]() {
                QString nom = ui->Nom->text();
                QString type = ui->type->currentItem()->text();
                QString statut = ui->Status->text();
                int quantite = ui->qte->text().toInt();

                // Input validation
                if (nom.isEmpty() || statut.isEmpty() || quantite <= 0) {
                    qDebug() << "Erreur: Tous les champs doivent être remplis correctement.";
                    return;
                }

                Equipement e;
                if (e.modifierEquip(equipmentId, nom, type, statut, quantite)) {
                    qDebug() << "Équipement modifié avec succès.";
                    afficherEquipements();  // Refresh the display
                    QMessageBox::information(this, "Succès", "L'équipement a été modifié avec succès.");
                } else {
                    qDebug() << "Erreur lors de la modification de l'équipement.";
                    QMessageBox::critical(this, "Erreur", "Une erreur s'est produite lors de la modification de l'équipement.");
                }
            });
        } else {
            // If the equipment doesn't exist
            QMessageBox::warning(this, "Erreur", "L'équipement avec cet ID n'existe pas.");
        }
    } else {
        qDebug() << "Aucun ID saisi ou ID invalide.";
    }
}


//AKREM + LOU ARDUINO

void MainWindow::readSerialData() {
    // Get the equipment ID from the QLineEdit (manual input),// Récupérer l'ID de l'équipement depuis le QLineEdit (saisie manuelle)
    bool ok;
    QString input = ui->idInputLineEdit->text();  // Retrieve the text entered by the user
    int equipmentId = input.toInt(&ok);  // Try converting the input to an integer
    QSqlQuery updateQuery;

    if (!ok || equipmentId <= 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID valide.");
        return;
    }

    // Fetch the quantity from the database,// Récupérer la quantité depuis la base de données
    QSqlQuery query;
    query.prepare("SELECT QUANTITE__EQUIPEMENT FROM EQUIPEMENTS WHERE ID_EQUIPEMENT = :id");
    query.bindValue(":id", equipmentId);

    if (!query.exec()) {
        return;
    }

    if (!query.next()) {
        return;
    }

    int quantite = query.value(0).toInt();  // Database quantity

    // Read from Arduino
    static QByteArray buffer;
    buffer += A.read_from_arduino();  // Accumulate incoming data

    // Process complete lines
    int endIndex;
    while ((endIndex = buffer.indexOf('\n')) != -1) {
        QByteArray line = buffer.left(endIndex).trimmed();  // Extract one line
        buffer.remove(0, endIndex + 1);  // Remove processed line

        line = line.trimmed();  // Clean line (remove \r, \n, spaces)

        QString text = QString::fromUtf8(line);

        if (text.startsWith("QUANTITE:")) {
            QString quantityStr = text.mid(9);  // Extract number after "QUANTITE:"
            bool ok;
            int quantity = quantityStr.toInt(&ok);  // This can be negative or positive

            if (ok) {
                int newQuantity = quantite + quantity;
                if (newQuantity < 0) {
                    QMessageBox::warning(this, "Erreur", "La quantité ne peut pas être négative.");
                    return;
                }
                ui->qtelabel->setText(QString::number(newQuantity));
                updateQuery.prepare("UPDATE EQUIPEMENTS SET QUANTITE__EQUIPEMENT = :newQuantite WHERE ID_EQUIPEMENT = :id");
                updateQuery.bindValue(":newQuantite", newQuantity);
                updateQuery.bindValue(":id", equipmentId);

                if (updateQuery.exec()) {
                    qDebug() << "✅ Quantity updated successfully in the database.";
                    // Send new quantity back to Arduino
                    QByteArray dataToSend = "NOUVELLE_QUANTITE:" + QByteArray::number(newQuantity) + "\n";
                    A.write_to_arduino(dataToSend);
                    A.getserial()->flush();  // Flush the buffer after sending
                    qDebug() << "📤 Envoyé à Arduino :" << dataToSend;
                } else {
                    qDebug() << "❌ Error updating quantity:" << updateQuery.lastError();
                }
            }
        }

    }
}


void MainWindow::on_Modbtn_3_clicked()
{
    connect(A.getserial(), SIGNAL(readyRead()), this, SLOT(readSerialData()));
}

//Arduino Maram+Yasmine
void MainWindow::updateSerialData()
{
    // Lecture des données depuis l'Arduino
    QByteArray rawData = A2.read_from_arduino();
    serialBuffer += QString::fromUtf8(rawData);

    // Si on a reçu une ligne complète (terminée par \n)
    if (serialBuffer.contains('\n')) {
        QStringList lines = serialBuffer.split('\n');
        QString completeUID = lines.at(0).trimmed().toUpper(); // Prend la première ligne complète
        serialBuffer = lines.size() > 1 ? lines.at(1) : "";    // Stocke le reste pour le prochain traitement

        qDebug() << "UID complet reçu: " << completeUID;

        // Vérification du statut du superviseur
        QSqlQuery query;
        query.prepare("SELECT statut_superviseur FROM superviseurs WHERE LOWER(id_superviseur) = LOWER(:uid)");
        query.bindValue(":uid", completeUID);

        if (query.exec() && query.next()) {
            QString statut = query.value(0).toString();
            qDebug() << "Statut: " << statut;

            if (statut == "occupé") {
                A2.sendToArduino("1"); // LED verte
                // Si on veut aussi ouvrir la porte quand occupé (comme dans le bouton)
                if(A2.isConnected()) {
                    A2.sendCommand('1'); // Envoie '1' pour ouvrir la porte
                }
            } else {
                A2.sendToArduino("0"); // LED rouge
            }
        } else {
            qDebug() << "Erreur SQL ou UID inconnu: " << query.lastError().text();
            A2.sendToArduino("0"); // UID inconnu => LED rouge
        }
    }

    // Lecture supplémentaire des données série si nécessaire (comme dans l'ancienne updateSerialData)
    QByteArray data = A2.getSerial()->readAll();
    if (!data.isEmpty()) {
        qDebug() << "Données reçues:" << data;
    }
}

/*void MainWindow::onSerialData() {
    buffer.append(serial->readAll());
    int idx;
    while ((idx = buffer.indexOf('\n')) != -1) {
        QByteArray line = buffer.left(idx).trimmed();
        buffer.remove(0, idx + 1);

        // Debug output
        qDebug() << "Received line:" << line;

        if (line.startsWith(QByteArray("NUM:"))) {
            // Build up buffer, max length CODE_LENGTH (4 in your case)
            if (codeBuffer.length() < 4) {  // Changed from CODE_LENGTH to hardcoded 4
                QByteArray numBytes = line.mid(4);
                QString num = QString::fromUtf8(numBytes);
                codeBuffer.append(num);
                qDebug() << "Code buffer:" << codeBuffer;

                // Optional: Send digit back to Arduino for display
                // serial->write(numBytes);
            }
            // Read from Arduino
            static QByteArray buffer;
            buffer += A3.read_from_arduino();  // Accumulate incoming data

        }
        else if (line == QByteArray("CLEARED")) {
            codeBuffer.clear();
            qDebug() << "Entry cleared";

            // Optional: Send clear confirmation
            // serial->write("CLEARED;");
        }
        else if (line == QByteArray("CODE:")) {  // '#' pressed
            // Verify only if correct length (4 digits)
            if (codeBuffer.length() == 4) {  // Changed from CODE_LENGTH to hardcoded 4
                QSqlQuery query;
                query.prepare("SELECT nom_candidat, prenom_candidat FROM candidat WHERE code_candidat = :code");
                query.bindValue(":code", codeBuffer);

                QString message;
                if (!query.exec()) {
                    qCritical() << "DB error:" << query.lastError().text();
                    message = "INTROUVABLE";
                }
                else if (query.next()) {
                    QString nom = query.value(0).toString().trimmed();
                    QString prenom = query.value(1).toString().trimmed();
                    message = nom + " " + prenom;
                    qDebug() << "Candidate found:" << message;
                }
                else {
                    message = "INTROUVABLE";
                    qDebug() << "Candidate not found";
                }

                // Send result to Arduino
                if (serial && serial->isOpen()) {
                    serial->write(message.toUtf8() + '\n');
                    serial->flush();
                }
            }
            else {
                qDebug() << "Need exactly 4 digits, got" << codeBuffer.length();
                if (serial && serial->isOpen()) {
                    serial->write("INTROUVABLE\n");
                }
            }
            codeBuffer.clear();
        }
    }
}

void MainWindow::verifierEtEnvoyerCode() {
    QString message;

    // Check if code has exactly 4 digits
    if (codeBuffer.length() != 4) {
        message = "INTROUVABLE";
        qDebug() << "Code must be exactly 4 digits. Current length:" << codeBuffer.length();
    } else {
        // Query database
        QSqlQuery query;
        query.prepare("SELECT nom_candidat, prenom_candidat FROM CANDIDAT WHERE code_candidat = :code");
        query.bindValue(":code", codeBuffer);

        if (!query.exec()) {
            qCritical() << "DB query error:" << query.lastError().text();
            message = "INTROUVABLE";
        } else if (query.next()) {
            QString nom = query.value(0).toString().trimmed();
            QString prenom = query.value(1).toString().trimmed();
            message = nom + " " + prenom;
            qDebug() << "Candidate found:" << message;
        } else {
            message = "INTROUVABLE";
            qDebug() << "Candidate not found in database";
        }
    }

    // Clear the buffer after processing
    codeBuffer.clear();

    // Send response via serial
    if (A3.isConnected()) {
        A3.sendToArduino(message.toUtf8() + "\n");
        qDebug() << "Sent to Arduino:" << message;
    } else {
        qCritical() << "Arduino not connected";
    }
}*/



void MainWindow::on_ArduinoCandid_clicked()
{
    // Connect to Arduino on COM11
    if (arduino.connect_arduino("COM11") == 0) {
        QMessageBox::information(this, "Success", "Connected to Arduino on COM11");
    } else {
        QMessageBox::warning(this, "Error", "Failed to connect to Arduino");
    }
}

void MainWindow::handleArduinoCandidateVerification()
{
    if (!arduino.getSerial()->isReadable()) return;

    // Append new data to buffer
    serialBuffer += QString::fromUtf8(arduino.read_from_arduino());

    // Check if we have a complete message (ends with newline)
    if (!serialBuffer.contains('\n') && !serialBuffer.contains('\r')) {
        return;  // Wait for more data
    }

    // Clean and process the message
    QString message = serialBuffer.trimmed();
    serialBuffer.clear();  // Reset buffer for next message

    qDebug() << "Complete message:" << message;

    // Check for CODE: prefix
    if (!message.startsWith("CODE:")) {
        qDebug() << "Waiting for CODE: prefix";
        return;
    }

    // Extract and validate code
    QString code = message.mid(5).left(4);  // Take first 4 digits after CODE:
    if (code.length() != 4) {
        arduino.write_to_arduino("INVALID_CODE\n");
        return;
    }

    // Database verification
    QSqlQuery query;
    query.prepare("SELECT NOM_CANDIDAT, PRENOM_CANDIDAT FROM CANDIDAT WHERE CODE_CANDIDAT = :code");
    query.bindValue(":code", code);

    if (!query.exec()) {
        arduino.write_to_arduino("DB_ERROR\n");
        return;
    }

    // Prepare response
    QString response = query.next()
                           ? query.value(0).toString().trimmed() + ";" + query.value(1).toString().trimmed()
                           : "INTROUVABLE";

    arduino.write_to_arduino((response + "\n").toUtf8());
}
