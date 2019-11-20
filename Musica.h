#ifndef MUSICA_H
#define MUSICA_H

#define SILENCIO " R"

#include "Instrumento.h"
#include "Oitava.h"
#include "Volume.h"
#include "Nota.h"

class Musica {
public:
    /** Default constructor */
    Musica(int instrumentoInicial);

    bool isInstrumento(char instrucao);
    void atualizaInstrumentoAtual(char instrucao);

    bool isNota(char instrucao);
    void atualizaNotaAtual(char instrucao);

    bool isVolume(char instrucao);
    //void dobrarVolume();

    bool isOitava(char instrucao);
    //void atualizaOitavaAtual()
    Instrumento instrumento;
    Oitava oitava;
    Volume volume;
    map <char, Nota> notasValidas;
    Nota nota;

private:


};

#endif // MUSICA_H
