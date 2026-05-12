#include "../include/CLInterface.h"

// SINGLETON DESIGN PATTERN

CLInterface::CLInterface() {}

CLInterface& CLInterface::get_instance() {
    static CLInterface cliSingleton;
    return cliSingleton;
}

// END SINGLETON DESIGN PATTERN
