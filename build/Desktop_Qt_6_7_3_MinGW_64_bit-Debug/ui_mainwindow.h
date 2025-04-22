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
    QPushButton *pdfBtn;
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
    QLineEdit *lineEditRech;
    QPushButton *rechBtn;
    QPushButton *suppButton;
    QLineEdit *Nom;
    QPushButton *SaveMod;
    QPushButton *btnAfficherTout;
    QPushButton *btnTrierNom;
    QPushButton *chatbotBtn;
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
    QPushButton *AffButton_4;
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
        MainWindow->resize(1455, 838);
        MainWindow->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: #D9E6F2; /* Bleu pastel plus visible */"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        fullMenu = new QWidget(centralwidget);
        fullMenu->setObjectName("fullMenu");
        fullMenu->setGeometry(QRect(10, 10, 161, 711));
        label_2 = new QLabel(fullMenu);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 0, 63, 61));
        label_2->setCursor(QCursor(Qt::CursorShape::ForbiddenCursor));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/img/logo.png")));
        label_3 = new QLabel(fullMenu);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 10, 91, 41));
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
        etaButton->raise();
        candButton->raise();
        eqButton->raise();
        examButton->raise();
        label_2->raise();
        label_3->raise();
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
        historiqueBtn->setGeometry(QRect(1360, 10, 36, 36));
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
        emailBtn->setGeometry(QRect(1310, 10, 36, 36));
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
        paramBtn->setGeometry(QRect(1260, 10, 36, 36));
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
        stackedWidget->setGeometry(QRect(170, 50, 1301, 791));
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
        pdfBtn = new QPushButton(GestFourn);
        pdfBtn->setObjectName("pdfBtn");
        pdfBtn->setGeometry(QRect(20, 500, 141, 41));
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
        tableFourn = new QTableView(GestFourn);
        tableFourn->setObjectName("tableFourn");
        tableFourn->setGeometry(QRect(20, 80, 721, 351));
        tableFourn->setStyleSheet(QString::fromUtf8("#tableWidget1 {\n"
"    border: 2px solid #4A90E2; /* Bordure bleue */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
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
"    padding: 6px;\n"
"    border: 1px solid #4A90E2; /* Bo"
                        "rdure des en-t\303\252tes */\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"#tableWidget1 QTableCornerButton::section {\n"
"    background-color: #4A90E2; /* Coin sup\303\251rieur gauche */\n"
"    border: 1px solid #4A90E2;\n"
"}\n"
""));
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
        ModButton->setGeometry(QRect(20, 450, 51, 41));
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
        listWidget_2->setGeometry(QRect(810, 140, 451, 521));
        listWidget_2->setStyleSheet(QString::fromUtf8("QListWidget {\n"
"    border: 2px solid blue;    /* Bordure bleue */\n"
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
        lineEditRech = new QLineEdit(GestFourn);
        lineEditRech->setObjectName("lineEditRech");
        lineEditRech->setGeometry(QRect(420, 450, 251, 41));
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
        rechBtn = new QPushButton(GestFourn);
        rechBtn->setObjectName("rechBtn");
        rechBtn->setGeometry(QRect(680, 450, 61, 41));
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
        QIcon icon6(QIcon::fromTheme(QIcon::ThemeIcon::SystemSearch));
        rechBtn->setIcon(icon6);
        suppButton = new QPushButton(GestFourn);
        suppButton->setObjectName("suppButton");
        suppButton->setGeometry(QRect(80, 450, 51, 41));
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
        QIcon icon7(QIcon::fromTheme(QIcon::ThemeIcon::EditDelete));
        suppButton->setIcon(icon7);
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
        SaveMod->setGeometry(QRect(840, 610, 51, 41));
        SaveMod->setStyleSheet(QString::fromUtf8("QPushButton#suppButton  {\n"
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
        QIcon icon8(QIcon::fromTheme(QIcon::ThemeIcon::DocumentNew));
        SaveMod->setIcon(icon8);
        btnAfficherTout = new QPushButton(GestFourn);
        btnAfficherTout->setObjectName("btnAfficherTout");
        btnAfficherTout->setGeometry(QRect(150, 450, 51, 41));
        btnAfficherTout->setStyleSheet(QString::fromUtf8("QPushButton#ModButton  {\n"
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
        QIcon icon9(QIcon::fromTheme(QIcon::ThemeIcon::DocumentRevert));
        btnAfficherTout->setIcon(icon9);
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
        chatbotBtn->setGeometry(QRect(170, 500, 141, 41));
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
        QIcon icon10;
        icon10.addFile(QString::fromUtf8("img/chat.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        chatbotBtn->setIcon(icon10);
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
        AffButton_4 = new QPushButton(AjSuperv);
        AffButton_4->setObjectName("AffButton_4");
        AffButton_4->setGeometry(QRect(0, 10, 121, 41));
        AffButton_4->setStyleSheet(QString::fromUtf8("QPushButton#AffButton_4  {\n"
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
"QPushButton#AffButton_4:hover {\n"
"    background-color: rgb(3, 150, 138); /* Vert sapin plus clair au survol */\n"
"    box-shadow: 0px 3px 8px rgba(1, 121, 111, 0.4);\n"
"}\n"
"\n"
"QPushButton#AffButton_4 :pressed {\n"
"    background-color: rgb(0, 100, 92); /* Vert sapin plus fonc\303\251*/\n"
"    box-shadow: 0px 2px 5px rgba(1, 121, 111, 0.5);\n"
"}"));
        AffButton_4->setIcon(icon8);
        stackedWidget->addWidget(AjSuperv);
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
        homeBtn->setGeometry(QRect(1210, 10, 36, 36));
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

        stackedWidget->setCurrentIndex(2);


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
        pdfBtn->setText(QCoreApplication::translate("MainWindow", "G\303\251rer la liste", nullptr));
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
        rechBtn->setText(QString());
        suppButton->setText(QString());
        Nom->setText(QString());
        SaveMod->setText(QString());
        btnAfficherTout->setText(QString());
        btnTrierNom->setText(QCoreApplication::translate("MainWindow", "Tri par Nom", nullptr));
        chatbotBtn->setText(QCoreApplication::translate("MainWindow", "chat", nullptr));
        sendChatBtn->setText(QCoreApplication::translate("MainWindow", "ENVOYER", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "ChatBot", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "Email Form", nullptr));
        EnvBtn->setText(QCoreApplication::translate("MainWindow", "Envoyer", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "R\303\251partition des fournisseurs par ", nullptr));
        comboBoxStatType->setItemText(0, QCoreApplication::translate("MainWindow", "Type de Service", nullptr));
        comboBoxStatType->setItemText(1, QCoreApplication::translate("MainWindow", "Adresse", nullptr));

        AffButton_4->setText(QString());
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
