#ifndef _INTERFACECOMANDO_H_
#define _INTERFACECOMANDO_H_

#include <iostream>
#include <string>

#include "str_to_upper.h"

class InterfaceComando { // CONTROLAS AS ENTRADAS E SAÍDAS DO TERMINAL

    private:

        InterfaceComando(); // SINGLETON DESIGN PATTERN: CONSTRUTOR PRIVADO

        std::string in;

    public:

        // SINGLETON DESIGN PATTERN

        InterfaceComando(const InterfaceComando&) = delete;
        InterfaceComando& operator=(const InterfaceComando&) = delete;

        static InterfaceComando& get_instance();

        // END SINGLETON DESIGN PATTERN

        // ARMAZENA INPUT DO USUÁRIO NA VARIÁVEL DO TERMINAL EM MAIÚSCULO
        void input() { std::cin >> in; std::cin.sync(); str_to_upper(in); }

        // RETORNA INPUT ARMAZENADO NA VARIÁVEL DO TERMINAL
        std::string get_input() const { return in; };

        template <class T> void output(const T&, bool = true) const;
        template <class T> void prompt(const T&, bool = false);

};

// ESCREVE UMA MENSAGEM NO TERMINAL
template <class T>
void InterfaceComando::output(const T& out, bool endl) const {
    std::cout << out;
    if (endl) std::cout << std::endl;
}

// ESCREVE UMA MENSAGEM + ARMAZENA INPUT
template <class T>
void InterfaceComando::prompt(const T& p, bool endl) { output(p, endl); input(); }

#endif