#include "include/InterfaceComando.h"
#include "include/Jogo.h"
#include "include/MaquinaEstados.h"
#include "include/Player.h"
#include "include/Zona.h"

#include "include/Capivara.h"
#include "include/Tucano.h"
#include "include/OncaPintada.h"
#include "include/Chefe.h"

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

            jogo.terminal.prompt("> ");

            if ( jogo.terminal.get_input() == "INICIAR" )
                jogo.maquinaEstados.toggle_em_jogo(); // emJogo = true;

            if ( jogo.terminal.get_input() == "SAIR" )
                return 0;

        }

        if ( jogo.maquinaEstados.get_em_jogo() && !jogo.maquinaEstados.get_venceu() ) { // JOGO COMEÇA

            // INICIALIZA JOGADOR
            jogo.player = new Player;

            // ZONA 0
            Zona* z0 = jogo.zonas[0];
            z0->carregar_inimigo(new Capivara); // 2 CAPIVARAS
            z0->carregar_inimigo(new Capivara);
            z0->carregar_plataforma(new Plataforma(BAIXA)); // 1 PLATAFORMA BAIXA
            z0->carregar_plataforma(new Plataforma(MEDIA)); // 1 PLATAFORMA MÉDIA

            // ZONA 1
            Zona* z1 = jogo.zonas[1];
            z1->carregar_inimigo(new Capivara); // 1 CAPIVARA
            z1->carregar_inimigo(new Tucano); // 1 TUCANO
            z1->carregar_plataforma(new Plataforma(BAIXA)); // 1 PLATAFORMA BAIXA
            z1->carregar_plataforma(new Plataforma(MEDIA)); // 1 PLATAFORMA MÉDIA

            // ZONA 2
            Zona* z2 = jogo.zonas[2];
            z2->carregar_inimigo(new OncaPintada); // 1 ONÇA
            z2->carregar_plataforma(new Plataforma(BAIXA)); // 1 PLATAFORMA BAIXA
            z2->carregar_plataforma(new Plataforma(MEDIA)); // 1 PLATAFORMA MÉDIA

            // ZONA 3
            Zona* z3 = jogo.zonas[3];
            z3->carregar_inimigo(new Capivara); // 1 CAPIVARA
            z3->carregar_inimigo(new Tucano); // 1 TUCANO
            z3->carregar_plataforma(new Plataforma(BAIXA)); // 1 PLATAFORMA BAIXA
            z3->carregar_plataforma(new Plataforma(MEDIA)); // 1 PLATAFORMA MÉDIA

            // ZONA 4
            Zona* z4 = jogo.zonas[4];
            z4->carregar_inimigo(new OncaPintada); // 1 ONÇA
            z4->carregar_plataforma(new Plataforma(BAIXA)); // 1 PLATAFORMA BAIXA
            z4->carregar_plataforma(new Plataforma(MEDIA)); // 1 PLATAFORMA MÉDIA

            // ZONA 5
            Zona* z5 = jogo.zonas[5];
            z5->carregar_inimigo(new Capivara); // 1 CAPIVARA
            z5->carregar_inimigo(new Tucano); // 1 TUCANO
            z5->carregar_plataforma(new Plataforma(BAIXA)); // 1 PLATAFORMA BAIXA
            z5->carregar_plataforma(new Plataforma(MEDIA)); // 1 PLATAFORMA MÉDIA

            // ZONA 6
            Zona* z6 = jogo.zonas[6];
            z6->carregar_inimigo(new OncaPintada); // 1 ONÇA
            z6->carregar_plataforma(new Plataforma(BAIXA)); // 1 PLATAFORMA BAIXA

            // ZONA 7
            Zona* z7 = jogo.zonas[7];
            z7->carregar_inimigo(new Tucano); // 1 TUCANO
            z7->carregar_plataforma(new Plataforma(BAIXA)); // 1 PLATAFORMA BAIXA
            z7->carregar_plataforma(new Plataforma(MEDIA)); // 2 PLATAFORMAS MÉDIAS
            z7->carregar_plataforma(new Plataforma(MEDIA));

            // ZONA 8
            Zona* z8 = jogo.zonas[8];
            z8->carregar_plataforma(new Plataforma(BAIXA)); // 1 PLATAFORMA BAIXA

            // ZONA 9
            Zona* z9 = jogo.zonas[9];
            z9->carregar_inimigo(new Capivara); // 1 CAPIVARA
            z9->carregar_inimigo(new Tucano); // 1 TUCANO
            z9->carregar_plataforma(new Plataforma(BAIXA)); // 1 PLATAFORMA BAIXA
            z9->carregar_plataforma(new Plataforma(MEDIA)); // 3 PLATAFORMAS MÉDIAS
            z9->carregar_plataforma(new Plataforma(MEDIA));
            z9->carregar_plataforma(new Plataforma(MEDIA));

            // ZONA 10
            Zona* z10 = jogo.zonas[10];
            z10->carregar_inimigo(new OncaPintada); // 1 ONÇA
            z10->carregar_plataforma(new Plataforma(BAIXA)); // 1 PLATAFORMA BAIXA
            z10->carregar_plataforma(new Plataforma(MEDIA)); // 1 PLATAFORMA MÉDIA
            z10->carregar_plataforma(new Plataforma(BAIXA)); // 1 PLATAFORMA BAIXA

            // ZONA 11
            Zona* z11 = jogo.zonas[11];
            z11->carregar_plataforma(new Plataforma(BAIXA)); // 1 PLATAFORMA BAIXA
            z11->carregar_plataforma(new Plataforma(MEDIA)); // 1 PLATAFORMA MÉDIA

            // ZONA 12
            Zona* z12 = jogo.zonas[12];
            z12->carregar_inimigo(new Chefe); // 1 CHEFE
            z12->carregar_plataforma(new Plataforma(BAIXA)); // 1 PLATAFORMA BAIXA
            z12->carregar_plataforma(new Plataforma(MEDIA)); // 1 PLATAFORMA MÉDIA
            z12->carregar_plataforma(new Plataforma(ALTA)); // 1 PLATAFORMA ALTA
            z12->carregar_plataforma(new Plataforma(MEDIA)); // 1 PLATAFORMA MÉDIA
            z12->carregar_plataforma(new Plataforma(BAIXA)); // 1 PLATAFORMA BAIXA

        }

        if ( !jogo.maquinaEstados.get_em_jogo() && jogo.maquinaEstados.get_venceu() ) { // JOGADOR VENCEU

            // DESTRÓI JOGADOR, INIMIGOS, COLETÁVEIS E PLATAFORMAS

            jogo.terminal.output("VOCÊ VENCEU!");
            jogo.terminal.output("[MENU]");
            jogo.terminal.output("[REINICIAR]");
            jogo.terminal.output("[SAIR]");

            jogo.terminal.prompt("> ");

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

    }

    return 0;

}
