#include "Player.h"

const string caminho = "./CFUGUE/";
const string opcao= "start /min ";

Player::Player() {
    sequencia="";
}
void Player::prepararPlayer(string textoOriginal, int instrumentoInicial) {
    Texto parser(textoOriginal,instrumentoInicial);
    parser.converterTexto();
    sequencia=parser.getTextoConvertido();
    std::ofstream temp(caminho+"temp.txt");
    temp << sequencia;
    temp.close();

}

void Player::tocarMusica() {
    string comando = opcao + caminho + "player \""+ caminho + "temp.txt\"";
    system(comando.c_str());
}

void Player::gerarMidi(string nomeArquivo) {
    string pasta = "./release/arquivosMIDI/";
    nomeArquivo += ".midi";
    string comando = opcao + caminho + "midiGenerator \""+  caminho + "temp.txt\" \"" + pasta + nomeArquivo + "\"";
    system(comando.c_str());
}
