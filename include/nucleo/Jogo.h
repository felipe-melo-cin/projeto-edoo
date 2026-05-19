#ifndef _JOGO_H_
#define _JOGO_H_

#include "InterfaceComando.h"
#include "MaquinaEstados.h"
#include "../entidades/Player.h"
#include "../mundo/Zona.h"

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
        Player* player = nullptr;
        Zona* zonas[13];

};

#endif