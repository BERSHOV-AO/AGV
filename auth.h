#ifndef AUTH_H
#define AUTH_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QtCore>
#include <QPushButton>
#include <QLineEdit>
#include <QGroupBox>
#include <QPixmap>
#include "mainwindow.h"

#define PASSWORD        "1"

class Auth : public QWidget
{
    Q_OBJECT
public:
    explicit Auth(QWidget *parent = nullptr);
private:

    QPushButton* pBtnOpenMainWindow;
    QLineEdit*   linePassword;
    QGroupBox*   pGrBoxAuth;
    QGroupBox*   pGrBoxLogo;
    QLabel*      imageLabelLogo;
    QLabel*      lableAgv;




private slots:
    void open_MainWindow();



signals:

};

#endif // AUTH_H
