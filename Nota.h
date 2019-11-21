#ifndef NOTA_H
#define NOTA_H
#include <bits/stdc++.h>

using namespace std;

class Nota {
public:
    Nota();
    Nota(string tipo, string codigo);
    void setTipo(string novoTipo);
    string getTipo();
    void setCodigo(string codigo);
    string getCodigo();

private:
    string tipo;
    string codigo;
};

#endif // NOTA_H
