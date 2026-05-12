#include "include/CLInterface.h"
#include "include/Game.h"
#include "include/StateMachine.h"

using namespace std;

int main() {

    Game& game = Game::get_instance(
        StateMachine::get_instance(),
        CLInterface::get_instance()
    );

    while (true) { // LOOP PRINCIPAL

        if ( !game.stateMachine.get_em_jogo() && !game.stateMachine.get_venceu() ) { // TELA INICIAL

            game.terminal.output("\nECOS DE ARAÑAMI");
            game.terminal.output("[INICIAR]");
            game.terminal.output("[SAIR]");

            if ( game.terminal.get_input() == "INICIAR" )
                game.stateMachine.toggle_em_jogo(); // emJogo = true;

            if ( game.terminal.get_input() == "SAIR" )
                return 0;

        }

        game.terminal.prompt("> ");

    }

    return 0;

}
