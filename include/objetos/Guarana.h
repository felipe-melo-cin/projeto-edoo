#ifndef _GUARANA_H_
#define _GUARANA_H_

#include <string>

#include "Coletavel.h"

class Guarana : public Coletavel {

    private:

        const static int codigo = 0; // A decidir qual o critério

    public:

        Guarana();    // Construtor
        ~Guarana() {} // Destrutor

        const static int get_codigo() {return codigo;}

};

#endif