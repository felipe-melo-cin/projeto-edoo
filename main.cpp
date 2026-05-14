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

        if ( game.stateMachine.get_em_jogo() && !game.stateMachine.get_venceu() ) { // JOGO COMEÇA

            // INICIALIZA JOGADOR, INIMIGOS, COLETÁVEIS E PLATAFORMAS

            // ZONA 1
            // 2 CAPIVARAS
            // 1 PLATAFORMA BAIXA
            // 1 PLATAFORMA MÉDIA

            // ZONA 2
            // 1 CAPIVARA
            // 1 TUCANO
            // 1 PLATAFORMA BAIXA
            // 1 PLATAFORMA MÉDIA

            // ZONA 3
            // 1 ONÇA
            // 1 PLATAFORMA BAIXA
            // 1 PLATAFORMA MÉDIA

            // ZONA 4
            // 1 CAPIVARA
            // 1 TUCANO
            // 1 PLATAFORMA BAIXA
            // 1 PLATAFORMA MÉDIA

            // ZONA 5
            // 1 ONÇA
            // 1 PLATAFORMA BAIXA
            // 1 PLATAFORMA MÉDIA

            // ZONA 6
            // 1 CAPIVARA
            // 1 TUCANO
            // 1 PLATAFORMA BAIXA
            // 1 PLATAFORMA MÉDIA

            // ZONA 7
            // 1 ONÇA
            // 1 PLATAFORMA BAIXA

            // ZONA 8
            // 1 TUCANO
            // 1 PLATAFORMA BAIXA
            // 2 PLATAFORMAS MÉDIAS

            // ZONA 9
            // 1 PLATAFORMA BAIXA

            // ZONA 10
            // 1 CAPIVARA
            // 1 TUCANO
            // 1 PLATAFORMA BAIXA
            // 3 PLATAFORMAS MÉDIAS

            // ZONA 11
            // 1 ONÇA
            // 2 PLATAFORMAS BAIXAS
            // 1 PLATAFORMA MÉDIA

            // ZONA 12
            // 1 PLATAFORMA BAIXA
            // 1 PLATAFORMA MÉDIA

            // ZONA 13
            // 1 CHEFE
            // 2 PLATAFORMAS BAIXAS
            // 2 PLATAFORMAS MÉDIAS
            // 1 PLATAFORMA ALTA

        }

        if ( !game.stateMachine.get_em_jogo() && game.stateMachine.get_venceu() ) { // JOGADOR VENCEU

            // DESTRÓI JOGADOR, INIMIGOS, COLETÁVEIS E PLATAFORMAS

            game.terminal.output("VOCÊ VENCEU!");
            game.terminal.output("[MENU]");
            game.terminal.output("[REINICIAR]");
            game.terminal.output("[SAIR]");

            if ( game.terminal.get_input() == "MENU" ) {
                game.stateMachine.toggle_em_jogo(); // emJogo = true;
                game.stateMachine.toggle_venceu(); // venceu = false;
            }
            
            if ( game.terminal.get_input() == "REINICIAR" ) {
                game.stateMachine.toggle_venceu(); // venceu = false;
            }

            if ( game.terminal.get_input() == "SAIR" )
                return 0;
            
        }

        game.terminal.prompt("> ");

    }

    return 0;

}
