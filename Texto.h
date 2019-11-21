#ifndef TEXTO_H
#define TEXTO_H
#include "Musica.h"
using namespace std;

#include <bits/stdc++.h>

class Texto {
public:
    Texto();
    Texto(string textoOriginal,int instrumentoInicial);
    void setTexto(string textoOriginal);
    void setInstrumentoInicial(int instrumentoInicial);
    void converterTexto();
    string getTextoConvertido();

private:
    string textoOriginal, textoConvertido;
    Musica musica;
};

#endif // TEXTO_H
