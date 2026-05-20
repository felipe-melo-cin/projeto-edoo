#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <unordered_map>

#include "Entidade.h"

#include "../mundo/Plataforma.h"

#include "../objetos/Guarana.h"
#include "../objetos/Pedra.h"
#include "../objetos/Pipa.h"

class Player : public Entidade {

    private:

        int maxVida = 8;
        bool puloDuplo = false;
        Plataforma* plataforma;
        std::unordered_map<int, int> inventario = {
            {Guarana::get_codigo(), 0},
            {Pedra::get_codigo(), 10},
            {Pipa::get_codigo(), 0}
        };
    
    public:

        Player();
        ~Player() { delete plataforma; }

        bool curar();

        void incremento_inventario(int codigo) { ++inventario.at(codigo); }
        void decremento_inventario(int codigo) { --inventario.at(codigo); }

        int get_max_vida() { return maxVida; }
        bool get_pulo_duplo() { return puloDuplo; }
        Plataforma* get_plataforma() { return plataforma; }
        int get_inventario(int codigo) { return inventario.at(codigo); }

        void toggle_pulo_duplo() { this->puloDuplo = !puloDuplo; }
        void set_plataforma(Plataforma* plataforma) { this->plataforma = plataforma; }

};

#endif