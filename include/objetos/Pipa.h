#ifndef _PIPA_H_
#define _PIPA_H_

#include <string>

#include "Coletavel.h"

class Pipa : public Coletavel {

    private:

        const static int codigo = 2; // A decidir qual o critério

    public:

        Pipa();    // Construtor
        ~Pipa() {} // Destrutor
        
        const static int get_codigo() {return codigo;}
        
};

#endif