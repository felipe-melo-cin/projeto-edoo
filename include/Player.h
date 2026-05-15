#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Entity.h"

class Player : public Entity {

    private:

        int maxVida = 8;
        bool puloDuplo = false;
    
    public:

        Player();
        ~Player() {}

};

#endif