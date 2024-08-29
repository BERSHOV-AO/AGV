#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
{
    button1 = new QPushButton("Добавить AGV");
    button2 = new QPushButton("Список AGV");
    button3 = new QPushButton("Log AGV");
    label = new QLabel("AGV Администратор");
    mainLabel = new QLabel();
    imageLabel = new QLabel();

    db = new DataBase;
    db->connectToDataBase();

    mainLabel->setStyleSheet("background-color: white; color: black; padding: 10px;"); // Белый фон и отступы
    label->setStyleSheet("color: white; padding: 10px; font-size: 30px; font-weight: bold;");
    label->setMaximumHeight(50);

    // Устанавливаем фиксированный размер для mainLabel
    mainLabel->setFixedSize(1000, 450);

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


    // Добавление лейаута с меткой и кнопками в основной лейаут
    mainLayout->addLayout(labelImageLayout); // Сначала добавляем лейаут с меткой
    mainLayout->addWidget(mainLabel); // Затем добавляем mainLabel
    mainLayout->addLayout(pbxLayout); // Затем добавляем лейаут с кнопками

    // Установка основного лейаута для виджета
    this->setLayout(mainLayout);
}



MainWindow::~MainWindow()
{
}

