#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>

/* Директивы имен таблицы, полей таблицы и базы данных */
#define DATABASE_NAME           "agv_db"
//#define DIR_AND_NAME_DATABASE   "./dbLogbook.db"
//#define DATABASE_HOSTNAME       "NameDataBase"                                              // имя хоста
//#define DIR_AND_NAME_DATABASE   "./dirDB/dbLogbook.db"                                      // Dir таблицы и имя
#define TABLE                   "agv"

class DataBase : public QObject
{
    Q_OBJECT
public:
    explicit DataBase(QObject *parent = nullptr);

signals:

};

#endif // DATABASE_H
