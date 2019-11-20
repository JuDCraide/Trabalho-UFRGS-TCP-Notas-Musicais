#ifndef PLAYER_H
#define PLAYER_H
#include "Texto.h"
#include <bits/stdc++.h>

using namespace std;

class Player {
public:
    Player();
    void prepararPlayer(string textoOriginal, int instrumentoInicial);
    void tocarMusica();
    void gerarMidi(string nomeArquivo);
private:
    string sequencia;
};

#endif // PLAYER_H
