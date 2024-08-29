#include "auth.h"

Auth::Auth(QWidget *parent) : QWidget(parent)
{

    pBtnOpenMainWindow = new QPushButton("AGV Администратор");
    linePassword = new QLineEdit();
    imageLabelLogo = new QLabel();
    lableAgv = new QLabel("AGV");

    QGridLayout* layoutMain = new QGridLayout(this);
    QGridLayout* layoutAuth = new QGridLayout();
    QGridLayout* layoutLogo = new QGridLayout();


    //------------------------------------стили----------------------------------
    QString buttonStyle = "QPushButton { background-color: white; color: black; }";
    pBtnOpenMainWindow->setStyleSheet(buttonStyle);
    linePassword->setStyleSheet("QLineEdit { background-color: lightgray; color: blue; }");
    lableAgv->setStyleSheet("QLabel {"
                            "color: white;"
                            "background-color: transparent;"
                            "font-size: 20px;"
                            "font-weight: bold;"
                            "text-align: center;"  // Выравнивание текста по центру
                            "}");
    //------------------------------------------------------------------------------


    //------------------------------------image-----------------------------------
    QPixmap pixmap("C:/Users/Aleksey/Documents/AGV/image/logo_gaz.png"); // Укажите путь к вашему изображению
    QPixmap scaledPixmap = pixmap.scaled(50, 50, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    imageLabelLogo->setPixmap(scaledPixmap);
    imageLabelLogo->setFixedSize(50, 50); // Установите размер, если необходимо
    //-----------------------------------------------------------------------------


    //-----------------------------------------------
    pGrBoxLogo = new QGroupBox;
    layoutLogo->addWidget(lableAgv,             0,0);
    layoutLogo->addWidget(imageLabelLogo,       0,1);
    pGrBoxLogo->setLayout(layoutLogo);
    //-----------------------------------------------

    //-----------------------------------------------
    pGrBoxAuth = new QGroupBox;
    layoutAuth->addWidget(linePassword,          0,0);
    layoutAuth->addWidget(pBtnOpenMainWindow,    1,0);
    pGrBoxAuth->setLayout(layoutAuth);
    //-----------------------------------------------

    layoutMain->addWidget(pGrBoxLogo,    0,1);
    layoutMain->addWidget(pGrBoxAuth,    1,1);
    this->setLayout(layoutMain);
    this->setWindowTitle(tr("Аутентификация администратора  AGV"));
    this->setStyleSheet("background-color: #FF1C385A;");
    this->resize(270, 150);

    connect(pBtnOpenMainWindow,SIGNAL(clicked()),this,SLOT(open_MainWindow()));
}

void Auth::open_MainWindow()
{
    if(linePassword->text() == PASSWORD) {
        MainWindow *m = new MainWindow(this);
        m->exec();
        delete m;
    }
}

