#include "../../include/nucleo/InterfaceComando.h"

// SINGLETON DESIGN PATTERN

InterfaceComando::InterfaceComando() {}

InterfaceComando& InterfaceComando::get_instance() {

    static InterfaceComando cliSingleton;
    
    return cliSingleton;
    
}

// END SINGLETON DESIGN PATTERN