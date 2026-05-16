#include "include/InterfaceComando.h"
#include "include/Jogo.h"
#include "include/MaquinaEstados.h"

using namespace std;

int main() {

    Jogo& jogo = Jogo::get_instance(
        MaquinaEstados::get_instance(),
        InterfaceComando::get_instance()
    );

    while (true) { // LOOP PRINCIPAL

        if ( !jogo.maquinaEstados.get_em_jogo() && !jogo.maquinaEstados.get_venceu() ) { // TELA INICIAL

            jogo.terminal.output("\nECOS DE ARAÑAMI");
            jogo.terminal.output("[INICIAR]");
            jogo.terminal.output("[SAIR]");

            if ( jogo.terminal.get_input() == "INICIAR" )
                jogo.maquinaEstados.toggle_em_jogo(); // emJogo = true;

            if ( jogo.terminal.get_input() == "SAIR" )
                return 0;

        }

        if ( jogo.maquinaEstados.get_em_jogo() && !jogo.maquinaEstados.get_venceu() ) { // JOGO COMEÇA

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

        if ( !jogo.maquinaEstados.get_em_jogo() && jogo.maquinaEstados.get_venceu() ) { // JOGADOR VENCEU

            // DESTRÓI JOGADOR, INIMIGOS, COLETÁVEIS E PLATAFORMAS

            jogo.terminal.output("VOCÊ VENCEU!");
            jogo.terminal.output("[MENU]");
            jogo.terminal.output("[REINICIAR]");
            jogo.terminal.output("[SAIR]");

            if ( jogo.terminal.get_input() == "MENU" ) {
                jogo.maquinaEstados.toggle_em_jogo(); // emJogo = true;
                jogo.maquinaEstados.toggle_venceu(); // venceu = false;
            }
            
            if ( jogo.terminal.get_input() == "REINICIAR" ) {
                jogo.maquinaEstados.toggle_venceu(); // venceu = false;
            }

            if ( jogo.terminal.get_input() == "SAIR" )
                return 0;
            
        }

        jogo.terminal.prompt("> ");

    }

    return 0;

}
