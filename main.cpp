#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Musicando");
    QIcon icone(":/img/imagens/favicon_created_by_logaster.ico");
    w.setWindowIcon(icone);
    w.showMaximized();
    //w.showFullScreen();
    return a.exec();
}
