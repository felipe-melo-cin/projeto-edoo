#ifndef _JOGO_H_
#define _JOGO_H_

#include "../include/InterfaceComando.h"
#include "../include/MaquinaEstados.h"

class Jogo { // CONTROLA OS ELEMENTOS DO JOGO E O TERMINAL

    private:

        Jogo(MaquinaEstados&, InterfaceComando&); // SINGLETON DESIGN PATTERN: CONSTRUTOR PRIVADO
    
    public:

        // SINGLETON DESIGN PATTERN

        Jogo(const Jogo&) = delete;
        Jogo& operator=(const Jogo&) = delete;

        static Jogo& get_instance(MaquinaEstados&, InterfaceComando&);

        // END SINGLETON DESIGN PATTERN

        MaquinaEstados& maquinaEstados;
        InterfaceComando& terminal;

};

#endif