#include "Texto.h"

Texto::Texto(string textoOriginal, int instrumentoInicial) : musica(instrumentoInicial) {
    this->textoOriginal = textoOriginal;
}
/*
void Texto::setTexto(string textoOriginal) {
    this->textoOriginal = textoOriginal;
}

void Texto::setInstrumentoInicial(string textoOriginal) {

}*/
void Texto::converterTexto() {
    textoConvertido = musica.instrumento.getCodigo();
    for(int i = 0; i < textoOriginal.size(); i++) {
        if(musica.isNota(textoOriginal[i])) {
            musica.atualizaNotaAtual(textoOriginal[i]);
            textoConvertido += (" " + musica.nota.getCodigo() + musica.oitava.getCodigo() + musica.volume.getCodigo()); //verificar
        } else if (musica.isVolume(textoOriginal[i])) {
            musica.volume.dobrarVolume();
        } else if (musica.isInstrumento(textoOriginal[i])) {
            musica.atualizaInstrumentoAtual(textoOriginal[i]);
            textoConvertido += musica.instrumento.getCodigo();
        } else if(musica.isOitava(textoOriginal[i])) {
            musica.oitava.aumentarOitava();
        } else {
            if(i != 0 && musica.isNota(textoOriginal[i - 1])) { //transformar em funcao
                textoConvertido += (" " + musica.nota.getCodigo() + musica.oitava.getCodigo() + musica.volume.getCodigo());
            } else {
                textoConvertido += SILENCIO;
            }
        }
    }
}
string Texto::getTextoConvertido() {
    return textoConvertido;
}
