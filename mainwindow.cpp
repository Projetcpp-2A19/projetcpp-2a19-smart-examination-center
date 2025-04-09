#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "fournisseurs.h"
#include <QMessageBox>
#include <QSqlError> // Assurez-vous que cette inclusion est présente
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
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChart>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QVBoxLayout>
#include <QLayoutItem>
#include <QLayout>













using namespace SimpleMail;




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
    QString id = ui->lineEditRech->text().trimmed(); // lineEditRech = ton champ de saisie d’ID

    if (id.isEmpty()) {
        QMessageBox::warning(this, "Recherche", "Veuillez entrer un ID !");
        return;
    }

    QSqlQueryModel *searchModel = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * FROM FOURNISSEURS WHERE ID_FOURNISSEUR = :id");  // remplace FOURNISSEURS par le nom réel de ta table
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
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_EnvBtn_clicked()
{
    // ⚙️ Configuration du serveur SMTP Gmail
    auto* smtp = new SimpleMail::Server(this);
    smtp->setHostname("smtp.gmail.com");
    smtp->setPort(587); // TLS (STARTTLS)
    smtp->setConnectionType(SimpleMail::Server::TlsConnection);

    // ✅ Remplace ici par ton adresse et ton mot de passe d'application
    smtp->setUsername("ddahmeni2.dali@gmail.com");
    smtp->setPassword("kbge ylvc ckpl ykmg"); // mot de passe d'application généré via https://myaccount.google.com/apppasswords

    // ✉️ Création de l'email
    SimpleMail::MimeMessage message;
    message.setSender(SimpleMail::EmailAddress("ddahmeni2.dali@gmail.com", "Dahmani"));
    message.setToRecipients({ SimpleMail::EmailAddress(ui->lineEdit_2->text(), "Destinataire") });
    message.setSubject(ui->lineEdit_3->text());

    auto text = std::make_shared<SimpleMail::MimeText>();
    text->setText(ui->textEdit->toPlainText());
    message.addPart(text);

    // 📤 Envoi de l'email
    auto reply = smtp->sendMail(message);

    // 🔁 Suivi de la réponse
    connect(reply, &SimpleMail::ServerReply::finished, this, [reply]() {
        if (!reply->error()) {
            QMessageBox::information(nullptr, "Succès", "📧 Email envoyé avec succès !");
        } else {
            QMessageBox::critical(nullptr, "Erreur SMTP",
                                  "Code : " + QString::number(reply->responseCode()) +
                                      "\nMessage : " + reply->responseText());
        }
        reply->deleteLater();
    });

    // ⚠️ Gestion des erreurs SMTP
    connect(smtp, &SimpleMail::Server::smtpError, this,
            [](SimpleMail::Server::SmtpError err, const QString& text) {
                QMessageBox::critical(nullptr, "Erreur SMTP",
                                      "Erreur SMTP : " + QString::number(static_cast<int>(err)) +
                                          "\nDétail : " + text);
            });

    // 🔒 Gestion des erreurs SSL
    connect(smtp, &SimpleMail::Server::sslErrors, this,
            [](const QList<QSslError>& errors) {
                QString allErrors;
                for (const QSslError& err : errors) {
                    allErrors += err.errorString() + "\n";
                }
                QMessageBox::critical(nullptr, "Erreurs SSL", allErrors);
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
    model = triModel;  // 🔄 On remplace le modèle actuel pour conserver la cohérence

    actualiserTableView(); // Ajuster les tailles des colonnes
}



void MainWindow::on_pdfBtn_clicked() {
    QString fileName = QFileDialog::getSaveFileName(this, "Enregistrer en PDF", "", "Fichiers PDF (*.pdf)");
    if (fileName.isEmpty())
        return;

    QPdfWriter writer(fileName);
    writer.setPageSize(QPageSize(QPageSize::A4));
    writer.setResolution(300);  // meilleure qualité

    QTextDocument doc;
    QString html = "<h2 align='center'>Liste des fournisseurs</h2>";

    html += "<style>"
            "table { border-collapse: collapse; font-size: 14pt; margin-left: auto; margin-right: auto; }"
            "th, td { border: 1px solid black; padding: 6px; text-align: center; }"
            "th { background-color: #f0f0f0; font-weight: bold; }"
            "</style>";

    html += "<table>";
    html += "<tr><th style='width:60px;'>ID</th><th style='width:120px;'>Nom</th><th style='width:120px;'>Téléphone</th>"
            "<th style='width:200px;'>Email</th><th style='width:200px;'>Adresse</th><th style='width:120px;'>Type de service</th></tr>";

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

    // Fixe la largeur du document pour remplir l'A4 (~210mm => 793 px à 96 DPI)
    doc.setPageSize(QSizeF(793, 1122));  // A4 portrait en pixels @ 96 DPI

    QPainter painter(&writer);
    doc.drawContents(&painter);
    painter.end();

    QMessageBox::information(this, "PDF", "✅ Le fichier PDF a été généré avec succès !");


    QDesktopServices::openUrl(QUrl::fromLocalFile(fileName));

}

void MainWindow::showStatistiques() {
    qDebug() << "📊 Mise à jour des statistiques des fournisseurs par type de service...";

    // Si le widget n'a pas de layout, on en crée un
    if (!ui->chartContainerType->layout()) {
        QVBoxLayout *layout = new QVBoxLayout(ui->chartContainerType);
        layout->setContentsMargins(0, 0, 0, 0);
        ui->chartContainerType->setLayout(layout);
    }

    // 🔁 Nettoyer le contenu précédent du layout
    QLayout *layout = ui->chartContainerType->layout();
    while (QLayoutItem *item = layout->takeAt(0)) {
        if (item->widget()) {
            item->widget()->deleteLater();
        }
        delete item;
    }

    // 📈 Préparer les données SQL (compter le nombre de fournisseurs par type)
    QSqlQuery query;
    QMap<QString, int> typeCounts;

    if (query.exec("SELECT TYPESERVICE, COUNT(*) FROM FOURNISSEURS GROUP BY TYPESERVICE")) {
        while (query.next()) {
            QString type = query.value(0).toString();
            int count = query.value(1).toInt();
            typeCounts[type] = count;
        }
    } else {
        QMessageBox::critical(this, "Erreur SQL", "Impossible de récupérer les statistiques.\n" + query.lastError().text());
        return;
    }

    // 🧩 Construction du camembert
    QPieSeries *series = new QPieSeries();
    int total = 0;

    for (auto it = typeCounts.begin(); it != typeCounts.end(); ++it) {
        total += it.value();
    }

    for (auto it = typeCounts.begin(); it != typeCounts.end(); ++it) {
        double pourcentage = (total > 0) ? (it.value() * 100.0 / total) : 0;
        QPieSlice *slice = series->append(it.key(), it.value());
        slice->setLabel(QString("%1: %2%").arg(it.key()).arg(pourcentage, 0, 'f', 1));
        slice->setLabelVisible(true);

        // effet de zoom au survol
        connect(slice, &QPieSlice::hovered, [slice](bool hovered) {
            slice->setExploded(hovered);
            slice->setLabelFont(QFont("Arial", hovered ? 12 : 10, hovered ? QFont::Bold : QFont::Normal));
        });
    }

    // 🖼️ Création du graphique
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des fournisseurs par type de service");
    chart->legend()->setAlignment(Qt::AlignRight);
    chart->setAnimationOptions(QChart::AllAnimations);

    // 📄 Affichage
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    ui->chartContainerType->layout()->addWidget(chartView);

    qDebug() << "✅ Statistiques affichées avec succès.";
}



void MainWindow::on_statButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(7); // Page des statistiques
    showStatistiques();
}
