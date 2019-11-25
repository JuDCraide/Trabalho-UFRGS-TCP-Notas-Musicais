#include "Musica.h"


Musica::Musica(int instrumentoInicial): instrumento(instrumentoInicial) {
    notasValidas['A'] = Nota("LA", "A");
    notasValidas['B'] = Nota("SI", "B");
    notasValidas['C'] = Nota("DO", "C");
    notasValidas['D'] = Nota("RE", "D");
    notasValidas['E'] = Nota("MI", "E");
    notasValidas['F'] = Nota("FA", "F");
    notasValidas['G'] = Nota("SOL", "G");
}

bool Musica::isInstrumento(char instrucao) {
    switch(instrucao) {
    case '!':
    case 'i':
    case 'I':
    case 'o':
    case 'O':
    case 'u':
    case 'U':
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case '\n':
    case ';':
    case ',':
        return true;
    default:
        return false;
    }
}

int charToInt(char numero){
    return numero-'0';
}

void Musica::atualizaInstrumentoAtual(char instrucao) {
    switch(instrucao) {
    case '!':
        instrumento.setAtual(AGOGO);
        break;
    case 'i':
    case 'I':
    case 'o':
    case 'O':
    case 'u':
    case 'U':
        instrumento.setAtual(HARPSICHORD);
        break;
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9': {
        int novo = instrumento.getAtual() + charToInt(instrucao) ;
        if(novo >= INSTRUMENTO_MIN && novo <= INSTRUMENTO_MAX) {

            instrumento.setAtual(novo);
        } else {
            instrumento.setAtual(instrumento.getInstrumentoPadrao());
        }
        break;
    }
    case '\n':
        instrumento.setAtual(TUBULAR_BELLS);
        break;
    case ';':
        instrumento.setAtual(PAN_FLUTE);
        break;
    case ',':
        instrumento.setAtual(CHURCH_ORGAN);
        break;

    }
}

bool Musica::isNota(char instrucao) {
    if(notasValidas.find(instrucao) != notasValidas.end()) {
        return true;
    } else {
        return false;
    }
}

void Musica::atualizaNotaAtual(char instrucao) {
    nota = notasValidas[instrucao];
}

bool Musica::isVolume(char instrucao) {
    if(instrucao == ' ') {
        return true;
    } else {
        return false;
    }
}

bool Musica::isOitava(char instrucao) {
    if(instrucao == '.' || instrucao == '?') {
        return true;
    } else {
        return false;
    }
}

string Musica::converteNotaAtual(){
    return (" " + nota.getCodigo() + oitava.getCodigo() + volume.getCodigo());
}
