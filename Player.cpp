#include "Player.h"

Player::Player() {
    sequencia="";
}
void Player::prepararPlayer(string textoOriginal, int instrumentoInicial) {
    Texto parser(textoOriginal,instrumentoInicial);
    parser.converterTexto();
    sequencia=parser.getTextoConvertido();
}

void Player::tocarMusica() {
    string comando = "start /min ./release/CFUGUE/player \""+ sequencia +  "\"";
    //string comando = "start /min D:\\CFUGUE\\player \""+ sequencia +  "\"";
    system(comando.c_str());
}

void Player::gerarMidi(string nomeArquivo) {
    string caminho = "./release/arquivosMIDI/";
    //string caminho=".//";
    nomeArquivo += ".midi";
    string comando = "start /min ./release/CFUGUE/midiGenerator \""+ sequencia +  "\" \"" + caminho + nomeArquivo + "\"";
    system(comando.c_str());
}
