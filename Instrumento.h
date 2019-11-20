#ifndef INSTRUMENTO_H
#define INSTRUMENTO_H

#define INSTRUMENTO_MAX 127
#define INSTRUMENTO_MIN 0

#define AGOGO 113
#define HARPSICHORD 6
#define TUBULAR_BELLS 14
#define PAN_FLUTE 75
#define CHURCH_ORGAN 19


#include <Componente.h>


class Instrumento : virtual public Componente {
public:

    Instrumento(int instrumentoPadrao);
    int getInstrumentoPadrao();
    string getCodigo();
private:
    int instrumentoPadrao;
};

#endif // INSTRUMENTO_H
