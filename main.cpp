#include "include/CLInterface.h"
#include "include/Game.h"
#include "include/StateMachine.h"

using namespace std;

int main() {

    Game& game = Game::getInstance(
        StateMachine::getInstance(),
        CLInterface::getInstance()
    );

    while (true) { // LOOP PRINCIPAL

        if ( !game.stateMachine.getEmJogo() && !game.stateMachine.getVenceu() ) { // TELA INICIAL

            game.terminal.output("\nECOS DE ARAÑAMI");
            game.terminal.output("[INICIAR]");
            game.terminal.output("[SAIR]");

            if ( game.terminal.getInput() == "INICIAR" )
                game.stateMachine.toggleEmJogo(); // emJogo = true;

            if ( game.terminal.getInput() == "SAIR" )
                return 0;

        }

        game.terminal.prompt("> ");

    }

    return 0;

}
