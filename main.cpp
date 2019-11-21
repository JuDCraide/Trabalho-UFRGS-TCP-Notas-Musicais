#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    window.setWindowTitle("Musicando");
    window.setWindowIcon(QIcon(":/imgs/imagens/favicon.ico"));
    window.showMaximized();
    return app.exec();
}
