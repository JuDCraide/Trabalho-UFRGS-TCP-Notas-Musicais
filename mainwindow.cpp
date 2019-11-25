#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Player.h"
#include "teladeajuda.h"

#include <bits/stdc++.h>
#include <QDebug>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include <QFileDialog>

#define VAZIO ""

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    hideArquivo();
    inicializaTimbres();

}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::inicializaTimbres(){
    QStringList timbres = lerArquivo(":/txt/textos/Instrumentos.txt").split('\n');
    if(timbres.empty() || timbres.size()>GENERALMIDISIZE){
        for(int i=0; i<GENERALMIDISIZE; i++){
            ui->selecionarTimbre->addItem(QString::number(i));
        }
        qDebug()<<timbres.size();
    }else{
        for(int i=0; i<timbres.size(); i++){
            ui->selecionarTimbre->addItem(timbres.at(i));
        }
    }
}

void MainWindow::on_botaoMusica_clicked(){
    Player player;
    std::string texto = ui->txtOriginal->toPlainText().toStdString();
    int indexTimbre = ui->selecionarTimbre->currentIndex();

    if(texto==VAZIO){
        mensagemDeErro(":/txt/textos/CaixaDeTextoVazia.txt");
    } else {

        player.prepararPlayer(texto,indexTimbre);
        player.tocarMusica();

        if(ui->gerarMIDI->isChecked()){
            std::string arquivo = ui->nomeArquivo->text().toStdString();
            if(arquivo==VAZIO){
                mensagemDeErro(":/txt/textos/NomeDoArquivoVazio.txt");
            }else{
                player.gerarMidi(arquivo);
            }
        }
    }
}

void MainWindow::on_botaoAjuda_clicked(){

    QString instrucoes = "Para iniciar o uso digite um texto ou abra um arquivo";
    instrucoes = lerArquivo(":/txt/textos/Instrucoes.txt");
    QMessageBox::StandardButton resposta;
    resposta = QMessageBox::information(this,"Instruções",instrucoes,QMessageBox::Ok|QMessageBox::Help);

    if(resposta==QMessageBox::Help){
        TelaDeAjuda ajuda;
        ajuda.setWindowIcon(QIcon(":/imgs/imagens/favicon.ico"));
        ajuda.setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
        ajuda.exec();
    }

}

QString MainWindow::lerArquivo(QString nomeDoArquivo){
    QFile arquivo(nomeDoArquivo);

    if(!arquivo.open(QFile::ReadOnly | QFile::Text)){
        return VAZIO;
    }
    QTextStream in(&arquivo);
    in.setCodec(CODIFICACAO_TEXTUAL);

    QString texto = in.readAll();
    arquivo.close();

    return texto;
}

void MainWindow::on_botaoArquivo_clicked(){
    const QString filtro="Arquivos de Texto (*.txt) ;; Todos Arquivos (*.*)";
    QString arquivo = QFileDialog::getOpenFileName(this,"Abrir Arquivoss","C://",filtro);
    if(arquivo==VAZIO){
        return;
    }
    QString arquivoTxt = lerArquivo(arquivo);
    ui->txtOriginal->setPlainText(arquivoTxt);
}

void MainWindow::on_gerarMIDI_clicked(){
    if(ui->gerarMIDI->isChecked()){
        showArquivo();
    } else{
        hideArquivo();
    }
}

void MainWindow::hideArquivo(){
    ui->nomeArquivo->hide();
    ui->lableDigiteNome->hide();
    ui->botaoMusica->setText("Tocar Música");
}

void MainWindow::showArquivo(){
    ui->nomeArquivo->show();
    ui->lableDigiteNome->show();
    ui->botaoMusica->setText("Gerar e Tocar Música");
}

void MainWindow::mensagemDeErro(QString nomeDoArquivo){
    QString titulo="Um erro ocorreu", mensagem="Certifique-se que nenhum campo está vazio";

    QStringList conteudo=lerArquivo(nomeDoArquivo).split('\n');
    if (conteudo.size()>=2){
        titulo=conteudo.at(0);
        mensagem=conteudo.at(1);
    }

    QMessageBox::critical(this,titulo,mensagem);

}
