#ifndef _CLINTERFACE_H_
#define _CLINTERFACE_H_

#include <iostream>
#include <string>

#include "toUpper.h"

class CLInterface { // CONTROLAS AS ENTRADAS E SAÍDAS DO TERMINAL

    private:

        CLInterface(); // SINGLETON DESIGN PATTERN: CONSTRUTOR PRIVADO

        std::string in;

    public:

        // SINGLETON DESIGN PATTERN

        CLInterface(const CLInterface&) = delete;
        CLInterface& operator=(const CLInterface&) = delete;

        static CLInterface& getInstance();

        // END SINGLETON DESIGN PATTERN

        // ARMAZENA INPUT DO USUÁRIO NA VARIÁVEL DO TERMINAL EM MAIÚSCULO
        void input() { std::cin >> in; toUpper(in); }

        // RETORNA INPUT ARMAZENADO NA VARIÁVEL DO TERMINAL
        std::string getInput() const { return in; };

        template <class T> void output(const T&, bool = true) const;
        template <class T> void prompt(const T&, bool = false);

};

// ESCREVE UMA MENSAGEM NO TERMINAL
template <class T>
void CLInterface::output(const T& out, bool endl) const {
    std::cout << out;
    if (endl) std::cout << std::endl;
}

// ESCREVE UMA MENSAGEM + ARMAZENA INPUT
template <class T>
void CLInterface::prompt(const T& p, bool endl) { output(p, endl); input(); }

#endif