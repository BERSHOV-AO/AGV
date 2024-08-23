#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QPushButton>
#include <QBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QDir>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QStringList>
#include <QDebug>
#include <QSqlError>
#include <QtSql>
#include <QtCore>
class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    QPushButton* button1;
    QPushButton* button2;
    QPushButton* button3;
    QLabel* label;
    QLabel* mainLabel;
    QLabel *imageLabel;
    QStringList  stringListModel;
    QString      getTableNames();

    ~MainWindow();
};
#endif // MAINWINDOW_H
