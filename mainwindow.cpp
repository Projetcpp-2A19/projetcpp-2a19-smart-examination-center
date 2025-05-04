#include "mainwindow.h"
#include "./ui_mainwindow.h"
<<<<<<< HEAD
#include <QMouseEvent>
#include <QPushButton>
#include <QHBoxLayout>
#include <QWidget>
#include "Superviseur.h"
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QDebug>
#include <QSqlError>
#include <QInputDialog>
#include <QTimer>
#include <QString>
=======
#include "fournisseurs.h"
#include <QMessageBox>
#include <QSqlError>
#include <QSslError>
#include <QSslSocket>
#include <QSqlQueryModel>
#include <QRegularExpression>
#include <QDesktopServices>
#include <QUrl>
#include <QPdfWriter>
#include <QPainter>
#include <QTextDocument>
#include <QFileDialog>
#include "simple-mail/src/server.h"
#include "simple-mail/src/serverreply.h"
#include "simple-mail/src/mimetext.h"
#include "simple-mail/src/mimemessage.h"
#include "simple-mail/src/emailaddress.h"
>>>>>>> b6702fb4186800406ca9e0726db1397b5b8a17b0
#include <QtCharts/QPieSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
<<<<<<< HEAD
#include <QVBoxLayout>
#include <QFileDialog>
#include <QPainter>
#include <QPdfWriter>
#include <QSqlQuery>
#include <QTextDocument>
#include <QTextCursor>
#include <QTextTable>
#include <QSqlRecord>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include "arduino.h"

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
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) ,
    networkManager(new QNetworkAccessManager(this)) , codeBuffer(), currentLineEdit(nullptr)

{
    ui->setupUi(this);
    connect(ui->BinSuperbtn, &QPushButton::clicked, this, &MainWindow::on_BinSuperbtn_clicked);
    connect(ui->SaveMod, &QPushButton::clicked, this, &MainWindow::on_SaveMod_clicked);
    ui->RechSuperviseur->setPlaceholderText("Rechercher...");
    ui->NumTelSup->setPlaceholderText("Numéro Téléphone...");
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
    int ret = A.connect_arduino();
    switch (ret) {
    case 0: qDebug() << "Arduino connecté."; break;
    case 1: qDebug() << "Arduino détecté mais erreur ouverture."; break;
    case -1: qDebug() << "Arduino non disponible."; break;
    }
    connect(A.getserial(), SIGNAL(readyRead()), this, SLOT(updateSerialData()));


    //IMEN
    // Set placeholder text for the subject input field
    ui->SearchBarExamen->setPlaceholderText("math, physique...");

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

    //arduino
    serial = new QSerialPort(this);
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setPortName("COM3");

    if (!serial->open(QIODevice::ReadOnly)) {
        qCritical() << "Failed to open serial port:" << serial->errorString();
        return;
    }
    else
        qCritical() << "connected:" ;

    // 3. Connect signal
    connect(serial, &QSerialPort::readyRead, this, &MainWindow::onSerialData);

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
}


MainWindow::~MainWindow() {
    delete ui;
    delete speechToText;
    if (serial->isOpen())
        serial->close();
}


void MainWindow::updateSerialData()
{
    QByteArray rawData = A.read_from_arduino();
    serialBuffer += QString::fromUtf8(rawData);

    // Suppose qu'un UID complet arrive avec un saut de ligne
    if (serialBuffer.contains('\n')) {
        QStringList lines = serialBuffer.split('\n');
        QString completeUID = lines.at(0).trimmed().toUpper(); // prend la première ligne complète
        serialBuffer = lines.size() > 1 ? lines.at(1) : "";    // stocke le reste

        qDebug() << "UID complet reçu: " << completeUID;
        verifierStatutSuperviseur(completeUID);
    }
}

void MainWindow::verifierStatutSuperviseur(const QString& uid)
{
    QSqlQuery query;
    query.prepare("SELECT statut_superviseur FROM superviseurs WHERE LOWER(id_superviseur) = LOWER(:uid)");
    query.bindValue(":uid", uid);

    qDebug() << "UID utilisé: " << uid;

    if (query.exec() && query.next()) {
        QString statut = query.value(0).toString();
        qDebug() << "Statut: " << statut;

        if (statut == "occupé") {
            A.write_to_arduino("1"); // LED verte
        } else {
            A.write_to_arduino("0"); // LED rouge
        }
    } else {
        qDebug() << "Erreur SQL: " << query.lastError().text();
        A.write_to_arduino("0"); // UID inconnu => LED rouge
    }
}


void MainWindow::on_examButton_clicked()
{
   ui->stackedWidget->setCurrentIndex(1);
=======
#include <QSerialPort>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QTextStream>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSerialPortInfo>
#include "Etablissement.h"
#include <QSqlQueryModel>
#include <QInputDialog>
#include <QPrinter>
#include <QPainter>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChartView>
#include "panoramicviewer.h"










using namespace SimpleMail;




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     verifierEtEnvoyerCode();

    ui->chatInput->setPlaceholderText("Poser une question ici...");
    ui->lineEdit_2->setPlaceholderText("Entrez l'adresse e-mail du destinataire");
    ui->lineEdit_3->setPlaceholderText("Entrez l'objet de l'email");
    ui->textEdit->setPlaceholderText("Écrivez ici le contenu de votre message...");
    ui->lineEditRech->setPlaceholderText("Recherche par ID ...");
    ui->searchDirector->setPlaceholderText("Recherche par directeur...");


    model = new QSqlQueryModel();  // Initialisation du modèle
    updateTableView();
    connect(ui->Ajbtn, &QPushButton::clicked, this, &MainWindow::handleAddFournisseur);
    connect(ui->suppButton, &QPushButton::clicked, this, &MainWindow::handleDeleteFournisseur);
    connect(ui->comboBoxStatType, &QComboBox::currentIndexChanged,
            this, &MainWindow::showStatistiques);



//etablissement
    ui->tableView_Eta->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);     // Connexions existantes...
    connect(ui->closeBtn, &QPushButton::clicked, this, &MainWindow::close);
    connect(ui->Binetabtn, &QPushButton::clicked, this, &MainWindow::on_Binetabtn_clicked);

    // Nouvelle connexion pour le bouton Nouveau
    connect(ui->neweta, &QPushButton::clicked, this, &MainWindow::on_neweta_clicked);
    // Nouvelle connexion pour la recherche
    connect(ui->searchDirector, &QLineEdit::textChanged,
            this, &MainWindow::on_searchDirector_textChanged);

    connect(ui->sortGovernorateBtn, &QPushButton::clicked,
            this, &MainWindow::on_sortGovernorate_clicked);

    // Connexion pour l'export PDF
    connect(ui->exportPdfBtn, &QPushButton::clicked,
            this, &MainWindow::on_exportPdfBtn_clicked);

    // Connexion du bouton stats
    connect(ui->statsButton, &QPushButton::clicked,
            this, &MainWindow::on_statsButton_clicked);

    connect(ui->tableView_Eta, &QTableView::clicked, this, &MainWindow::on_tableView_Eta_clicked);
    updatetableView_Eta();

    // Initialiser les stats
    setupGovernorateStats();


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
>>>>>>> b6702fb4186800406ca9e0726db1397b5b8a17b0
}


void MainWindow::on_supButton_clicked()
{
<<<<<<< HEAD
    ui->stackedWidget->setCurrentIndex(2);
=======
    ui->stackedWidget->setCurrentIndex(8);
>>>>>>> b6702fb4186800406ca9e0726db1397b5b8a17b0
}



void MainWindow::on_eqButton_clicked()
{
<<<<<<< HEAD
    ui->stackedWidget->setCurrentIndex(4);
=======
    ui->stackedWidget->setCurrentIndex(5);
>>>>>>> b6702fb4186800406ca9e0726db1397b5b8a17b0
}



void MainWindow::on_FourButton_clicked()
{
<<<<<<< HEAD
    ui->stackedWidget->setCurrentIndex(5);
=======
    ui->stackedWidget->setCurrentIndex(6);
>>>>>>> b6702fb4186800406ca9e0726db1397b5b8a17b0
}


void MainWindow::on_candButton_clicked()
{
<<<<<<< HEAD
    ui->stackedWidget->setCurrentIndex(6);
=======

>>>>>>> b6702fb4186800406ca9e0726db1397b5b8a17b0
}


void MainWindow::on_etaButton_clicked()
{
<<<<<<< HEAD
    ui->stackedWidget->setCurrentIndex(7);
}


=======
    ui->stackedWidget->setCurrentIndex(2);
}






>>>>>>> b6702fb4186800406ca9e0726db1397b5b8a17b0
void MainWindow::on_homeBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

<<<<<<< HEAD
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
=======

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
>>>>>>> b6702fb4186800406ca9e0726db1397b5b8a17b0

    modificationInProgress = true; // Définir le flag quand la modification commence
}

void MainWindow::on_SaveMod_clicked() {
    if (!modificationInProgress) {
<<<<<<< HEAD
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
=======
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

    Fournisseur f(currentId, nom, adresse, email, numTel, typeService);

    if (f.modifier(currentId)) {
        QMessageBox::information(this, "Modification", "Fournisseur modifié avec succès !");
        updateTableView();
>>>>>>> b6702fb4186800406ca9e0726db1397b5b8a17b0
        modificationInProgress = false;
    } else {
        QMessageBox::critical(this, "Erreur", "La modification a échoué.");
    }
}

<<<<<<< HEAD
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
=======

void MainWindow::on_rechBtn_clicked()
{
    QString id = ui->lineEditRech->text().trimmed();

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


void MainWindow::on_emailBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
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
    updateTableView();
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
    model = triModel;

    actualiserTableView();
}



void MainWindow::on_pdfBtn_clicked() {
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



void MainWindow::showStatistiques() {
    qDebug() << ":bar_chart: Updating Fournisseur Type Statistics...";
>>>>>>> b6702fb4186800406ca9e0726db1397b5b8a17b0

    if (!ui->chartContainerType) {
        qDebug() << ":x: ERROR: chartContainerType is NULL!";
        return;
    }

<<<<<<< HEAD
    // Clear existing layout content
=======
    // Nettoyage ancien contenu
>>>>>>> b6702fb4186800406ca9e0726db1397b5b8a17b0
    if (ui->chartContainerType->layout()) {
        QLayout *layout = ui->chartContainerType->layout();
        while (QLayoutItem *item = layout->takeAt(0)) {
            if (QWidget *widget = item->widget()) {
                widget->deleteLater();
            }
            delete item;
        }
    } else {
<<<<<<< HEAD
        ui->chartContainerType->setLayout(new QVBoxLayout());
    }

    // :bar_chart: Pie Chart (Type Distribution)
    QPieSeries *pieSeries = new QPieSeries();
    QMap<QString, int> statsType = S.getStatistiquesParZone();

    int total = 0;
    for (auto it = statsType.begin(); it != statsType.end(); ++it) {
        total += it.value();  // Calculate total count of all equipment
    }

    if (statsType.isEmpty()) {
        qDebug() << ":warning: WARNING: No data found for equipment types!";
    } else {
        for (auto it = statsType.begin(); it != statsType.end(); ++it) {
            double percentage = (total > 0) ? (it.value() * 100.0 / total) : 0;  // Calculate percentage

            QPieSlice *slice = pieSeries->append(it.key(), it.value());

            // Set label format to show percentage
            slice->setLabel(QString("%1: %2%").arg(it.key()).arg(percentage, 0, 'f', 1));

            slice->setLabelVisible(true);  // Ensure label is visible

            // Add hover effect
            connect(slice, &QPieSlice::hovered, [slice](bool hovered) {
                slice->setExploded(hovered);
                slice->setLabelFont(QFont("Arial", hovered ? 12 : 10, hovered ? QFont::Bold : QFont::Normal));
            });
        }
=======
        QVBoxLayout *layout = new QVBoxLayout();
        layout->setContentsMargins(0, 0, 0, 0);
        ui->chartContainerType->setLayout(layout);
    }

    // 📊 Choix des statistiques (Type de Service ou Adresse)
    QString critere = ui->comboBoxStatType->currentText(); // ex: "Type de Service" ou "Adresse"

    Fournisseur f;
    QMap<QString, int> stats;

    if (critere == "Type de Service") {
        stats = f.getStatistiquesParTypeService();
    } else if (critere == "Adresse") {
        stats = f.getStatistiquesParAdresse();
    } else {
        qDebug() << "❌ Critère non reconnu :" << critere;
        return;
    }

    QPieSeries *pieSeries = new QPieSeries();
    int total = 0;
    for (auto it = stats.begin(); it != stats.end(); ++it) {
        total += it.value();
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
>>>>>>> b6702fb4186800406ca9e0726db1397b5b8a17b0
    }

    QChart *pieChart = new QChart();
    pieChart->addSeries(pieSeries);
<<<<<<< HEAD
    //pieChart->setTitle("Répartition des équipements par type");

    // Set Background Color :art:
    //pieChart->setBackgroundBrush(QBrush(QColor(234, 251, 255)));

    QChartView *chartView = new QChartView(pieChart);
    chartView->setRenderHint(QPainter::Antialiasing);

    ui->chartContainerType->layout()->addWidget(chartView);

    qDebug() << ":white_check_mark: Type Statistics Updated Successfully!";
}


/*void MainWindow::on_StatButton_clicked()
{
    showStatistiques();
    qDebug() << "Statistics loaded successfully!";
    ui->stackedWidget->setCurrentIndex(3);
}*/
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
                  "FROM EXAMENS e, ETABLISSEMENTS et, SUPERVISEURS s, AFFECTER a, SUPERVISE sp "
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
=======


    QChartView *chartView = new QChartView(pieChart);
    chartView->setRenderHint(QPainter::Antialiasing);
    ui->chartContainerType->layout()->addWidget(chartView);

    qDebug() << ":white_check_mark: Fournisseur " << critere << " Statistics Updated Successfully!";
}


void MainWindow::on_statButton_clicked() {
    ui->stackedWidget->setCurrentIndex(5); // Page des statistiques
    showStatistiques();
}


void MainWindow::on_chatbotBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_sendChatBtn_clicked() {
    QString userMessage = ui->chatInput->text().trimmed();
    if (userMessage.isEmpty()) return;

    ui->chatDisplay->append("👤: " + userMessage);
    ui->chatInput->clear();

    QUrl apiUrl("https://api-inference.huggingface.co/models/HuggingFaceH4/zephyr-7b-beta");
    QNetworkRequest request(apiUrl);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", "Bearer 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");

    QJsonObject json;
    json["inputs"] = QString("### Instruction:\n%1\n\n### Response:").arg(userMessage);

    QNetworkAccessManager* manager = new QNetworkAccessManager(this);
    QNetworkReply* reply = manager->post(request, QJsonDocument(json).toJson());

    connect(reply, &QNetworkReply::finished, this, [=]() {
        QByteArray response = reply->readAll();
        if (reply->error() == QNetworkReply::NoError) {
            QJsonDocument doc = QJsonDocument::fromJson(response);
            QString replyText;
            if (doc.isArray()) {
                replyText = doc.array().first().toObject().value("generated_text").toString();
            }

            if (replyText.isEmpty()) replyText = "(Réponse vide)";
            ui->chatDisplay->append("🤖: " + replyText);
        } else {
            ui->chatDisplay->append("❌ Erreur : " + reply->errorString());
            ui->chatDisplay->append("🧾 Réponse brute :\n" + QString::fromUtf8(response));
        }
        reply->deleteLater();
    });
}


void MainWindow::on_historiqueBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);

    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery("SELECT ID, DESTINATAIRE, SUJET, CONTENU, TO_CHAR(DATE_ENVOI, 'YYYY-MM-DD HH24:MI:SS') AS DATE_ENVOI FROM EMAILS ORDER BY DATE_ENVOI DESC");

    if (model->lastError().isValid()) {
        qDebug() << "❌ Erreur lors de la récupération des emails :" << model->lastError().text();
    }

    ui->emailHistoryTable->setModel(model);
    ui->emailHistoryTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->emailHistoryTable->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}
void MainWindow::verifierEtEnvoyerCode()
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
>>>>>>> b6702fb4186800406ca9e0726db1397b5b8a17b0
        return;
    }

    QSqlQuery query;
<<<<<<< HEAD
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
=======
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
}


//etablissement

void MainWindow::updatetableView_Eta()
{
    QSqlQueryModel *model = Etablissement().afficher();
    ui->tableView_Eta->setModel(model);
    ui->tableView_Eta->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}


void MainWindow::on_Ajteta_clicked()
{
    // Récupérer les valeurs des champs de saisie
    QString id = ui->idEtablissementLineEdit->text();
    QString gouvernorat = ui->gouvernoratLineEdit->text();
    QString type = ui->typeLineEdit->currentText();
    QString directeur = ui->directeurLineEdit->text();
    QString nom = ui->nomLineEdit->text();
    int nombreSalle = ui->nombreSalleLineEdit->text().toInt();
    QString ville = ui->villeLineEdit->text();
    QString adresse = ui->adresseLineEdit->text(); // Nouveau champ
    QString id_superviseur = ui->idSuperviseurLineEdit->text();
    QString id_equipement = ui->idEquipementLineEdit->text();

    // Vérifier que tous les champs sont remplis
    if (id.isEmpty() || gouvernorat.isEmpty() || type.isEmpty() || directeur.isEmpty() ||
        nom.isEmpty() || ville.isEmpty() || adresse.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis.");
        return;
    }
    if (nombreSalle <= 0)
    {
        QMessageBox::warning(this, "Erreur", "Le nombre de salles doit être supérieur à 0.");
        ui->nombreSalleLineEdit->setFocus();
        return;
    }

    // Créer un objet Etablissement
    Etablissement E(id, gouvernorat, type, directeur, nom, nombreSalle, ville, adresse,
                    selectedImagePath, id_superviseur, id_equipement);

    // Ajouter l'établissement à la base de données
    if (E.ajouter())
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
    if (E.supprimer(id))
    {
        QMessageBox::information(this, "Succès", "Établissement supprimé avec succès !");
        updatetableView_Eta();  // Mettre à jour le tableau
    }
    else
    {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression.");
    }
}

// Modifier un établissement
// Modifier un établissement
void MainWindow::on_Modeta_clicked() {
    QModelIndex index = ui->tableView_Eta->selectionModel()->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Modification", "Veuillez sélectionner un établissement à modifier.");
        return;
    }

    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(ui->tableView_Eta->model());
    if (!model) return;

    int row = index.row();
    currentIdEta = model->data(model->index(row, 0)).toString();
    currentGouvernoratEta = model->data(model->index(row, 1)).toString();
    currentTypeEta = model->data(model->index(row, 2)).toString();
    currentDirecteurEta = model->data(model->index(row, 3)).toString();
    currentNomEta = model->data(model->index(row, 4)).toString();
    currentNbSEta = model->data(model->index(row, 5)).toInt(); // Utilisez currentNbSEta
    currentVilleEta = model->data(model->index(row, 6)).toString();
    currentAdresseEta = model->data(model->index(row, 7)).toString();
    currentIdSuperviseurEta = model->data(model->index(row, 9)).toString();
    currentIdEquipementEta = model->data(model->index(row, 10)).toString();

    ui->idEtablissementLineEdit->setText(currentIdEta);
    ui->gouvernoratLineEdit->setText(currentGouvernoratEta);
    ui->typeLineEdit->setCurrentText(currentTypeEta);
    ui->directeurLineEdit->setText(currentDirecteurEta);
    ui->nomLineEdit->setText(currentNomEta);
    ui->nombreSalleLineEdit->setText(QString::number(currentNbSEta));
    ui->villeLineEdit->setText(currentVilleEta);
    ui->adresseLineEdit->setText(currentAdresseEta);
    ui->idSuperviseurLineEdit->setText(currentIdSuperviseurEta);
    ui->idEquipementLineEdit->setText(currentIdEquipementEta);
}
// Sauvegarder les modifications
void MainWindow::on_Saveta_clicked()
{
    // Récupérer les nouvelles valeurs des champs de saisie
    QString id = ui->idEtablissementLineEdit->text();
    QString gouvernorat = ui->gouvernoratLineEdit->text();
    QString type = ui->typeLineEdit->currentText();
    QString directeur = ui->directeurLineEdit->text();
    QString nom = ui->nomLineEdit->text();
    int nombreSalle = ui->nombreSalleLineEdit->text().toInt();
    QString ville = ui->villeLineEdit->text();
    QString adresse = ui->adresseLineEdit->text();
    QString id_superviseur = ui->idSuperviseurLineEdit->text();
    QString id_equipement = ui->idEquipementLineEdit->text();

    // Vérifier que tous les champs sont remplis
    if (id.isEmpty() || gouvernorat.isEmpty() || type.isEmpty() || directeur.isEmpty() || nom.isEmpty() || ville.isEmpty())
    {
        QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis.");
        return;
    }
    if (nombreSalle <= 0)
    {
        QMessageBox::warning(this, "Erreur", "Le nombre de salles doit être supérieur à 0.");
        ui->nombreSalleLineEdit->setFocus();
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
    if (E.modifier())
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
    ui->idEtablissementLineEdit->clear();
    ui->gouvernoratLineEdit->clear();
    ui->typeLineEdit->setCurrentIndex(0);
    ui->directeurLineEdit->clear();
    ui->nomLineEdit->clear();
    ui->nombreSalleLineEdit->clear();
    ui->villeLineEdit->clear();
    ui->nombreSalleLineEdit->setText("1");
    ui->adresseLineEdit->clear();
    ui->idSuperviseurLineEdit->clear();
    ui->idEquipementLineEdit->clear();



    // Réinitialiser l'objet E (optionnel mais recommandé)
    E = Etablissement();

    // Donner le focus au premier champ pour une meilleure UX
    ui->idEtablissementLineEdit->setFocus();

    // Si vous avez ajouté le mode optionnel avec label
    // ui->titleLabel->setText("Ajouter un nouvel établissement");
    // ui->Ajteta->setEnabled(true);
    // ui->Saveta->setEnabled(false);
}
void MainWindow::setupGovernorateStats()
{

    QSqlQuery query;
    query.prepare("SELECT GOUVERNORAT_ETABLISSEMENT, COUNT(*) FROM ETABLISSEMENT GROUP BY GOUVERNORAT_ETABLISSEMENT");

    if (!query.exec()) {
        qDebug() << "Erreur statistiques:" << query.lastError().text();
        return;
    }

    // Créer la série de données
    QPieSeries *series = new QPieSeries();

    while (query.next()) {
        QString governorate = query.value(0).toString();
        int count = query.value(1).toInt();

        QPieSlice *slice = series->append(governorate + " (" + QString::number(count) + ")", count);
        slice->setLabelVisible();
    }

    // Créer le chart
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des établissements par gouvernorat");
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight);

    // Créer la vue
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Ajouter à l'interface (par exemple dans un QFrame ou QWidget dédié)
    // Assurez-vous que ui->statsContainer existe dans votre interface
    if (ui->statsContainer) {
        QLayout *layout = ui->statsContainer->layout();
        if (!layout) {
            layout = new QVBoxLayout(ui->statsContainer);
        }
        // Nettoyer le contenu existant
        QLayoutItem *child;
        while ((child = layout->takeAt(0)) != nullptr) {
            delete child->widget();
            delete child;
        }
        layout->addWidget(chartView);
    }
}
// Dans le constructeur, ajoutez cette connexion :

// Nouvelle méthode pour gérer les clics sur le tableau
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
void MainWindow::on_searchDirector_textChanged(const QString &text)
{
    QSqlQueryModel *model = new QSqlQueryModel();

    if (text.isEmpty()) {
        // Si le champ de recherche est vide, afficher tous les établissements
        model->setQuery("SELECT * FROM ETABLISSEMENT");
    } else {
        // Recherche avec filtre sur le directeur
        QSqlQuery query;
        query.prepare("SELECT * FROM ETABLISSEMENT WHERE DIRECTEUR_ETABLISSEMENT LIKE :directeur");
        query.bindValue(":directeur", "%" + text + "%");

        if (query.exec()) {
            model->setQuery(std::move(query));
        } else {
            qDebug() << "Erreur de recherche:" << query.lastError().text();
>>>>>>> b6702fb4186800406ca9e0726db1397b5b8a17b0
            return;
        }
    }

<<<<<<< HEAD
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
=======
    // Définir les en-têtes comme dans Etablissement::afficher()
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Gouvernorat"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Directeur"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Nombre de Salles"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Ville"));

    ui->tableView_Eta->setModel(model);
}
void MainWindow::on_sortGovernorate_clicked()
{
    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(ui->tableView_Eta->model());

    if (!model) {
        model = new QSqlQueryModel(this);
        model->setQuery("SELECT * FROM ETABLISSEMENT ORDER BY GOUVERNORAT_ETABLISSEMENT ASC");
    } else {
        // Si le modèle existe déjà, on le réutilise avec un nouveau tri
        model->setQuery("SELECT * FROM ETABLISSEMENT ORDER BY GOUVERNORAT_ETABLISSEMENT ASC",
                        QSqlDatabase::database());
    }

    // Définir les en-têtes
    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("Gouvernorat"));
    model->setHeaderData(2, Qt::Horizontal, tr("Type"));
    model->setHeaderData(3, Qt::Horizontal, tr("Directeur"));
    model->setHeaderData(4, Qt::Horizontal, tr("Nom"));
    model->setHeaderData(5, Qt::Horizontal, tr("Nb Salles"));
    model->setHeaderData(6, Qt::Horizontal, tr("Ville"));
    model->setHeaderData(7, Qt::Horizontal, tr("Adresse"));


    ui->tableView_Eta->setModel(model);
}

void MainWindow::on_exportPdfBtn_clicked()
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
    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(ui->tableView_Eta->model());
    for (int col = 0; col < model->columnCount(); ++col) {
        html += "<th>" + model->headerData(col, Qt::Horizontal).toString() + "</th>";
    }
    html += "</tr>";

    // Données
    for (int row = 0; row < model->rowCount(); ++row) {
        html += "<tr>";
        for (int col = 0; col < model->columnCount(); ++col) {
            html += "<td>" + model->data(model->index(row, col)).toString() + "</td>";
        }
        html += "</tr>";
    }
    html += "</table>";

    doc.setHtml(html);
    doc.print(&printer);

    QMessageBox::information(this, "Export réussi",
                             "Le tableau a été exporté au format PDF avec succès !");
>>>>>>> b6702fb4186800406ca9e0726db1397b5b8a17b0
}



<<<<<<< HEAD
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
=======
void MainWindow::on_statsButton_clicked()
{
    QDialog statsDialog(this);
    statsDialog.setWindowTitle("Statistiques par gouvernorat");
    statsDialog.resize(800, 600);

    QVBoxLayout *layout = new QVBoxLayout(&statsDialog);

    QPieSeries *series = new QPieSeries();

    QSqlQuery query;
    if (!query.exec("SELECT GOUVERNORAT_ETABLISSEMENT, COUNT(*) FROM ETABLISSEMENT GROUP BY GOUVERNORAT_ETABLISSEMENT")) {
        qDebug() << "Erreur lors de l'exécution de la requête:" << query.lastError().text();
        return;
    }

    while (query.next()) {
        QString gouvernorat = query.value(0).toString();
        int count = query.value(1).toInt();
        QPieSlice *slice = series->append(gouvernorat, count);
        slice->setLabelVisible();
        slice->setLabel(QString("%1 (%2)").arg(gouvernorat).arg(count));
>>>>>>> b6702fb4186800406ca9e0726db1397b5b8a17b0
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
<<<<<<< HEAD
    chart->setTitle("Répartition des examens par statut");
    chart->legend()->setAlignment(Qt::AlignRight);
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    ui->ExamChartContainer->layout()->addWidget(chartView);


}



void MainWindow::onSerialData() {
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
}



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
    showStatistiques();
    qDebug() << "Statistics loaded successfully!";
    ui->stackedWidget->setCurrentIndex(3);
}

=======
    chart->setTitle("Répartition des établissements par gouvernorat");
    chart->legend()->setAlignment(Qt::AlignRight);
    chart->setAnimationOptions(QChart::AllAnimations);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    layout->addWidget(chartView);

    statsDialog.exec();

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

void MainWindow::on_selectImageBtn_clicked() {
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
    QDirIterator it(":/etablissements/", {"*.jpg", "*.png", "*.jpeg"}, QDir::Files);
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
        QPoint dernierPoint;

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
>>>>>>> b6702fb4186800406ca9e0726db1397b5b8a17b0
