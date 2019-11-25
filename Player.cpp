#include "Player.h"

const string caminho = "start /min ./release/CFUGUE/";

Player::Player() {
    sequencia="";
}
void Player::prepararPlayer(string textoOriginal, int instrumentoInicial) {
    Texto parser(textoOriginal,instrumentoInicial);
    parser.converterTexto();
    sequencia=parser.getTextoConvertido();
}

void Player::tocarMusica() {
    string comando = caminho + "player \""+ sequencia +  "\"";
    system(comando.c_str());
}

void Player::gerarMidi(string nomeArquivo) {
    string caminho = "./release/arquivosMIDI/";
    nomeArquivo += ".midi";
    string comando = caminho + "midiGenerator \""+ sequencia +  "\" \"" + caminho + nomeArquivo + "\"";
    system(comando.c_str());
}
