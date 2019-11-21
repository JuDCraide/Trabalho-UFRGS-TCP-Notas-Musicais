#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Player.h"

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
    QString timbres[128] = {"0 - ACOUSTIC GRAND PIANO","1 - BRIGHT ACOUSTIC","2 - ELECTRIC GRAND","3 - HONKEY TONK","4 - ELECTRIC PIANO 1","5 - ELECTRIC PIANO 2","6 - HARPISCHORD","7 - CLAVINET","8 - CELESTA","9 - GLOCKENSPIEL","10 - MUSIC BOX","11 - VIBRAPHONE","12 - MARIMBA","13 - XYLOPHONE","14 - TUBULAR BELLS","15 - DULCIMER","16 - DRAWBAR ORGAN","17 - PERCUSSIVE ORGAN","18 - ROCK ORGAN","19 - CHURCH ORGAN","20 - REED ORGAN","21 - ACCORDIAN","22 - HARMONICA","23 - TANGO ACCORDIAN","24 - NYLON STRING GUITAR","25 - STEEL STRING GUITAR","26 - ELECTRIC JAZZ GUITAR","27 - ELECTRIC CLEAN GUITAR","28 - ELECTRIC MUTED GUITAR","29 - OVERDRIVEN GUITAR","30 - DISTORTION GUITAR","31 - GUITAR HARMONICS","32 - ACOUSTIC BASS","33 - ELECTRIC BASS FINGER","34 - ELECTRIC BASS PICK","35 - FRETLESS BASS","36 - SLAP BASS 1","37 - SLAP BASS 2","38 - SYNTH BASS 1","39 - SYNTH BASS 2","40 - VIOLIN","41 - VIOLA","42 - CELLO","43 - CONTRABASS","44 - TREMOLO STRINGS","45 - PIZZICATO STRINGS","46 - ORCHESTRAL STRINGS","47 - TIMPANI","48 - STRING ENSEMBLE 1","49 - STRING ENSEMBLE 2","50 - SYNTH STRINGS 1","51 - SYNTH STRINGS 2","52 - CHOIR AAHS","53 - VOICE OOHS","54 - SYNTH VOICE","55 - ORCHESTRA HIT","56 - TRUMPET","57 - TROMBONE","58 - TUBA","59 - MUTED TRUMPET","60 - FRENCH HORN","61 - BRASS SECTION","62 - SYNTHBRASS 1","63 - SYNTHBRASS 2","64 - SOPRANO SAX","65 - ALTO SAX","66 - TENOR SAX","67 - BARITONE SAX","68 - OBOE","69 - ENGLISH HORN","70 - BASSOON","71 - CLARINET","72 - PICCOLO","73 - FLUTE","74 - RECORDER","75 - PAN FLUTE","76 - BLOWN BOTTLE","77 - SKAKUHACHI","78 - WHISTLE","79 - OCARINA","80 - SQUARE","81 - SAWTOOTH","82 - CALLIOPE","83 - CHIFF","84 - CHARANG","85 - VOICE","86 - FIFTHS","87 - BASSLEAD","88 - NEW AGE","89 - WARM","90 - POLYSYNTH","91 - CHOIR","92 - BOWED","93 - METALLIC","94 - HALO","95 - SWEEP","96 - RAIN","97 - SOUNDTRACK","98 - CRYSTAL","99 - ATMOSPHERE","100 - BRIGHTNESS","101 - GOBLINS","102 - ECHOES","103 - SCI-FI","104 - SITAR","105 - BANJO","106 - SHAMISEN","107 - KOTO","108 - KALIMBA","109 - BAGPIPE","110 - FIDDLE","111 - SHANAI","112 - TINKLE BELL","113 - AGOGO","114 - STEEL DRUMS","115 - WOODBLOCK","116 - TAIKO DRUM","117 - MELODIC TOM","118 - SYNTH DRUM","119 - REVERSE CYMBAL","120 - GUITAR FRET NOISE","121 - BREATH NOISE","122 - SEASHORE","123 - BIRD TWEET","124 - TELEPHONE RING","125 - HELICOPTER","126 - APPLAUSE","127 - GUNSHOT"};
    for(int i=0; i<128; i++){
        ui->selecionarTimbre->addItem(timbres[i]);
    }
}

void MainWindow::on_botaoMusica_clicked(){
    Player player;
    std::string texto = ui->txtOriginal->toPlainText().toStdString();
    //std::cout<<texto;
    if(texto==VAZIO){
        QMessageBox::critical(this,"Não foi possível tocar a música","O campo de texto não pode ser deixado vazio.");
        return;
    }
    int indexTimbre = ui->selecionarTimbre->currentIndex();
    //qDebug() << indexTimbre;
    player.prepararPlayer(texto,indexTimbre);
    qDebug()<<"preparou";
    player.tocarMusica();
    qDebug()<<"tocou";
    if(ui->gerarMIDI->isChecked()){
        std::string arquivo = ui->nomeArquivo->text().toStdString();
        if(arquivo==VAZIO){
            QMessageBox::critical(this,"Não foi possível tocar a música","O nome do arquivo não pode ser deixado vazio,\nquando a opção de gerar MIDI estiver selecionada");
            return;
        }else{
            player.gerarMidi(arquivo);
        }
    }
}

void MainWindow::on_botaoAjuda_clicked(){
    QMessageBox::information(this,"Instruções","Para iniciar o uso digite um texto ou abra um arquivo\nEm seguida escolha um timbre inicial, ou deixe no piano padrão\nCaso deseje salvar a música clique no checkbox\nAssim, será possível escolher um nome para o seu arquivo\nEm seguida aperte o botão para Tocar/Gerar e Tocar a música e PRONTO\nAprecie sua música gerada a partir de texto");
}

QString readFile(QString fileName){
    QFile file(fileName);

    if(!file.open(QFile::ReadOnly | QFile::Text)){
        return VAZIO;
    }
    QTextStream in(&file);

    QString text = in.readAll();
    file.close();

    return text;
}

void MainWindow::on_botaoArquivo_clicked(){
    const QString filtro="Arquivos de Texto (*.txt) ;; Todos Arquivos (*.*)";
    QString file = QFileDialog::getOpenFileName(this,"Abrir Arquivoss","C://",filtro);
    if(file==VAZIO){
        return;
    }
    QString txtFile = readFile(file);
    ui->txtOriginal->setPlainText(txtFile);
}

void MainWindow::on_gerarMIDI_clicked()
{
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
