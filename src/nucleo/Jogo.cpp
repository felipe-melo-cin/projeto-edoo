#include "../../include/nucleo/Jogo.h"

// SINGLETON DESIGN PATTERN

Jogo::Jogo(MaquinaEstados& maquinaEstados, InterfaceComando& terminal) :
    maquinaEstados(maquinaEstados), terminal(terminal) {}

Jogo& Jogo::get_instance(MaquinaEstados& maquinaEstados, InterfaceComando& terminal) {
    static Jogo jogoSingleton(maquinaEstados, terminal);
    return jogoSingleton;
}

// END SINGLETON DESIGN PATTERN