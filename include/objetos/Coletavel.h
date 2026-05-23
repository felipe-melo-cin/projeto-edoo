#ifndef _COLETAVEL_H_
#define _COLETAVEL_H_

#include <string>

#include "TipoColetavel.h"

class Coletavel {

    private:

        TipoColetavel tipo;
        std::string   nome;
    
    protected:

        Coletavel() {} // CLASSE ABSTRATA: CONSTRUTOR PROTEGIDO

    public:
    
        virtual ~Coletavel() {} // Destrutor

        int gerarPosicao(); // Gera e retorna uma posição aleatória de 0 a 12

        // Getters

        TipoColetavel      get_tipo() {return tipo;}
        const std::string& get_nome() {return nome;}

        // Setters
        
        void set_tipo(TipoColetavel tipo) {this->tipo = tipo;}
        void set_nome(std::string nome  ) {this->nome = nome;}

};

#endif