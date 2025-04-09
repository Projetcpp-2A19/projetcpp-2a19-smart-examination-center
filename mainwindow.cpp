#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMouseEvent>  // For detecting mouse events
#include <QPushButton>
#include <QHBoxLayout>
#include <QWidget>
#include "Etablissement.h"
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QDebug>
#include <QSqlError>  // Ajoute cette ligne pour inclure QSqlError
#include <QInputDialog>
#include <QTimer>
<<<<<<< HEAD
#include <QSqlQuery>
#include <QFileDialog>       // Pour QFileDialog
#include <QStandardPaths>    // Pour QStandardPaths
#include <QPrinter>          // Pour QPrinter
#include <QPainter>          // Pour QPainter
#include <QDate>




=======

>>>>>>> c72197f8b0853cd878fb0a1821205a90fddb9313
// Constructeur
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

<<<<<<< HEAD
    // Initialisations existantes...
    ui->tableView1->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);     // Connexions existantes...
    connect(ui->closeBtn, &QPushButton::clicked, this, &MainWindow::close);
    connect(ui->BinSuperbtn, &QPushButton::clicked, this, &MainWindow::on_BinSuperbtn_clicked);

    // Nouvelle connexion pour le bouton Nouveau
    connect(ui->newBtn, &QPushButton::clicked, this, &MainWindow::on_newBtn_clicked);
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

    // Initialiser les stats
    setupGovernorateStats();
=======
    // Initialiser le modèle pour afficher les établissements
    ui->tableView1->setModel(E.afficher());

    // Configurer le placeholder pour la recherche
    ui->lineEdit->setPlaceholderText("Rechercher...");

    // Connexion des boutons
    connect(ui->closeBtn, &QPushButton::clicked, this, &MainWindow::close);
    connect(ui->BinSuperbtn, &QPushButton::clicked, this, &MainWindow::on_BinSuperbtn_clicked);
>>>>>>> c72197f8b0853cd878fb0a1821205a90fddb9313
}

// Destructeur
MainWindow::~MainWindow()
{
    delete ui;
    delete model; // Supprimer le modèle pour éviter les fuites de mémoire
}

// Mettre à jour le tableau des établissements
void MainWindow::updateTableView()
{
    ui->tableView1->setModel(E.afficher());
}

// Ajouter un établissement
void MainWindow::on_Ajbtn_clicked()
{
    // Récupérer les valeurs des champs de saisie
    QString id = ui->idEtablissementLineEdit->text();
    QString gouvernorat = ui->gouvernoratLineEdit->text();
<<<<<<< HEAD
    QString type = ui->typeLineEdit->currentText();
=======
    QString type = ui->typeLineEdit->text();
>>>>>>> c72197f8b0853cd878fb0a1821205a90fddb9313
    QString directeur = ui->directeurLineEdit->text();
    QString nom = ui->nomLineEdit->text();
    int nombreSalle = ui->nombreSalleLineEdit->text().toInt();
    QString ville = ui->villeLineEdit->text();
<<<<<<< HEAD
    QString adresse = ui->adresseLineEdit->text(); // Nouveau champ


    // Vérifier que tous les champs sont remplis
    if (id.isEmpty() || gouvernorat.isEmpty() || type.isEmpty() || directeur.isEmpty() || nom.isEmpty() || ville.isEmpty() || adresse.isEmpty())
=======

    // Vérifier que tous les champs sont remplis
    if (id.isEmpty() || gouvernorat.isEmpty() || type.isEmpty() || directeur.isEmpty() || nom.isEmpty() || ville.isEmpty())
>>>>>>> c72197f8b0853cd878fb0a1821205a90fddb9313
    {
        QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis.");
        return;
    }
<<<<<<< HEAD
    if (nombreSalle <= 0)
    {
        QMessageBox::warning(this, "Erreur", "Le nombre de salles doit être supérieur à 0.");
        ui->nombreSalleLineEdit->setFocus();
        return;
    }

    // Créer un objet Etablissement
    Etablissement E(id, gouvernorat, type, directeur, nom, nombreSalle, ville, adresse);
=======

    // Créer un objet Etablissement
    Etablissement E(id, gouvernorat, type, directeur, nom, nombreSalle, ville);
>>>>>>> c72197f8b0853cd878fb0a1821205a90fddb9313

    // Ajouter l'établissement à la base de données
    if (E.ajouter())
    {
        QMessageBox::information(this, "Succès", "Établissement ajouté avec succès !");
        updateTableView();  // Mettre à jour le tableau
    }
    else
    {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout de l'établissement.");
    }
}

// Supprimer un établissement
void MainWindow::on_BinSuperbtn_clicked()
{
    // Récupérer l'index de la ligne sélectionnée dans le tableau
    QModelIndex index = ui->tableView1->selectionModel()->currentIndex();
    if (!index.isValid())
    {
        QMessageBox::warning(this, "Suppression", "Veuillez sélectionner un établissement à supprimer.");
        return;
    }

    // Récupérer l'ID de l'établissement sélectionné
    QString id = ui->tableView1->model()->data(index).toString();

    // Supprimer l'établissement de la base de données
    if (E.supprimer(id))
    {
        QMessageBox::information(this, "Succès", "Établissement supprimé avec succès !");
        updateTableView();  // Mettre à jour le tableau
    }
    else
    {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression.");
    }
}

// Modifier un établissement
<<<<<<< HEAD
// Modifier un établissement
=======
>>>>>>> c72197f8b0853cd878fb0a1821205a90fddb9313
void MainWindow::on_Modbtn_clicked()
{
    // Récupérer l'index de la ligne sélectionnée dans le tableau
    QModelIndex index = ui->tableView1->selectionModel()->currentIndex();
    if (!index.isValid())
    {
        QMessageBox::warning(this, "Modification", "Veuillez sélectionner un établissement à modifier.");
        return;
    }

<<<<<<< HEAD
    // Récupérer toutes les données de la ligne sélectionnée
    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(ui->tableView1->model());
    if (!model) return;

    int row = index.row();
    QString id = model->data(model->index(row, 0)).toString();
    QString gouvernorat = model->data(model->index(row, 1)).toString();
    QString type = model->data(model->index(row, 2)).toString();
    QString directeur = model->data(model->index(row, 3)).toString();
    QString nom = model->data(model->index(row, 4)).toString();
    int nombreSalle = model->data(model->index(row, 5)).toInt();
    QString ville = model->data(model->index(row, 6)).toString();
    QString adresse = model->data(model->index(row, 7)).toString();


    // Mettre à jour l'objet E avec les données récupérées
    E.setId(id);
    E.setGouvernorat(gouvernorat);
    E.setType(type);
    E.setDirecteur(directeur);
    E.setNom(nom);
    E.setNombreSalle(nombreSalle);
    E.setVille(ville);
    E.setAdresse(adresse);

    // Remplir les champs de saisie avec les données de l'établissement sélectionné
    ui->idEtablissementLineEdit->setText(id);
    ui->gouvernoratLineEdit->setText(gouvernorat);
    ui->typeLineEdit->setCurrentIndex(0);
    ui->directeurLineEdit->setText(directeur);
    ui->nomLineEdit->setText(nom);
    ui->nombreSalleLineEdit->setText(QString::number(nombreSalle));
    ui->villeLineEdit->setText(ville);
    ui->adresseLineEdit->setText(adresse);

}
=======
    // Récupérer l'ID de l'établissement sélectionné
    QString id = ui->tableView1->model()->data(index).toString();

    // Remplir les champs de saisie avec les données de l'établissement sélectionné
    E.setId(id);
    ui->idEtablissementLineEdit->setText(id);
    ui->gouvernoratLineEdit->setText(E.getGouvernorat());
    ui->typeLineEdit->setText(E.getType());
    ui->directeurLineEdit->setText(E.getDirecteur());
    ui->nomLineEdit->setText(E.getNom());
    ui->nombreSalleLineEdit->setText(QString::number(E.getNombreSalle()));
    ui->villeLineEdit->setText(E.getVille());
}

>>>>>>> c72197f8b0853cd878fb0a1821205a90fddb9313
// Sauvegarder les modifications
void MainWindow::on_SaveMod_clicked()
{
    // Récupérer les nouvelles valeurs des champs de saisie
    QString id = ui->idEtablissementLineEdit->text();
    QString gouvernorat = ui->gouvernoratLineEdit->text();
<<<<<<< HEAD
    QString type = ui->typeLineEdit->currentText();
=======
    QString type = ui->typeLineEdit->text();
>>>>>>> c72197f8b0853cd878fb0a1821205a90fddb9313
    QString directeur = ui->directeurLineEdit->text();
    QString nom = ui->nomLineEdit->text();
    int nombreSalle = ui->nombreSalleLineEdit->text().toInt();
    QString ville = ui->villeLineEdit->text();
<<<<<<< HEAD
    QString adresse = ui->adresseLineEdit->text();
=======
>>>>>>> c72197f8b0853cd878fb0a1821205a90fddb9313

    // Vérifier que tous les champs sont remplis
    if (id.isEmpty() || gouvernorat.isEmpty() || type.isEmpty() || directeur.isEmpty() || nom.isEmpty() || ville.isEmpty())
    {
        QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis.");
        return;
    }
<<<<<<< HEAD
    if (nombreSalle <= 0)
    {
        QMessageBox::warning(this, "Erreur", "Le nombre de salles doit être supérieur à 0.");
        ui->nombreSalleLineEdit->setFocus();
        return;
    }
=======

>>>>>>> c72197f8b0853cd878fb0a1821205a90fddb9313
    // Mettre à jour les données de l'établissement
    E.setId(id);
    E.setGouvernorat(gouvernorat);
    E.setType(type);
    E.setDirecteur(directeur);
    E.setNom(nom);
    E.setNombreSalle(nombreSalle);
    E.setVille(ville);
<<<<<<< HEAD
    E.setAdresse(adresse);
=======
>>>>>>> c72197f8b0853cd878fb0a1821205a90fddb9313

    // Modifier l'établissement dans la base de données
    if (E.modifier())
    {
        QMessageBox::information(this, "Succès", "Établissement modifié avec succès !");
        updateTableView();  // Mettre à jour le tableau
    }
    else
    {
        QMessageBox::critical(this, "Erreur", "Échec de la modification.");
    }
}
<<<<<<< HEAD
void MainWindow::on_newBtn_clicked()
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


    // Réinitialiser l'objet E (optionnel mais recommandé)
    E = Etablissement();

    // Donner le focus au premier champ pour une meilleure UX
    ui->idEtablissementLineEdit->setFocus();

    // Si vous avez ajouté le mode optionnel avec label
    // ui->titleLabel->setText("Ajouter un nouvel établissement");
    // ui->Ajbtn->setEnabled(true);
    // ui->SaveMod->setEnabled(false);
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
            model->setQuery(query);
        } else {
            qDebug() << "Erreur de recherche:" << query.lastError().text();
            return;
        }
    }

    // Définir les en-têtes comme dans Etablissement::afficher()
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Gouvernorat"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Directeur"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Nombre de Salles"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Ville"));

    ui->tableView1->setModel(model);
}
void MainWindow::on_sortGovernorate_clicked()
{
    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(ui->tableView1->model());

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


    ui->tableView1->setModel(model);
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
    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(ui->tableView1->model());
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
}


void MainWindow::setupGovernorateStats()
{
    // Requête pour compter les établissements par gouvernorat
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
void MainWindow::on_statsButton_clicked()
{
    // Création de la boîte de dialogue
    QDialog statsDialog(this);
    statsDialog.setWindowTitle("Statistiques par gouvernorat");
    statsDialog.resize(800, 600);

    // Création du layout
    QVBoxLayout *layout = new QVBoxLayout(&statsDialog);

    // Création du diagramme
    QPieSeries *series = new QPieSeries();

    // Requête pour obtenir les statistiques
    QSqlQuery query;
    if (!query.exec("SELECT GOUVERNORAT_ETABLISSEMENT, COUNT(*) FROM ETABLISSEMENT GROUP BY GOUVERNORAT_ETABLISSEMENT")) {
        qDebug() << "Erreur lors de l'exécution de la requête:" << query.lastError().text();
        return;
    }

    // Ajout des données au diagramme
    while (query.next()) {
        QString gouvernorat = query.value(0).toString();
        int count = query.value(1).toInt();
        QPieSlice *slice = series->append(gouvernorat, count);
        slice->setLabelVisible();
        slice->setLabel(QString("%1 (%2)").arg(gouvernorat).arg(count));
    }

    // Configuration du graphique
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des établissements par gouvernorat");
    chart->legend()->setAlignment(Qt::AlignRight);
    chart->setAnimationOptions(QChart::AllAnimations);

    // Création de la vue du graphique
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Ajout à la boîte de dialogue
    layout->addWidget(chartView);

    // Affichage de la boîte de dialogue
    statsDialog.exec();

    // Nettoyage mémoire (effectué automatiquement par le système de parenté Qt)
}

void MainWindow::on_mapsButton_clicked()
{
    if (!mapView) {
        mapView = new QQuickView;
        mapView->setSource(QUrl(QStringLiteral("qrc:/map.qml")));
        mapView->setResizeMode(QQuickView::SizeRootObjectToView);
        mapView->setColor(QColor(1, 121, 111));


        // Définir une taille plus petite
        mapView->setWidth(800);  // Par exemple
        mapView->setHeight(500);
        mapView->setTitle("Chercher une adresse");
    }

    mapView->show();
}


=======
>>>>>>> c72197f8b0853cd878fb0a1821205a90fddb9313

// Navigation dans l'interface
void MainWindow::on_examButton_clicked() { ui->stackedWidget->setCurrentIndex(1); }
void MainWindow::on_supButton_clicked() { ui->stackedWidget->setCurrentIndex(2); }
void MainWindow::on_eqButton_clicked() { ui->stackedWidget->setCurrentIndex(5); }
void MainWindow::on_FourButton_clicked() { ui->stackedWidget->setCurrentIndex(6); }
void MainWindow::on_candButton_clicked() { ui->stackedWidget->setCurrentIndex(7); }
void MainWindow::on_etaButton_clicked() { ui->stackedWidget->setCurrentIndex(8); }
void MainWindow::on_homeBtn_clicked() { ui->stackedWidget->setCurrentIndex(0); }
void MainWindow::on_notifBtn_clicked() { ui->stackedWidget->setCurrentIndex(3); }
void MainWindow::on_EvalAssist_clicked() { ui->stackedWidget->setCurrentIndex(5); }
