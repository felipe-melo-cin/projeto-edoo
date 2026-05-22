#ifndef _PEDRA_H_
#define _PEDRA_H_

#include <string>

#include "Coletavel.h"

class Pedra : public Coletavel {

    private:

        const static int codigo = 1; // A decidir qual o critério

    public:

        Pedra();    // Construtor
        ~Pedra() {} // Destrutor

        const static int get_codigo() {return codigo;}
    
};

#endif