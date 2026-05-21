#ifndef _ENTIDADE_H_
#define _ENTIDADE_H_

#include <string>

#include "../utilitarios/Camada.h"

// Entidades, incluindo jogador e inimigos
class Entidade {

    private:

        std::string nome;
        int vida;
        bool atacando = false;
        Camada camada;

    public:
        
        void atacar(Entidade& alvo); // Recebe um alvo e lhe inflige dano
        void sofrer_dano(); // Decrementa a vida

        // Getters
        const std::string& get_nome() {return nome;}
        int get_vida() {return vida;}
        bool get_atacando() {return atacando;}
        Camada get_camada() {return camada;}
        
        // Setters
        void set_nome(std::string nome) {this->nome = nome;}
        void set_vida(int vida) {this->vida = vida;}
        void toggle_atacando() {atacando = !atacando;}
        void set_camada(Camada camada) {this->camada = camada;}
        
};

#endif