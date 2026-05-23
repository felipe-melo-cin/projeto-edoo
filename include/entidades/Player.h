#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <unordered_map>

#include "Entidade.h"

#include "../mundo/Plataforma.h"
#include "../objetos/TipoColetavel.h"

class Player : public Entidade {

    private:

        int maxVida = 8;
        bool puloDuplo = false;
        Plataforma* plataforma;
        std::unordered_map<int, int> inventario = {
            {static_cast<int>(TipoColetavel::GUARANA), 0 },
            {static_cast<int>(TipoColetavel::PEDRA)  , 10},
            {static_cast<int>(TipoColetavel::PIPA)   , 0 }
        };
    
    public:

        Player();                      // Construtor
        ~Player() {delete plataforma;} // Destrutor

        bool curar(); // Incrementa a vida

        void incremento_inventario(int codigo) {++inventario.at(codigo);} // Incrementa o item do código recebido
        void decremento_inventario(int codigo) {--inventario.at(codigo);} // Decrementa o item do código recebido

        // Getters

        int         get_max_vida  (          ) {return maxVida              ;} 
        bool        get_pulo_duplo(          ) {return puloDuplo            ;}
        Plataforma* get_plataforma(          ) {return plataforma           ;}
        int         get_inventario(int codigo) {return inventario.at(codigo);}

        // Setters

        void toggle_pulo_duplo(                      ) {this->puloDuplo  = !puloDuplo;}
        void set_plataforma   (Plataforma* plataforma) {this->plataforma = plataforma;}

};

#endif