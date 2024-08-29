#include "mainwindow.h"
#include "auth.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Auth w;
    //w.setStyleSheet("background-color: #FF1C385A;");
    //w.resize(800, 800);
    w.show();
    return a.exec();
}
