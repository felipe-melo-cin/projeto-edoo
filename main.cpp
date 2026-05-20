#include "include/entidades/Player.h"
#include "include/entidades/Capivara.h"
#include "include/entidades/Tucano.h"
#include "include/entidades/OncaPintada.h"
#include "include/entidades/Chefe.h"

#include "include/nucleo/InterfaceComando.h"
#include "include/nucleo/Jogo.h"
#include "include/nucleo/MaquinaEstados.h"

#include "include/objetos/Guarana.h"
#include "include/objetos/Pedra.h"
#include "include/objetos/Pipa.h"

#include "include/utilitarios/gerador_aleatoriedade.h"
#include "include/mundo/Zona.h"

using namespace std;

int main() {

    Jogo& jogo = Jogo::get_instance(
        MaquinaEstados::get_instance(),
        InterfaceComando::get_instance()
    );

    Zona *zonaAtual, *z0, *z1, *z2, *z3, *z4, *z5, *z6, *z7, *z8, *z9, *z10, *z11, *z12;
    int indiceZonaAtual = 0;

    bool turnoInimigos;

    while (true) { // LOOP PRINCIPAL

        if ( !jogo.maquinaEstados.get_em_jogo() && !jogo.maquinaEstados.get_venceu() ) { // TELA INICIAL

            // OPÇÕES DE ESCOLHA
            jogo.terminal.output("\nECOS DE ARAÑAMI");
            jogo.terminal.output("[INICIAR]");
            jogo.terminal.output("[SAIR]");

            // JOGADOR ESCOLHE
            jogo.terminal.prompt("> ");
            string terminalInput = jogo.terminal.get_input();

            // ESCOLHA É AVALIADA
            if ( terminalInput == "INICIAR" ) {

                jogo.maquinaEstados.toggle_em_jogo(); // emJogo = true;
            
            } else if ( terminalInput == "SAIR" ) {

                return 0;

            }

        }

        if ( jogo.maquinaEstados.get_em_jogo() && !jogo.maquinaEstados.get_venceu() ) { // JOGO JÁ FOI INICIADO

            if (jogo.player == nullptr) { // JOGO COMEÇA
                
                // INICIALIZA JOGADOR
                jogo.player = new Player;

                // INICIALIZA ZONAS
                for (int i = 0; i < 13; ++i)
                    jogo.zonas[i] = new Zona;

                // INICIALIZA COLETÁVEIS
                for (int i = 0; i < 8; ++i) {
                    Guarana* g = new Guarana;
                    Zona* zonaAparece = jogo.zonas[g->aparecer()];
                    zonaAparece->carregar_coletavel(g);
                }

                for (int i = 0; i < 30; ++i) {
                    Pedra* p = new Pedra;
                    Zona* zonaAparece = jogo.zonas[p->aparecer()];
                    zonaAparece->carregar_coletavel(p);
                }

                {
                    Pipa* p = new Pipa;
                    Zona* zonaAparece = jogo.zonas[p->aparecer()];
                    zonaAparece->carregar_coletavel(p);
                }

                // DEFINE ZONAS
                z0  = jogo.zonas[0],
                z1  = jogo.zonas[1],
                z2  = jogo.zonas[2],
                z3  = jogo.zonas[3],
                z4  = jogo.zonas[4],
                z5  = jogo.zonas[5],
                z6  = jogo.zonas[6],
                z7  = jogo.zonas[7],
                z8  = jogo.zonas[8],
                z9  = jogo.zonas[9],
                z10 = jogo.zonas[10],
                z11 = jogo.zonas[11],
                z12 = jogo.zonas[12];

                // DEFINE ZONA INICIAL
                zonaAtual = z0;
                indiceZonaAtual = 0;

                // DEFINE TURNO DOS INIMIGOS
                bool turnoInimigos = false;

                // ZONA 0
                z0->carregar_inimigo(new Capivara); // 2 CAPIVARAS
                z0->carregar_inimigo(new Capivara);
                z0->carregar_plataforma(new Plataforma(CHAO)); // CHÃO
                z0->carregar_plataforma(new Plataforma(BAIXA)); // 1 PLATAFORMA BAIXA
                z0->carregar_plataforma(new Plataforma(MEDIA)); // 1 PLATAFORMA MÉDIA

                // PLAYER COMEÇA NO CHÃO DA ZONA 0
                jogo.player->set_plataforma(z0->get_plataforma(0));

                // ZONA 1
                z1->carregar_inimigo(new Capivara); // 1 CAPIVARA
                z1->carregar_inimigo(new Tucano); // 1 TUCANO
                z1->carregar_plataforma(new Plataforma(CHAO)); // CHÃO
                z1->carregar_plataforma(new Plataforma(BAIXA)); // 1 PLATAFORMA BAIXA
                z1->carregar_plataforma(new Plataforma(MEDIA)); // 1 PLATAFORMA MÉDIA

                // ZONA 2
                z2->carregar_inimigo(new OncaPintada); // 1 ONÇA
                z2->carregar_plataforma(new Plataforma(CHAO)); // CHÃO
                z2->carregar_plataforma(new Plataforma(BAIXA)); // 1 PLATAFORMA BAIXA
                z2->carregar_plataforma(new Plataforma(MEDIA)); // 1 PLATAFORMA MÉDIA

                // ZONA 3
                z3->carregar_inimigo(new Capivara); // 1 CAPIVARA
                z3->carregar_inimigo(new Tucano); // 1 TUCANO
                z3->carregar_plataforma(new Plataforma(CHAO)); // CHÃO
                z3->carregar_plataforma(new Plataforma(BAIXA)); // 1 PLATAFORMA BAIXA
                z3->carregar_plataforma(new Plataforma(MEDIA)); // 1 PLATAFORMA MÉDIA

                // ZONA 4
                z4->carregar_inimigo(new OncaPintada); // 1 ONÇA
                z4->carregar_plataforma(new Plataforma(CHAO)); // CHÃO
                z4->carregar_plataforma(new Plataforma(BAIXA)); // 1 PLATAFORMA BAIXA
                z4->carregar_plataforma(new Plataforma(MEDIA)); // 1 PLATAFORMA MÉDIA

                // ZONA 5
                z5->carregar_inimigo(new Capivara); // 1 CAPIVARA
                z5->carregar_inimigo(new Tucano); // 1 TUCANO
                z5->carregar_plataforma(new Plataforma(CHAO)); // CHÃO
                z5->carregar_plataforma(new Plataforma(BAIXA)); // 1 PLATAFORMA BAIXA
                z5->carregar_plataforma(new Plataforma(MEDIA)); // 1 PLATAFORMA MÉDIA

                // ZONA 6
                z6->carregar_inimigo(new OncaPintada); // 1 ONÇA
                z6->carregar_plataforma(new Plataforma(CHAO)); // CHÃO
                z6->carregar_plataforma(new Plataforma(BAIXA)); // 1 PLATAFORMA BAIXA

                // ZONA 7
                z7->carregar_inimigo(new Tucano); // 1 TUCANO
                z7->carregar_plataforma(new Plataforma(CHAO)); // CHÃO
                z7->carregar_plataforma(new Plataforma(BAIXA)); // 1 PLATAFORMA BAIXA
                z7->carregar_plataforma(new Plataforma(MEDIA)); // 2 PLATAFORMAS MÉDIAS
                z7->carregar_plataforma(new Plataforma(MEDIA));

                // ZONA 8
                z8->carregar_plataforma(new Plataforma(CHAO)); // CHÃO
                z8->carregar_plataforma(new Plataforma(BAIXA)); // 1 PLATAFORMA BAIXA

                // ZONA 9
                z9->carregar_inimigo(new Capivara); // 1 CAPIVARA
                z9->carregar_inimigo(new Tucano); // 1 TUCANO
                z9->carregar_plataforma(new Plataforma(CHAO)); // CHÃO
                z9->carregar_plataforma(new Plataforma(BAIXA)); // 1 PLATAFORMA BAIXA
                z9->carregar_plataforma(new Plataforma(MEDIA)); // 3 PLATAFORMAS MÉDIAS
                z9->carregar_plataforma(new Plataforma(MEDIA));
                z9->carregar_plataforma(new Plataforma(MEDIA));

                // ZONA 10
                z10->carregar_inimigo(new OncaPintada); // 1 ONÇA
                z10->carregar_plataforma(new Plataforma(CHAO)); // CHÃO
                z10->carregar_plataforma(new Plataforma(BAIXA)); // 1 PLATAFORMA BAIXA
                z10->carregar_plataforma(new Plataforma(MEDIA)); // 1 PLATAFORMA MÉDIA
                z10->carregar_plataforma(new Plataforma(BAIXA)); // 1 PLATAFORMA BAIXA

                // ZONA 11
                z11->carregar_plataforma(new Plataforma(CHAO)); // CHÃO
                z11->carregar_plataforma(new Plataforma(BAIXA)); // 1 PLATAFORMA BAIXA
                z11->carregar_plataforma(new Plataforma(MEDIA)); // 1 PLATAFORMA MÉDIA

                // ZONA 12
                z12->carregar_inimigo(new Chefe); // 1 CHEFE
                z12->carregar_plataforma(new Plataforma(CHAO)); // CHÃO
                z12->carregar_plataforma(new Plataforma(BAIXA)); // 1 PLATAFORMA BAIXA
                z12->carregar_plataforma(new Plataforma(MEDIA)); // 1 PLATAFORMA MÉDIA
                z12->carregar_plataforma(new Plataforma(ALTA)); // 1 PLATAFORMA ALTA
                z12->carregar_plataforma(new Plataforma(MEDIA)); // 1 PLATAFORMA MÉDIA
                z12->carregar_plataforma(new Plataforma(BAIXA)); // 1 PLATAFORMA BAIXA

            } else /* if (jogo.player != nullptr) */ { // LOOP DE AÇÕES DO JOGO

                int quantidadeInimigos = zonaAtual->quantidade_inimigos();
                int quantidadePlataformas = zonaAtual->quantidade_plataformas();
                int quantidadeColetaveis = zonaAtual->quantidade_coletaveis();

                int indiceInimigo;
                Inimigo* atacante;

                jogo.terminal.output(""); // LINHA VAZIA

                jogo.terminal.output("VIDA: ", false);
                jogo.terminal.output(jogo.player->get_vida(), false);
                jogo.terminal.output('/', false);
                jogo.terminal.output(jogo.player->get_max_vida());
                jogo.terminal.output("PEDRAS: ", false);
                jogo.terminal.output(jogo.player->get_inventario(Pedra::get_codigo()));
                jogo.terminal.output("GUARANÁ: ", false);
                jogo.terminal.output(jogo.player->get_inventario(Guarana::get_codigo()));
                jogo.terminal.output("PIPA: ", false);
                jogo.terminal.output(jogo.player->get_inventario(Pipa::get_codigo()));
                jogo.terminal.output("LOCAL: ", false);
                jogo.terminal.output(jogo.player->get_plataforma()->get_nome());

                jogo.terminal.output(""); // LINHA VAZIA

                if (turnoInimigos = !turnoInimigos) { // INIMIGOS ATACAM EM TURNOS PARES

                    if (!quantidadeInimigos) {

                        atacante = nullptr;
                        jogo.terminal.output("Não há inimigos na zona atual");

                    } else {
                        
                        if (quantidadeInimigos == 1)
                            indiceInimigo = 0;
                        else
                            indiceInimigo = aleatorizar(quantidadeInimigos);
                        
                        atacante = zonaAtual->get_inimigo(indiceInimigo);

                        jogo.terminal.output(atacante->get_nome(), false);
                        jogo.terminal.output(" [", false);
                        jogo.terminal.output(indiceInimigo + 1, false);
                        jogo.terminal.output(']', false);
                        jogo.terminal.output(" vai te atacar...");

                    }
                    
                } else /* if (!turnoInimigos) */ {

                    atacante = nullptr;
                    jogo.terminal.output("Os inimigos não atacam nesse turno");

                }

                // OPÇÕES DE ESCOLHA
                jogo.terminal.output("[ATACAR]");
                jogo.terminal.output("[PULAR]");
                jogo.terminal.output("[COLETAR]");
                jogo.terminal.output("[AVANCAR]");
                jogo.terminal.output("[VOLTAR]");

                // JOGADOR ESCOLHE
                jogo.terminal.prompt("> ");
                string terminalInput = jogo.terminal.get_input();
                
                if ( terminalInput == "ATACAR" ) { // JOGADOR ATACA INIMIGO

                    if (quantidadeInimigos) { // EXISTEM INIMIGOS NA ZONA

                        int indiceAlvo;
                        Inimigo* alvo;

                        do {

                            jogo.terminal.listar_vetor(zonaAtual, &Zona::get_inimigo, &Inimigo::get_nome, &Zona::quantidade_inimigos);

                            jogo.terminal.prompt("> ");
                            indiceAlvo = std::stoi(jogo.terminal.get_input()) - 1;

                        } while (indiceAlvo < 0 || indiceAlvo >= quantidadeInimigos);

                        alvo = zonaAtual->get_inimigo(indiceAlvo);

                        if (jogo.player->get_camada() != alvo->get_camada()) { // JOGADOR ERRA

                            jogo.terminal.output("Seu ataque falhou. O inimigo está em uma camada diferente.");

                        } else if (jogo.player->get_inventario(Pedra::get_codigo())) { // JOGADOR ACERTA INIMIGO

                            jogo.player->atacar(*alvo);
                            jogo.player->decremento_inventario(Pedra::get_codigo());

                            jogo.terminal.output(jogo.player->get_nome(), false);
                            jogo.terminal.output(" acertou ", false);
                            jogo.terminal.output(alvo->get_nome());

                        } else { // NÃO HÁ MUNIÇÃO O SUFICIENTE

                            jogo.terminal.output("Seu ataque falhou. Você não tem munição.");

                        }

                        if (atacante != nullptr) {

                            std::string nomeAtacante = atacante->get_nome();
                            bool vivoAtacante = atacante->get_vida();
                            bool mesmaCamada = jogo.player->get_camada() == atacante->get_camada();

                            if (
                                (nomeAtacante == "Capivara" && mesmaCamada) ||
                                (nomeAtacante == "Tucano" && vivoAtacante) ||
                                (nomeAtacante == "Onça" && vivoAtacante && mesmaCamada) ||
                                (nomeAtacante == "Chefe" && vivoAtacante && mesmaCamada)
                            ) {

                                atacante->atacar(*jogo.player);

                                jogo.terminal.output(nomeAtacante, false);
                                jogo.terminal.output(" acertou ", false);
                                jogo.terminal.output(jogo.player->get_nome());

                            } else if (vivoAtacante) {

                                jogo.terminal.output(nomeAtacante, false);
                                jogo.terminal.output(" errou");

                            }

                        }

                    } else /* if (!quantidadeInimigos) */ { // NÃO EXISTEM INIMIGOS NA ZONA

                        jogo.terminal.output("Seu ataque falhou. Não há inimigos na zona atual");

                    }

                } else if ( terminalInput == "PULAR" ) { // JOGADOR PULA EM PLATAFORMA

                    int indiceAlvo;
                    int distanciaAlvo;
                    Plataforma* alvo;

                    do {

                        jogo.terminal.listar_vetor(zonaAtual, &Zona::get_plataforma, &Plataforma::get_nome, &Zona::quantidade_plataformas);

                        jogo.terminal.prompt("> ");
                        indiceAlvo = std::stoi(jogo.terminal.get_input()) - 1;

                    } while (indiceAlvo < 0 || indiceAlvo > quantidadePlataformas - 1);

                    alvo = zonaAtual->get_plataforma(indiceAlvo);

                    distanciaAlvo = alvo->get_camada() - jogo.player->get_camada();

                    if (distanciaAlvo >= 3 || distanciaAlvo == 2 && !jogo.player->get_pulo_duplo()) {

                        jogo.terminal.output("Você não conseguiu pular nessa plataforma");

                    } else {

                        jogo.player->set_plataforma(alvo);
                        jogo.player->set_camada(alvo->get_camada());

                    }

                    if (atacante != nullptr) {

                        std::string nomeAtacante = atacante->get_nome();

                        if (nomeAtacante == "Chefe" && jogo.player->get_camada() == CHAO && !jogo.player->get_pulo_duplo()) {

                            atacante->atacar(*jogo.player);

                            jogo.terminal.output("Não é possível pular por cima do chefe sem a pipa");
                            jogo.terminal.output(nomeAtacante, false);
                            jogo.terminal.output(" acertou ", false);
                            jogo.terminal.output(jogo.player->get_nome());

                        } else {
                        
                            jogo.terminal.output(nomeAtacante, false);
                            jogo.terminal.output(" errou");

                        }

                    }

                } else if ( terminalInput == "COLETAR" ) {

                    if (!quantidadeColetaveis) { // NÃO EXISTEM COLETÁVEIS NA ZONA

                        jogo.terminal.output("Não há coletáveis nessa zona.");
                    
                    } else if (jogo.player->get_camada() != CHAO) { // PLAYER NÃO ESTÁ NO CHÃO

                        jogo.terminal.output("Não é possível coletar itens onde você está");

                    } else { // EXISTEM COLETÁVEIS NA ZONA E PLAYER ESTÁ NA CHÃO

                        int indiceAlvo;
                        std::string alvoNome;
                        Coletavel* alvo;

                        do {

                            jogo.terminal.listar_vetor(zonaAtual, &Zona::get_coletavel, &Coletavel::get_nome, &Zona::quantidade_coletaveis);

                            jogo.terminal.prompt("> ");
                            indiceAlvo = std::stoi(jogo.terminal.get_input()) - 1;

                        } while (indiceAlvo < 0 || indiceAlvo > quantidadeColetaveis - 1);

                        alvo = zonaAtual->get_coletavel(indiceAlvo);

                        alvoNome = alvo->get_nome();

                        zonaAtual->eliminar_coletavel(indiceAlvo);

                        jogo.terminal.output("Você coletou ", false);
                        jogo.terminal.output(alvoNome);

                        if (alvoNome == "Guaraná") {

                            jogo.player->incremento_inventario(Guarana::get_codigo());

                            if (jogo.player->curar()) {

                                jogo.terminal.output("Você recuperou um ponto de vida");

                            } else {

                                jogo.terminal.output("Você já está com a vida cheia");

                            }


                        } else if (alvoNome == "Pedra") {

                            jogo.player->incremento_inventario(Pedra::get_codigo());

                        } else if (alvoNome == "Pipa") {

                            jogo.player->incremento_inventario(Pipa::get_codigo());
                            jogo.player->toggle_pulo_duplo(); // puloDuplo = true

                        }

                        if (atacante != nullptr) {

                            std::string nomeAtacante = atacante->get_nome();
                            bool mesmaCamada = jogo.player->get_camada() == atacante->get_camada();
                            
                            if (
                                (nomeAtacante == "Capivara" && mesmaCamada) ||
                                (nomeAtacante == "Tucano") ||
                                (nomeAtacante == "Onça" && mesmaCamada) ||
                                (nomeAtacante == "Chefe" && mesmaCamada)
                            ) {

                                atacante->atacar(*jogo.player);

                                jogo.terminal.output(nomeAtacante, false);
                                jogo.terminal.output(" acertou ", false);
                                jogo.terminal.output(jogo.player->get_nome());

                            } else {

                                jogo.terminal.output(nomeAtacante, false);
                                jogo.terminal.output(" errou");

                            }

                        }

                    }

                } else if ( terminalInput == "AVANCAR" ) {

                    if (zonaAtual == z12) {

                        jogo.terminal.output("Você está na última zona. Não é possível avançar mais.");
                        jogo.terminal.output("\nM A T E  O  C H E F E");

                    } else {

                        zonaAtual = jogo.zonas[++indiceZonaAtual];
                        turnoInimigos = false;

                        jogo.player->set_plataforma(zonaAtual->get_plataforma(0));
                        jogo.player->set_camada(CHAO);

                        jogo.terminal.output("Você avançou para a Zona ", false);
                        jogo.terminal.output(indiceZonaAtual + 1);

                    }

                } else if ( terminalInput == "VOLTAR" ) {

                    if (zonaAtual == z0) {

                        jogo.terminal.output("Você está na primeira zona. Não é possível voltar mais.");

                    } else {

                        zonaAtual = jogo.zonas[--indiceZonaAtual];
                        turnoInimigos = false;

                        jogo.player->set_plataforma(zonaAtual->get_plataforma(0));
                        jogo.player->set_camada(CHAO);

                        jogo.terminal.output("Você voltou para a Zona ", false);
                        jogo.terminal.output(indiceZonaAtual + 1);

                    }

                }

                {

                    int i = 0;

                    while (i < zonaAtual->quantidade_inimigos()) {

                        Inimigo* inimigo = zonaAtual->get_inimigo(i);

                        if (!inimigo->get_vida()) {

                            jogo.terminal.output(inimigo->get_nome(), false);
                            jogo.terminal.output(" morreu");

                            if (inimigo->get_nome() == "Chefe") { // JOGO TERMINA (FINAL BOM)

                                jogo.maquinaEstados.toggle_em_jogo(); // emJogo = false
                                jogo.maquinaEstados.toggle_venceu(); // venceu = true

                            }

                            zonaAtual->eliminar_inimigo(i);
                            continue;

                        }

                        ++i;

                    }
                
                }

                if (!jogo.player->get_vida()) { // JOGO TERMINA (FINAL RUIM)

                    jogo.terminal.output(jogo.player->get_nome(), false);
                    jogo.terminal.output(" morreu. Fim de Jogo.");

                    // DESTRÓI JOGADOR
                    delete jogo.player;
                    jogo.player = nullptr;

                    // DESTRÓI ZONAS
                    for (int i = 0; i < 13; ++i)
                        delete jogo.zonas[i];

                    jogo.maquinaEstados.toggle_em_jogo(); // emJogo = false

                }

            }

        }

        if ( !jogo.maquinaEstados.get_em_jogo() && jogo.maquinaEstados.get_venceu() ) { // JOGADOR JÁ VENCEU

            if (jogo.player != nullptr) { // JOGO TERMINA

                // DESTRÓI JOGADOR
                delete jogo.player;
                jogo.player = nullptr;

                // DESTRÓI ZONAS
                for (int i = 0; i < 13; ++i)
                    delete jogo.zonas[i];

            }

            // OPÇÕES DE ESCOLHA
            jogo.terminal.output("\nVOCÊ VENCEU!");
            jogo.terminal.output("[MENU]");
            jogo.terminal.output("[REINICIAR]");
            jogo.terminal.output("[SAIR]");

            // JOGADOR ESCOLHE
            jogo.terminal.prompt("> ");
            string terminalInput = jogo.terminal.get_input();
            
            // ESCOLHA É AVALIADA
            if ( terminalInput == "MENU" ) {

                jogo.maquinaEstados.toggle_venceu(); // venceu = false;

            } else if ( terminalInput == "REINICIAR" ) {

                jogo.maquinaEstados.toggle_em_jogo(); // emJogo = true;
                jogo.maquinaEstados.toggle_venceu(); // venceu = false;

            } else if ( terminalInput == "SAIR" ) {

                return 0;

            }

        }
    
    }

    return 0;

}
