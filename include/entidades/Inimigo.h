#ifndef _INIMIGO_H_
#define _INIMIGO_H_

#include "Entidade.h"

class Inimigo : public Entidade {

    public:

        Inimigo() {}
        virtual ~Inimigo() {}

        const std::string& get_nome() { return Entidade::get_nome(); }

};

#endif