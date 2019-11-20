#include "Oitava.h"

Oitava::Oitava() {
    setAtual(OITAVA_PADRAO);
}

void Oitava::aumentarOitava() {
    if(getAtual() + 1 <= OITAVA_MAX) {
        setAtual(getAtual() + 1);
    } else {
        setAtual(OITAVA_PADRAO);
    }
}

string Oitava::getCodigo() {
    return to_string(getAtual());
}
