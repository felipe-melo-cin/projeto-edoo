#include "../../include/nucleo/MaquinaEstados.h"

// SINGLETON DESIGN PATTERN

MaquinaEstados::MaquinaEstados() : emJogo(false), venceu(false) {}

MaquinaEstados& MaquinaEstados::get_instance() {
    static MaquinaEstados maquinaEstadosSingleton;
    return maquinaEstadosSingleton;
}

// END SINGLETON DESIGN PATTERN