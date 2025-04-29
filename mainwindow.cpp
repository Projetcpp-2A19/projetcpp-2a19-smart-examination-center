#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "equipement.h"
#include "arduino.h"
#include <QDebug>
//#include <QMouseEvent>
#include <QMessageBox>
#include <QMessageBox>
#include <cstdlib>  // Pour rand() et srand()
#include <ctime>    // Pour time()
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <ctime>
#include <QPainter>
#include <QPdfWriter>
#include <QSqlQuery>
#include <QSqlError>
#include <QDesktopServices>
#include <QUrl>
#include <QDir>
#include <QChart>
#include <QLineSeries>
#include <QPieSeries>
#include <QChartView>
#include <QProcess>
#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QByteArray>
#include <QSqlQuery>
#include <QMessageBox>
#include <QByteArray>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->closeBtn, &QPushButton::clicked, this, &MainWindow::close);
    connect(ui->closeBtn, &QPushButton::clicked, this, &MainWindow::close);
    ui->labelNotification1->setTextInteractionFlags(Qt::TextBrowserInteraction);
    connect(ui->Modbtn, &QPushButton::clicked, this, &MainWindow::on_Modbtn_clicked);

    /*ui->scrollArea->setVisible(false);
     ui->scrollArea->raise();
    // Toujours afficher la barre de scroll verticale
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
     ui->scrollAreaWidgetContents->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);


    // Connexion du bouton pour afficher les notifications
     connect(ui->notifBtn, &QPushButton::clicked, this, &MainWindow::showNotifications);*/


    int ret = A.connect_arduino();
    switch (ret) {
    case 0:
        qDebug() << "Arduino connected on port:" << A.getarduino_port_name();
        break;
    case 1:
        qDebug() << "Arduino detected but not connected!";
        break;
    case -1:
        qDebug() << "Arduino not available!";
        break;
    }

    if (ret == 0) {
        // Now check if we are properly connected to the Arduino
    } else {
        qDebug() << "Failed to connect Arduino, cannot proceed with reading data.";
    }
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



/*void MainWindow::on_Modbtn_clicked()
{
    // Create a message box
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Information);  // Set the icon to Information
    msgBox.setWindowTitle("Alert");            // Set the title of the message box
    msgBox.setText("The button was clicked!"); // Set the message text
    msgBox.exec();                            // Show the message box
}
*/

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



// 📌 Afficher les équipements
void MainWindow::afficherEquipements() {
    Equipement e;
    QSqlQueryModel *model = e.afficher();

    // Debugging: Check if the model is valid and contains data
    if (!model) {
        qDebug() << "Erreur: Le modèle est nul.";
        return;
    }

    if (model->rowCount() == 0) {
        qDebug() << "Erreur: Le modèle est vide.";
        return;
    }

    qDebug() << "Nombre de lignes dans le modèle:" << model->rowCount();
    qDebug() << "Nombre de colonnes dans le modèle:" << model->columnCount();

    // Creating a QTableWidget to manually insert data since setModel is not available
    ui->tableView->clear();  // Clear the existing data in the table view
    ui->tableView->setRowCount(model->rowCount());
    ui->tableView->setColumnCount(model->columnCount());

    // Setting the headers
    ui->tableView->setHorizontalHeaderLabels({ "Nom", "Type", "Statut", "Quantité" });

    // Manually populate the table with the model data
    for (int i = 0; i < model->rowCount(); i++) {
        for (int j = 0; j < model->columnCount(); j++) {
            QString data = model->data(model->index(i, j)).toString();
            ui->tableView->setItem(i, j, new QTableWidgetItem(data));
        }
    }

    // Optionally resize columns
    ui->tableView->resizeColumnsToContents();
}


#include <QInputDialog>
#include <QMessageBox>

void MainWindow::on_BinSuperbtn_clicked()
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
        if (e.supprimer(equipmentId)) {
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

/*void MainWindow::modifierEquipement()
{
    Equipement e("Imprimante", "Bureau", "En panne", 5);
    if (e.modifier("EQ001")) {
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
    if (e.supprimer("EQ001")) {
        qDebug() << "Équipement supprimé.";
        afficherEquipements(); // Rafraîchir l'affichage
    } else {
        qDebug() << "Erreur lors de la suppression.";
    }
}
*/

void MainWindow::on_Ajbtn_clicked()
{
    qDebug() << "Bouton 'Ajouter' cliqué.";

    // Fetching data from the UI elements
    QString nom = ui->Nom->text();
    qDebug() << "Nom saisi :" << nom;

    // Getting the selected item from the QListWidget
    QListWidgetItem *selectedItem = ui->type->currentItem();
    if (!selectedItem) {
        qDebug() << "Erreur: Aucun type sélectionné dans la liste.";
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un type d'équipement.");
        return;
    }
    QString type = selectedItem->text();
    qDebug() << "Type sélectionné :" << type;

    QString statut = ui->Status->text();
    qDebug() << "Statut saisi :" << statut;

    QString quantiteStr = ui->qte->text();
    bool ok;
    int quantite = quantiteStr.toInt(&ok);
    qDebug() << "Quantité saisie :" << quantiteStr << ", convertie en entier :" << quantite;

    // Input Validation
    if (nom.isEmpty()) {
        qDebug() << "Erreur: Le champ 'Nom' est vide.";
        QMessageBox::warning(this, "Erreur", "Le champ 'Nom' est obligatoire.");
        return;
    }

    if (statut.isEmpty()) {
        qDebug() << "Erreur: Le champ 'Statut' est vide.";
        QMessageBox::warning(this, "Erreur", "Le champ 'Statut' est obligatoire.");
        return;
    }

    if (quantiteStr.isEmpty()) {
        qDebug() << "Erreur: Le champ 'Quantité' est vide.";
        QMessageBox::warning(this, "Erreur", "Le champ 'Quantité' est obligatoire.");
        return;
    }

    if (!ok || quantite <= 0) {
        qDebug() << "Erreur: La quantité doit être un nombre entier positif.";
        QMessageBox::warning(this, "Erreur", "La quantité doit être un nombre entier positif.");
        return;
    }

    // Creating the Equipement object without specifying the ID
    qDebug() << "Création de l'objet Équipement avec les valeurs: "
             << "Nom:" << nom << ", Type:" << type << ", Statut:" << statut << ", Quantité:" << quantite;

    Equipement e(nom, type, statut, quantite);

    // Attempting to add the equipment
    if (e.ajouter()) {
        qDebug() << "Succès: Équipement ajouté avec succès.";
        afficherEquipements(); // Refresh the table view
        QMessageBox::information(this, "Succès", "L'équipement a été ajouté avec succès.");
    } else {
        qDebug() << "Erreur: Échec lors de l'ajout de l'équipement.";
        QMessageBox::critical(this, "Erreur", "Une erreur est survenue lors de l'ajout de l'équipement.");
    }
    ui->stackedWidget_2->setCurrentWidget(ui->page);
}

void MainWindow::on_Modbtn_clicked()
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
                if (e.modifier(equipmentId, nom, type, statut, quantite)) {
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
void MainWindow::on_pushButton_2_clicked()
{
    Equipement e;
    QSqlQueryModel *model = e.trierParNom();

    // Debugging: Check if the model is valid and contains data
    if (!model) {
        qDebug() << "Erreur: Le modèle est nul.";
        return;
    }

    if (model->rowCount() == 0) {
        qDebug() << "Erreur: Le modèle est vide.";
        return;
    }

    qDebug() << "Nombre de lignes dans le modèle:" << model->rowCount();
    qDebug() << "Nombre de colonnes dans le modèle:" << model->columnCount();

    // Creating a QTableWidget to manually insert data since setModel is not available
    ui->tableView->clear();  // Clear the existing data in the table view
    ui->tableView->setRowCount(model->rowCount());
    ui->tableView->setColumnCount(model->columnCount());

    // Setting the headers
    ui->tableView->setHorizontalHeaderLabels({ "Nom", "Type", "Statut", "Quantité" });

    // Remplir le tableau avec les données de la base
    for (int i = 0; i < model->rowCount(); i++) {
        for (int j = 0; j < model->columnCount(); j++) {
            QString data = model->data(model->index(i, j)).toString();
            ui->tableView->setItem(i, j, new QTableWidgetItem(data));
        }
    }

    //  Ajuster automatiquement la largeur des colonnes
    ui->tableView->resizeColumnsToContents();
    ui->stackedWidget_2->setCurrentWidget(ui->page);
}

void MainWindow::on_pushButton_clicked()
{
    QString nomRecherche = ui->recherche->text();
    Equipement e;
    QSqlQueryModel *model = e.rechercherParNom(nomRecherche);

    int rowCount = model->rowCount();
    qDebug() << "Résultats trouvés pour" << nomRecherche << ":" << rowCount;

    ui->tableView->clear();
    ui->tableView->setRowCount(rowCount);
    ui->tableView->setColumnCount(model->columnCount());

    QStringList headers;
    headers << "ID" << "Nom" << "Type" << "Statut" << "Quantité";
    ui->tableView->setHorizontalHeaderLabels(headers);

    for (int i = 0; i < rowCount; ++i) {
        for (int j = 0; j < model->columnCount(); ++j) {
            QString data = model->data(model->index(i, j)).toString();
            ui->tableView->setItem(i, j, new QTableWidgetItem(data));
        }
    }
    ui->stackedWidget_2->setCurrentWidget(ui->page);
}
void MainWindow::genererRapportPDF()
{
    QString filePath = QDir::homePath() + "/Documents/new equipement branch/rapport_equipements.pdf";
    QPdfWriter pdfWriter(filePath);
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));
    pdfWriter.setResolution(300);
    QPainter painter(&pdfWriter);

    // Marges
    const int marginLeft = 40;
    const int marginTop = 50;
    const int pageWidth = pdfWriter.width() - 2 * marginLeft;

    // Logo et titre
    //QPixmap logo("/mnt/data/44298757-c475-4d62-8415-e4d92b1b761b-removebg-preview.png");
    //painter.drawPixmap(marginLeft, marginTop, 80, 80, logo);
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

    // Largeur totale à diviser
    QVector<int> columnWidths = {
        int(pageWidth * 0.10),  // ID
        int(pageWidth * 0.30),  // Nom
        int(pageWidth * 0.25),  // Type
        int(pageWidth * 0.15),  // Statut
        int(pageWidth * 0.20)   // Quantité
    };

    QStringList headers = {"ID", "Nom", "Type", "Statut", "Quantité"};

    // En-tête stylée
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

    // Récupération des équipements
    QSqlQuery query;
    if (!query.exec("SELECT ID_EQUIPEMENT, NOM_EQUIPEMENT, TYPE_EQUIPEMENT, STATUT_EQUIPEMENT, QUANTITE__EQUIPEMENT FROM EQUIPEMENTS ORDER BY ID_EQUIPEMENT")) {
        QMessageBox::critical(this, "Erreur SQL", "Impossible de récupérer les équipements: " + query.lastError().text());
        return;
    }

    // Dessiner les lignes
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

        // Saut de page si dépassement
        if (y > pdfWriter.height() - 100) {
            pdfWriter.newPage();
            y = marginTop;
        }
    }

    painter.end();
    QMessageBox::information(this, "Succès", "Le rapport PDF a été généré avec succès !");
}
void MainWindow::on_pdfSuperbtn_clicked(){
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

    // Nettoyer l'ancien layout s'il existe dans page_2 de stackedWidget_2
    QLayout *oldLayout = ui->page_2->layout();
    if (oldLayout) {
        QLayoutItem *item;
        while ((item = oldLayout->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        delete oldLayout;
    }

    // Créer un nouveau layout et ajouter le graphique
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(chartView);
    ui->page_2->setLayout(layout);

    // Activer la page_2 dans stackedWidget_2 si besoin
    ui->stackedWidget_2->setCurrentWidget(ui->page_2);
}

void MainWindow::on_ModButton_clicked(){
    afficherStatistiquesEquipements();
}
void MainWindow::rechercheVocale()
{
    QProcess process;

    // Utilise un chemin correct avec des doubles antislashs ou des slashes normaux
    QString pythonScript = "C:/Users/21628/Documents/new equipement branch/speech_to_text.py";

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
    on_pushButton_clicked();
}

void MainWindow::on_btnRechercheVocale_clicked(){
    rechercheVocale();
}








void MainWindow::on_Modbtn_2_clicked() {
    connect(A.getserial(), SIGNAL(readyRead()), this, SLOT(readSerialData()));
}

void MainWindow::readSerialData() {
    // Get the equipment ID from the QLineEdit (manual input)
    bool ok;
    QString input = ui->idInputLineEdit->text();  // Retrieve the text entered by the user
    int equipmentId = input.toInt(&ok);  // Try converting the input to an integer

    if (!ok || equipmentId <= 0) {
        qDebug() << "Aucun ID saisi ou ID invalide.";
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID valide.");
        return;
    }

    qDebug() << "ID de l'équipement sélectionné : " << equipmentId;

    // Fetch the quantity from the database
    QSqlQuery query;
    query.prepare("SELECT QUANTITE__EQUIPEMENT FROM EQUIPEMENTS WHERE ID_EQUIPEMENT = :id");
    query.bindValue(":id", equipmentId);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la récupération de la quantité de l'équipement:" << query.lastError();
        return;
    }

    if (!query.next()) {
        qDebug() << "Aucun équipement trouvé pour l'ID:" << equipmentId;
        return;
    }

    int quantite = query.value(0).toInt();  // Database quantity
    qDebug() << "Quantité de l'équipement ID" << equipmentId << "est :" << quantite;

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
        qDebug() << "📨 Donnée brute reçue :" << text;

        if (text.startsWith("QUANTITE:")) {
            QString quantityStr = text.mid(9);  // After "QUANTITE:"
            bool ok;
            int quantity = quantityStr.toInt(&ok);

            if (ok) {
                qDebug() << "✅ Received Quantity from Arduino:" << quantity;

                int newQuantity = quantite + quantity;
                qDebug() << "🔵 New Quantity to update:" << newQuantity;
                ui->qtelabel->setText(QString::number(newQuantity));
















            } else {
                qDebug() << "❌ Failed to convert quantity!";
            }
        } else {
            qDebug() << "❌ Format inattendu (pas de 'QUANTITE:') → " << text;
        }
    }
}









/*QSqlQuery updateQuery;
                updateQuery.prepare("UPDATE EQUIPEMENTS SET QUANTITE__EQUIPEMENT = :newQuantite WHERE ID_EQUIPEMENT = :id");
                updateQuery.bindValue(":newQuantite", newQuantity);
                updateQuery.bindValue(":id", equipmentId);

                if (updateQuery.exec()) {
                    qDebug() << "✅ Quantity updated successfully in the database.";
                    // Send new quantity back to Arduino
                    QByteArray dataToSend = "NOUVELLE_QUANTITE:" + QByteArray::number(newQuantity) + "\n";
                    A.write_to_arduino(dataToSend);
                    qDebug() << "📤 Envoyé à Arduino :" << dataToSend;
                } else {
                    qDebug() << "❌ Error updating quantity:" << updateQuery.lastError();
                }*/
