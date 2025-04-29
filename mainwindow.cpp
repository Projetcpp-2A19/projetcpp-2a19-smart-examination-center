#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "candidat.h"
#include <QMessageBox>
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QPieSeries>
#include <QPainter>
#include <QFileDialog>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <QtWidgets/QMessageBox>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtWidgets/QFileDialog>
#include <QPixmap>
#include <QDate>
#include <QDebug>
#include <QPdfWriter>
#include <QtQuick/QQuickImageProvider>
#include <QStandardPaths>
#include "../../Downloads/qrcodegen.hpp"
using namespace qrcodegen;
#include "equipement.h"
#include "arduino.h"




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    afficherCandidats(); // Charger les candidats au démarrage


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
        connect(A.getserial(), SIGNAL(readyRead()), this, SLOT(readSerialData()));
    } else {
        qDebug() << "Failed to connect Arduino, cannot proceed with reading data.";
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}
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
    if (candidat.ajouter()) {
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

    ui->tableView->clear();  // Effacer les anciennes données
    ui->tableView->setRowCount(0);
    ui->tableView->setColumnCount(7);  // Nombre de colonnes correspondant aux champs

    // Définir les en-têtes de colonnes
    QStringList labels = {"Code", "Prénom", "CIN", "Adresse", "Nom", "NumTel", "Niveau"};
    ui->tableView->setHorizontalHeaderLabels(labels);

    int row = 0;
    while (query.next()) {
        ui->tableView->insertRow(row);
        for (int col = 0; col < 7; col++) {
            ui->tableView->setItem(row, col, new QTableWidgetItem(query.value(col).toString()));
        }
        row++;
    }
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
    if (c.supprimer(code)) {
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
    if (c.modifier(code, prenom, cin, adresse, nom, numTel, niveau, photo)) {
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
    QString code = ui->lineCODE->text();

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

void MainWindow::on_btnStats_clicked()
{
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
void MainWindow::on_btnConvocation_clicked()
{
    QString code = ui->lineCode->text();

    if (code.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un code candidat.");
        ui->lineCode->setFocus();
        return;
    }

    genererConvocationPDF(code);
}
QImage MainWindow::genererQRCodeImage(const QString& data, int pixelParModule) {
    QrCode qr = QrCode::encodeText(data.toUtf8().constData(), QrCode::Ecc::LOW);
    int size = qr.getSize();
    QImage image(size * pixelParModule, size * pixelParModule, QImage::Format_RGB32);
    image.fill(Qt::white);

    QPainter painter(&image);
    painter.setBrush(Qt::black);
    painter.setPen(Qt::NoPen);

    for (int y = 0; y < size; ++y) {
        for (int x = 0; x < size; ++x) {
            if (qr.getModule(x, y)) {
                painter.drawRect(x * pixelParModule, y * pixelParModule,
                                 pixelParModule, pixelParModule);
            }
        }
    }

    return image;
}
bool MainWindow::genererConvocationPDF(const QString& codeCandidat)
{
    // 1. Récupération des données du candidat
    QSqlQuery query;
    query.prepare("SELECT NOM_CANDIDAT, PRENOM_CANDIDAT, CIN_CANDIDAT, "
                  "ADRESSE_CANDIDAT, PHOTO_CANDIDAT FROM CANDIDAT "
                  "WHERE CODE_CANDIDAT = ?");
    query.addBindValue(codeCandidat);

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur BD",
                              "Erreur lors de la requête :\n" + query.lastError().text());
        return false;
    }

    if (!query.next()) {
        QMessageBox::warning(this, "Non trouvé",
                             "Aucun candidat trouvé avec ce code.");
        return false;
    }

    // 2. Préparation des données
    QString nom = query.value("NOM_CANDIDAT").toString();
    QString prenom = query.value("PRENOM_CANDIDAT").toString();
    QString cin = query.value("CIN_CANDIDAT").toString();
    QString adresse = query.value("ADRESSE_CANDIDAT").toString();
    QByteArray photoData = query.value("PHOTO_CANDIDAT").toByteArray();
    QString date = QDate::currentDate().toString("dd/MM/yyyy");

    // 3. Sélection du fichier de sortie
    QString defaultName = QString("Convocation_%1_%2.pdf").arg(nom, prenom).replace(" ", "_");
    QString filePath = QFileDialog::getSaveFileName(this,
                                                    "Enregistrer la convocation",
                                                    QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/" + defaultName,
                                                    "Fichiers PDF (*.pdf)");

    if (filePath.isEmpty()) return false;
    if (!filePath.endsWith(".pdf", Qt::CaseInsensitive)) {
        filePath += ".pdf";
    }

    // 4. Création du PDF
    QPdfWriter pdf(filePath);
    pdf.setPageSize(QPageSize(QPageSize::A4));
    pdf.setResolution(120);
    pdf.setTitle(QString("Convocation %1 %2").arg(prenom, nom));

    QPainter painter(&pdf);
    if (!painter.isActive()) {
        QMessageBox::critical(this, "Erreur", "Impossible de créer le fichier PDF");
        return false;
    }

    const int margin = 40;
    const int pageWidth = pdf.width();
    const int contentWidth = pageWidth - 2 * margin;
    int yPos = 0;

    // En-tête
    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor(31, 97, 141));
    painter.drawRect(0, yPos, pageWidth, 60);
    painter.setPen(Qt::white);
    painter.setFont(QFont("Arial", 12, QFont::Bold));
    painter.drawText(margin, yPos + 30, "République Tunisienne");
    painter.drawText(margin, yPos + 50, "Ministère de l'Éducation");
    yPos += 80;

    // Titre
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 16, QFont::Bold));
    painter.drawText(0, yPos, pageWidth, 30, Qt::AlignCenter, "CONVOCATION OFFICIELLE");
    yPos += 40;

    // Informations
    painter.setFont(QFont("Arial", 10));
    QRect cadre(margin, yPos, contentWidth, 200);
    painter.setPen(QPen(Qt::black, 1));
    painter.drawRect(cadre);

    const int lineHeight = 30;
    const int labelWidth = 120;
    QStringList labels = {"Nom :", "Prénom :", "CIN :", "Adresse :", "Date d'émission :"};
    QStringList values = {nom, prenom, cin, adresse, date};

    for (int i = 0; i < labels.size(); ++i) {
        int currentY = yPos + 20 + (i * lineHeight);
        painter.setFont(QFont("Arial", 10, QFont::Bold));
        painter.drawText(margin + 10, currentY, labelWidth, lineHeight,
                         Qt::AlignLeft | Qt::AlignVCenter, labels[i]);
        painter.setFont(QFont("Arial", 10));
        painter.drawText(margin + labelWidth + 20, currentY,
                         contentWidth - labelWidth - 30, lineHeight,
                         Qt::AlignLeft | Qt::AlignVCenter, values[i]);
    }

    // Photo
    QRect photoRect(pageWidth - margin - 90, yPos + 20, 80, 100);
    painter.setPen(QPen(Qt::gray, 1));
    painter.drawRect(photoRect);

    if (!photoData.isEmpty()) {
        QPixmap photo;
        if (photo.loadFromData(photoData)) {
            QPixmap scaled = photo.scaled(photoRect.width() - 4, photoRect.height() - 4,
                                          Qt::KeepAspectRatio, Qt::SmoothTransformation);
            painter.drawPixmap(photoRect.x() + 2, photoRect.y() + 2, scaled);
        } else {
            painter.drawText(photoRect, Qt::AlignCenter, "Photo\ncorrompue");
        }
    } else {
        painter.drawText(photoRect, Qt::AlignCenter, "Photo\nabsente");
    }

    yPos += 220;

    // Signature
    painter.setFont(QFont("Arial", 10));
    painter.drawText(margin, yPos, 200, 20,
                     Qt::AlignLeft | Qt::AlignVCenter, "Le Responsable :");
    painter.drawLine(margin + 150, yPos + 10, margin + 350, yPos + 10);
    painter.drawText(pageWidth - margin - 100, yPos, 100, 20,
                     Qt::AlignRight | Qt::AlignVCenter, "Cachet");

    yPos += 60;

    // ✅ QR Code
    QString contenuQR = QString("Candidat: %1 %2\nCIN: %3\nCode: %4\nExamen: Mathématique Centre  - 12/06/2025")
                            .arg(nom, prenom, cin, codeCandidat);

    QImage qrImage = genererQRCodeImage(contenuQR, 5); // 5 pixels/module

    if (!qrImage.isNull()) {
        int qrSize = 100;
        int qrX = margin;
        int qrY = yPos;

        painter.drawImage(QRect(qrX, qrY, qrSize, qrSize), qrImage);
        painter.setFont(QFont("Arial", 9));
        painter.drawText(qrX, qrY + qrSize + 5, qrSize + 20, 20,
                         Qt::AlignLeft, "Scanner pour infos examen");
    }

    painter.end();

    return true;
}
#include <QBuffer>
#include <QBuffer>
#include <QImageWriter>
#include <QPainter>
#include "..\..\Downloads\qrcodegen.hpp"  // Important
using qrcodegen::QrCode;
using qrcodegen::QrSegment;
QImage generateQrCodeImage(const QString &text, int size = 150) {
    QrCode qr = QrCode::encodeText(text.toUtf8().constData(), QrCode::Ecc::LOW);
    const int border = 2;
    int scale = size / (qr.getSize() + border * 2);

    QImage image((qr.getSize() + border * 2) * scale, (qr.getSize() + border * 2) * scale, QImage::Format_RGB32);
    image.fill(Qt::white);
    QPainter painter(&image);
    painter.setBrush(Qt::black);
    painter.setPen(Qt::NoPen);

    for (int y = 0; y < qr.getSize(); y++) {
        for (int x = 0; x < qr.getSize(); x++) {
            if (qr.getModule(x, y)) {
                QRect r((x + border) * scale, (y + border) * scale, scale, scale);
                painter.drawRect(r);
            }
        }
    }

    return image;
}



void MainWindow::on_btnAfficherConvocation_clicked()
{
    QString code = ui->lineCodeCandidat->text().trimmed();
    if (code.isEmpty()) {
        QMessageBox::warning(this, "Champ vide", "Veuillez entrer un code candidat.");
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

    // --- Contenu QR ---
    QString contenuQR = QString("Candidat: %1 %2\nCIN: %3\nCode: %4\nExamen: Mathématique Centre 51  - 12/06/2025 - 8h - Durée : 3 heures")
                            .arg(nom, prenom, cin, code);

    // --- Vrai QR image générée ---
    QImage qrImage = generateQrCodeImage(contenuQR);  // ✅ Correction ici

    // --- QR en base64 ---
    QByteArray qrBa;
    QBuffer qrBuffer(&qrBa);
    qrBuffer.open(QIODevice::WriteOnly);
    qrImage.save(&qrBuffer, "PNG");
    QString qrBase64 = QString::fromLatin1(qrBa.toBase64());

    // --- Photo candidat en base64 ---
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

    // --- HTML final ---
    QString convocation = QString(R"(
    <div style='font-family:Arial; padding:30px; color:#1C1C1C; background-color:#fdfefe; border:2px solid #3498DB; border-radius:12px;'>

        <!-- EN-TETE -->
        <div style='text-align:center; margin-bottom:30px;'>
            <h3 style='margin:0; color:#154360;'>République Tunisienne</h3>
            <h3 style='margin:0; color:#154360;'>Ministère de l'Éducation</h3>
            <h2 style='margin-top:15px; color:#21618C;'>Convocation Officielle à l'Examen</h2>
        </div>

        <hr style='border:none; border-top:1px solid #ccc; margin-bottom:20px;' />

        <!-- INFORMATIONS -->
        <table style='width:100%;'>
            <tr>
                <td style='vertical-align:top; width:60%; padding-right:15px;'>
                    <p><strong style='color:#21618C;'>Nom :</strong> %1</p>
                    <p><strong style='color:#21618C;'>Prénom :</strong> %2</p>
                    <p><strong style='color:#21618C;'>CIN :</strong> %3</p>
                    <p><strong style='color:#21618C;'>Adresse :</strong> %4</p>
                    <p><strong style='color:#21618C;'>Téléphone :</strong> %5</p>
                    <p><strong style='color:#21618C;'>Niveau :</strong> %6</p>
                    <p style='color:#566573; font-style:italic;'>
                        Veuillez vous présenter à l'heure prévue pour votre examen.
                    </p>
                </td>
                <td style='text-align:center; vertical-align:top;'>
                    %7<br/><br/>
                    <img src='data:image/png;base64,%8' width='150' height='150' style='border:1px solid #999;' />
                    <p style='font-size:11px; color:#888;'>QR Code d'identification</p>
                </td>
            </tr>
        </table>

        <hr style='border:none; border-top:1px solid #ccc; margin-top:30px;' />

        <!-- MESSAGE ET CITATION EN BAS -->
        <div style='text-align:center; margin-top:20px;'>
            <p style='font-size:14px; color:#117864; font-weight:bold;'>Bonne chance à tous les candidats !</p>
            <p style='color:#7D3C98; font-style:italic; font-size:13px; margin:10px 50px;'>
                “Croyez en vos rêves et ils se réaliseront peut-être. Croyez en vous et ils se réaliseront sûrement.”<br/>
                – <strong>Martin Luther King</strong>
            </p>
        </div>

    </div>
)").arg(nom, prenom, cin, adresse, numtel, niveau,
                                   photoBase64.isEmpty()
                                       ? ""
                                       : QString("<img src='data:image/png;base64,%1' width='150' height='150' style='border-radius:8px; border:1px solid #bbb;' />").arg(photoBase64),
                                   qrBase64);

    ui->textBrowserConvocation->setHtml(convocation);
}









































void MainWindow::readSerialData() {
    // 1. Définir quantite manuellement
    int quantite = 20;
    qDebug() << "Quantité fixe (Qt):" << quantite;

    // 2. Définir ID fixe à 6
    int equipmentId = 6;
    qDebug() << "ID Equipement fixe:" << equipmentId;

    // 3. Définir quantityFromDB manuellement
    int quantityFromDB = 3;
    qDebug() << "Quantité fixe (DB simulée):" << quantityFromDB;

    // 4. Faire la somme
    int somme = quantite + quantityFromDB;
    qDebug() << "Somme :" << somme;

    // 5. Mettre à jour la base
    QSqlQuery updateQuery;
    updateQuery.prepare("UPDATE EQUIPEMENTS SET QUANTITE__EQUIPEMENT = :newQuantite WHERE ID_EQUIPEMENT = :id");
    updateQuery.bindValue(":newQuantite", somme);
    updateQuery.bindValue(":id", equipmentId);

    if (updateQuery.exec()) {
        qDebug() << "✅ Quantité mise à jour avec succès dans la base.";
    } else {
        qDebug() << "❌ Erreur lors du UPDATE:" << updateQuery.lastError();
        return;
    }

    // 6. Envoyer la somme à Arduino
    QByteArray dataToSend = "SOMME:" + QByteArray::number(somme) + "\n";
    A.write_to_arduino(dataToSend);
    qDebug() << "📤 Envoyé à Arduino:" << dataToSend;
}










