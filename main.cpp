#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    window.setWindowTitle("Musicando");
    window.setWindowIcon(QIcon(":/img/imagens/favicon_created_by_logaster.ico"));
    window.showMaximized();
    return app.exec();
}
