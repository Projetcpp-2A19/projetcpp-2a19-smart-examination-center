/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *fullMenu;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *supButton;
    QPushButton *eqButton;
    QPushButton *FourButton;
    QPushButton *candButton;
    QPushButton *etaButton;
    QPushButton *examButton;
    QPushButton *ModButton;
    QPushButton *EvalAssist;
    QWidget *Menu;
    QStackedWidget *stackedWidget;
    QWidget *HOME;
    QLabel *label_17;
    QWidget *GestExam;
    QLabel *label_13;
    QWidget *AffSuperv;
    QTableWidget *tableView;
    QLabel *label_27;
    QWidget *widget_9;
    QLabel *PdfLabel;
    QPushButton *pdfSuperbtn;
    QLabel *label;
    QPushButton *BinSuperbtn;
    QPushButton *Modbtn;
    QWidget *widget;
    QListWidget *listWidget_2;
    QLabel *label_11;
    QLabel *label_18;
    QLineEdit *PostLineEdit;
    QLabel *label_21;
    QLabel *label_20;
    QLineEdit *NomLineEdit;
    QLabel *label_24;
    QLineEdit *EmailLineEdit;
    QPushButton *Ajbtn;
    QListWidget *listWidget;
    QLabel *Trilabel4;
    QLineEdit *TriLineEdit4;
    QPushButton *rechBtn_2;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QWidget *notifSup;
    QLabel *label_31;
    QWidget *widget_2;
    QPushButton *smsEnv;
    QLineEdit *MsgSup;
    QLabel *smsMsg;
    QLineEdit *NumTelSup;
    QLabel *smsNB;
    QLabel *histo;
    QWidget *Historique;
    QWidget *gridLayoutWidget_2;
    QGridLayout *HistoConenu;
    QLabel *label_46;
    QPushButton *testnotf;
    QLabel *label_42;
    QLabel *label_41;
    QLabel *label_40;
    QLabel *label_47;
    QLabel *label_43;
    QLabel *label_39;
    QLabel *label_44;
    QLabel *label_45;
    QLabel *labelNotification1;
    QWidget *popupNotification;
    QLabel *labelNotificationContent;
    QWidget *ModSuperv;
    QWidget *chatBot;
    QLabel *chatbotTitre;
    QWidget *widget_4;
    QWidget *widget_5;
    QWidget *widget_6;
    QLabel *chatpropo;
    QLabel *label_4;
    QWidget *widget_7;
    QLineEdit *chatUser;
    QPushButton *sendChat;
    QLineEdit *chatConvo;
    QWidget *GestEquip;
    QLabel *label_14;
    QWidget *GestFourn;
    QLabel *label_12;
    QWidget *GestCand;
    QLabel *label_15;
    QWidget *GestEtab;
    QLabel *label_16;
    QPushButton *closeBtn;
    QPushButton *notifBtn;
    QPushButton *emailBtn;
    QPushButton *paramBtn;
    QPushButton *homeBtn;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1286, 740);
        MainWindow->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: #D9E6F2; /* Bleu pastel plus visible */"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        fullMenu = new QWidget(centralwidget);
        fullMenu->setObjectName("fullMenu");
        fullMenu->setGeometry(QRect(10, 20, 161, 641));
        label_2 = new QLabel(fullMenu);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 0, 63, 61));
        label_2->setCursor(QCursor(Qt::CursorShape::ForbiddenCursor));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/img/logo.png")));
        label_3 = new QLabel(fullMenu);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(70, 20, 91, 41));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"    font-size: 18px;\n"
"    font-weight: bold;"));
        supButton = new QPushButton(fullMenu);
        supButton->setObjectName("supButton");
        supButton->setGeometry(QRect(0, 170, 161, 41));
        supButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        supButton->setStyleSheet(QString::fromUtf8("QPushButton#supButton {\n"
"    background-color: #4A90E2;\n"
"    border: 2px solid #4A90E2;\n"
"    border-radius: 20px; /* Coins arrondis */\n"
"    padding: 8px 12px; /* Espacement interne */\n"
"    font-size: 16px; /* Taille de police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: black; /* Couleur du texte */\n"
"    selection-background-color: #A0B9D9; /* Couleur de s\303\251lection */\n"
"    qproperty-icon: url(:/new/prefix1/img/rechercher-des-personnes.png);\n"
"    qproperty-iconSize: 32px 32px; /* Taille de l'ic\303\264ne */\n"
"    transition: background-color 0.3s ease, border-color 0.3s ease; /* Animation fluide */\n"
"}\n"
"\n"
"/* Effet au survol */\n"
"QPushButton#supButton:hover { /* <-- PAS d'espace */\n"
"    background-color: #F9F9F9; /* Bleu tr\303\250s clair */\n"
"    border-color: #6C91C2; /* Bleu un peu plus fonc\303\251 */\n"
"}\n"
"\n"
"/* Effet lors du clic */\n"
"QPushButton#supButton:pressed { /* <-- PAS d'espace */\n"
"    background-color: #C74C4C; /* Rouge "
                        "fonc\303\251 */\n"
"    border-color: #C74C4C; /* Rouge fonc\303\251 */\n"
"    color: #FFFFFF; /* Texte blanc pour contraste */\n"
"}\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/rechercher-des-personnes.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        supButton->setIcon(icon);
        supButton->setCheckable(true);
        supButton->setAutoExclusive(true);
        eqButton = new QPushButton(fullMenu);
        eqButton->setObjectName("eqButton");
        eqButton->setGeometry(QRect(0, 240, 161, 41));
        eqButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        eqButton->setStyleSheet(QString::fromUtf8("QPushButton#eqButton {\n"
"    background-color: #4A90E2;\n"
"    border: 2px solid #4A90E2;\n"
"    border-radius: 20px; /* Coins arrondis */\n"
"    padding: 8px 12px; /* Espacement interne */\n"
"    font-size: 16px; /* Taille de police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: black; /* Couleur du texte */\n"
"    selection-background-color: #A0B9D9; /* Couleur de s\303\251lection */\n"
"    qproperty-icon: url(:/new/prefix1/img/equipe.png);\n"
"    qproperty-iconSize: 32px 32px; /* Taille de l'ic\303\264ne */\n"
"    transition: background-color 0.3s ease, border-color 0.3s ease; /* Animation fluide */\n"
"}\n"
"\n"
"/* Effet au survol */\n"
"QPushButton#eqButton:hover { /* Suppression de l'espace */\n"
"    background-color: #F9F9F9; /* Bleu tr\303\250s clair */\n"
"    border-color: #6C91C2; /* Bleu un peu plus fonc\303\251 */\n"
"}\n"
"\n"
"/* Effet lors du clic */\n"
"QPushButton#eqButton:pressed { /* Suppression de l'espace */\n"
"    background-color: #C74C4C; /* Rouge fonc\303"
                        "\251 */\n"
"    border-color: #C74C4C; /* Rouge fonc\303\251 */\n"
"    color: #FFFFFF; /* Texte blanc pour contraste */\n"
"}\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/equipe.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        eqButton->setIcon(icon1);
        eqButton->setCheckable(true);
        eqButton->setAutoExclusive(true);
        FourButton = new QPushButton(fullMenu);
        FourButton->setObjectName("FourButton");
        FourButton->setGeometry(QRect(0, 310, 161, 41));
        FourButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        FourButton->setStyleSheet(QString::fromUtf8("QPushButton#FourButton {\n"
"    background-color: #4A90E2;\n"
"    border: 2px solid #4A90E2;\n"
"    border-radius: 20px; /* Coins arrondis */\n"
"    padding: 8px 12px; /* Espacement interne */\n"
"    font-size: 16px; /* Taille de police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: black; /* Couleur du texte */\n"
"    selection-background-color: #A0B9D9; /* Couleur de s\303\251lection */\n"
"    qproperty-icon: url(:/new/prefix1/img/livreur.png); \n"
"    qproperty-iconSize: 32px 32px; /* Taille de l'ic\303\264ne */\n"
"    transition: background-color 0.3s ease, border-color 0.3s ease; /* Animation fluide */\n"
"}\n"
"\n"
"/* Effet au survol */\n"
"QPushButton#FourButton:hover { /* Suppression de l'espace */\n"
"    background-color: #F9F9F9; /* Bleu tr\303\250s clair */\n"
"    border-color: #6C91C2; /* Bleu un peu plus fonc\303\251 */\n"
"}\n"
"\n"
"/* Effet lors du clic */\n"
"QPushButton#FourButton:pressed { /* Suppression de l'espace */\n"
"    background-color: #C74C4C; /* Rouge"
                        " fonc\303\251 */\n"
"    border-color: #C74C4C; /* Rouge fonc\303\251 */\n"
"    color: #FFFFFF; /* Texte blanc pour contraste */\n"
"}\n"
""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/livreur.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        FourButton->setIcon(icon2);
        FourButton->setCheckable(true);
        FourButton->setAutoExclusive(true);
        candButton = new QPushButton(fullMenu);
        candButton->setObjectName("candButton");
        candButton->setGeometry(QRect(0, 380, 161, 41));
        candButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        candButton->setStyleSheet(QString::fromUtf8("QPushButton#candButton {\n"
"    background-color: #4A90E2;\n"
"    border: 2px solid #4A90E2;\n"
"    border-radius: 20px; /* Coins arrondis */\n"
"    padding: 8px 12px; /* Espacement interne */\n"
"    font-size: 16px; /* Taille de police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: black; /* Couleur du texte */\n"
"    selection-background-color: #A0B9D9; /* Couleur de s\303\251lection */\n"
"    qproperty-icon: url(:/new/prefix1/img/candidat.png);\n"
"    qproperty-iconSize: 32px 32px; /* Taille de l'ic\303\264ne */\n"
"    transition: background-color 0.3s ease, border-color 0.3s ease; /* Animation fluide */\n"
"}\n"
"\n"
"/* Effet au survol */\n"
"QPushButton#candButton:hover { /* Suppression de l'espace */\n"
"    background-color: #F9F9F9; /* Bleu tr\303\250s clair */\n"
"    border-color: #6C91C2; /* Bleu un peu plus fonc\303\251 */\n"
"}\n"
"\n"
"/* Effet lors du clic */\n"
"QPushButton#candButton:pressed { /* Suppression de l'espace */\n"
"    background-color: #C74C4C; /* Rouge"
                        " fonc\303\251 */\n"
"    border-color: #C74C4C; /* Rouge fonc\303\251 */\n"
"    color: #FFFFFF; /* Texte blanc pour contraste */\n"
"}\n"
""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/img/candidat.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        candButton->setIcon(icon3);
        candButton->setCheckable(true);
        candButton->setAutoExclusive(true);
        etaButton = new QPushButton(fullMenu);
        etaButton->setObjectName("etaButton");
        etaButton->setGeometry(QRect(0, 450, 161, 41));
        etaButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        etaButton->setStyleSheet(QString::fromUtf8("QPushButton#etaButton {\n"
"    background-color: #4A90E2;\n"
"    border: 2px solid #4A90E2;\n"
"    border-radius: 20px; /* Coins arrondis */\n"
"    padding: 8px 12px; /* Espacement interne */\n"
"    font-size: 16px; /* Taille de police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: black; /* Couleur du texte */\n"
"    selection-background-color: #A0B9D9; /* Couleur de s\303\251lection */\n"
"    qproperty-icon: url(:/new/prefix1/img/batiment-educatif.png);\n"
"    qproperty-iconSize: 32px 32px; /* Taille de l'ic\303\264ne */\n"
"    transition: background-color 0.3s ease, border-color 0.3s ease; /* Animation fluide */\n"
"}\n"
"\n"
"/* Effet au survol */\n"
"QPushButton#etaButton:hover { /* Suppression de l'espace */\n"
"    background-color: #F9F9F9; /* Bleu tr\303\250s clair */\n"
"    border-color: #6C91C2; /* Bleu un peu plus fonc\303\251 */\n"
"}\n"
"\n"
"/* Effet lors du clic */\n"
"QPushButton#etaButton:pressed { /* Suppression de l'espace */\n"
"    background-color: #C74C4C; /*"
                        " Rouge fonc\303\251 */\n"
"    border-color: #C74C4C; /* Rouge fonc\303\251 */\n"
"    color: #FFFFFF; /* Texte blanc pour contraste */\n"
"}\n"
""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/img/batiment-educatif.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        etaButton->setIcon(icon4);
        etaButton->setCheckable(true);
        etaButton->setAutoExclusive(true);
        examButton = new QPushButton(fullMenu);
        examButton->setObjectName("examButton");
        examButton->setGeometry(QRect(0, 100, 161, 41));
        examButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        examButton->setStyleSheet(QString::fromUtf8("QPushButton#examButton {\n"
"    background-color: #4A90E2;\n"
"     border: 2px solid #4A90E2;\n"
"    border-radius: 20px; /* Coins arrondis */\n"
"    padding: 8px 12px; /* Espacement interne */\n"
"    font-size: 16px; /* Taille de police */\n"
"\n"
"font-weight: bold; \n"
"    color: black; /* Couleur du texte */\n"
"    selection-background-color: #A0B9D9; /* Couleur de s\303\251lection */\n"
"    qproperty-icon:  url(:/new/prefix1/img/examen.png);\n"
"    qproperty-iconSize: 32px 32px; /* Taille de l'ic\303\264ne */\n"
"    transition: background-color 0.3s ease, border-color 0.3s ease; /* Animation fluide */\n"
"}\n"
"\n"
"/* Effet au survol */\n"
"QPushButton#examButton:hover {\n"
"    background-color: #F9F9F9; /* Bleu tr\303\250s clair */\n"
"    border-color: #6C91C2; /* Bleu un peu plus fonc\303\251 */\n"
"}\n"
"\n"
"/* Effet lors du clic */\n"
"QPushButton#examButton:pressed {\n"
"    background-color: #C74C4C;; /* Bleu-gris pastel */\n"
"    border-color: #C74C4C; /* Bleu fonc\303\251 */\n"
"   "
                        " color: #FFFFFF; /* Texte blanc pour contraste */\n"
"}\n"
""));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/img/examen.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        examButton->setIcon(icon5);
        examButton->setIconSize(QSize(32, 32));
        examButton->setCheckable(true);
        examButton->setAutoExclusive(true);
        ModButton = new QPushButton(fullMenu);
        ModButton->setObjectName("ModButton");
        ModButton->setGeometry(QRect(0, 540, 161, 41));
        ModButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        ModButton->setStyleSheet(QString::fromUtf8("QPushButton#ModButton  {\n"
"    background-color: rgb(1, 121, 111); /* Vert sapin */\n"
"    color: white;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    border-radius: 18px; /* La moiti\303\251 de la taille pour un cercle */\n"
"    border: none;\n"
"    transition: all 0.3s ease-in-out;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QPushButton#ModButton:hover {\n"
"    background-color: rgb(3, 150, 138); /* Vert sapin plus clair au survol */\n"
"    box-shadow: 0px 3px 8px rgba(1, 121, 111, 0.4);\n"
"}\n"
"\n"
"QPushButton#ModButton :pressed {\n"
"    background-color: rgb(0, 100, 92); /* Vert sapin plus fonc\303\251*/\n"
"    box-shadow: 0px 2px 5px rgba(1, 121, 111, 0.5);\n"
"}"));
        QIcon icon6(QIcon::fromTheme(QIcon::ThemeIcon::MailMessageNew));
        ModButton->setIcon(icon6);
        EvalAssist = new QPushButton(fullMenu);
        EvalAssist->setObjectName("EvalAssist");
        EvalAssist->setGeometry(QRect(0, 590, 161, 41));
        EvalAssist->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        EvalAssist->setStyleSheet(QString::fromUtf8("QPushButton#EvalAssist  {\n"
"    background-color: rgb(1, 121, 111); /* Vert sapin */\n"
"    color: white;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    border-radius: 18px; /* La moiti\303\251 de la taille pour un cercle */\n"
"    border: none;\n"
"    transition: all 0.3s ease-in-out;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QPushButton#EvalAssist:hover {\n"
"    background-color: rgb(3, 150, 138); /* Vert sapin plus clair au survol */\n"
"    box-shadow: 0px 3px 8px rgba(1, 121, 111, 0.4);\n"
"}\n"
"\n"
"QPushButton#EvalAssist :pressed {\n"
"    background-color: rgb(0, 100, 92); /* Vert sapin plus fonc\303\251*/\n"
"    box-shadow: 0px 2px 5px rgba(1, 121, 111, 0.5);\n"
"}"));
        EvalAssist->setIcon(icon6);
        etaButton->raise();
        candButton->raise();
        eqButton->raise();
        examButton->raise();
        label_2->raise();
        label_3->raise();
        supButton->raise();
        FourButton->raise();
        ModButton->raise();
        EvalAssist->raise();
        Menu = new QWidget(centralwidget);
        Menu->setObjectName("Menu");
        Menu->setGeometry(QRect(191, 60, 1131, 831));
        stackedWidget = new QStackedWidget(Menu);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, -10, 1091, 801));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(234, 251, 255);\n"
""));
        HOME = new QWidget();
        HOME->setObjectName("HOME");
        HOME->setStyleSheet(QString::fromUtf8("color: rgb(215, 255, 246);"));
        label_17 = new QLabel(HOME);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(50, 30, 571, 431));
        label_17->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/img/logo.png);\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-size: contain; /* ou 'cover' selon l'effet souhait\303\251 */"));
        stackedWidget->addWidget(HOME);
        GestExam = new QWidget();
        GestExam->setObjectName("GestExam");
        label_13 = new QLabel(GestExam);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(250, 40, 181, 41));
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        stackedWidget->addWidget(GestExam);
        AffSuperv = new QWidget();
        AffSuperv->setObjectName("AffSuperv");
        tableView = new QTableWidget(AffSuperv);
        if (tableView->columnCount() < 4)
            tableView->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableView->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableView->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableView->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableView->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(30, 70, 501, 281));
        tableView->setStyleSheet(QString::fromUtf8("#tableWidget1 {\n"
"   border: 2px solid #A0B9D9; /* L\303\251g\303\250re bordure bleu-gris pastel */\n"
"    border-radius: 10px;        /* Coins arrondis */\n"
"    background-color: #F0F4F8; /* Fond l\303\251g\303\250rement gris-bleu */\n"
"    gridline-color: #A0B9D9; /* Couleur des lignes du tableau */\n"
"    selection-background-color: #4A90E2; /* Couleur de s\303\251lection */\n"
"    selection-color: white; /* Texte blanc lors de la s\303\251lection */\n"
"}\n"
"\n"
"#tableWidget1::item {\n"
"    padding: 8px; /* Espacement entre le texte et la cellule */\n"
"    color: #2C3E50; /* Texte bleu fonc\303\251 */\n"
"}\n"
"\n"
"#tableWidget1::item:selected {\n"
"    background-color: #4A90E2; /* Fond bleu lors de la s\303\251lection */\n"
"    color: white; /* Texte blanc */\n"
"}\n"
"\n"
"#tableWidget1 QHeaderView::section {\n"
"    background-color: #A0B9D9; /* En-t\303\252te avec une teinte bleu-gris */\n"
"    color: #2C3E50; /* Texte des en-t\303\252tes en bleu fonc\303\251 */\n"
"     padding: 5px;  "
                        "\n"
"    border: 2px solid #A0B9D9; /* L\303\251g\303\250re bordure bleu-gris pastel */\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#tableWidget1 QTableCornerButton::section {\n"
"    background-color: #4A90E2; /* Coin sup\303\251rieur gauche */\n"
"     border: 2px solid #A0B9D9; /* L\303\251g\303\250re bordure bleu-gris pastel */\n"
"}\n"
"\n"
"   \n"
"       "));
        tableView->horizontalHeader()->setVisible(true);
        label_27 = new QLabel(AffSuperv);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(20, 20, 301, 31));
        label_27->setStyleSheet(QString::fromUtf8("#label_27 { \n"
"    font-size: 25px; /* Taille r\303\251duite du texte */\n"
"    font-weight: bold; /* Texte en gras pour un effet titre */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour une bonne lisibilit\303\251 */\n"
"    background-color: transparent; /* Fond transparent */\n"
"    padding: 4px 8px; /* Espacement pour l'a\303\251ration */\n"
"    \n"
"    text-align: center; /* Centrage du texte */\n"
"}\n"
""));
        widget_9 = new QWidget(AffSuperv);
        widget_9->setObjectName("widget_9");
        widget_9->setGeometry(QRect(30, 460, 551, 171));
        widget_9->setStyleSheet(QString::fromUtf8("#widget_9 {\n"
"    border: 2px dashed #3498db; /* Bordure en pointill\303\251s bleue */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    background-color: #f8f9fa; /* Couleur de fond l\303\251g\303\250re */\n"
"}\n"
""));
        PdfLabel = new QLabel(widget_9);
        PdfLabel->setObjectName("PdfLabel");
        PdfLabel->setGeometry(QRect(50, 90, 41, 41));
        PdfLabel->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/img/pdf.png);"));
        pdfSuperbtn = new QPushButton(widget_9);
        pdfSuperbtn->setObjectName("pdfSuperbtn");
        pdfSuperbtn->setGeometry(QRect(120, 90, 411, 41));
        pdfSuperbtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pdfSuperbtn->setStyleSheet(QString::fromUtf8("QPushButton#pdfSuperbtn {\n"
"    background-color: #3A7BD5; \n"
"    color: white;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    padding: 10px 20px; /* Uniformiser le padding */\n"
"    border-radius: 20px;\n"
"    border: 2px dashed #3A7BD5;\n"
"    text-align: center; /* Alignement horizontal */\n"
"    qproperty-alignment: 'AlignCenter'; /* Alignement Qt */\n"
"}\n"
"\n"
"QPushButton#pdfSuperbtn:hover {\n"
"    background-color: #A0C4FF; \n"
"    border: 2px dashed #A0C4FF; \n"
"    color: #F9F9F9; \n"
"}\n"
"\n"
"QPushButton#pdfSuperbtn:pressed {\n"
"    background-color: #A8D5BA; \n"
"    border: 2px dashed #5A9BD5;\n"
"}\n"
""));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/img/pdf.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pdfSuperbtn->setIcon(icon7);
        pdfSuperbtn->setIconSize(QSize(20, 20));
        pdfSuperbtn->setCheckable(true);
        pdfSuperbtn->setAutoExclusive(true);
        label = new QLabel(AffSuperv);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 440, 181, 31));
        label->setStyleSheet(QString::fromUtf8(" font-size: 20px; /* Taille r\303\251duite du texte */\n"
"    font-weight: bold; /* Texte en gras pour un effet titre */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour une bonne lisibilit\303\251 */\n"
"    \n"
"    padding: 4px 8px; /* Espacement pour l'a\303\251ration */"));
        BinSuperbtn = new QPushButton(AffSuperv);
        BinSuperbtn->setObjectName("BinSuperbtn");
        BinSuperbtn->setGeometry(QRect(30, 370, 51, 41));
        BinSuperbtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        BinSuperbtn->setStyleSheet(QString::fromUtf8("QPushButton#BinSuperbtn {\n"
"    background-color: #D64545;\n"
"    color: white;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    padding: 10px 20px; /* Uniformiser le padding */\n"
"    border-radius: 20px;\n"
"   /* border: 2px dashed #3A7BD5;\n"
"    text-align: center; /* Alignement horizontal */\n"
"    qproperty-alignment: 'AlignCenter'; /* Alignement Qt */\n"
"}\n"
"\n"
"QPushButton#BinSuperbtn:hover {\n"
"    background-color: #E06666; \n"
"    \n"
"    color: #F9F9F9; \n"
"}\n"
"\n"
"QPushButton#BinSuperbtn:pressed {\n"
"    background-color: #B83232; \n"
"  \n"
"}\n"
""));
        QIcon icon8(QIcon::fromTheme(QIcon::ThemeIcon::EditDelete));
        BinSuperbtn->setIcon(icon8);
        BinSuperbtn->setIconSize(QSize(20, 20));
        BinSuperbtn->setCheckable(true);
        BinSuperbtn->setAutoExclusive(true);
        Modbtn = new QPushButton(AffSuperv);
        Modbtn->setObjectName("Modbtn");
        Modbtn->setGeometry(QRect(90, 370, 51, 41));
        Modbtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        Modbtn->setStyleSheet(QString::fromUtf8("QPushButton#Modbtn {\n"
"    background-color: #3A7BD5; \n"
"    color: white;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    padding: 10px 20px; /* Uniformiser le padding */\n"
"    border-radius: 20px;\n"
"    /*border: 2px dashed #3A7BD5;*/\n"
"    text-align: center; /* Alignement horizontal */\n"
"    qproperty-alignment: 'AlignCenter'; /* Alignement Qt */\n"
"}\n"
"\n"
"QPushButton#Modbtn:hover {\n"
"    background-color: #A0C4FF; \n"
"  \n"
"    color: #F9F9F9; \n"
"}\n"
"\n"
"QPushButton#Modbtn:pressed {\n"
"    background-color: #A8D5BA; \n"
"   \n"
"}\n"
""));
        Modbtn->setIcon(icon6);
        widget = new QWidget(AffSuperv);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(600, 120, 481, 541));
        listWidget_2 = new QListWidget(widget);
        listWidget_2->setObjectName("listWidget_2");
        listWidget_2->setGeometry(QRect(10, 0, 471, 511));
        listWidget_2->setStyleSheet(QString::fromUtf8("QListWidget {\n"
"   border: 2px solid #A0B9D9; /* L\303\251g\303\250re bordure bleu-gris pastel */\n"
"    border-radius: 10px;        /* Coins arrondis */\n"
"    padding: 5px;               /* Un peu d'espace \303\240 l'int\303\251rieur */\n"
"}\n"
""));
        label_11 = new QLabel(widget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(70, 10, 391, 61));
        label_11->setStyleSheet(QString::fromUtf8("#label_11 { \n"
"    font-size: 30px; /* Taille r\303\251duite du texte */\n"
"    font-weight: bold; /* Texte en gras pour un effet titre */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour une bonne lisibilit\303\251 */\n"
"    background-color: transparent; /* Fond transparent */\n"
"    padding: 4px 8px; /* Espacement pour l'a\303\251ration */\n"
"   \n"
"    \n"
"    text-align: center; /* Centrage du texte */\n"
"}\n"
""));
        label_18 = new QLabel(widget);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(100, 100, 63, 20));
        label_18->setStyleSheet(QString::fromUtf8("color: rgb(12, 12, 12);"));
        PostLineEdit = new QLineEdit(widget);
        PostLineEdit->setObjectName("PostLineEdit");
        PostLineEdit->setGeometry(QRect(180, 420, 171, 41));
        PostLineEdit->setStyleSheet(QString::fromUtf8("#PostLineEdit {\n"
"    background-color: #FFFFFF; /* Blanc pur pour un bon contraste */\n"
"    border: 2px solid #A0B9D9; /* Bordure bleu-gris pastel */\n"
"    border-radius: 20px; /* Coins arrondis */\n"
"    padding: 8px 12px; /* Espacement interne */\n"
"    font-size: 16px; /* Taille de police agr\303\251able */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour le texte */\n"
"    selection-background-color: #A0B9D9; /* Couleur de s\303\251lection */\n"
"}\n"
"\n"
"#PostLineEdit:focus {\n"
"    border: 2px solid #4A90E2; /* Bleu clair plus intense lors du focus */\n"
"    background-color: #F0F4F8; /* L\303\251g\303\250re variation pour effet moderne */\n"
"}\n"
"\n"
""));
        label_21 = new QLabel(widget);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(110, 360, 63, 20));
        label_21->setStyleSheet(QString::fromUtf8("color: rgb(12, 12, 12);"));
        label_20 = new QLabel(widget);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(90, 220, 63, 20));
        label_20->setStyleSheet(QString::fromUtf8("color: rgb(12, 12, 12);"));
        NomLineEdit = new QLineEdit(widget);
        NomLineEdit->setObjectName("NomLineEdit");
        NomLineEdit->setGeometry(QRect(160, 90, 161, 41));
        NomLineEdit->setStyleSheet(QString::fromUtf8("#NomLineEdit {\n"
"    background-color: #FFFFFF; /* Blanc pur pour un bon contraste */\n"
"    border: 2px solid #A0B9D9; /* Bordure bleu-gris pastel */\n"
"    border-radius: 20px; /* Coins arrondis */\n"
"    padding: 8px 12px; /* Espacement interne */\n"
"    font-size: 16px; /* Taille de police agr\303\251able */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour le texte */\n"
"    selection-background-color: #A0B9D9; /* Couleur de s\303\251lection */\n"
"}\n"
"\n"
"#NomLineEdit:focus {\n"
"    border: 2px solid #4A90E2; /* Bleu clair plus intense lors du focus */\n"
"    background-color: #F0F4F8; /* L\303\251g\303\250re variation pour effet moderne */\n"
"}\n"
"\n"
""));
        label_24 = new QLabel(widget);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(110, 440, 63, 20));
        label_24->setStyleSheet(QString::fromUtf8("color: rgb(12, 12, 12);"));
        EmailLineEdit = new QLineEdit(widget);
        EmailLineEdit->setObjectName("EmailLineEdit");
        EmailLineEdit->setGeometry(QRect(170, 350, 181, 41));
        EmailLineEdit->setStyleSheet(QString::fromUtf8("#EmailLineEdit {\n"
"    background-color: #FFFFFF; /* Blanc pur pour un bon contraste */\n"
"    border: 2px solid #A0B9D9; /* Bordure bleu-gris pastel */\n"
"    border-radius: 20px; /* Coins arrondis */\n"
"    padding: 8px 12px; /* Espacement interne */\n"
"    font-size: 16px; /* Taille de police agr\303\251able */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour le texte */\n"
"    selection-background-color: #A0B9D9; /* Couleur de s\303\251lection */\n"
"}\n"
"\n"
"#EmailLineEdit:focus {\n"
"    border: 2px solid #4A90E2; /* Bleu clair plus intense lors du focus */\n"
"    background-color: #F0F4F8; /* L\303\251g\303\250re variation pour effet moderne */\n"
"}\n"
"\n"
""));
        Ajbtn = new QPushButton(widget);
        Ajbtn->setObjectName("Ajbtn");
        Ajbtn->setGeometry(QRect(350, 460, 121, 41));
        Ajbtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        Ajbtn->setStyleSheet(QString::fromUtf8("QPushButton#Ajbtn {\n"
"    background-color: #3A7BD5; \n"
"    color: white;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    padding: 10px 20px; /* Uniformiser le padding */\n"
"    border-radius: 20px;\n"
"    border: 2px dashed #3A7BD5;\n"
"    text-align: center; /* Alignement horizontal */\n"
"    qproperty-alignment: 'AlignCenter'; /* Alignement Qt */\n"
"}\n"
"\n"
"QPushButton#Ajbtn:hover {\n"
"    background-color: #A0C4FF; \n"
"    border: 2px dashed #A0C4FF; \n"
"    color: #F9F9F9; \n"
"}\n"
"\n"
"QPushButton#Ajbtn:pressed {\n"
"    background-color: #A8D5BA; \n"
"    border: 2px dashed #5A9BD5;\n"
"}\n"
""));
        listWidget = new QListWidget(widget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(160, 140, 256, 192));
        Trilabel4 = new QLabel(AffSuperv);
        Trilabel4->setObjectName("Trilabel4");
        Trilabel4->setGeometry(QRect(350, 20, 151, 31));
        Trilabel4->setStyleSheet(QString::fromUtf8("#Trilabel4 { \n"
"    font-size: 20px; /* Taille r\303\251duite du texte */\n"
"    font-weight: bold; /* Texte en gras pour un effet titre */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour une bonne lisibilit\303\251 */\n"
"    background-color: transparent; /* Fond transparent */\n"
"    padding: 4px 8px; /* Espacement pour l'a\303\251ration */\n"
"  \n"
"    border-radius: 5px; /* Coins l\303\251g\303\250rement arrondis */\n"
"    text-align: center; /* Centrage du texte */\n"
"}\n"
""));
        TriLineEdit4 = new QLineEdit(AffSuperv);
        TriLineEdit4->setObjectName("TriLineEdit4");
        TriLineEdit4->setGeometry(QRect(490, 20, 211, 41));
        TriLineEdit4->setStyleSheet(QString::fromUtf8("#TriLineEdit4 { \n"
"    background-color: #FFFFFF; /* Blanc pur pour un bon contraste */\n"
"    border: 2px solid rgb(1, 121, 111); /* Bordure rouge brique pastel */\n"
"\n"
"    border-radius: 20px; /* Coins arrondis */\n"
"    padding: 8px 12px; /* Espacement interne */\n"
"    font-size: 16px; /* Taille de police agr\303\251able */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour le texte */\n"
"    selection-background-color: #B85042; /* Couleur de s\303\251lection */\n"
"}\n"
"\n"
"#TriLineEdit4:focus { \n"
"    border: 2px solid rgb(1, 121, 111); /* Rouge brique l\303\251g\303\250rement plus clair au focus */\n"
"    background-color: #F8E8E6; /* L\303\251g\303\250re variation pour effet moderne */\n"
"}\n"
""));
        rechBtn_2 = new QPushButton(AffSuperv);
        rechBtn_2->setObjectName("rechBtn_2");
        rechBtn_2->setGeometry(QRect(900, 20, 61, 41));
        rechBtn_2->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        rechBtn_2->setStyleSheet(QString::fromUtf8("QPushButton#rechBtn_2{\n"
"    background-color: rgb(234, 251, 255);\n"
"    color: white;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    padding: 10px 111px 10px 20px; /* Increase right padding */\n"
"    border-radius: 20px;\n"
"    border: 2px solid #4A90E2;\n"
"    text-align: left; /* Align text to the left */\n"
" \n"
"}\n"
"\n"
"QPushButton#rechBtn_2:hover {\n"
"    background-color: #5A9BD5; /* Bleu plus clair au survol */\n"
"    border: 2px solid #F9F9F9; /* Bordure plus claire */\n"
"    color: #F9F9F9; /* Texte plus clair */\n"
"}\n"
"\n"
"QPushButton#rechBtn_2:pressed {\n"
"    background-color: #C74C4C; /* Rouge brique au clic */\n"
"    border: 2px solid #C74C4C;\n"
"}\n"
""));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/new/prefix1/img/recherche.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        rechBtn_2->setIcon(icon9);
        comboBox = new QComboBox(AffSuperv);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(980, 30, 91, 31));
        pushButton = new QPushButton(AffSuperv);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(730, 20, 161, 41));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"       background-color: rgb(1, 121, 111);\n"
"    color: white;\n"
"    border: none;\n"
"    padding: 10px 20px;\n"
"    text-align: center;\n"
"    text-decoration: none;\n"
"    display: inline-block;\n"
"    font-size: 16px;\n"
"    cursor: pointer;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #45a049;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #388e3c;\n"
"}\n"
""));
        stackedWidget->addWidget(AffSuperv);
        widget->raise();
        tableView->raise();
        label_27->raise();
        widget_9->raise();
        label->raise();
        BinSuperbtn->raise();
        Modbtn->raise();
        Trilabel4->raise();
        TriLineEdit4->raise();
        rechBtn_2->raise();
        comboBox->raise();
        pushButton->raise();
        notifSup = new QWidget();
        notifSup->setObjectName("notifSup");
        label_31 = new QLabel(notifSup);
        label_31->setObjectName("label_31");
        label_31->setGeometry(QRect(350, 30, 261, 41));
        label_31->setStyleSheet(QString::fromUtf8("#label_31 { \n"
"    font-size: 40px; /* Taille r\303\251duite du texte */\n"
"    font-weight: bold; /* Texte en gras pour un effet titre */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour une bonne lisibilit\303\251 */\n"
"    background-color: transparent; /* Fond transparent */\n"
"    padding: 4px 8px; /* Espacement pour l'a\303\251ration */\n"
"   \n"
"    text-align: center; /* Centrage du texte */\n"
"}\n"
""));
        widget_2 = new QWidget(notifSup);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(40, 100, 471, 511));
        smsEnv = new QPushButton(widget_2);
        smsEnv->setObjectName("smsEnv");
        smsEnv->setGeometry(QRect(320, 440, 121, 41));
        smsEnv->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        smsEnv->setStyleSheet(QString::fromUtf8("QPushButton#smsEnv {\n"
"    background-color: #28A745; /* Vert standard pour l'envoi */\n"
"    color: white;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    padding: 10px 20px; /* Uniformiser le padding */\n"
"    border-radius: 20px;\n"
"    border: 2px dashed #218838; /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"    text-align: center; /* Alignement horizontal */\n"
"    qproperty-alignment: 'AlignCenter'; /* Alignement Qt */\n"
"}\n"
"\n"
"QPushButton#smsEnv:hover {\n"
"    background-color: #218838; /* Vert plus fonc\303\251 au survol */\n"
"    border: 2px dashed #1E7E34; /* Bordure encore plus fonc\303\251e */\n"
"    color: #F9F9F9; \n"
"}\n"
"\n"
"QPushButton#smsEnv:pressed {\n"
"    background-color: #1E7E34; /* Vert encore plus fonc\303\251 quand press\303\251 */\n"
"    border: 2px dashed #155724; /* Bordure assombrie */\n"
"}\n"
""));
        MsgSup = new QLineEdit(widget_2);
        MsgSup->setObjectName("MsgSup");
        MsgSup->setGeometry(QRect(20, 150, 341, 201));
        MsgSup->setStyleSheet(QString::fromUtf8("#MsgSup {\n"
"    background-color: #FFFFFF; /* Blanc pur pour un bon contraste */\n"
"    border: 2px solid #A0B9D9; /* Bordure bleu-gris pastel */\n"
"    border-radius: 20px; /* Coins arrondis */\n"
"    padding: 8px 12px; /* Espacement interne */\n"
"    font-size: 16px; /* Taille de police agr\303\251able */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour le texte */\n"
"    selection-background-color: #A0B9D9; /* Couleur de s\303\251lection */\n"
"}\n"
"\n"
"#MsgSup:focus {\n"
"    border: 2px solid #4A90E2; /* Bleu clair plus intense lors du focus */\n"
"    background-color: #F0F4F8; /* L\303\251g\303\250re variation pour effet moderne */\n"
"}\n"
"\n"
""));
        smsMsg = new QLabel(widget_2);
        smsMsg->setObjectName("smsMsg");
        smsMsg->setGeometry(QRect(20, 110, 101, 41));
        smsMsg->setStyleSheet(QString::fromUtf8("#smsMsg { \n"
"    font-size: 15px; /* Taille r\303\251duite du texte */\n"
"    font-weight: bold; /* Texte en gras pour un effet titre */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour une bonne lisibilit\303\251 */\n"
"    background-color: transparent; /* Fond transparent */\n"
"    padding: 4px 8px; /* Espacement pour l'a\303\251ration */\n"
"   \n"
"    text-align: center; /* Centrage du texte */\n"
"}\n"
""));
        NumTelSup = new QLineEdit(widget_2);
        NumTelSup->setObjectName("NumTelSup");
        NumTelSup->setGeometry(QRect(20, 50, 291, 51));
        NumTelSup->setStyleSheet(QString::fromUtf8("#NumTelSup {\n"
"    background-color: #FFFFFF; /* Blanc pur pour un bon contraste */\n"
"    border: 2px solid #A0B9D9; /* Bordure bleu-gris pastel */\n"
"    border-radius: 20px; /* Coins arrondis */\n"
"    padding: 8px 12px; /* Espacement interne */\n"
"    font-size: 16px; /* Taille de police agr\303\251able */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour le texte */\n"
"    selection-background-color: #A0B9D9; /* Couleur de s\303\251lection */\n"
"}\n"
"\n"
"#NumTelSup:focus {\n"
"    border: 2px solid #4A90E2; /* Bleu clair plus intense lors du focus */\n"
"    background-color: #F0F4F8; /* L\303\251g\303\250re variation pour effet moderne */\n"
"}\n"
"\n"
""));
        smsNB = new QLabel(widget_2);
        smsNB->setObjectName("smsNB");
        smsNB->setGeometry(QRect(20, 10, 191, 41));
        smsNB->setStyleSheet(QString::fromUtf8("#smsNB { \n"
"    font-size: 15px; /* Taille r\303\251duite du texte */\n"
"    font-weight: bold; /* Texte en gras pour un effet titre */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour une bonne lisibilit\303\251 */\n"
"    background-color: transparent; /* Fond transparent */\n"
"    padding: 4px 8px; /* Espacement pour l'a\303\251ration */\n"
"   \n"
"    text-align: center; /* Centrage du texte */\n"
"}\n"
""));
        histo = new QLabel(notifSup);
        histo->setObjectName("histo");
        histo->setGeometry(QRect(720, 80, 161, 31));
        histo->setStyleSheet(QString::fromUtf8(" font-size: 20px; /* Taille r\303\251duite du texte */\n"
"    font-weight: bold; /* Texte en gras pour un effet titre */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour une bonne lisibilit\303\251 */\n"
"    \n"
"    padding: 4px 8px; /* Espacement pour l'a\303\251ration */"));
        Historique = new QWidget(notifSup);
        Historique->setObjectName("Historique");
        Historique->setGeometry(QRect(680, 100, 351, 501));
        Historique->setStyleSheet(QString::fromUtf8("#Historique {\n"
"    border: 2px dashed #3498db; /* Bordure en pointill\303\251s bleue */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    background-color: #f8f9fa; /* Couleur de fond l\303\251g\303\250re */\n"
"}\n"
""));
        gridLayoutWidget_2 = new QWidget(Historique);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(20, 30, 271, 421));
        HistoConenu = new QGridLayout(gridLayoutWidget_2);
        HistoConenu->setObjectName("HistoConenu");
        HistoConenu->setContentsMargins(0, 0, 0, 0);
        label_46 = new QLabel(gridLayoutWidget_2);
        label_46->setObjectName("label_46");

        HistoConenu->addWidget(label_46, 10, 0, 1, 1);

        testnotf = new QPushButton(gridLayoutWidget_2);
        testnotf->setObjectName("testnotf");

        HistoConenu->addWidget(testnotf, 0, 0, 1, 1);

        label_42 = new QLabel(gridLayoutWidget_2);
        label_42->setObjectName("label_42");

        HistoConenu->addWidget(label_42, 4, 0, 1, 1);

        label_41 = new QLabel(gridLayoutWidget_2);
        label_41->setObjectName("label_41");

        HistoConenu->addWidget(label_41, 8, 0, 1, 1);

        label_40 = new QLabel(gridLayoutWidget_2);
        label_40->setObjectName("label_40");

        HistoConenu->addWidget(label_40, 9, 0, 1, 1);

        label_47 = new QLabel(gridLayoutWidget_2);
        label_47->setObjectName("label_47");

        HistoConenu->addWidget(label_47, 5, 0, 1, 1);

        label_43 = new QLabel(gridLayoutWidget_2);
        label_43->setObjectName("label_43");

        HistoConenu->addWidget(label_43, 6, 0, 1, 1);

        label_39 = new QLabel(gridLayoutWidget_2);
        label_39->setObjectName("label_39");

        HistoConenu->addWidget(label_39, 7, 0, 1, 1);

        label_44 = new QLabel(gridLayoutWidget_2);
        label_44->setObjectName("label_44");

        HistoConenu->addWidget(label_44, 3, 0, 1, 1);

        label_45 = new QLabel(gridLayoutWidget_2);
        label_45->setObjectName("label_45");

        HistoConenu->addWidget(label_45, 2, 0, 1, 1);

        labelNotification1 = new QLabel(gridLayoutWidget_2);
        labelNotification1->setObjectName("labelNotification1");

        HistoConenu->addWidget(labelNotification1, 1, 0, 1, 1);

        popupNotification = new QWidget(notifSup);
        popupNotification->setObjectName("popupNotification");
        popupNotification->setGeometry(QRect(300, 280, 381, 200));
        popupNotification->setStyleSheet(QString::fromUtf8("QWidget#popupNotification {\n"
"    background-color: white;\n"
"    border: 2px solid #28A745;\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
""));
        labelNotificationContent = new QLabel(popupNotification);
        labelNotificationContent->setObjectName("labelNotificationContent");
        labelNotificationContent->setGeometry(QRect(70, 20, 251, 161));
        labelNotificationContent->setStyleSheet(QString::fromUtf8("\n"
"QLabelt#labelNotificationContent {\n"
"    font-size: 14px;\n"
"padding: 10px;\n"
"text-align: center;\n"
"}\n"
""));
        labelNotificationContent->setWordWrap(true);
        stackedWidget->addWidget(notifSup);
        widget_2->raise();
        label_31->raise();
        Historique->raise();
        histo->raise();
        popupNotification->raise();
        ModSuperv = new QWidget();
        ModSuperv->setObjectName("ModSuperv");
        stackedWidget->addWidget(ModSuperv);
        chatBot = new QWidget();
        chatBot->setObjectName("chatBot");
        chatbotTitre = new QLabel(chatBot);
        chatbotTitre->setObjectName("chatbotTitre");
        chatbotTitre->setGeometry(QRect(40, 30, 301, 31));
        chatbotTitre->setStyleSheet(QString::fromUtf8("#chatbotTitre{ \n"
"    font-size: 25px; /* Taille r\303\251duite du texte */\n"
"    font-weight: bold; /* Texte en gras pour un effet titre */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour une bonne lisibilit\303\251 */\n"
"    background-color: transparent; /* Fond transparent */\n"
"    padding: 4px 8px; /* Espacement pour l'a\303\251ration */\n"
"    \n"
"    text-align: center; /* Centrage du texte */\n"
"}\n"
""));
        widget_4 = new QWidget(chatBot);
        widget_4->setObjectName("widget_4");
        widget_4->setGeometry(QRect(40, 100, 371, 491));
        widget_5 = new QWidget(widget_4);
        widget_5->setObjectName("widget_5");
        widget_5->setGeometry(QRect(20, 10, 351, 181));
        widget_5->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/img/chatBot.png);"));
        widget_6 = new QWidget(widget_4);
        widget_6->setObjectName("widget_6");
        widget_6->setGeometry(QRect(10, 220, 361, 261));
        chatpropo = new QLabel(widget_6);
        chatpropo->setObjectName("chatpropo");
        chatpropo->setGeometry(QRect(30, 10, 301, 61));
        chatpropo->setStyleSheet(QString::fromUtf8("#chatpropo{ \n"
"    font-size: 25px; /* Taille r\303\251duite du texte */\n"
"    font-weight: bold; /* Texte en gras pour un effet titre */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour une bonne lisibilit\303\251 */\n"
"    background-color: transparent; /* Fond transparent */\n"
"    padding: 4px 8px; /* Espacement pour l'a\303\251ration */\n"
"    \n"
"    text-align: center; /* Centrage du texte */\n"
"}\n"
""));
        label_4 = new QLabel(widget_6);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(50, 100, 241, 111));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        widget_7 = new QWidget(chatBot);
        widget_7->setObjectName("widget_7");
        widget_7->setGeometry(QRect(550, 30, 501, 561));
        chatUser = new QLineEdit(widget_7);
        chatUser->setObjectName("chatUser");
        chatUser->setGeometry(QRect(62, 477, 371, 61));
        chatUser->setStyleSheet(QString::fromUtf8("#chatUser {\n"
"    background-color: #FFFFFF; /* Blanc pur pour un bon contraste */\n"
"    border: 2px solid #A0B9D9; /* Bordure bleu-gris pastel */\n"
"    border-radius: 20px; /* Coins arrondis */\n"
"    padding: 8px 12px; /* Espacement interne */\n"
"    font-size: 16px; /* Taille de police agr\303\251able */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour le texte */\n"
"    selection-background-color: #A0B9D9; /* Couleur de s\303\251lection */\n"
"}\n"
"\n"
"#chatUser:focus {\n"
"    border: 2px solid #4A90E2; /* Bleu clair plus intense lors du focus */\n"
"    background-color: #F0F4F8; /* L\303\251g\303\250re variation pour effet moderne */\n"
"}\n"
"\n"
""));
        sendChat = new QPushButton(widget_7);
        sendChat->setObjectName("sendChat");
        sendChat->setGeometry(QRect(440, 490, 36, 36));
        sendChat->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        sendChat->setStyleSheet(QString::fromUtf8("QPushButton#sendChat {\n"
"    color: rgb(8, 8, 8);\n"
"    background-color: rgb(1, 121, 111); /* Vert sapin */\n"
"    color: white;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    min-width: 36px; /* Largeur minimale */\n"
"    min-height: 36px; /* Hauteur minimale */\n"
"    max-width: 36px; /* Largeur maximale */\n"
"    max-height: 36px; /* Hauteur maximale */\n"
"    border-radius: 18px; /* La moiti\303\251 de la taille pour un cercle */\n"
"    border: none;\n"
"    transition: all 0.3s ease-in-out;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QPushButton#sendChat:hover {\n"
"    background-color: rgb(3, 150, 138); /* Vert sapin plus clair au survol */\n"
"    box-shadow: 0px 3px 8px rgba(1, 121, 111, 0.4);\n"
"}\n"
"\n"
"QPushButton#sendChat:pressed {\n"
"    background-color: rgb(0, 100, 92); /* Vert sapin plus fonc\303\251 au clic */\n"
"    box-shadow: 0px 2px 5px rgba(1, 121, 111, 0.5);\n"
"}\n"
""));
        sendChat->setIconSize(QSize(20, 15));
        chatConvo = new QLineEdit(widget_7);
        chatConvo->setObjectName("chatConvo");
        chatConvo->setGeometry(QRect(20, 20, 451, 441));
        chatConvo->setStyleSheet(QString::fromUtf8("#chatConvo {\n"
"   \n"
"background-color: #FFFFFF; /* Blanc pur pour un bon contraste */\n"
"    border: 2px solid #A0B9D9; /* Bordure bleu-gris pastel */\n"
"    border-radius: 20px; /* Coins arrondis */\n"
"    padding: 8px 12px; /* Espacement interne */\n"
"    font-size: 16px; /* Taille de police agr\303\251able */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour le texte */\n"
"    selection-background-color: #A0B9D9; /* Couleur de s\303\251lection */\n"
"}\n"
"\n"
"#chatConvo:focus {\n"
"    border: 2px solid #4A90E2; /* Bleu clair plus intense lors du focus */\n"
"    background-color: #F0F4F8; /* L\303\251g\303\250re variation pour effet moderne */\n"
"}\n"
"\n"
""));
        stackedWidget->addWidget(chatBot);
        GestEquip = new QWidget();
        GestEquip->setObjectName("GestEquip");
        label_14 = new QLabel(GestEquip);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(310, 40, 181, 41));
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        stackedWidget->addWidget(GestEquip);
        GestFourn = new QWidget();
        GestFourn->setObjectName("GestFourn");
        label_12 = new QLabel(GestFourn);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(270, 40, 171, 31));
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(11, 11, 11);"));
        stackedWidget->addWidget(GestFourn);
        GestCand = new QWidget();
        GestCand->setObjectName("GestCand");
        label_15 = new QLabel(GestCand);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(280, 50, 161, 31));
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(12, 12, 12);"));
        stackedWidget->addWidget(GestCand);
        GestEtab = new QWidget();
        GestEtab->setObjectName("GestEtab");
        label_16 = new QLabel(GestEtab);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(250, 50, 191, 16));
        label_16->setStyleSheet(QString::fromUtf8("color: rgb(8, 8, 8);"));
        stackedWidget->addWidget(GestEtab);
        closeBtn = new QPushButton(centralwidget);
        closeBtn->setObjectName("closeBtn");
        closeBtn->setGeometry(QRect(1240, 10, 36, 36));
        closeBtn->setCursor(QCursor(Qt::CursorShape::ClosedHandCursor));
        closeBtn->setStyleSheet(QString::fromUtf8("QPushButton#closeBtn {\n"
"	image: url(:/new/prefix1/img/fermer-la-fenetre.png);\n"
"    background-color: #D64545; /* Rouge brique pastel */\n"
"    color: white;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    min-width: 36px; /* Largeur minimale */\n"
"    min-height: 36px; /* Hauteur minimale */\n"
"    max-width: 36px; /* Largeur maximale */\n"
"    max-height: 36px; /* Hauteur maximale */\n"
"    border-radius: 18px; /* La moiti\303\251 de la taille pour un cercle */\n"
"    border: none;\n"
"    transition: all 0.3s ease-in-out;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QPushButton#closeBtn:hover {\n"
"    background-color: #E06666; /* Rouge plus clair au survol */\n"
"    box-shadow: 0px 3px 8px rgba(214, 69, 69, 0.4);\n"
"}\n"
"\n"
"QPushButton#closeBtn:pressed {\n"
"    background-color: #B83232; /* Rouge plus fonc\303\251 au clic */\n"
"    box-shadow: 0px 2px 5px rgba(184, 50, 50, 0.5);\n"
"}\n"
""));
        QIcon icon10(QIcon::fromTheme(QIcon::ThemeIcon::ApplicationExit));
        closeBtn->setIcon(icon10);
        notifBtn = new QPushButton(centralwidget);
        notifBtn->setObjectName("notifBtn");
        notifBtn->setGeometry(QRect(1190, 10, 36, 36));
        notifBtn->setStyleSheet(QString::fromUtf8("QPushButton#notifBtn {\n"
"	image: url(:/new/prefix1/img/notif.png);\n"
"    background-color: rgb(131, 151, 166); /* Rouge brique pastel */\n"
"    color: white;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    min-width: 36px; /* Largeur minimale */\n"
"    min-height: 36px; /* Hauteur minimale */\n"
"    max-width: 36px; /* Largeur maximale */\n"
"    max-height: 36px; /* Hauteur maximale */\n"
"    border-radius: 18px; /* La moiti\303\251 de la taille pour un cercle */\n"
"    border: none;\n"
"    transition: all 0.3s ease-in-out;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QPushButton#notifBtn:hover {\n"
"    background-color: rgb(158, 175, 189); /* Rouge plus clair au survol */\n"
"    box-shadow: 0px 3px 8px rgba(214, 69, 69, 0.4);\n"
"}\n"
"\n"
"QPushButton#notifBtn:pressed {\n"
"    background-color:rgb(158, 175, 189); /* Rouge plus fonc\303\251 au clic */\n"
"    box-shadow: 0px 2px 5px rgba(184, 50, 50, 0.5);\n"
"}\n"
""));
        emailBtn = new QPushButton(centralwidget);
        emailBtn->setObjectName("emailBtn");
        emailBtn->setGeometry(QRect(1130, 10, 36, 36));
        emailBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        emailBtn->setStyleSheet(QString::fromUtf8("QPushButton#emailBtn {\n"
"	\n"
"	image: url(:/new/prefix1/img/email.png);\n"
"    background-color: rgb(131, 151, 166); /* Rouge brique pastel */\n"
"    color: white;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    min-width: 36px; /* Largeur minimale */\n"
"    min-height: 36px; /* Hauteur minimale */\n"
"    max-width: 36px; /* Largeur maximale */\n"
"    max-height: 36px; /* Hauteur maximale */\n"
"    border-radius: 18px; /* La moiti\303\251 de la taille pour un cercle */\n"
"    border: none;\n"
"    transition: all 0.3s ease-in-out;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QPushButton#emailBtn:hover {\n"
"    background-color: rgb(158, 175, 189); /* Rouge plus clair au survol */\n"
"    box-shadow: 0px 3px 8px rgba(214, 69, 69, 0.4);\n"
"}\n"
"\n"
"QPushButton#emailBtn:pressed {\n"
"    background-color:rgb(158, 175, 189); /* Rouge plus fonc\303\251 au clic */\n"
"    box-shadow: 0px 2px 5px rgba(184, 50, 50, 0.5);\n"
"}\n"
""));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/img/email.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        emailBtn->setIcon(icon11);
        paramBtn = new QPushButton(centralwidget);
        paramBtn->setObjectName("paramBtn");
        paramBtn->setGeometry(QRect(1070, 10, 36, 36));
        paramBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        paramBtn->setStyleSheet(QString::fromUtf8("QPushButton#paramBtn {\n"
"	image: url(:/new/prefix1/img/parametres.png);\n"
"    background-color: rgb(131, 151, 166); /* Rouge brique pastel */\n"
"    color: white;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    min-width: 36px; /* Largeur minimale */\n"
"    min-height: 36px; /* Hauteur minimale */\n"
"    max-width: 36px; /* Largeur maximale */\n"
"    max-height: 36px; /* Hauteur maximale */\n"
"    border-radius: 18px; /* La moiti\303\251 de la taille pour un cercle */\n"
"    border: none;\n"
"    transition: all 0.3s ease-in-out;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QPushButton#paramBtn:hover {\n"
"    background-color: rgb(158, 175, 189); /* Rouge plus clair au survol */\n"
"    box-shadow: 0px 3px 8px rgba(214, 69, 69, 0.4);\n"
"}\n"
"\n"
"QPushButton#paramBtn:pressed {\n"
"    background-color:rgb(158, 175, 189); /* Rouge plus fonc\303\251 au clic */\n"
"    box-shadow: 0px 2px 5px rgba(184, 50, 50, 0.5);\n"
"}\n"
""));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/img/settings.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        paramBtn->setIcon(icon12);
        homeBtn = new QPushButton(centralwidget);
        homeBtn->setObjectName("homeBtn");
        homeBtn->setGeometry(QRect(1010, 10, 36, 36));
        homeBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        homeBtn->setStyleSheet(QString::fromUtf8("QPushButton#homeBtn {\n"
"	\n"
"	image: url(:/new/prefix1/img/accueil.png);\n"
"    color: rgb(8, 8, 8);\n"
"    background-color: rgb(1, 121, 111); /* Vert sapin */\n"
"    color: white;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    min-width: 36px; /* Largeur minimale */\n"
"    min-height: 36px; /* Hauteur minimale */\n"
"    max-width: 36px; /* Largeur maximale */\n"
"    max-height: 36px; /* Hauteur maximale */\n"
"    border-radius: 18px; /* La moiti\303\251 de la taille pour un cercle */\n"
"    border: none;\n"
"    transition: all 0.3s ease-in-out;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QPushButton#homeBtn:hover {\n"
"    background-color: rgb(3, 150, 138); /* Vert sapin plus clair au survol */\n"
"    box-shadow: 0px 3px 8px rgba(1, 121, 111, 0.4);\n"
"}\n"
"\n"
"QPushButton#homeBtn:pressed {\n"
"    background-color: rgb(0, 100, 92); /* Vert sapin plus fonc\303\251 au clic */\n"
"    box-shadow: 0px 2px 5px rgba(1, 121, 111, 0.5);\n"
"}\n"
""));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/img/accueil.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        homeBtn->setIcon(icon13);
        homeBtn->setIconSize(QSize(20, 15));
        MainWindow->setCentralWidget(centralwidget);
        Menu->raise();
        fullMenu->raise();
        closeBtn->raise();
        notifBtn->raise();
        emailBtn->raise();
        paramBtn->raise();
        homeBtn->raise();
        QWidget::setTabOrder(FourButton, candButton);
        QWidget::setTabOrder(candButton, etaButton);
        QWidget::setTabOrder(etaButton, examButton);
        QWidget::setTabOrder(examButton, closeBtn);
        QWidget::setTabOrder(closeBtn, notifBtn);
        QWidget::setTabOrder(notifBtn, emailBtn);
        QWidget::setTabOrder(emailBtn, paramBtn);
        QWidget::setTabOrder(paramBtn, homeBtn);
        QWidget::setTabOrder(homeBtn, tableView);
        QWidget::setTabOrder(tableView, TriLineEdit4);
        QWidget::setTabOrder(TriLineEdit4, rechBtn_2);
        QWidget::setTabOrder(rechBtn_2, pdfSuperbtn);
        QWidget::setTabOrder(pdfSuperbtn, supButton);
        QWidget::setTabOrder(supButton, BinSuperbtn);
        QWidget::setTabOrder(BinSuperbtn, Modbtn);
        QWidget::setTabOrder(Modbtn, listWidget_2);
        QWidget::setTabOrder(listWidget_2, PostLineEdit);
        QWidget::setTabOrder(PostLineEdit, NomLineEdit);
        QWidget::setTabOrder(NomLineEdit, EmailLineEdit);
        QWidget::setTabOrder(EmailLineEdit, Ajbtn);
        QWidget::setTabOrder(Ajbtn, ModButton);
        QWidget::setTabOrder(ModButton, eqButton);

        retranslateUi(MainWindow);
        QObject::connect(labelNotification1, &QLabel::linkActivated, popupNotification, qOverload<>(&QWidget::show));

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "SmartEval", nullptr));
        supButton->setText(QCoreApplication::translate("MainWindow", "Superviseurs", nullptr));
        eqButton->setText(QCoreApplication::translate("MainWindow", "Equipements", nullptr));
        FourButton->setText(QCoreApplication::translate("MainWindow", "Fournisseurs", nullptr));
        candButton->setText(QCoreApplication::translate("MainWindow", "Candidats", nullptr));
        etaButton->setText(QCoreApplication::translate("MainWindow", "Etablissements", nullptr));
        examButton->setText(QCoreApplication::translate("MainWindow", "Examens", nullptr));
        ModButton->setText(QCoreApplication::translate("MainWindow", "Statistiques", nullptr));
        EvalAssist->setText(QCoreApplication::translate("MainWindow", "Eval Assist", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Gestion Des Examens", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableView->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableView->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableView->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Statut", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableView->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Quantit\303\251", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "Liste des equipements :", nullptr));
        PdfLabel->setText(QString());
        pdfSuperbtn->setText(QCoreApplication::translate("MainWindow", "Rapport d\303\251taill\303\251 sur statut des \303\251quipements", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "exportation pdf", nullptr));
        BinSuperbtn->setText(QString());
        Modbtn->setText(QString());
        label_11->setText(QCoreApplication::translate("MainWindow", "Ajouter un equipement", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Nom :", nullptr));
        PostLineEdit->setText(QString());
        label_21->setText(QCoreApplication::translate("MainWindow", "Statut : ", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "Type :", nullptr));
        NomLineEdit->setText(QString());
        label_24->setText(QCoreApplication::translate("MainWindow", "Quantit\303\251 :", nullptr));
        EmailLineEdit->setText(QString());
        Ajbtn->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("MainWindow", "Imprimantes", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("MainWindow", "Scanners", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("MainWindow", "Claviers ", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("MainWindow", "Souris", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = listWidget->item(4);
        ___qlistwidgetitem4->setText(QCoreApplication::translate("MainWindow", "\303\211crans", nullptr));
        QListWidgetItem *___qlistwidgetitem5 = listWidget->item(5);
        ___qlistwidgetitem5->setText(QCoreApplication::translate("MainWindow", "Chaises standards", nullptr));
        QListWidgetItem *___qlistwidgetitem6 = listWidget->item(6);
        ___qlistwidgetitem6->setText(QCoreApplication::translate("MainWindow", "Tables", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);

        Trilabel4->setText(QCoreApplication::translate("MainWindow", "Tri par nom :", nullptr));
        TriLineEdit4->setText(QString());
        rechBtn_2->setText(QString());
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "3", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "4", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "5", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("MainWindow", "6", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("MainWindow", "7", nullptr));
        comboBox->setItemText(7, QCoreApplication::translate("MainWindow", "8", nullptr));
        comboBox->setItemText(8, QCoreApplication::translate("MainWindow", "9", nullptr));
        comboBox->setItemText(9, QCoreApplication::translate("MainWindow", "10", nullptr));
        comboBox->setItemText(10, QString());

        pushButton->setText(QCoreApplication::translate("MainWindow", "recherche par id ", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "Form SMS :", nullptr));
        smsEnv->setText(QCoreApplication::translate("MainWindow", "Envoyer", nullptr));
        MsgSup->setText(QString());
        smsMsg->setText(QCoreApplication::translate("MainWindow", "Message  :", nullptr));
        NumTelSup->setText(QString());
        smsNB->setText(QCoreApplication::translate("MainWindow", "Num\303\251ro Du t\303\251l\303\251phone :", nullptr));
        histo->setText(QCoreApplication::translate("MainWindow", "Historiques :", nullptr));
        label_46->setText(QCoreApplication::translate("MainWindow", "notif4", nullptr));
        testnotf->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        label_42->setText(QCoreApplication::translate("MainWindow", "notif2", nullptr));
        label_41->setText(QCoreApplication::translate("MainWindow", "notif3", nullptr));
        label_40->setText(QCoreApplication::translate("MainWindow", "notif3", nullptr));
        label_47->setText(QCoreApplication::translate("MainWindow", "notif2", nullptr));
        label_43->setText(QCoreApplication::translate("MainWindow", "notif2", nullptr));
        label_39->setText(QCoreApplication::translate("MainWindow", "notif3", nullptr));
        label_44->setText(QCoreApplication::translate("MainWindow", "notif2", nullptr));
        label_45->setText(QCoreApplication::translate("MainWindow", "notif2", nullptr));
        labelNotification1->setText(QCoreApplication::translate("MainWindow", "notif1", nullptr));
#if QT_CONFIG(tooltip)
        popupNotification->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700;\">Nom</span> : <span style=\" font-family:'Courier New';\">windowFlags</span></p><p><span style=\" font-weight:700;\">Type</span> : <span style=\" font-family:'Courier New';\">int</span></p><p><span style=\" font-weight:700;\">Valeur</span> : <span style=\" font-family:'Courier New';\">Qt::Popup | Qt::FramelessWindowHint</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        labelNotificationContent->setText(QCoreApplication::translate("MainWindow", "Exemple de notification compl\303\250te", nullptr));
        chatbotTitre->setText(QCoreApplication::translate("MainWindow", "Votre Eval Assit :", nullptr));
        chatpropo->setText(QCoreApplication::translate("MainWindow", "A propos d'Eval Assist :", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\n"
"\360\237\223\214 V\303\251rif. disponibilit\303\251.\n"
"\360\237\223\214 Conseils & recommandations.\n"
"\360\237\223\214 Notifications & rappels .\n"
"\360\237\223\214Affectation des superviseurs.", nullptr));
        sendChat->setText(QString());
        label_14->setText(QCoreApplication::translate("MainWindow", "Gestion Des Equipements", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Gestion des Fournisseurs", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Gestion des Candidats", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Gestion des Etablissements", nullptr));
        closeBtn->setText(QString());
        notifBtn->setText(QString());
        emailBtn->setText(QString());
        paramBtn->setText(QString());
        homeBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
