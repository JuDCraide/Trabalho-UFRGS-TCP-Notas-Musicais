#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->nomeArquivo->hide();
    ui->lableDigiteNome->hide();

    QString cursos[128]={"0","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31","32","33","34","35","36","37","38","39","40","41","42","43","44","45","46","47","48","49","50","51","52","53","54","55","56","57","58","59","60","61","62","63","64","65","66","67","68","69","70","71","72","73","74","75","76","77","78","79","80","81","82","83","84","85","86","87","88","89","90","91","92","93","94","95","96","97","98","99","100","101","102","103","104","105","106","107","108","109","110","111","112","113","114","115","116","117","118","119","120","121","122","123","124","125","126","127"};
    for(int i=0; i<128; i++){
        ui->selecionarTimbre->addItem(cursos[i]);
    }

    //ui->comboBox->addItem(cursos[5],num[5])

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_botaoMusica_clicked()
{
   // ui->label->setText("alo coco");
    QString texto = ui->txtOriginal->toPlainText();
    qDebug() << texto;
    if(texto==""){
         QMessageBox::critical(this,"Não foi possível tocar a música","O campo de texto não pode ser deixado vazio.");
        return;
    }
    //qDebug() << ui->selecionarTimbre->currentText();
    qDebug() << ui->selecionarTimbre->currentIndex();
    if(ui->gerarMIDI->isChecked()){
        QString arquivo = ui->nomeArquivo->text();
        qDebug() << arquivo;
        if(arquivo==""){
            QMessageBox::critical(this,"Não foi possível tocar a música","O nome do arquivo não pode ser deixado vazio,\nenquanto a opção gerar MIDI estiver selecionada");
            return;
        }
    }
}



void MainWindow::on_botaoAjuda_clicked()
{
    qDebug() << "ajudaa";
    QMessageBox::information(this,"Instruções","Aq vão as instruções");

}

QString readFile(QString fileName){
    QFile file(fileName);

    if(!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug()<<"erro";
    }
    QTextStream in(&file);

    QString text = in.readAll();
    //qDebug() << text;
    file.close();
    return text;
}

void MainWindow::on_botaoArquivo_clicked()
{
    //QString file = "D:/cachorro.txt";
    const QString filtro="Arquivos de Texto (*.txt) ;; Todos Arquivos (*.*)";
    QString file = QFileDialog::getOpenFileName(this,"Abrir Arquivoss","C://",filtro);
    QString txtFile = readFile(file);
    ui->txtOriginal->setPlainText(txtFile);
}


void MainWindow::on_gerarMIDI_clicked()
{
    if(ui->gerarMIDI->isChecked()){
        ui->nomeArquivo->show();
        ui->lableDigiteNome->show();
        ui->botaoMusica->setText("Gerar e Tocar Música");
    } else{
        ui->nomeArquivo->hide();
        ui->lableDigiteNome->hide();
        ui->botaoMusica->setText("Tocar Música");
    }
}
