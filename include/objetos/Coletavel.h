#ifndef _COLETAVEL_H_
#define _COLETAVEL_H_

#include <string>
#include <random> //biblioteca muito melhor para gerar aleatórios em relação as tranqueiras do C.
#include <ctime> //semente para deixar as saídas pseudoaleatórias

class Coletavel {

    private:

        std::string nome;

    public:

        Coletavel() {}
        virtual ~Coletavel() {}

        int aparecer();

        // Getter
        const std::string& get_nome() { return nome; }

        // Setter
        void set_nome(const std::string& nome) { this->nome = nome; }

    };

#endif