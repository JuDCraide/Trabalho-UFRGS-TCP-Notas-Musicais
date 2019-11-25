#ifndef COMPONENTE_H
#define COMPONENTE_H

#include <bits/stdc++.h>

using namespace std;

class Componente {
public:
    Componente();
    virtual ~Componente() = 0;
    virtual string getCodigo();
    void setAtual(int novo);
    int getAtual();
protected:
    string codigo;
    int atual;

};

#endif // COMPONENTE_H
