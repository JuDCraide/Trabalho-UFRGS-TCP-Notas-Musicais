#include "Componente.h"

Componente::Componente() {
    codigo = "";
}

Componente::~Componente() {}

string Componente::getCodigo() {
    return codigo;
}

void Componente::setAtual(int novo) {
    atual = novo;
}

int Componente::getAtual() {
    return atual;
}

