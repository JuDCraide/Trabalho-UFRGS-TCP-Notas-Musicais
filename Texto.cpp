#include "Texto.h"

Texto::Texto(string textoOriginal, int instrumentoInicial) : musica(instrumentoInicial) {
    this->textoOriginal = textoOriginal;
}

void Texto::converterTexto() {

    textoConvertido = musica.instrumento.getCodigo();

    for(unsigned int i = 0; i < textoOriginal.size(); i++) {
        if(musica.isNota(textoOriginal[i])) {
            musica.atualizaNotaAtual(textoOriginal[i]);
            textoConvertido += musica.converteNotaAtual();
        }
        else if (musica.isVolume(textoOriginal[i])) {
            musica.volume.dobrarVolume();
        }
        else if (musica.isInstrumento(textoOriginal[i])) {
            musica.atualizaInstrumentoAtual(textoOriginal[i]);
            textoConvertido += musica.instrumento.getCodigo();
        }
        else if(musica.isOitava(textoOriginal[i])) {
            musica.oitava.aumentarOitava();
        }
        else {
            if(anteriorIsNota(i)) {
                textoConvertido += musica.converteNotaAtual();
            } else {
                textoConvertido += SILENCIO;
            }
        }
    }
}

string Texto::getTextoConvertido() {
    return textoConvertido;
}

bool Texto::anteriorIsNota(unsigned int posicaoAtual){
    if(posicaoAtual != 0){
        return musica.isNota(textoOriginal[posicaoAtual - 1]);
    }
    return false;
}
