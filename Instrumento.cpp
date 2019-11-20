#include "Instrumento.h"

Instrumento::Instrumento(int instrumentoPadrao) {
    this->instrumentoPadrao = instrumentoPadrao;
    setAtual(instrumentoPadrao);
    codigo = "I";
}
int Instrumento::getInstrumentoPadrao() {
    return instrumentoPadrao;
}

string Instrumento::getCodigo()  {
    return " " + codigo + to_string(getAtual());
}

