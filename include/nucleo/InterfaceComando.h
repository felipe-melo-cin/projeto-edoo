#ifndef _INTERFACECOMANDO_H_
#define _INTERFACECOMANDO_H_

#include <iostream>
#include <string>

#include "../mundo/Zona.h"

#include "../entidades/Entidade.h"

#include "../utilitarios/str_to_upper.h"

class InterfaceComando { // CONTROLAS AS ENTRADAS E SAÍDAS DO TERMINAL

    private:

        InterfaceComando(); // SINGLETON DESIGN PATTERN: CONSTRUTOR PRIVADO

        // INPUTS ARMAZENADOS NO TERMINAL
        std::string stringIn;
        int intIn;

    public:

        // SINGLETON DESIGN PATTERN

        InterfaceComando(const InterfaceComando&) = delete;
        InterfaceComando& operator=(const InterfaceComando&) = delete;

        static InterfaceComando& get_instance();

        // END SINGLETON DESIGN PATTERN

        // IMPRIME UMA LINHA VAZIA
        void line_break() const { std::cout << std::endl; }

        // ARMAZENAM INPUT DO USUÁRIO NO TERMINAL
        void input() { std::cin >> stringIn; std::cin.sync(); str_to_upper(stringIn); }
        void int_input() { std::cin >> intIn; std::cin.sync(); }

        // RETORNA INPUT ARMAZENADO NO TERMINAL
        std::string get_input() const { return stringIn; };
        int get_int_input() const { return intIn; }

        template <class T> void output(const T&, bool = true) const;
        template <class T> void prompt(const T&, bool = false);
        template <class T> void int_prompt(const T&, bool = false);
        template <class T> void listar_vetor(Zona*, T* (Zona::*)(int), const std::string& (T::*)(), int (Zona::*)()) const;

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

// ESCREVE UM NÚMERO + ARMAZENA INPUT
template <class T>
void InterfaceComando::int_prompt(const T& p, bool endl) { output(p, endl); int_input(); }

// LISTA UM ATRIBUTO DOS ELEMENTOS DO VETOR DE UMA ZONA EM ORDEM CRESCENTE
template <class T>
void InterfaceComando::listar_vetor(Zona* zona, T* (Zona::*func_getter_zona)(int), const std::string& (T::*func_getter_tipo)(), int (Zona::*func_quantidade)()) const {

    for (int i = 0; i < (zona->*func_quantidade)(); ++i) {
        std::cout << '[' << i + 1 << "] ";
        output(((zona->*func_getter_zona)(i)->*func_getter_tipo)());
    }

}

#endif