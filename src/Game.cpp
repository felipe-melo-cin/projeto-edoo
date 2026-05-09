#include "../include/Game.h"

// SINGLETON DESIGN PATTERN

Game::Game(StateMachine& stateMachine, CLInterface& terminal) :
    stateMachine(stateMachine), terminal(terminal) {}

Game& Game::getInstance(StateMachine& stateMachine, CLInterface& terminal) {
    static Game gameSingleton(stateMachine, terminal);
    return gameSingleton;
}

// END SINGLETON DESIGN PATTERN
