#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_botaoMusica_clicked();

    void on_botaoAjuda_clicked();

    void on_botaoArquivo_clicked();

    void on_gerarMIDI_clicked();

    void inicializaTimbres();

    void hideArquivo();

    void showArquivo();

    QString lerArquivo(QString nomeDoArquivo);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
