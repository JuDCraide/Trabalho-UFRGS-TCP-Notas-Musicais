#ifndef OITAVA_H
#define OITAVA_H
#define OITAVA_MAX 8
#define OITAVA_MIN 0
#define OITAVA_PADRAO 5

#include <Componente.h>


class Oitava : virtual public Componente {
public:
    Oitava();
    void aumentarOitava();
    string getCodigo();
protected:

private:
};

#endif // OITAVA_H
