#include "mainwindow.h"  // pour std::unique_ptr
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
#include <QInputDialog>
#include <QTimer>
#include <QString>
//#include <QMouseEvent>
#include <QtCharts/QPieSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QPainter>
#include <QPdfWriter>
#include <QSqlQuery>
#include <QTextDocument>
#include <QTextCursor>
#include <QTextTable>
#include <QSqlRecord> // Ajoutez cette inclusion
 //using namespace QtCharts;
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) ,
    networkManager(new QNetworkAccessManager(this))

{
    ui->setupUi(this);
     // Pour éviter de préfixer avec QtCharts::

    //ui->tableView1->setModel(Etmp.afficher()); // Remplace tableWidget1 par tableView
    // Affichage direct du tableView1 au démarrage
    //SSupprimer
    connect(ui->BinSuperbtn, &QPushButton::clicked, this, &MainWindow::on_BinSuperbtn_clicked);
    connect(ui->SaveMod, &QPushButton::clicked, this, &MainWindow::on_SaveMod_clicked);


    ui->lineEdit1->setPlaceholderText("Rechercher...");
    connect(ui->closeBtn, &QPushButton::clicked, this, &MainWindow::close);
    connect(ui->closeBtn, &QPushButton::clicked, this, &MainWindow::close);
    //ui->labelNotification1->setTextInteractionFlags(Qt::TextBrowserInteraction);
    // Connexion du bouton de recherche
    connect(ui->rechBtn_2, &QPushButton::clicked, this, &MainWindow::rechercherSuperviseur);
   // connect(ui->TriButton, &QPushButton::clicked, this, &MainWindow::onTriButtonClicked);
    connect(ui->TriButton, SIGNAL(clicked()), this, SLOT(onTriButtonClicked()));
    connect(ui->ReMod, SIGNAL(clicked()), this, SLOT(resetTableView()));
    // Connecter le bouton d'envoi avec le slot

    connect(ui->sendButton, &QPushButton::clicked, this, &MainWindow::handleChatCommand);
    connect(ui->chatInput, &QLineEdit::returnPressed, this, &MainWindow::handleChatCommand);

}


MainWindow::~MainWindow()
{
    delete ui;
    delete model;


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


/*void MainWindow::on_ModButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}*/

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
    QString statut = ui->StatutlineEdit->text().trimmed();
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
    ui->StatutlineEdit->setText(originalStatut);
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
    QString newStatut = ui->StatutlineEdit->text();
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
    QString idRecherche = ui->lineEdit1->text();  // L'ID entré par l'utilisateur

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
    }

    QChart *pieChart = new QChart();
    pieChart->addSeries(pieSeries);
    //pieChart->setTitle("Répartition des équipements par type");

    // Set Background Color :art:
    //pieChart->setBackgroundBrush(QBrush(QColor(234, 251, 255)));

    QChartView *chartView = new QChartView(pieChart);
    chartView->setRenderHint(QPainter::Antialiasing);

    ui->chartContainerType->layout()->addWidget(chartView);

    qDebug() << ":white_check_mark: Type Statistics Updated Successfully!";
}


void MainWindow::on_ModButton_clicked()
{
    showStatistiques();

    qDebug() << "Statistics loaded successfully!";
    ui->stackedWidget->setCurrentIndex(4);
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
        ui->StatutlineEdit->setText(originalStatut);
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

