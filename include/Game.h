#ifndef _GAME_H_
#define _GAME_H_

#include "../include/CLInterface.h"
#include "../include/StateMachine.h"

class Game { // CONTROLA OS ELEMENTOS DO JOGO E O TERMINAL

    private:

        Game(StateMachine&, CLInterface&); // SINGLETON DESIGN PATTERN: CONSTRUTOR PRIVADO
    
    public:

        // SINGLETON DESIGN PATTERN

        Game(const Game&) = delete;
        Game& operator=(const Game&) = delete;

        static Game& getInstance(StateMachine&, CLInterface&);

        // END SINGLETON DESIGN PATTERN

        StateMachine& stateMachine;
        CLInterface& terminal;

};

#endif