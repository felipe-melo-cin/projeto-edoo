#include "Entity.h"

void Entity::atacar(Entity& alvo) {
    alvo.sofrer_dano();
}

void Entity::sofrer_dano() {
    vida--;
}