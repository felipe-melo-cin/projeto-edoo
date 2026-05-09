#include "../include/StateMachine.h"

// SINGLETON DESIGN PATTERN

StateMachine::StateMachine() : emJogo(false), venceu(false) {}

StateMachine& StateMachine::getInstance() {
    static StateMachine stateMachineSingleton;
    return stateMachineSingleton;
}

// END SINGLETON DESIGN PATTERN
