#ifndef _PLATAFORMA_H_
#define _PLATAFORMA_H_

#include "../utilitarios/Camada.h"

class Plataforma {

    private:

        enum Camada camada;
    
    public:

        Plataforma(enum Camada camada);

};

#endif