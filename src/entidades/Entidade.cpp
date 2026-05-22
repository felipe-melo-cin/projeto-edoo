#include "../../include/entidades/Entidade.h"

void Entidade::atacar(Entidade& alvo) {

    alvo.sofrer_dano();

}

void Entidade::sofrer_dano() {

    vida--;
    
}