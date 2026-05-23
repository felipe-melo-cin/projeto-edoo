#ifndef _PLATAFORMA_H_
#define _PLATAFORMA_H_

#include <string>

#include "../mundo/Camada.h"

class Plataforma {

    private:

        std::string nome  ;
        Camada      camada;
    
    public:

        Plataforma(Camada camada); // Construtor
        ~Plataforma() {}           // Destrutor

        // Getters

        const std::string& get_nome  () {return nome  ;}
        Camada             get_camada() {return camada;}

};

#endif