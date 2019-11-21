#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Musicando");
    //QIcon icone(":/img/imagens/favicon_created_by_logaster.ico");
    w.setWindowIcon(QIcon(":/img/imagens/favicon_created_by_logaster.ico"));
    w.showMaximized();
    //w.showFullScreen();
    return a.exec();
}
