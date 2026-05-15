#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "Camada.h"

// Entidades, incluindo jogador e inimigos
class Entity {

    private:

        int vida;
        bool atacando = false;
        enum Camada camada;

    public:
        
        void atacar(Entity& alvo); // Recebe um alvo e lhe inflige dano
        void sofrer_dano(); // Decrementa a vida

        // Getters
        int  get_vida() {return vida;}
        bool get_atacando() {return atacando;}
        int  get_camada() {return camada;}
        
        // Setters
        void set_vida(int vida) {this->vida = vida;}
        void toggle_atacando() {atacando = !atacando;}
        void set_camada(enum Camada camada) {this->camada = camada;}
        
};

#endif