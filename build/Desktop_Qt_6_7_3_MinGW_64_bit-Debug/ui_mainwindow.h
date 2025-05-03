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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
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
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_4;
    QPushButton *statButton;
    QLabel *label_25;
    QWidget *Menu;
    QPushButton *closeBtn;
    QPushButton *historiqueBtn;
    QPushButton *emailBtn;
    QPushButton *paramBtn;
    QStackedWidget *stackedWidget;
    QWidget *HOME;
    QLabel *label_17;
    QWidget *GestExam;
    QLabel *label_13;
    QWidget *GestFourn;
    QTableView *tableFourn;
    QLabel *label_27;
    QPushButton *ModButton;
    QListWidget *listWidget_2;
    QLineEdit *TypeService;
    QLineEdit *ID;
    QLineEdit *Email;
    QLineEdit *NumTel;
    QLineEdit *ADRESSE;
    QPushButton *Ajbtn;
    QLabel *label_11;
    QLabel *NomT;
    QLabel *label_19;
    QLabel *label_23;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QPushButton *suppButton;
    QLineEdit *Nom;
    QPushButton *SaveMod;
    QPushButton *btnAfficherTout;
    QPushButton *btnTrierNom;
    QPushButton *chatbotBtn;
    QWidget *widget_10;
    QLabel *PdfLabel_3;
    QLineEdit *lineEditRech;
    QPushButton *rechBtn;
    QPushButton *pdfBtn;
    QWidget *CHAT;
    QTextEdit *chatDisplay;
    QPushButton *sendChatBtn;
    QLineEdit *chatInput;
    QLabel *label_30;
    QWidget *Email_2;
    QListWidget *listWidget_3;
    QLabel *label_28;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QTextEdit *textEdit;
    QPushButton *EnvBtn;
    QWidget *Stats;
    QWidget *chartContainerType;
    QLabel *label_31;
    QComboBox *comboBoxStatType;
    QWidget *AjSuperv;
    QWidget *widget_6;
    QTableView *tableView_Eta;
    QWidget *widget;
    QLineEdit *idEtablissementLineEdit;
    QLabel *label_18;
    QLineEdit *directeurLineEdit;
    QLabel *label_24;
    QLabel *label_26;
    QLineEdit *villeLineEdit;
    QLabel *label_32;
    QLineEdit *nomLineEdit;
    QLabel *label_33;
    QLabel *label_34;
    QLineEdit *nombreSalleLineEdit;
    QLabel *label_35;
    QLineEdit *gouvernoratLineEdit;
    QPushButton *Saveta;
    QPushButton *Ajteta;
    QComboBox *typeLineEdit;
    QLineEdit *adresseLineEdit;
    QLabel *label_36;
    QPushButton *selectImageBtn;
    QLineEdit *idSuperviseurLineEdit;
    QLineEdit *idEquipementLineEdit;
    QLabel *label_37;
    QLabel *label_38;
    QListWidget *listWidget_4;
    QLabel *aze;
    QPushButton *sortGovernorateBtn;
    QPushButton *ReMod;
    QWidget *widget_9;
    QLineEdit *searchDirector;
    QLabel *PdfLabel_2;
    QPushButton *exportPdfBtn;
    QPushButton *statsButton;
    QPushButton *mapsButton;
    QLabel *label_39;
    QFrame *statsContainer;
    QPushButton *Binetabtn;
    QPushButton *Modeta;
    QPushButton *neweta;
    QWidget *GestEquip;
    QLabel *label_14;
    QWidget *GestSuperv;
    QLabel *label_12;
    QWidget *GestEtab;
    QLabel *label_16;
    QWidget *His;
    QTableView *emailHistoryTable;
    QLabel *label_29;
    QPushButton *homeBtn;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1449, 797);
        MainWindow->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: #D9E6F2; /* Bleu pastel plus visible */"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        fullMenu = new QWidget(centralwidget);
        fullMenu->setObjectName("fullMenu");
        fullMenu->setGeometry(QRect(10, 10, 161, 711));
        label_2 = new QLabel(fullMenu);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 0, 61, 61));
        label_2->setCursor(QCursor(Qt::CursorShape::ForbiddenCursor));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/img/logo.png")));
        label_3 = new QLabel(fullMenu);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(60, 20, 91, 41));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"    font-size: 18px;\n"
"    font-weight: bold;"));
        supButton = new QPushButton(fullMenu);
        supButton->setObjectName("supButton");
        supButton->setGeometry(QRect(0, 170, 151, 41));
        supButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        supButton->setStyleSheet(QString::fromUtf8("QPushButton#supButton {\n"
"	image: url(:/new/prefix1/img/rechercher-des-personnes.png);\n"
"    background-color: #4A90E2;\n"
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
"QPushButton#supButton:hover {\n"
"    background-color: #5A9BD5; /* Bleu plus clair au survol */\n"
"    border: 2px solid #F9F9F9; /* Bordure plus claire */\n"
"    color: #F9F9F9; /* Texte plus clair */\n"
"}\n"
"\n"
"QPushButton#supButton:pressed {\n"
"    background-color: #C74C4C; /* Rouge brique au clic */\n"
"    border: 2px solid #C74C4C;\n"
"}\n"
""));
        supButton->setCheckable(true);
        supButton->setAutoExclusive(true);
        eqButton = new QPushButton(fullMenu);
        eqButton->setObjectName("eqButton");
        eqButton->setGeometry(QRect(0, 240, 151, 41));
        eqButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        eqButton->setStyleSheet(QString::fromUtf8("QPushButton#eqButton {\n"
"	image: url(:/new/prefix1/img/equipe.png);\n"
"    background-color: #4A90E2;\n"
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
"QPushButton#eqButton:hover {\n"
"    background-color: #5A9BD5; /* Bleu plus clair au survol */\n"
"    border: 2px solid #F9F9F9; /* Bordure plus claire */\n"
"    color: #F9F9F9; /* Texte plus clair */\n"
"}\n"
"\n"
"QPushButton#eqButton:pressed {\n"
"    background-color: #C74C4C; /* Rouge brique au clic */\n"
"    border: 2px solid #C74C4C;\n"
"}\n"
""));
        eqButton->setCheckable(true);
        eqButton->setAutoExclusive(true);
        FourButton = new QPushButton(fullMenu);
        FourButton->setObjectName("FourButton");
        FourButton->setGeometry(QRect(0, 310, 151, 41));
        FourButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        FourButton->setStyleSheet(QString::fromUtf8("QPushButton#FourButton {\n"
"	image: url(:/new/prefix1/img/livreur.png);\n"
"	\n"
"    background-color: #4A90E2;\n"
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
"QPushButton#FourButton:hover {\n"
"    background-color: #5A9BD5; /* Bleu plus clair au survol */\n"
"    border: 2px solid #F9F9F9; /* Bordure plus claire */\n"
"    color: #F9F9F9; /* Texte plus clair */\n"
"}\n"
"\n"
"QPushButton#FourButton:pressed {\n"
"    background-color: #C74C4C; /* Rouge brique au clic */\n"
"    border: 2px solid #C74C4C;\n"
"}\n"
""));
        FourButton->setCheckable(true);
        FourButton->setAutoExclusive(true);
        candButton = new QPushButton(fullMenu);
        candButton->setObjectName("candButton");
        candButton->setGeometry(QRect(0, 380, 151, 41));
        candButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        candButton->setStyleSheet(QString::fromUtf8("QPushButton#candButton {\n"
"	\n"
"	image: url(:/new/prefix1/img/candidat.png);\n"
"	\n"
"    background-color: #4A90E2;\n"
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
"QPushButton#candButton:hover {\n"
"    background-color: #5A9BD5; /* Bleu plus clair au survol */\n"
"    border: 2px solid #F9F9F9; /* Bordure plus claire */\n"
"    color: #F9F9F9; /* Texte plus clair */\n"
"}\n"
"\n"
"QPushButton#candButton:pressed {\n"
"    background-color: #C74C4C; /* Rouge brique au clic */\n"
"    border: 2px solid #C74C4C;\n"
"}\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/img/candidat.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        candButton->setIcon(icon);
        candButton->setCheckable(true);
        candButton->setAutoExclusive(true);
        etaButton = new QPushButton(fullMenu);
        etaButton->setObjectName("etaButton");
        etaButton->setGeometry(QRect(0, 450, 151, 41));
        etaButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        etaButton->setStyleSheet(QString::fromUtf8("QPushButton#etaButton {\n"
"	image: url(:/new/prefix1/img/batiment-educatif.png);\n"
"    background-color: #4A90E2;\n"
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
"QPushButton#etaButton:hover {\n"
"    background-color: #5A9BD5; /* Bleu plus clair au survol */\n"
"    border: 2px solid #F9F9F9; /* Bordure plus claire */\n"
"    color: #F9F9F9; /* Texte plus clair */\n"
"}\n"
"\n"
"QPushButton#etaButton:pressed {\n"
"    background-color: #C74C4C; /* Rouge brique au clic */\n"
"    border: 2px solid #C74C4C;\n"
"}\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("img/livreur.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        etaButton->setIcon(icon1);
        etaButton->setCheckable(true);
        etaButton->setAutoExclusive(true);
        examButton = new QPushButton(fullMenu);
        examButton->setObjectName("examButton");
        examButton->setGeometry(QRect(0, 100, 151, 41));
        examButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        examButton->setStyleSheet(QString::fromUtf8("QPushButton#examButton {\n"
"    image: url(:/new/prefix1/img/examen.png);\n"
"    background-color: #4A90E2;\n"
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
"QPushButton#examButton:hover {\n"
"    background-color: #5A9BD5; /* Bleu plus clair au survol */\n"
"    border: 2px solid #F9F9F9; /* Bordure plus claire */\n"
"    color: #F9F9F9; /* Texte plus clair */\n"
"}\n"
"\n"
"QPushButton#examButton:pressed {\n"
"    background-color: #C74C4C; /* Rouge brique au clic */\n"
"    border: 2px solid #C74C4C;\n"
"}\n"
""));
        examButton->setIconSize(QSize(20, 20));
        examButton->setCheckable(true);
        examButton->setAutoExclusive(true);
        label_5 = new QLabel(fullMenu);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(40, 180, 101, 20));
        label_5->setStyleSheet(QString::fromUtf8(" color: black;\n"
"background-color: rgb(74, 144, 226);\n"
"    font-size: 15px;\n"
"    font-weight: bold;"));
        label_6 = new QLabel(fullMenu);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(40, 250, 91, 20));
        label_6->setStyleSheet(QString::fromUtf8(" color: black;\n"
"background-color: rgb(74, 144, 226);\n"
"    font-size: 15px;\n"
"    font-weight: bold;"));
        label_7 = new QLabel(fullMenu);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(40, 320, 91, 20));
        label_7->setStyleSheet(QString::fromUtf8(" color: black;\n"
"    font-size: 15px;\n"
"    font-weight: bold;\n"
"background-color: rgb(74, 144, 226);"));
        label_8 = new QLabel(fullMenu);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(50, 390, 71, 20));
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"    font-size: 15px;\n"
"    font-weight: bold;\n"
"background-color: rgb(74, 144, 226);"));
        label_9 = new QLabel(fullMenu);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(40, 460, 101, 20));
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(3, 3, 3);\n"
"    font-size: 13px;\n"
"    font-weight: bold;\n"
"background-color: rgb(74, 144, 226);"));
        label_4 = new QLabel(fullMenu);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(50, 110, 81, 20));
        label_4->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        label_4->setStyleSheet(QString::fromUtf8("\n"
"color: black;\n"
"background-color: rgb(74, 144, 226);\n"
"\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
""));
        statButton = new QPushButton(fullMenu);
        statButton->setObjectName("statButton");
        statButton->setGeometry(QRect(0, 530, 151, 41));
        statButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        statButton->setStyleSheet(QString::fromUtf8("QPushButton#statButton {\n"
"	image: url(:/new/prefix1/img/analytics.png);\n"
"    background-color: #4A90E2;\n"
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
"QPushButton#statButton:hover {\n"
"    background-color: #5A9BD5; /* Bleu plus clair au survol */\n"
"    border: 2px solid #F9F9F9; /* Bordure plus claire */\n"
"    color: #F9F9F9; /* Texte plus clair */\n"
"}\n"
"\n"
"QPushButton#statButton:pressed {\n"
"    background-color: #C74C4C; /* Rouge brique au clic */\n"
"    border: 2px solid #C74C4C;\n"
"}\n"
""));
        statButton->setCheckable(true);
        statButton->setAutoExclusive(true);
        label_25 = new QLabel(fullMenu);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(50, 540, 91, 20));
        label_25->setStyleSheet(QString::fromUtf8("color: rgb(3, 3, 3);\n"
"    font-size: 13px;\n"
"    font-weight: bold;\n"
"background-color: rgb(74, 144, 226);"));
        label_3->raise();
        etaButton->raise();
        candButton->raise();
        eqButton->raise();
        examButton->raise();
        label_2->raise();
        supButton->raise();
        FourButton->raise();
        label_5->raise();
        label_6->raise();
        label_7->raise();
        label_8->raise();
        label_9->raise();
        label_4->raise();
        statButton->raise();
        label_25->raise();
        Menu = new QWidget(centralwidget);
        Menu->setObjectName("Menu");
        Menu->setGeometry(QRect(201, 50, 1021, 831));
        closeBtn = new QPushButton(centralwidget);
        closeBtn->setObjectName("closeBtn");
        closeBtn->setGeometry(QRect(1410, 10, 36, 36));
        closeBtn->setCursor(QCursor(Qt::CursorShape::ClosedHandCursor));
        closeBtn->setStyleSheet(QString::fromUtf8("QPushButton#closeBtn {\n"
"	image: url(:/new/prefix1/img/close.png);\n"
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
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::ApplicationExit));
        closeBtn->setIcon(icon2);
        historiqueBtn = new QPushButton(centralwidget);
        historiqueBtn->setObjectName("historiqueBtn");
        historiqueBtn->setGeometry(QRect(1370, 10, 36, 36));
        historiqueBtn->setStyleSheet(QString::fromUtf8("QPushButton#notifBtn {\n"
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
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::DocumentOpen));
        historiqueBtn->setIcon(icon3);
        emailBtn = new QPushButton(centralwidget);
        emailBtn->setObjectName("emailBtn");
        emailBtn->setGeometry(QRect(1320, 10, 36, 36));
        emailBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        emailBtn->setStyleSheet(QString::fromUtf8("QPushButton#emailBtn {\n"
"	\n"
"	image: url(:/new/prefix1/img/mail.png);\n"
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
        QIcon icon4(QIcon::fromTheme(QIcon::ThemeIcon::MailForward));
        emailBtn->setIcon(icon4);
        paramBtn = new QPushButton(centralwidget);
        paramBtn->setObjectName("paramBtn");
        paramBtn->setGeometry(QRect(1270, 10, 36, 36));
        paramBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        paramBtn->setStyleSheet(QString::fromUtf8("QPushButton#paramBtn {\n"
"	\n"
"	image: url(:/new/prefix1/img/settings.png);\n"
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
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(170, 50, 1281, 791));
        stackedWidget->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(239, 239, 239);"));
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
        GestFourn = new QWidget();
        GestFourn->setObjectName("GestFourn");
        tableFourn = new QTableView(GestFourn);
        tableFourn->setObjectName("tableFourn");
        tableFourn->setGeometry(QRect(20, 80, 721, 351));
        tableFourn->setStyleSheet(QString::fromUtf8("#tableFourn {\n"
"    border: 2px solid #A0B9D9; /* L\303\251g\303\250re bordure bleu-gris pastel */\n"
"    border-radius: 10px;       /* Coins arrondis */\n"
"    background-color: #F0F4F8; /* Fond l\303\251g\303\250rement gris-bleu */\n"
"    gridline-color: #A0B9D9;   /* Couleur des lignes du tableau */\n"
"    selection-background-color: #4A90E2; /* Couleur de s\303\251lection */\n"
"    selection-color: white;     /* Texte blanc lors de la s\303\251lection */\n"
"}\n"
"\n"
"#tableFourn::item {\n"
"    padding: 8px;              /* Espacement entre le texte et la cellule */\n"
"    color: #2C3E50;            /* Texte bleu fonc\303\251 */\n"
"}\n"
"\n"
"#tableFourn::item:selected {\n"
"    background-color: #4A90E2; /* Fond bleu lors de la s\303\251lection */\n"
"    color: white;              /* Texte blanc */\n"
"}\n"
"\n"
"#tableFourn QHeaderView::section {\n"
"    background-color: #A0B9D9; /* En-t\303\252te avec une teinte bleu-gris */\n"
"    color: #2C3E50;            /* Texte des en-t\303\252tes en"
                        " bleu fonc\303\251 */\n"
"    padding: 5px;              /* Espacement interne dans l'en-t\303\252te */\n"
"    border: 2px solid #A0B9D9; /* L\303\251g\303\250re bordure bleu-gris pastel */\n"
"    font-weight: bold;         /* Mettre le texte en gras */\n"
"}\n"
"\n"
"#tableFourn QTableCornerButton::section {\n"
"    background-color: #4A90E2; /* Coin sup\303\251rieur gauche */\n"
"    border: 2px solid #A0B9D9; /* L\303\251g\303\250re bordure bleu-gris pastel */\n"
"}\n"
"\n"
"#tableFourn QHeaderView {\n"
"    border: none;              /* Supprimer la bordure de l'en-t\303\252te */\n"
"}"));
        tableFourn->horizontalHeader()->setDefaultSectionSize(40);
        label_27 = new QLabel(GestFourn);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(20, 20, 311, 51));
        label_27->setStyleSheet(QString::fromUtf8("#label_27 { \n"
"    font-size: 25px; /* Taille r\303\251duite du texte */\n"
"    font-weight: bold; /* Texte en gras pour un effet titre */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour une bonne lisibilit\303\251 */\n"
"    background-color: transparent; /* Fond transparent */\n"
"    padding: 4px 8px; /* Espacement pour l'a\303\251ration */\n"
"    border: 1px solid #A0B9D9; /* L\303\251g\303\250re bordure bleu-gris pastel */\n"
"    border-radius: 5px; /* Coins l\303\251g\303\250rement arrondis */\n"
"    text-align: center; /* Centrage du texte */\n"
"}\n"
""));
        ModButton = new QPushButton(GestFourn);
        ModButton->setObjectName("ModButton");
        ModButton->setGeometry(QRect(30, 440, 51, 41));
        ModButton->setStyleSheet(QString::fromUtf8("QPushButton#ModButton  {\n"
"    color: white;\n"
"	background-color: rgb(58, 123, 213);\n"
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
        QIcon icon5(QIcon::fromTheme(QIcon::ThemeIcon::MailMessageNew));
        ModButton->setIcon(icon5);
        listWidget_2 = new QListWidget(GestFourn);
        listWidget_2->setObjectName("listWidget_2");
        listWidget_2->setGeometry(QRect(760, 140, 511, 521));
        listWidget_2->setStyleSheet(QString::fromUtf8("QListWidget {\n"
"   border: 2px solid #A0B9D9; /* L\303\251g\303\250re bordure bleu-gris pastel */\n"
"    border-radius: 10px;        /* Coins arrondis */\n"
"    padding: 5px;               /* Un peu d'espace \303\240 l'int\303\251rieur */\n"
"}\n"
""));
        TypeService = new QLineEdit(GestFourn);
        TypeService->setObjectName("TypeService");
        TypeService->setGeometry(QRect(1070, 250, 181, 41));
        TypeService->setStyleSheet(QString::fromUtf8("#NomLineEdit {\n"
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
        ID = new QLineEdit(GestFourn);
        ID->setObjectName("ID");
        ID->setGeometry(QRect(820, 360, 181, 41));
        ID->setStyleSheet(QString::fromUtf8("#IDLineEdit {\n"
"    background-color: #FFFFFF; /* Blanc pur pour un bon contraste */\n"
"    border: 2px solid #A0B9D9; /* Bordure bleu-gris pastel */\n"
"    border-radius: 20px; /* Coins arrondis */\n"
"    padding: 8px 12px; /* Espacement interne */\n"
"    font-size: 16px; /* Taille de police agr\303\251able */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour le texte */\n"
"    selection-background-color: #A0B9D9; /* Couleur de s\303\251lection */\n"
"}\n"
"\n"
"#IDLineEdit:focus {\n"
"    border: 2px solid #4A90E2; /* Bleu clair plus intense lors du focus */\n"
"    background-color: #F0F4F8; /* L\303\251g\303\250re variation pour effet moderne */\n"
"}\n"
"\n"
""));
        Email = new QLineEdit(GestFourn);
        Email->setObjectName("Email");
        Email->setGeometry(QRect(1070, 360, 181, 41));
        Email->setStyleSheet(QString::fromUtf8("#TlfLineEdit {\n"
"    background-color: #FFFFFF; /* Blanc pur pour un bon contraste */\n"
"    border: 2px solid #A0B9D9; /* Bordure bleu-gris pastel */\n"
"    border-radius: 20px; /* Coins arrondis */\n"
"    padding: 8px 12px; /* Espacement interne */\n"
"    font-size: 16px; /* Taille de police agr\303\251able */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour le texte */\n"
"    selection-background-color: #A0B9D9; /* Couleur de s\303\251lection */\n"
"}\n"
"\n"
"#TlfLineEdit:focus {\n"
"    border: 2px solid #4A90E2; /* Bleu clair plus intense lors du focus */\n"
"    background-color: #F0F4F8; /* L\303\251g\303\250re variation pour effet moderne */\n"
"}\n"
"\n"
""));
        NumTel = new QLineEdit(GestFourn);
        NumTel->setObjectName("NumTel");
        NumTel->setGeometry(QRect(820, 470, 181, 41));
        NumTel->setStyleSheet(QString::fromUtf8("#EmailLineEdit {\n"
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
        ADRESSE = new QLineEdit(GestFourn);
        ADRESSE->setObjectName("ADRESSE");
        ADRESSE->setGeometry(QRect(1070, 470, 181, 41));
        ADRESSE->setStyleSheet(QString::fromUtf8("#CINLineEdit {\n"
"    background-color: #FFFFFF; /* Blanc pur pour un bon contraste */\n"
"    border: 2px solid #A0B9D9; /* Bordure bleu-gris pastel */\n"
"    border-radius: 20px; /* Coins arrondis */\n"
"    padding: 8px 12px; /* Espacement interne */\n"
"    font-size: 16px; /* Taille de police agr\303\251able */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour le texte */\n"
"    selection-background-color: #A0B9D9; /* Couleur de s\303\251lection */\n"
"}\n"
"\n"
"#CINLineEdit:focus {\n"
"    border: 2px solid #4A90E2; /* Bleu clair plus intense lors du focus */\n"
"    background-color: #F0F4F8; /* L\303\251g\303\250re variation pour effet moderne */\n"
"}\n"
"\n"
""));
        Ajbtn = new QPushButton(GestFourn);
        Ajbtn->setObjectName("Ajbtn");
        Ajbtn->setGeometry(QRect(980, 560, 141, 51));
        Ajbtn->setStyleSheet(QString::fromUtf8("#Ajbtn { \n"
"    background-color: #3A7BD5; /* Bleu plus profond et \303\251l\303\251gant */\n"
"     border: 2px dashed #2E5FA2; /* Bordure bleu fonc\303\251 */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 8px 16px; /* Espacement interne */\n"
"    font-size: 14px; /* Taille du texte */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: white; /* Texte blanc */\n"
"}\n"
"\n"
"#Ajbtn:hover { \n"
"    background-color: #5294E2; /* Bleu l\303\251g\303\250rement plus clair au survol */\n"
"    border: 2px solid #3A7BD5;\n"
"}\n"
"\n"
"#Ajbtn:pressed { \n"
"    background-color: #A8D5BA; /* Vert pastel au clic */\n"
"    border: 2px solid #86C79A; /* Bordure verte pastel */\n"
"    color: #2C3E50; /* Texte bleu fonc\303\251 */\n"
"}\n"
""));
        label_11 = new QLabel(GestFourn);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(870, 160, 311, 41));
        label_11->setStyleSheet(QString::fromUtf8("#label_11 { \n"
"    font-size: 25px; /* Taille r\303\251duite du texte */\n"
"    font-weight: bold; /* Texte en gras pour un effet titre */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour une bonne lisibilit\303\251 */\n"
"    background-color: transparent; /* Fond transparent */\n"
"    padding: 4px 8px; /* Espacement pour l'a\303\251ration */\n"
"    border: 1px solid #A0B9D9; /* L\303\251g\303\250re bordure bleu-gris pastel */\n"
"    border-radius: 5px; /* Coins l\303\251g\303\250rement arrondis */\n"
"    text-align: center; /* Centrage du texte */\n"
"}\n"
""));
        NomT = new QLabel(GestFourn);
        NomT->setObjectName("NomT");
        NomT->setGeometry(QRect(830, 220, 63, 20));
        NomT->setStyleSheet(QString::fromUtf8("color: rgb(12, 12, 12);\n"
"font: 10pt \"Sitka\";"));
        label_19 = new QLabel(GestFourn);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(1070, 220, 121, 20));
        label_19->setStyleSheet(QString::fromUtf8("color: rgb(12, 12, 12);\n"
"font: 10pt \"Sitka\";"));
        label_23 = new QLabel(GestFourn);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(820, 330, 141, 20));
        label_23->setStyleSheet(QString::fromUtf8("color: rgb(12, 12, 12);\n"
"font: 10pt \"Sitka\";"));
        label_20 = new QLabel(GestFourn);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(1070, 330, 63, 20));
        label_20->setStyleSheet(QString::fromUtf8("color: rgb(12, 12, 12);\n"
"font: 10pt \"Sitka\";"));
        label_21 = new QLabel(GestFourn);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(820, 440, 101, 20));
        label_21->setStyleSheet(QString::fromUtf8("color: rgb(12, 12, 12);\n"
"font: 10pt \"Sitka\";"));
        label_22 = new QLabel(GestFourn);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(1070, 440, 171, 20));
        label_22->setStyleSheet(QString::fromUtf8("color: rgb(12, 12, 12);\n"
"font: 10pt \"Sitka\";"));
        suppButton = new QPushButton(GestFourn);
        suppButton->setObjectName("suppButton");
        suppButton->setGeometry(QRect(150, 440, 51, 41));
        suppButton->setStyleSheet(QString::fromUtf8("QPushButton#suppButton  {\n"
"	image: url(:/new/prefix1/img/supprimer.png);\n"
"    color: white;\n"
"	background-color: rgb(176, 48, 48);\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    border-radius: 18px; /* La moiti\303\251 de la taille pour un cercle */\n"
"    border: none;\n"
"    transition: all 0.3s ease-in-out;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QPushButton#suppButton:hover {\n"
"    background-color: rgb(3, 150, 138); /* Vert sapin plus clair au survol */\n"
"    box-shadow: 0px 3px 8px rgba(1, 121, 111, 0.4);\n"
"}\n"
"\n"
"QPushButton#suppButton :pressed {\n"
"    background-color: rgb(0, 100, 92); /* Vert sapin plus fonc\303\251*/\n"
"    box-shadow: 0px 2px 5px rgba(1, 121, 111, 0.5);\n"
"}"));
        QIcon icon6(QIcon::fromTheme(QIcon::ThemeIcon::EditDelete));
        suppButton->setIcon(icon6);
        Nom = new QLineEdit(GestFourn);
        Nom->setObjectName("Nom");
        Nom->setGeometry(QRect(830, 240, 181, 41));
        Nom->setStyleSheet(QString::fromUtf8("#NomLineEdit {\n"
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
        SaveMod = new QPushButton(GestFourn);
        SaveMod->setObjectName("SaveMod");
        SaveMod->setGeometry(QRect(850, 560, 51, 41));
        SaveMod->setStyleSheet(QString::fromUtf8("QPushButton#SaveMod  {\n"
"    color: white;\n"
"	background-color: rgb(58, 123, 213);\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    border-radius: 18px; /* La moiti\303\251 de la taille pour un cercle */\n"
"    border: none;\n"
"    transition: all 0.3s ease-in-out;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QPushButton#SaveMod:hover {\n"
"    background-color: rgb(3, 150, 138); /* Vert sapin plus clair au survol */\n"
"    box-shadow: 0px 3px 8px rgba(1, 121, 111, 0.4);\n"
"}\n"
"\n"
"QPushButton#btnAfficherTout :SaveMod {\n"
"    background-color: rgb(0, 100, 92); /* Vert sapin plus fonc\303\251*/\n"
"    box-shadow: 0px 2px 5px rgba(1, 121, 111, 0.5);\n"
"}"));
        QIcon icon7(QIcon::fromTheme(QIcon::ThemeIcon::DocumentNew));
        SaveMod->setIcon(icon7);
        btnAfficherTout = new QPushButton(GestFourn);
        btnAfficherTout->setObjectName("btnAfficherTout");
        btnAfficherTout->setGeometry(QRect(90, 440, 51, 41));
        btnAfficherTout->setStyleSheet(QString::fromUtf8("QPushButton#btnAfficherTout  {\n"
"    color: white;\n"
"	background-color: rgb(58, 123, 213);\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    border-radius: 18px; /* La moiti\303\251 de la taille pour un cercle */\n"
"    border: none;\n"
"    transition: all 0.3s ease-in-out;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QPushButton#btnAfficherTout:hover {\n"
"    background-color: rgb(3, 150, 138); /* Vert sapin plus clair au survol */\n"
"    box-shadow: 0px 3px 8px rgba(1, 121, 111, 0.4);\n"
"}\n"
"\n"
"QPushButton#btnAfficherTout :pressed {\n"
"    background-color: rgb(0, 100, 92); /* Vert sapin plus fonc\303\251*/\n"
"    box-shadow: 0px 2px 5px rgba(1, 121, 111, 0.5);\n"
"}"));
        QIcon icon8(QIcon::fromTheme(QIcon::ThemeIcon::DocumentRevert));
        btnAfficherTout->setIcon(icon8);
        btnTrierNom = new QPushButton(GestFourn);
        btnTrierNom->setObjectName("btnTrierNom");
        btnTrierNom->setGeometry(QRect(570, 30, 151, 41));
        btnTrierNom->setStyleSheet(QString::fromUtf8("QPushButton#btnTrierNom {\n"
"    background-color: #3A7BD5;\n"
"    color: white;\n"
"    font-size: 15px;\n"
"    font-weight: 500;\n"
"    padding: 8px 18px;\n"
"    border-radius: 12px;\n"
"    border: none;\n"
"    transition: all 0.3s ease;\n"
"}\n"
"\n"
"QPushButton#btnTrierNom:hover {\n"
"    background-color: #5596e6;\n"
"}\n"
"\n"
"QPushButton#btnTrierNom:pressed {\n"
"    background-color: #2e5fa3;\n"
"}\n"
""));
        chatbotBtn = new QPushButton(GestFourn);
        chatbotBtn->setObjectName("chatbotBtn");
        chatbotBtn->setGeometry(QRect(600, 440, 141, 41));
        chatbotBtn->setStyleSheet(QString::fromUtf8("QPushButton#chatbotBtn {\n"
"    background-color: #3A7BD5;\n"
"    color: white;\n"
"    font-size: 15px;\n"
"    font-weight: 500;\n"
"    padding: 8px 18px;\n"
"    border-radius: 12px;\n"
"    border: none;\n"
"    transition: all 0.3s ease;\n"
"}\n"
"\n"
"QPushButton#chatbotBtn:hover {\n"
"    background-color: #5596e6;\n"
"}\n"
"\n"
"QPushButton#chatbotBtn:pressed {\n"
"    background-color: #2e5fa3;\n"
"}\n"
""));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8("img/chat.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        chatbotBtn->setIcon(icon9);
        widget_10 = new QWidget(GestFourn);
        widget_10->setObjectName("widget_10");
        widget_10->setGeometry(QRect(40, 570, 321, 161));
        widget_10->setStyleSheet(QString::fromUtf8("#widget_10 {\n"
"    border: 2px dashed #3498db; /* Bordure en pointill\303\251s bleue */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    background-color: #f8f9fa; /* Couleur de fond l\303\251g\303\250re */\n"
"}\n"
""));
        PdfLabel_3 = new QLabel(widget_10);
        PdfLabel_3->setObjectName("PdfLabel_3");
        PdfLabel_3->setGeometry(QRect(80, 80, 41, 41));
        PdfLabel_3->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/img/pdf.png);"));
        lineEditRech = new QLineEdit(widget_10);
        lineEditRech->setObjectName("lineEditRech");
        lineEditRech->setGeometry(QRect(20, 10, 181, 41));
        lineEditRech->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #FFFFFF; /* Blanc pur pour un bon contraste */\n"
"    border: 2px solid #A0B9D9; /* Bordure bleu-gris pastel */\n"
"    border-radius: 20px; /* Coins arrondis */\n"
"    padding: 8px 12px; /* Espacement interne */\n"
"    font-size: 16px; /* Taille de police agr\303\251able */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour le texte */\n"
"    selection-background-color: #A0B9D9; /* Couleur de s\303\251lection */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #4A90E2; /* Bleu clair plus intense lors du focus */\n"
"    background-color: #F0F4F8; /* L\303\251g\303\250re variation pour effet moderne */\n"
"}\n"
""));
        rechBtn = new QPushButton(widget_10);
        rechBtn->setObjectName("rechBtn");
        rechBtn->setGeometry(QRect(210, 10, 61, 41));
        rechBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        rechBtn->setStyleSheet(QString::fromUtf8("QPushButton#rechBtn {\n"
"    background-color: #4A90E2;\n"
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
"QPushButton#rechBtn:hover {\n"
"    background-color: #5A9BD5; /* Bleu plus clair au survol */\n"
"    border: 2px solid #F9F9F9; /* Bordure plus claire */\n"
"    color: #F9F9F9; /* Texte plus clair */\n"
"}\n"
"\n"
"QPushButton#rechBtn:pressed {\n"
"    background-color: #C74C4C; /* Rouge brique au clic */\n"
"    border: 2px solid #C74C4C;\n"
"}\n"
""));
        QIcon icon10(QIcon::fromTheme(QIcon::ThemeIcon::SystemSearch));
        rechBtn->setIcon(icon10);
        pdfBtn = new QPushButton(widget_10);
        pdfBtn->setObjectName("pdfBtn");
        pdfBtn->setGeometry(QRect(150, 80, 141, 41));
        pdfBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pdfBtn->setStyleSheet(QString::fromUtf8("QPushButton#pdfBtn {\n"
"    background-color: #3A7BD5;\n"
"    color: white;\n"
"    font-size: 15px;\n"
"    font-weight: 500;\n"
"    padding: 8px 18px;\n"
"    border-radius: 12px;\n"
"    border: none;\n"
"    transition: all 0.3s ease;\n"
"}\n"
"\n"
"QPushButton#pdfBtn:hover {\n"
"    background-color: #5596e6;\n"
"}\n"
"\n"
"QPushButton#pdfBtn:pressed {\n"
"    background-color: #2e5fa3;\n"
"}\n"
""));
        pdfBtn->setIconSize(QSize(20, 20));
        pdfBtn->setCheckable(true);
        pdfBtn->setAutoExclusive(true);
        stackedWidget->addWidget(GestFourn);
        CHAT = new QWidget();
        CHAT->setObjectName("CHAT");
        chatDisplay = new QTextEdit(CHAT);
        chatDisplay->setObjectName("chatDisplay");
        chatDisplay->setGeometry(QRect(130, 130, 1021, 491));
        chatDisplay->setStyleSheet(QString::fromUtf8("#chatDisplay { \n"
"    font-size: 25px; /* Taille r\303\251duite du texte */\n"
"    font-weight: bold; /* Texte en gras pour un effet titre */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour une bonne lisibilit\303\251 */\n"
"    background-color: transparent; /* Fond transparent */\n"
"    padding: 4px 8px; /* Espacement pour l'a\303\251ration */\n"
"    border: 1px solid #3A7BD5; /* L\303\251g\303\250re bordure bleu-gris pastel */\n"
"    border-radius: 5px; /* Coins l\303\251g\303\250rement arrondis */\n"
"    text-align: center; /* Centrage du texte */\n"
"}"));
        sendChatBtn = new QPushButton(CHAT);
        sendChatBtn->setObjectName("sendChatBtn");
        sendChatBtn->setGeometry(QRect(1020, 640, 131, 51));
        sendChatBtn->setStyleSheet(QString::fromUtf8("#sendChatBtn { \n"
"    background-color: #3A7BD5; /* Bleu plus profond et \303\251l\303\251gant */\n"
"     border: 2px dashed #2E5FA2; /* Bordure bleu fonc\303\251 */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 8px 16px; /* Espacement interne */\n"
"    font-size: 14px; /* Taille du texte */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: white; /* Texte blanc */\n"
"}\n"
"\n"
"#sendChatBtn:hover { \n"
"    background-color: #5294E2; /* Bleu l\303\251g\303\250rement plus clair au survol */\n"
"    border: 2px solid #3A7BD5;\n"
"}\n"
"\n"
"#sendChatBtn:pressed { \n"
"    background-color: #A8D5BA; /* Vert pastel au clic */\n"
"    border: 2px solid #86C79A; /* Bordure verte pastel */\n"
"    color: #2C3E50; /* Texte bleu fonc\303\251 */\n"
"}\n"
""));
        chatInput = new QLineEdit(CHAT);
        chatInput->setObjectName("chatInput");
        chatInput->setGeometry(QRect(130, 640, 881, 61));
        chatInput->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #FFFFFF; /* Blanc pur pour un bon contraste */\n"
"    border: 2px solid #A0B9D9; /* Bordure bleu-gris pastel */\n"
"    border-radius: 20px; /* Coins arrondis */\n"
"    padding: 8px 12px; /* Espacement interne */\n"
"    font-size: 16px; /* Taille de police agr\303\251able */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour le texte */\n"
"    selection-background-color: #A0B9D9; /* Couleur de s\303\251lection */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #4A90E2; /* Bleu clair plus intense lors du focus */\n"
"    background-color: #F0F4F8; /* L\303\251g\303\250re variation pour effet moderne */\n"
"}\n"
""));
        label_30 = new QLabel(CHAT);
        label_30->setObjectName("label_30");
        label_30->setGeometry(QRect(560, 20, 141, 51));
        label_30->setStyleSheet(QString::fromUtf8("#label_30 { \n"
"    font-size: 25px; /* Taille r\303\251duite du texte */\n"
"    font-weight: bold; /* Texte en gras pour un effet titre */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour une bonne lisibilit\303\251 */\n"
"    background-color: transparent; /* Fond transparent */\n"
"    padding: 4px 8px; /* Espacement pour l'a\303\251ration */\n"
"    border: 1px solid #A0B9D9; /* L\303\251g\303\250re bordure bleu-gris pastel */\n"
"    border-radius: 5px; /* Coins l\303\251g\303\250rement arrondis */\n"
"    text-align: center; /* Centrage du texte */\n"
"}\n"
""));
        stackedWidget->addWidget(CHAT);
        Email_2 = new QWidget();
        Email_2->setObjectName("Email_2");
        listWidget_3 = new QListWidget(Email_2);
        listWidget_3->setObjectName("listWidget_3");
        listWidget_3->setGeometry(QRect(40, 40, 1191, 681));
        listWidget_3->setStyleSheet(QString::fromUtf8("QListWidget {\n"
"    border: 2px solid blue;    /* Bordure bleue */\n"
"    border-radius: 10px;        /* Coins arrondis */\n"
"    padding: 5px;               /* Un peu d'espace \303\240 l'int\303\251rieur */\n"
"}\n"
""));
        label_28 = new QLabel(Email_2);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(520, 60, 161, 51));
        label_28->setStyleSheet(QString::fromUtf8("#label_28 { \n"
"    font-size: 25px; /* Taille r\303\251duite du texte */\n"
"    font-weight: bold; /* Texte en gras pour un effet titre */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour une bonne lisibilit\303\251 */\n"
"    background-color: transparent; /* Fond transparent */\n"
"    padding: 4px 8px; /* Espacement pour l'a\303\251ration */\n"
"    border: 1px solid #A0B9D9; /* L\303\251g\303\250re bordure bleu-gris pastel */\n"
"    border-radius: 5px; /* Coins l\303\251g\303\250rement arrondis */\n"
"    text-align: center; /* Centrage du texte */\n"
"}\n"
""));
        lineEdit_2 = new QLineEdit(Email_2);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(180, 180, 731, 41));
        lineEdit_2->setStyleSheet(QString::fromUtf8("#lineEdit_2 { \n"
"    font-size: 25px; /* Taille r\303\251duite du texte */\n"
"    font-weight: bold; /* Texte en gras pour un effet titre */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour une bonne lisibilit\303\251 */\n"
"    background-color: transparent; /* Fond transparent */\n"
"    padding: 4px 8px; /* Espacement pour l'a\303\251ration */\n"
"    border: 1px solid #A0B9D9; /* L\303\251g\303\250re bordure bleu-gris pastel */\n"
"    border-radius: 5px; /* Coins l\303\251g\303\250rement arrondis */\n"
"    text-align: center; /* Centrage du texte */\n"
"}"));
        lineEdit_3 = new QLineEdit(Email_2);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(180, 255, 511, 41));
        lineEdit_3->setStyleSheet(QString::fromUtf8("#lineEdit_3 { \n"
"    font-size: 25px; /* Taille r\303\251duite du texte */\n"
"    font-weight: bold; /* Texte en gras pour un effet titre */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour une bonne lisibilit\303\251 */\n"
"    background-color: transparent; /* Fond transparent */\n"
"    padding: 4px 8px; /* Espacement pour l'a\303\251ration */\n"
"    border: 1px solid #A0B9D9; /* L\303\251g\303\250re bordure bleu-gris pastel */\n"
"    border-radius: 5px; /* Coins l\303\251g\303\250rement arrondis */\n"
"    text-align: center; /* Centrage du texte */\n"
"}"));
        textEdit = new QTextEdit(Email_2);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(180, 330, 991, 281));
        textEdit->setStyleSheet(QString::fromUtf8("#textEdit { \n"
"    font-size: 25px; /* Taille r\303\251duite du texte */\n"
"    font-weight: bold; /* Texte en gras pour un effet titre */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour une bonne lisibilit\303\251 */\n"
"    background-color: transparent; /* Fond transparent */\n"
"    padding: 4px 8px; /* Espacement pour l'a\303\251ration */\n"
"    border: 1px solid #3A7BD5; /* L\303\251g\303\250re bordure bleu-gris pastel */\n"
"    border-radius: 5px; /* Coins l\303\251g\303\250rement arrondis */\n"
"    text-align: center; /* Centrage du texte */\n"
"}"));
        EnvBtn = new QPushButton(Email_2);
        EnvBtn->setObjectName("EnvBtn");
        EnvBtn->setGeometry(QRect(1030, 650, 141, 51));
        EnvBtn->setStyleSheet(QString::fromUtf8("#EnvBtn { \n"
"    background-color: #3A7BD5; /* Bleu plus profond et \303\251l\303\251gant */\n"
"     border: 2px dashed #2E5FA2; /* Bordure bleu fonc\303\251 */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 8px 16px; /* Espacement interne */\n"
"    font-size: 14px; /* Taille du texte */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: white; /* Texte blanc */\n"
"}\n"
"\n"
"#Ajbtn:hover { \n"
"    background-color: #5294E2; /* Bleu l\303\251g\303\250rement plus clair au survol */\n"
"    border: 2px solid #3A7BD5;\n"
"}\n"
"\n"
"#Ajbtn:pressed { \n"
"    background-color: #A8D5BA; /* Vert pastel au clic */\n"
"    border: 2px solid #86C79A; /* Bordure verte pastel */\n"
"    color: #2C3E50; /* Texte bleu fonc\303\251 */\n"
"}\n"
""));
        stackedWidget->addWidget(Email_2);
        Stats = new QWidget();
        Stats->setObjectName("Stats");
        chartContainerType = new QWidget(Stats);
        chartContainerType->setObjectName("chartContainerType");
        chartContainerType->setGeometry(QRect(280, 100, 731, 531));
        chartContainerType->setStyleSheet(QString::fromUtf8("QWidget#chartContainerType {\n"
"    background-color: qlineargradient(\n"
"        x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 #f0f4f8,\n"
"        stop:1 #d9e2ec\n"
"    );\n"
"    border: 1px solid #a0b9d9;\n"
"    border-radius: 10px;\n"
"    padding: 12px;\n"
"}\n"
""));
        label_31 = new QLabel(Stats);
        label_31->setObjectName("label_31");
        label_31->setGeometry(QRect(320, 30, 611, 51));
        label_31->setStyleSheet(QString::fromUtf8("#label_31 { \n"
"    font-size: 25px; /* Taille r\303\251duite du texte */\n"
"    font-weight: bold; /* Texte en gras pour un effet titre */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour une bonne lisibilit\303\251 */\n"
"    background-color: transparent; /* Fond transparent */\n"
"    padding: 4px 8px; /* Espacement pour l'a\303\251ration */\n"
"    border: 1px solid #A0B9D9; /* L\303\251g\303\250re bordure bleu-gris pastel */\n"
"    border-radius: 5px; /* Coins l\303\251g\303\250rement arrondis */\n"
"    text-align: center; /* Centrage du texte */\n"
"}\n"
""));
        comboBoxStatType = new QComboBox(Stats);
        comboBoxStatType->addItem(QString());
        comboBoxStatType->addItem(QString());
        comboBoxStatType->setObjectName("comboBoxStatType");
        comboBoxStatType->setGeometry(QRect(720, 40, 181, 31));
        comboBoxStatType->setStyleSheet(QString::fromUtf8("#comboBoxStatType {\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    color: #2C3E50;\n"
"    background-color: #F0F4F8;\n"
"    border: 1px solid #A0B9D9;\n"
"    border-radius: 5px;\n"
"    padding: 4px 8px;\n"
"    selection-background-color: #A0B9D9;\n"
"    combobox-popup: 0;\n"
"}\n"
""));
        stackedWidget->addWidget(Stats);
        AjSuperv = new QWidget();
        AjSuperv->setObjectName("AjSuperv");
        widget_6 = new QWidget(AjSuperv);
        widget_6->setObjectName("widget_6");
        widget_6->setGeometry(QRect(260, 0, 481, 61));
        tableView_Eta = new QTableView(AjSuperv);
        tableView_Eta->setObjectName("tableView_Eta");
        tableView_Eta->setGeometry(QRect(10, 110, 761, 401));
        tableView_Eta->setStyleSheet(QString::fromUtf8("#tableView_Eta {\n"
"    border: 2px solid #A0B9D9; /* L\303\251g\303\250re bordure bleu-gris pastel */\n"
"    border-radius: 10px;       /* Coins arrondis */\n"
"    background-color: #F0F4F8; /* Fond l\303\251g\303\250rement gris-bleu */\n"
"    gridline-color: #A0B9D9;   /* Couleur des lignes du tableau */\n"
"    selection-background-color: #4A90E2; /* Couleur de s\303\251lection */\n"
"    selection-color: white;     /* Texte blanc lors de la s\303\251lection */\n"
"}\n"
"\n"
"#tableView_Eta::item {\n"
"    padding: 8px;              /* Espacement entre le texte et la cellule */\n"
"    color: #2C3E50;            /* Texte bleu fonc\303\251 */\n"
"}\n"
"\n"
"#tableView_Eta::item:selected {\n"
"    background-color: #4A90E2; /* Fond bleu lors de la s\303\251lection */\n"
"    color: white;              /* Texte blanc */\n"
"}\n"
"\n"
"#tableView_Eta QHeaderView::section {\n"
"    background-color: #A0B9D9; /* En-t\303\252te avec une teinte bleu-gris */\n"
"    color: #2C3E50;            /* Texte des en-t\303"
                        "\252tes en bleu fonc\303\251 */\n"
"    padding: 5px;              /* Espacement interne dans l'en-t\303\252te */\n"
"    border: 2px solid #A0B9D9; /* L\303\251g\303\250re bordure bleu-gris pastel */\n"
"    font-weight: bold;         /* Mettre le texte en gras */\n"
"}\n"
"\n"
"#tableView_Eta QTableCornerButton::section {\n"
"    background-color: #4A90E2; /* Coin sup\303\251rieur gauche */\n"
"    border: 2px solid #A0B9D9; /* L\303\251g\303\250re bordure bleu-gris pastel */\n"
"}\n"
"\n"
"#tableView_Eta QHeaderView {\n"
"    border: none;              /* Supprimer la bordure de l'en-t\303\252te */\n"
"}"));
        tableView_Eta->horizontalHeader()->setDefaultSectionSize(34);
        widget = new QWidget(AjSuperv);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(780, 160, 491, 551));
        idEtablissementLineEdit = new QLineEdit(widget);
        idEtablissementLineEdit->setObjectName("idEtablissementLineEdit");
        idEtablissementLineEdit->setGeometry(QRect(80, 100, 161, 41));
        idEtablissementLineEdit->setStyleSheet(QString::fromUtf8("#idEtablissementLineEdit {\n"
"    background-color: #FFFFFF; /* Blanc pur pour un bon contraste */\n"
"    border: 2px solid #A0B9D9; /* Bordure bleu-gris pastel */\n"
"    border-radius: 20px; /* Coins arrondis */\n"
"    padding: 8px 12px; /* Espacement interne */\n"
"    font-size: 16px; /* Taille de police agr\303\251able */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour le texte */\n"
"    selection-background-color: #A0B9D9; /* Couleur de s\303\251lection */\n"
"}\n"
"\n"
"#idEtablissementLineEdit:focus {\n"
"    border: 2px solid #4A90E2; /* Bleu clair plus intense lors du focus */\n"
"    background-color: #F0F4F8; /* L\303\251g\303\250re variation pour effet moderne */\n"
"}\n"
"\n"
""));
        label_18 = new QLabel(widget);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(80, 150, 63, 20));
        label_18->setStyleSheet(QString::fromUtf8("color: rgb(12, 12, 12);"));
        directeurLineEdit = new QLineEdit(widget);
        directeurLineEdit->setObjectName("directeurLineEdit");
        directeurLineEdit->setGeometry(QRect(80, 340, 161, 41));
        directeurLineEdit->setStyleSheet(QString::fromUtf8("#directeurLineEdit {\n"
"    background-color: #FFFFFF; /* Blanc pur pour un bon contraste */\n"
"    border: 2px solid #A0B9D9; /* Bordure bleu-gris pastel */\n"
"    border-radius: 20px; /* Coins arrondis */\n"
"    padding: 8px 12px; /* Espacement interne */\n"
"    font-size: 16px; /* Taille de police agr\303\251able */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour le texte */\n"
"    selection-background-color: #A0B9D9; /* Couleur de s\303\251lection */\n"
"}\n"
"\n"
"#directeurLineEdit:focus {\n"
"    border: 2px solid #4A90E2; /* Bleu clair plus intense lors du focus */\n"
"    background-color: #F0F4F8; /* L\303\251g\303\250re variation pour effet moderne */\n"
"}\n"
"\n"
""));
        label_24 = new QLabel(widget);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(80, 230, 131, 20));
        label_24->setStyleSheet(QString::fromUtf8("color: rgb(12, 12, 12);"));
        label_26 = new QLabel(widget);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(80, 70, 63, 20));
        label_26->setStyleSheet(QString::fromUtf8("color: rgb(12, 12, 12);"));
        villeLineEdit = new QLineEdit(widget);
        villeLineEdit->setObjectName("villeLineEdit");
        villeLineEdit->setGeometry(QRect(310, 260, 141, 41));
        villeLineEdit->setStyleSheet(QString::fromUtf8("#villeLineEdit {\n"
"    background-color: #FFFFFF; /* Blanc pur pour un bon contraste */\n"
"    border: 2px solid #A0B9D9; /* Bordure bleu-gris pastel */\n"
"    border-radius: 20px; /* Coins arrondis */\n"
"    padding: 8px 12px; /* Espacement interne */\n"
"    font-size: 16px; /* Taille de police agr\303\251able */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour le texte */\n"
"    selection-background-color: #A0B9D9; /* Couleur de s\303\251lection */\n"
"}\n"
"\n"
"#villeLineEdit:focus {\n"
"    border: 2px solid #4A90E2; /* Bleu clair plus intense lors du focus */\n"
"    background-color: #F0F4F8; /* L\303\251g\303\250re variation pour effet moderne */\n"
"}\n"
"\n"
""));
        label_32 = new QLabel(widget);
        label_32->setObjectName("label_32");
        label_32->setGeometry(QRect(310, 150, 141, 20));
        label_32->setStyleSheet(QString::fromUtf8("color: rgb(12, 12, 12);"));
        nomLineEdit = new QLineEdit(widget);
        nomLineEdit->setObjectName("nomLineEdit");
        nomLineEdit->setGeometry(QRect(80, 180, 151, 41));
        nomLineEdit->setStyleSheet(QString::fromUtf8("#nomLineEdit {\n"
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
        label_33 = new QLabel(widget);
        label_33->setObjectName("label_33");
        label_33->setGeometry(QRect(310, 310, 111, 20));
        label_33->setStyleSheet(QString::fromUtf8("color: rgb(12, 12, 12);"));
        label_34 = new QLabel(widget);
        label_34->setObjectName("label_34");
        label_34->setGeometry(QRect(320, 230, 63, 20));
        label_34->setStyleSheet(QString::fromUtf8("color: rgb(12, 12, 12);"));
        nombreSalleLineEdit = new QLineEdit(widget);
        nombreSalleLineEdit->setObjectName("nombreSalleLineEdit");
        nombreSalleLineEdit->setGeometry(QRect(310, 180, 141, 41));
        nombreSalleLineEdit->setStyleSheet(QString::fromUtf8("#nombreSalleLineEdit {\n"
"    background-color: #FFFFFF; /* Blanc pur pour un bon contraste */\n"
"    border: 2px solid #A0B9D9; /* Bordure bleu-gris pastel */\n"
"    border-radius: 20px; /* Coins arrondis */\n"
"    padding: 8px 12px; /* Espacement interne */\n"
"    font-size: 16px; /* Taille de police agr\303\251able */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour le texte */\n"
"    selection-background-color: #A0B9D9; /* Couleur de s\303\251lection */\n"
"}\n"
"\n"
"#nombreSalleLineEdit:focus {\n"
"    border: 2px solid #4A90E2; /* Bleu clair plus intense lors du focus */\n"
"    background-color: #F0F4F8; /* L\303\251g\303\250re variation pour effet moderne */\n"
"}\n"
"\n"
""));
        label_35 = new QLabel(widget);
        label_35->setObjectName("label_35");
        label_35->setGeometry(QRect(80, 310, 101, 20));
        label_35->setStyleSheet(QString::fromUtf8("color: rgb(12, 12, 12);"));
        gouvernoratLineEdit = new QLineEdit(widget);
        gouvernoratLineEdit->setObjectName("gouvernoratLineEdit");
        gouvernoratLineEdit->setGeometry(QRect(80, 260, 161, 41));
        gouvernoratLineEdit->setStyleSheet(QString::fromUtf8("#gouvernoratLineEdit {\n"
"    background-color: #FFFFFF; /* Blanc pur pour un bon contraste */\n"
"    border: 2px solid #A0B9D9; /* Bordure bleu-gris pastel */\n"
"    border-radius: 20px; /* Coins arrondis */\n"
"    padding: 8px 12px; /* Espacement interne */\n"
"    font-size: 16px; /* Taille de police agr\303\251able */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour le texte */\n"
"    selection-background-color: #A0B9D9; /* Couleur de s\303\251lection */\n"
"}\n"
"\n"
"#gouvernoratLineEdit:focus {\n"
"    border: 2px solid #4A90E2; /* Bleu clair plus intense lors du focus */\n"
"    background-color: #F0F4F8; /* L\303\251g\303\250re variation pour effet moderne */\n"
"}\n"
"\n"
""));
        Saveta = new QPushButton(widget);
        Saveta->setObjectName("Saveta");
        Saveta->setGeometry(QRect(230, 490, 41, 41));
        Saveta->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        Saveta->setStyleSheet(QString::fromUtf8("QPushButton#Saveta {\n"
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
"QPushButton#Saveta:hover {\n"
"    background-color: #A0C4FF; \n"
"  \n"
"    color: #F9F9F9; \n"
"}\n"
"\n"
"QPushButton#Saveta:pressed {\n"
"    background-color: #A8D5BA; \n"
"   \n"
"}\n"
""));
        QIcon icon11(QIcon::fromTheme(QIcon::ThemeIcon::DocumentPrintPreview));
        Saveta->setIcon(icon11);
        Ajteta = new QPushButton(widget);
        Ajteta->setObjectName("Ajteta");
        Ajteta->setGeometry(QRect(350, 490, 101, 41));
        Ajteta->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        Ajteta->setStyleSheet(QString::fromUtf8("QPushButton#Ajteta {\n"
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
"QPushButton#Ajbtn:Ajteta {\n"
"    background-color: #A0C4FF; \n"
"    border: 2px dashed #A0C4FF; \n"
"    color: #F9F9F9; \n"
"}\n"
"\n"
"QPushButton#Ajteta:pressed {\n"
"    background-color: #A8D5BA; \n"
"    border: 2px dashed #5A9BD5;\n"
"}\n"
""));
        typeLineEdit = new QComboBox(widget);
        typeLineEdit->addItem(QString());
        typeLineEdit->addItem(QString());
        typeLineEdit->addItem(QString());
        typeLineEdit->setObjectName("typeLineEdit");
        typeLineEdit->setGeometry(QRect(310, 340, 141, 41));
        typeLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour une bonne lisibilit\303\251 */\n"
""));
        adresseLineEdit = new QLineEdit(widget);
        adresseLineEdit->setObjectName("adresseLineEdit");
        adresseLineEdit->setGeometry(QRect(310, 100, 141, 41));
        adresseLineEdit->setStyleSheet(QString::fromUtf8("#adresseLineEdit {\n"
"    background-color: #FFFFFF; /* Blanc pur pour un bon contraste */\n"
"    border: 2px solid #A0B9D9; /* Bordure bleu-gris pastel */\n"
"    border-radius: 20px; /* Coins arrondis */\n"
"    padding: 8px 12px; /* Espacement interne */\n"
"    font-size: 16px; /* Taille de police agr\303\251able */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour le texte */\n"
"    selection-background-color: #A0B9D9; /* Couleur de s\303\251lection */\n"
"}\n"
"\n"
"#adresseLineEdit:focus {\n"
"    border: 2px solid #4A90E2; /* Bleu clair plus intense lors du focus */\n"
"    background-color: #F0F4F8; /* L\303\251g\303\250re variation pour effet moderne */\n"
"}\n"
"\n"
""));
        label_36 = new QLabel(widget);
        label_36->setObjectName("label_36");
        label_36->setGeometry(QRect(310, 70, 63, 20));
        label_36->setStyleSheet(QString::fromUtf8("color: rgb(12, 12, 12);"));
        selectImageBtn = new QPushButton(widget);
        selectImageBtn->setObjectName("selectImageBtn");
        selectImageBtn->setGeometry(QRect(80, 490, 121, 41));
        selectImageBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        selectImageBtn->setStyleSheet(QString::fromUtf8("QPushButton#selectImageBtn{\n"
"    background-color: #3A7BD5; \n"
"    color: white;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    padding: 10px 20px; /* Uniformiser le padding */\n"
"    border-radius: 20px;\n"
"    text-align: center; /* Alignement horizontal */\n"
"    qproperty-alignment: 'AlignCenter'; /* Alignement Qt */\n"
"}\n"
"\n"
"QPushButton#selectImageBtn:hover {\n"
"    background-color: #A0C4FF; \n"
"    border: 2px dashed #A0C4FF; \n"
"    color: #F9F9F9; \n"
"}\n"
"\n"
"QPushButton#selectImageBtn:pressed {\n"
"    background-color: #A8D5BA; \n"
"    border: 2px dashed #5A9BD5;\n"
"}\n"
""));
        idSuperviseurLineEdit = new QLineEdit(widget);
        idSuperviseurLineEdit->setObjectName("idSuperviseurLineEdit");
        idSuperviseurLineEdit->setGeometry(QRect(80, 420, 161, 41));
        idSuperviseurLineEdit->setStyleSheet(QString::fromUtf8("#idSuperviseurLineEdit {\n"
"    background-color: #FFFFFF; /* Blanc pur pour un bon contraste */\n"
"    border: 2px solid #A0B9D9; /* Bordure bleu-gris pastel */\n"
"    border-radius: 20px; /* Coins arrondis */\n"
"    padding: 8px 12px; /* Espacement interne */\n"
"    font-size: 16px; /* Taille de police agr\303\251able */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour le texte */\n"
"    selection-background-color: #A0B9D9; /* Couleur de s\303\251lection */\n"
"}\n"
"\n"
"#idSuperviseurLineEdit:focus {\n"
"    border: 2px solid #4A90E2; /* Bleu clair plus intense lors du focus */\n"
"    background-color: #F0F4F8; /* L\303\251g\303\250re variation pour effet moderne */\n"
"}\n"
"\n"
""));
        idEquipementLineEdit = new QLineEdit(widget);
        idEquipementLineEdit->setObjectName("idEquipementLineEdit");
        idEquipementLineEdit->setGeometry(QRect(310, 420, 141, 41));
        idEquipementLineEdit->setStyleSheet(QString::fromUtf8("#idEquipementLineEdit {\n"
"    background-color: #FFFFFF; /* Blanc pur pour un bon contraste */\n"
"    border: 2px solid #A0B9D9; /* Bordure bleu-gris pastel */\n"
"    border-radius: 20px; /* Coins arrondis */\n"
"    padding: 8px 12px; /* Espacement interne */\n"
"    font-size: 16px; /* Taille de police agr\303\251able */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour le texte */\n"
"    selection-background-color: #A0B9D9; /* Couleur de s\303\251lection */\n"
"}\n"
"\n"
"#idEquipementLineEdit:focus {\n"
"    border: 2px solid #4A90E2; /* Bleu clair plus intense lors du focus */\n"
"    background-color: #F0F4F8; /* L\303\251g\303\250re variation pour effet moderne */\n"
"}\n"
"\n"
""));
        label_37 = new QLabel(widget);
        label_37->setObjectName("label_37");
        label_37->setGeometry(QRect(310, 390, 121, 20));
        label_37->setStyleSheet(QString::fromUtf8("color: rgb(12, 12, 12);"));
        label_38 = new QLabel(widget);
        label_38->setObjectName("label_38");
        label_38->setGeometry(QRect(80, 390, 101, 20));
        label_38->setStyleSheet(QString::fromUtf8("color: rgb(12, 12, 12);"));
        listWidget_4 = new QListWidget(widget);
        listWidget_4->setObjectName("listWidget_4");
        listWidget_4->setGeometry(QRect(40, 0, 431, 551));
        listWidget_4->setStyleSheet(QString::fromUtf8("QListWidget {\n"
"   border: 2px solid #A0B9D9; /* L\303\251g\303\250re bordure bleu-gris pastel */\n"
"    border-radius: 10px;        /* Coins arrondis */\n"
"    padding: 5px;               /* Un peu d'espace \303\240 l'int\303\251rieur */\n"
"}\n"
""));
        aze = new QLabel(widget);
        aze->setObjectName("aze");
        aze->setGeometry(QRect(90, 10, 391, 41));
        aze->setStyleSheet(QString::fromUtf8("#aze { \n"
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
        listWidget_4->raise();
        idEtablissementLineEdit->raise();
        label_18->raise();
        directeurLineEdit->raise();
        label_24->raise();
        label_26->raise();
        villeLineEdit->raise();
        label_32->raise();
        nomLineEdit->raise();
        label_33->raise();
        label_34->raise();
        nombreSalleLineEdit->raise();
        label_35->raise();
        gouvernoratLineEdit->raise();
        Saveta->raise();
        Ajteta->raise();
        typeLineEdit->raise();
        adresseLineEdit->raise();
        label_36->raise();
        selectImageBtn->raise();
        idSuperviseurLineEdit->raise();
        idEquipementLineEdit->raise();
        label_37->raise();
        label_38->raise();
        aze->raise();
        sortGovernorateBtn = new QPushButton(AjSuperv);
        sortGovernorateBtn->setObjectName("sortGovernorateBtn");
        sortGovernorateBtn->setGeometry(QRect(930, 100, 181, 41));
        sortGovernorateBtn->setStyleSheet(QString::fromUtf8("#sortGovernorateBtn { \n"
"    background-color: #FFFFFF; /* Fond blanc pour un bon contraste */\n"
"    border: 2px solid rgb(1, 121, 111); /* Bordure verte fonc\303\251e */\n"
"    border-radius: 20px; /* Coins arrondis */\n"
"    padding: 10px 15px; /* Espacement interne ajust\303\251 */\n"
"    font-size: 16px; /* Taille de police */\n"
"    font-weight: bold; /* Texte en gras pour une meilleure lisibilit\303\251 */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour le texte */\n"
"    cursor: pointer; /* Curseur en main pour montrer l'interactivit\303\251 */\n"
"    transition: all 0.3s ease-in-out; /* Animation fluide des effets */\n"
"}\n"
"\n"
"#sortGovernorateBtn:hover { \n"
"    background-color: rgb(1, 121, 111); /* Fond vert au survol */\n"
"    color: #FFFFFF; /* Texte blanc pour un bon contraste */\n"
"}\n"
"\n"
"#sortGovernorateBtn:focus, #sortGovernorateBtn:active { \n"
"    border: 2px solid rgb(1, 121, 111); /* Bordure renforc\303\251e */\n"
"    background-color: #E8F6F3; /* L\303\251ger vert"
                        " pastel au focus */\n"
"    outline: none; /* Supprime le contour bleu par d\303\251faut */\n"
"}\n"
""));
        ReMod = new QPushButton(AjSuperv);
        ReMod->setObjectName("ReMod");
        ReMod->setGeometry(QRect(1120, 100, 51, 41));
        ReMod->setStyleSheet(QString::fromUtf8("#ReMod { \n"
"    background-color: #FFFFFF; /* Fond blanc pour un bon contraste */\n"
"    border: 2px solid rgb(1, 121, 111); /* Bordure verte fonc\303\251e */\n"
"    border-radius: 20px; /* Coins arrondis */\n"
"    padding: 10px 15px; /* Espacement interne ajust\303\251 */\n"
"    font-size: 16px; /* Taille de police */\n"
"    font-weight: bold; /* Texte en gras pour une meilleure lisibilit\303\251 */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour le texte */\n"
"    cursor: pointer; /* Curseur en main pour montrer l'interactivit\303\251 */\n"
"    transition: all 0.3s ease-in-out; /* Animation fluide des effets */\n"
"}\n"
"\n"
"#ReMod:hover { \n"
"    background-color: rgb(1, 121, 111); /* Fond vert au survol */\n"
"    color: #FFFFFF; /* Texte blanc pour un bon contraste */\n"
"}\n"
"\n"
"#ReMod:focus, #ReMod:active { \n"
"    border: 2px solid rgb(1, 121, 111); /* Bordure renforc\303\251e */\n"
"    background-color: #E8F6F3; /* L\303\251ger vert pastel au focus */\n"
"    outline: none; /* Suppri"
                        "me le contour bleu par d\303\251faut */\n"
"}\n"
""));
        ReMod->setIcon(icon8);
        widget_9 = new QWidget(AjSuperv);
        widget_9->setObjectName("widget_9");
        widget_9->setGeometry(QRect(10, 590, 321, 151));
        widget_9->setStyleSheet(QString::fromUtf8("#widget_9 {\n"
"    border: 2px dashed #3498db; /* Bordure en pointill\303\251s bleue */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    background-color: #f8f9fa; /* Couleur de fond l\303\251g\303\250re */\n"
"}\n"
""));
        searchDirector = new QLineEdit(widget_9);
        searchDirector->setObjectName("searchDirector");
        searchDirector->setGeometry(QRect(40, 20, 181, 31));
        searchDirector->setStyleSheet(QString::fromUtf8("QLineEdit#searchDirector {\n"
"    border: 2px solid #3498db;     /* Bordure bleu clair */\n"
"    border-radius: 10px;           /* Coins arrondis */\n"
"    padding: 5px;                  /* Espacement interne */\n"
"    font-size: 14px;               /* Taille de la police */\n"
"    color: black;                  /* Texte saisi en noir */\n"
"}\n"
"\n"
"QLineEdit#searchDirector:focus {\n"
"    border: 2px solid #2ecc71;     /* Bordure verte quand le champ est focus */\n"
"}\n"
"\n"
"QLineEdit#searchDirector::placeholder {\n"
"    color: #2C3E50;                /* Couleur pour le texte d\342\200\231indication */\n"
"    font-style: italic;            /* Texte en italique */\n"
"}\n"
""));
        PdfLabel_2 = new QLabel(widget_9);
        PdfLabel_2->setObjectName("PdfLabel_2");
        PdfLabel_2->setGeometry(QRect(80, 80, 41, 41));
        PdfLabel_2->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/img/pdf.png);"));
        exportPdfBtn = new QPushButton(widget_9);
        exportPdfBtn->setObjectName("exportPdfBtn");
        exportPdfBtn->setGeometry(QRect(130, 80, 161, 41));
        exportPdfBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        exportPdfBtn->setStyleSheet(QString::fromUtf8("QPushButton#exportPdfBtn {\n"
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
"QPushButton#exportPdfBtn:hover {\n"
"    background-color: #A0C4FF; \n"
"    border: 2px dashed #A0C4FF; \n"
"    color: #F9F9F9; \n"
"}\n"
"\n"
"QPushButton#exportPdfBtn:pressed {\n"
"    background-color: #A8D5BA; \n"
"    border: 2px dashed #5A9BD5;\n"
"}\n"
""));
        exportPdfBtn->setIconSize(QSize(20, 20));
        exportPdfBtn->setCheckable(true);
        exportPdfBtn->setAutoExclusive(true);
        statsButton = new QPushButton(AjSuperv);
        statsButton->setObjectName("statsButton");
        statsButton->setGeometry(QRect(670, 700, 51, 41));
        statsButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        statsButton->setStyleSheet(QString::fromUtf8("QPushButton#statsButton{\n"
"    color: white;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"	border-image: url(:/new/prefix1/img/analytics.png);\n"
"    padding: 10px 20px; /* Uniformiser le padding */\n"
"    border-radius: 20px;\n"
"    border: 2px dashed #3A7BD5;\n"
"    text-align: center; /* Alignement horizontal */\n"
"    qproperty-alignment: 'AlignCenter'; /* Alignement Qt */\n"
"}\n"
"\n"
"QPushButton#statsButton:hover {\n"
"    background-color: #A0C4FF; \n"
"    border: 2px dashed #A0C4FF; \n"
"    color: #F9F9F9; \n"
"}\n"
"\n"
"QPushButton#statsButton:pressed {\n"
"    background-color: #A8D5BA; \n"
"    border: 2px dashed #5A9BD5;\n"
"}\n"
""));
        mapsButton = new QPushButton(AjSuperv);
        mapsButton->setObjectName("mapsButton");
        mapsButton->setGeometry(QRect(730, 700, 51, 41));
        mapsButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        mapsButton->setStyleSheet(QString::fromUtf8("QPushButton#mapsButton{\n"
"	border-image: url(:/img/carte-3d.png);\n"
"    background-color: #3A7BD5; \n"
"    color: white;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    padding: 10px 20px; /* Uniformiser le padding */\n"
"    border-radius: 20px;\n"
"    text-align: center; /* Alignement horizontal */\n"
"    qproperty-alignment: 'AlignCenter'; /* Alignement Qt */\n"
"}\n"
"\n"
"QPushButton#mapsButton:hover {\n"
"    background-color: #A0C4FF; \n"
"    border: 2px dashed #A0C4FF; \n"
"    color: #F9F9F9; \n"
"}\n"
"\n"
"QPushButton#mapsButton:pressed {\n"
"    background-color: #A8D5BA; \n"
"    border: 2px dashed #5A9BD5;\n"
"}\n"
""));
        label_39 = new QLabel(AjSuperv);
        label_39->setObjectName("label_39");
        label_39->setGeometry(QRect(20, 20, 381, 81));
        label_39->setStyleSheet(QString::fromUtf8("#label_39 { \n"
"    font-size: 25px; /* Taille r\303\251duite du texte */\n"
"    font-weight: bold; /* Texte en gras pour un effet titre */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour une bonne lisibilit\303\251 */\n"
"    background-color: transparent; /* Fond transparent */\n"
"    padding: 4px 8px; /* Espacement pour l'a\303\251ration */\n"
"    \n"
"    text-align: center; /* Centrage du texte */\n"
"}\n"
""));
        statsContainer = new QFrame(AjSuperv);
        statsContainer->setObjectName("statsContainer");
        statsContainer->setGeometry(QRect(320, 30, 71, 31));
        statsContainer->setFrameShape(QFrame::Shape::StyledPanel);
        statsContainer->setFrameShadow(QFrame::Shadow::Raised);
        Binetabtn = new QPushButton(AjSuperv);
        Binetabtn->setObjectName("Binetabtn");
        Binetabtn->setGeometry(QRect(20, 520, 51, 41));
        Binetabtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        Binetabtn->setStyleSheet(QString::fromUtf8("QPushButton#Binetabtn {\n"
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
"QPushButton#Binetabtn:hover {\n"
"    background-color: #E06666; \n"
"    \n"
"    color: #F9F9F9; \n"
"}\n"
"\n"
"QPushButton#Binetabtn:pressed {\n"
"    background-color: #B83232; \n"
"  \n"
"}\n"
""));
        Binetabtn->setIcon(icon6);
        Binetabtn->setIconSize(QSize(20, 20));
        Binetabtn->setCheckable(true);
        Binetabtn->setAutoExclusive(true);
        Modeta = new QPushButton(AjSuperv);
        Modeta->setObjectName("Modeta");
        Modeta->setGeometry(QRect(80, 520, 51, 41));
        Modeta->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        Modeta->setStyleSheet(QString::fromUtf8("QPushButton#Modeta {\n"
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
"QPushButton#Modeta:hover {\n"
"    background-color: #A0C4FF; \n"
"  \n"
"    color: #F9F9F9; \n"
"}\n"
"\n"
"QPushButton#Modeta:pressed {\n"
"    background-color: #A8D5BA; \n"
"   \n"
"}\n"
""));
        Modeta->setIcon(icon5);
        neweta = new QPushButton(AjSuperv);
        neweta->setObjectName("neweta");
        neweta->setGeometry(QRect(140, 520, 51, 41));
        QFont font;
        font.setBold(true);
        neweta->setFont(font);
        neweta->setStyleSheet(QString::fromUtf8("QPushButton#neweta  {\n"
"    background-color: rgb(1, 121, 111); /* Vert sapin */\n"
"    color: white;\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    border-radius: 18px; /* La moiti\303\251 de la taille pour un cercle */\n"
"    border: none;\n"
"    transition: all 0.3s ease-in-out;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QPushButton#neweta:hover {\n"
"    background-color: rgb(3, 150, 138); /* Vert sapin plus clair au survol */\n"
"    box-shadow: 0px 3px 8px rgba(1, 121, 111, 0.4);\n"
"}\n"
"\n"
"QPushButton#neweta:pressed {\n"
"    background-color: rgb(0, 100, 92); /* Vert sapin plus fonc\303\251*/\n"
"    box-shadow: 0px 2px 5px rgba(1, 121, 111, 0.5);\n"
"}"));
        QIcon icon12(QIcon::fromTheme(QIcon::ThemeIcon::ListAdd));
        neweta->setIcon(icon12);
        stackedWidget->addWidget(AjSuperv);
        statsContainer->raise();
        widget_6->raise();
        tableView_Eta->raise();
        widget->raise();
        sortGovernorateBtn->raise();
        ReMod->raise();
        widget_9->raise();
        statsButton->raise();
        mapsButton->raise();
        label_39->raise();
        Binetabtn->raise();
        Modeta->raise();
        neweta->raise();
        GestEquip = new QWidget();
        GestEquip->setObjectName("GestEquip");
        label_14 = new QLabel(GestEquip);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(310, 40, 181, 41));
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        stackedWidget->addWidget(GestEquip);
        GestSuperv = new QWidget();
        GestSuperv->setObjectName("GestSuperv");
        label_12 = new QLabel(GestSuperv);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(270, 40, 171, 31));
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(11, 11, 11);"));
        stackedWidget->addWidget(GestSuperv);
        GestEtab = new QWidget();
        GestEtab->setObjectName("GestEtab");
        label_16 = new QLabel(GestEtab);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(250, 50, 191, 16));
        label_16->setStyleSheet(QString::fromUtf8("color: rgb(8, 8, 8);"));
        stackedWidget->addWidget(GestEtab);
        His = new QWidget();
        His->setObjectName("His");
        emailHistoryTable = new QTableView(His);
        emailHistoryTable->setObjectName("emailHistoryTable");
        emailHistoryTable->setGeometry(QRect(130, 130, 1011, 531));
        emailHistoryTable->setStyleSheet(QString::fromUtf8("QTableView {\n"
"    background-color: #f0f4f8;\n"
"    border: 2px solid #3a6ea5;\n"
"    gridline-color: #bcccdc;\n"
"    font-size: 13px;\n"
"    font-family: \"Segoe UI\";\n"
"    alternate-background-color: #e8edf3;\n"
"    selection-background-color: #3a6ea5;\n"
"    selection-color: white;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #3a6ea5;\n"
"    color: white;\n"
"    padding: 6px;\n"
"    font-weight: bold;\n"
"    border: 1px solid #ccc;\n"
"}\n"
"\n"
"QTableView::item:selected {\n"
"    background-color: #3a6ea5;\n"
"    color: white;\n"
"}\n"
""));
        label_29 = new QLabel(His);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(490, 50, 281, 51));
        label_29->setStyleSheet(QString::fromUtf8("#label_29 { \n"
"    font-size: 25px; /* Taille r\303\251duite du texte */\n"
"    font-weight: bold; /* Texte en gras pour un effet titre */\n"
"    color: #2C3E50; /* Bleu fonc\303\251 pour une bonne lisibilit\303\251 */\n"
"    background-color: transparent; /* Fond transparent */\n"
"    padding: 4px 8px; /* Espacement pour l'a\303\251ration */\n"
"    border: 1px solid #A0B9D9; /* L\303\251g\303\250re bordure bleu-gris pastel */\n"
"    border-radius: 5px; /* Coins l\303\251g\303\250rement arrondis */\n"
"    text-align: center; /* Centrage du texte */\n"
"}\n"
""));
        stackedWidget->addWidget(His);
        homeBtn = new QPushButton(centralwidget);
        homeBtn->setObjectName("homeBtn");
        homeBtn->setGeometry(QRect(1220, 10, 36, 36));
        homeBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        homeBtn->setStyleSheet(QString::fromUtf8("QPushButton#homeBtn {\n"
"	image: url(:/new/prefix1/img/home.png);\n"
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
        homeBtn->setIconSize(QSize(20, 15));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(6);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "SmartEval", nullptr));
        supButton->setText(QString());
        eqButton->setText(QString());
        FourButton->setText(QString());
        candButton->setText(QString());
        etaButton->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "Superviseurs", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Equipements", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Etablissements", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Candidats", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Fournisseurs", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Examens", nullptr));
        statButton->setText(QString());
        label_25->setText(QCoreApplication::translate("MainWindow", "Statistiques", nullptr));
        closeBtn->setText(QString());
        historiqueBtn->setText(QString());
        emailBtn->setText(QString());
        paramBtn->setText(QString());
        label_17->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Gestion Des Examens", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "Liste des Fournisseurs :", nullptr));
        ModButton->setText(QString());
        TypeService->setText(QString());
        ID->setText(QString());
        Email->setText(QString());
        NumTel->setText(QString());
        ADRESSE->setText(QString());
        Ajbtn->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Ajouter un Fournisseur :", nullptr));
        NomT->setText(QCoreApplication::translate("MainWindow", "Nom :", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "TypeService :", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "Email :", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "NumTel:", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "Adresse :", nullptr));
        suppButton->setText(QString());
        Nom->setText(QString());
        SaveMod->setText(QString());
        btnAfficherTout->setText(QString());
        btnTrierNom->setText(QCoreApplication::translate("MainWindow", "Tri par Nom", nullptr));
        chatbotBtn->setText(QCoreApplication::translate("MainWindow", "chat", nullptr));
        PdfLabel_3->setText(QString());
        rechBtn->setText(QString());
        pdfBtn->setText(QCoreApplication::translate("MainWindow", "Liste en PDF", nullptr));
        sendChatBtn->setText(QCoreApplication::translate("MainWindow", "ENVOYER", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "ChatBot", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "Email Form", nullptr));
        EnvBtn->setText(QCoreApplication::translate("MainWindow", "Envoyer", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "R\303\251partition des fournisseurs par ", nullptr));
        comboBoxStatType->setItemText(0, QCoreApplication::translate("MainWindow", "Type de Service", nullptr));
        comboBoxStatType->setItemText(1, QCoreApplication::translate("MainWindow", "Adresse", nullptr));

        idEtablissementLineEdit->setText(QString());
        label_18->setText(QCoreApplication::translate("MainWindow", "Nom :", nullptr));
        directeurLineEdit->setText(QString());
        label_24->setText(QCoreApplication::translate("MainWindow", "Gouvernorat :", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "ID :", nullptr));
        villeLineEdit->setText(QString());
        label_32->setText(QCoreApplication::translate("MainWindow", "Nombre de Salles :", nullptr));
        nomLineEdit->setText(QString());
        label_33->setText(QCoreApplication::translate("MainWindow", "Type :", nullptr));
        label_34->setText(QCoreApplication::translate("MainWindow", "Ville :", nullptr));
        nombreSalleLineEdit->setText(QString());
        label_35->setText(QCoreApplication::translate("MainWindow", "Directeur :", nullptr));
        gouvernoratLineEdit->setText(QString());
        Saveta->setText(QString());
        Ajteta->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        typeLineEdit->setItemText(0, QCoreApplication::translate("MainWindow", "Lyc\303\251e ", nullptr));
        typeLineEdit->setItemText(1, QCoreApplication::translate("MainWindow", "coll\303\250ge", nullptr));
        typeLineEdit->setItemText(2, QCoreApplication::translate("MainWindow", "\303\251cole", nullptr));

        adresseLineEdit->setText(QString());
        label_36->setText(QCoreApplication::translate("MainWindow", "Adresse :", nullptr));
        selectImageBtn->setText(QCoreApplication::translate("MainWindow", "image 360", nullptr));
        idSuperviseurLineEdit->setText(QString());
        idEquipementLineEdit->setText(QString());
        label_37->setText(QCoreApplication::translate("MainWindow", "ID Equiepement :", nullptr));
        label_38->setText(QCoreApplication::translate("MainWindow", "ID Superviseur :", nullptr));
        aze->setText(QCoreApplication::translate("MainWindow", "Ajouter un Etablissement", nullptr));
        sortGovernorateBtn->setText(QCoreApplication::translate("MainWindow", "Tri par gouvernorat", nullptr));
        ReMod->setText(QString());
        PdfLabel_2->setText(QString());
        exportPdfBtn->setText(QCoreApplication::translate("MainWindow", "Liste en PDF", nullptr));
        statsButton->setText(QString());
        mapsButton->setText(QString());
        label_39->setText(QCoreApplication::translate("MainWindow", "Liste des Etablissements  :", nullptr));
        Binetabtn->setText(QString());
        Modeta->setText(QString());
        neweta->setText(QString());
        label_14->setText(QCoreApplication::translate("MainWindow", "Gestion Des Equipements", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Gestion des Fournisseurs", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Gestion des Superviseurs", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "Historique Des Emails", nullptr));
        homeBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
