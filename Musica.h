#ifndef MUSICA_H
#define MUSICA_H

#define SILENCIO " R"

#include "Instrumento.h"
#include "Oitava.h"
#include "Volume.h"
#include "Nota.h"
#include <bits/stdc++.h>

using namespace std;

class Musica {
public:
    Musica(int instrumentoInicial);

    bool isInstrumento(char instrucao);
    void atualizaInstrumentoAtual(char instrucao);

    bool isNota(char instrucao);
    void atualizaNotaAtual(char instrucao);

    bool isVolume(char instrucao);

    bool isOitava(char instrucao);

    string converteNotaAtual();

    Instrumento instrumento;
    Oitava oitava;
    Volume volume;
    Nota nota;

private:
    map <char, Nota> notasValidas;
};

#endif // MUSICA_H
