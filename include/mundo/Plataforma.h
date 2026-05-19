#ifndef _PLATAFORMA_H_
#define _PLATAFORMA_H_

#include <string>

#include "../utilitarios/Camada.h"

class Plataforma {

    private:

        std::string nome;
        enum Camada camada;
    
    public:

        Plataforma(enum Camada camada);

        const std::string& get_nome() { return nome; }
        enum Camada get_camada() { return camada; }

};

#endif