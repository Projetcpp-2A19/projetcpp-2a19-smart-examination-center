#include "mainwindow.h"
#include "./ui_mainwindow.h"
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
#include <QtCharts/QPieSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
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


    model = new QSqlQueryModel();  // Initialisation du modèle
    updateTableView();
    connect(ui->Ajbtn, &QPushButton::clicked, this, &MainWindow::handleAddFournisseur);
    connect(ui->suppButton, &QPushButton::clicked, this, &MainWindow::handleDeleteFournisseur);
    connect(ui->comboBoxStatType, &QComboBox::currentIndexChanged,
            this, &MainWindow::showStatistiques);






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

    modificationInProgress = true; // Définir le flag quand la modification commence
}

void MainWindow::on_SaveMod_clicked() {
    if (!modificationInProgress) {
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
        modificationInProgress = false;
    } else {
        QMessageBox::critical(this, "Erreur", "La modification a échoué.");
    }
}


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
    QString password = "kbge ylvc ckpl ykmg"; // Mot de passe d'application Gmail
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

    // Préparation de la commande curl
    QStringList arguments;
    arguments << "--url" << "smtps://smtp.gmail.com:465"
              << "--ssl-reqd"
              << "--mail-from" << sender
              << "--mail-rcpt" << recipient
              << "--user" << sender + ":" + password
              << "--upload-file" << emailFilePath;

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
                    // 🔸 Enregistrement dans la table EMAILS après envoi réussi
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
                    QMessageBox::critical(this, "Erreur", "Échec de l'envoi de l'email . Code: " + QString::number(exitCode));
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

    if (!ui->chartContainerType) {
        qDebug() << ":x: ERROR: chartContainerType is NULL!";
        return;
    }

    // Nettoyage ancien contenu
    if (ui->chartContainerType->layout()) {
        QLayout *layout = ui->chartContainerType->layout();
        while (QLayoutItem *item = layout->takeAt(0)) {
            if (QWidget *widget = item->widget()) {
                widget->deleteLater();
            }
            delete item;
        }
    } else {
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
    }

    QChart *pieChart = new QChart();
    pieChart->addSeries(pieSeries);


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
}
