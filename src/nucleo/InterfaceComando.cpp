#include "../../include/nucleo/InterfaceComando.h"

// SINGLETON DESIGN PATTERN

InterfaceComando::InterfaceComando() {}

InterfaceComando& InterfaceComando::get_instance() {
    static InterfaceComando cliSingleton;
    return cliSingleton;
}

// END SINGLETON DESIGN PATTERN

void InterfaceComando::input() {

    std::cin >> stringIn;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.sync();
        throw std::invalid_argument("Entrada Inválida.");
    }

    std::cin.sync();
    str_to_upper(stringIn);

}

void InterfaceComando::int_input() {

    std::cin >> intIn;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.sync();
        throw std::invalid_argument("Entrada Inválida.");
    }

    std::cin.sync();

}
