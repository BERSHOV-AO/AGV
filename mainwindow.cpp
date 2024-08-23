#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    button1 = new QPushButton("Добавить AGV");
    button2 = new QPushButton("Список AGV");
    button3 = new QPushButton("Log AGV");
    label = new QLabel("AGV Администратор");
    mainLabel = new QLabel();
    imageLabel = new QLabel();

    mainLabel->setStyleSheet("background-color: white; color: black; padding: 10px;"); // Белый фон и отступы
    label->setStyleSheet("color: white; padding: 10px; font-size: 30px; font-weight: bold; font-style: italic;");
    label->setMaximumHeight(50);

    // Устанавливаем фиксированный размер для mainLabel
    mainLabel->setFixedSize(1400, 700);

    QPixmap pixmap("C:/Users/Aleksey/Documents/AGV/image/logo_gaz.png"); // Укажите путь к вашему изображению
    QPixmap scaledPixmap = pixmap.scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    imageLabel->setPixmap(scaledPixmap);
    imageLabel->setFixedSize(100, 100); // Установите размер, если необходимо

    // Устанавливаем политику размера для метки
    label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    label->setAlignment(Qt::AlignCenter); // Выравнивание по центру

    // Устанавливаем политику размера для кнопок
    button1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    button2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    button3->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

    // Устанавливаем стиль для кнопок
    QString buttonStyle = "QPushButton { background-color: white; color: black; }";
    button1->setStyleSheet(buttonStyle);
    button2->setStyleSheet(buttonStyle);
    button3->setStyleSheet(buttonStyle);

    button1->setFixedSize(150, 50);
    button2->setFixedSize(150, 50);
    button3->setFixedSize(150, 50);

    //Layout setup
    QVBoxLayout* mainLayout = new QVBoxLayout;
    QHBoxLayout* labelImageLayout = new QHBoxLayout;
    QBoxLayout* pbxLayout = new QBoxLayout(QBoxLayout::LeftToRight); // Горизонтальный лейаут для кнопок

    // Добавляем метку и изображение в горизонтальный лейаут
    labelImageLayout->addWidget(label);
    labelImageLayout->addWidget(imageLabel);

    pbxLayout->addWidget(button1, 1);
    pbxLayout->addWidget(button2, 2);
    pbxLayout->addWidget(button3, 3);

    //******************************************************************************************
    QStringList drivers = QSqlDatabase::drivers();
    // Преобразование QStringList в QString
    QString driversString = drivers.join(", "); // Разделитель ", " можно изменить по желанию
    //mainLabel->setText(driversString);
    //******************************************************************************************


    //___________________________________DB____________________________________
//        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
//        db.setHostName("localhost");
//        db.setDatabaseName("agv_db");
//        db.setUserName("root");
//        db.setPassword("");

    //    //____________________________________________________________________________

    //      QSqlQuery query;
    //      QString str = QString("SELECT serialNumber FROM agv");
    //      query.prepare(str);

    //      if(query.exec())
    //      {
    //          for(int i = 0; i < 3; i++)
    //          {
    //              query.next();
    //              stringListModel << query.value(0).toString();
    //          }
    //      }

    QString tables = getTableNames();
    mainLabel->setText(tables);


    // Добавление лейаута с меткой и кнопками в основной лейаут
    mainLayout->addLayout(labelImageLayout); // Сначала добавляем лейаут с меткой
    mainLayout->addWidget(mainLabel); // Затем добавляем mainLabel
    mainLayout->addLayout(pbxLayout); // Затем добавляем лейаут с кнопками

    // Установка основного лейаута для виджета
    this->setLayout(mainLayout);
}

QString MainWindow::getTableNames() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("agv_db");
    db.setUserName("root");
   // db.setPassword("");

//    if (!db.open()) {
//        qDebug() << "Ошибка подключения к базе данных:"; //<< db.lastError().text();
//        return QString();
//    }

    if( db.open() )
       {
           qDebug() << "Connected!";

       }
       else
       {
           QString errorMessage;
           QString errorMessageDriverText;
           QSqlError error = db.lastError();
           if (error.isValid()) {
                errorMessage = error.text(); // Получаем текст ошибки как QString
                errorMessageDriverText = error.driverText();

               // Теперь вы можете использовать errorMessage по своему усмотрению
           }

           qDebug() << "Failed to connect." << errorMessage << "   errorMessageDriverText: " << errorMessageDriverText;
           return 0;
       }


    QStringList tableNames = db.tables(); // Получаем список таблиц
    QString allTableNames = tableNames.join(", "); // Объединяем названия в одну строку через запятую

    return allTableNames; // Возвращаем строку с названиями таблиц
}

MainWindow::~MainWindow()
{
}

