#include "teladeajuda.h"
#include "ui_teladeajuda.h"
#include <QFile>
#include <QString>
#include <QTextStream>
#define VAZIO ""

TelaDeAjuda::TelaDeAjuda(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TelaDeAjuda)
{
    ui->setupUi(this);
    QString ajuda=lerArquivo(":/txt/textos/ajuda.txt");
    ui->textBrowser->setText(ajuda);
}

TelaDeAjuda::~TelaDeAjuda()
{
    delete ui;
}

QString TelaDeAjuda::lerArquivo(QString nomeDoArquivo){
    QFile arquivo(nomeDoArquivo);

    if(!arquivo.open(QFile::ReadOnly | QFile::Text)){
        return VAZIO;
    }
    QTextStream in(&arquivo);
    in.setCodec("UTF-8");

    QString texto = in.readAll();
    arquivo.close();

    return texto;
}
