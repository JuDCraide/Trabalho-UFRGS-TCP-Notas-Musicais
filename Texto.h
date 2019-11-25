#ifndef TEXTO_H
#define TEXTO_H
#include "Musica.h"
using namespace std;

#include <bits/stdc++.h>

class Texto {
public:
    //Texto();
    Texto(string textoOriginal,int instrumentoInicial);
    void converterTexto();
    string getTextoConvertido();
    bool anteriorIsNota(unsigned int posicaoAtual);

private:
    string textoOriginal, textoConvertido;
    Musica musica;

};

#endif // TEXTO_H
