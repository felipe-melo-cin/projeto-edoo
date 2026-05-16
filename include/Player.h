#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Entidade.h"

class Player : public Entidade {

    private:

        int maxVida = 8;
        bool puloDuplo = false;
    
    public:

        Player();
        ~Player() {}

};

#endif