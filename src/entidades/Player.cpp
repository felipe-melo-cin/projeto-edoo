#include "../../include/entidades/Player.h"

Player::Player() {
    set_nome("Helicônia");
    set_vida(maxVida);
    set_camada(Camada::CHAO);
}

bool Player::curar() {

    if (get_vida() == get_max_vida())
        return false;
    
    set_vida(get_vida() + 1);

    return true;

}
