#ifndef VOLUME_H
#define VOLUME_H
#define VOLUME_MAX 120
#define VOLUME_MIN 0
#define VOLUME_PADRAO 30

#include "Componente.h"

class Volume : virtual public Componente {
public:
    Volume();
    void dobrarVolume();
    string getCodigo();
private:
};

#endif // VOLUME_H
