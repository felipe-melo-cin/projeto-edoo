#include "../include/CLInterface.h"

// SINGLETON DESIGN PATTERN

CLInterface::CLInterface() {}

CLInterface& CLInterface::getInstance() {
    static CLInterface cliSingleton;
    return cliSingleton;
}

// END SINGLETON DESIGN PATTERN
