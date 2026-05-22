#ifndef _COLETAVEL_H_
#define _COLETAVEL_H_

#include <string>

#include "gerador_aleatoriedade.h"

class Coletavel {

    private:

        std::string nome;

    public:

        Coletavel() {}          // Construtor
        virtual ~Coletavel() {} // Destrutor

        int gerarPosicao(); // Gera e retorna uma posição aleatória de 0 a 12

        // Getters

        const std::string& get_nome() {return nome;}

        // Setters
        
        void set_nome(const std::string& nome) {this->nome = nome;}

};

#endif