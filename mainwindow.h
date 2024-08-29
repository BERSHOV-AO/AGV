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
#include <QDialog>
#include <QTableWidget>
#include <QStringList>
#include <QHeaderView>
#include "database.h"

class MainWindow : public QDialog
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
    QList<AgvItem> listAgv;
    //  QString      getTableNames();
    DataBase*        db;
    QTableWidget *table;


    ~MainWindow();
};
#endif // MAINWINDOW_H
