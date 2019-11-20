#include "Volume.h"

Volume::Volume() {
    setAtual(VOLUME_PADRAO);
    codigo = "V";
}

string Volume::getCodigo() {
    return codigo+to_string(atual)+codigo+to_string(atual);
}

void Volume::dobrarVolume() {
    if(2*getAtual() <= VOLUME_MAX) {
        setAtual(getAtual()*2);
    } else {
        setAtual(VOLUME_PADRAO);
    }
}



