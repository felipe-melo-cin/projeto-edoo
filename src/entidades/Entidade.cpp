#include "../../include/entidades/Entidade.h"

void Entidade::sofrer_dano() {

    vida--;
    
}

void Entidade::atacar(Entidade& alvo) {

    alvo.sofrer_dano();

}
