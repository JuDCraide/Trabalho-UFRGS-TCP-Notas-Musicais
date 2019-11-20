#include "Nota.h"

using namespace std;


Nota::Nota(string tipo, string codigo) {
    this->tipo = tipo;
    this->codigo = codigo;
}

Nota::Nota() {
}


void Nota::setTipo(string tipo) {
    this->tipo = tipo;
}

string Nota::getTipo() {
    return tipo;
}

void Nota::setCodigo(string codigo) {
    this->codigo = codigo;
}
string Nota::getCodigo() {
    return codigo;
}
