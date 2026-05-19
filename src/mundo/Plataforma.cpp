#include "../../include/mundo/Plataforma.h"

Plataforma::Plataforma(enum Camada camada) : camada(camada) {

    switch (camada) {

        case CHAO:
            nome = "Chão";
            break;
        case BAIXA:
            nome = "Plataforma baixa";
            break;
        case MEDIA:
            nome = "Plataforma média";
            break;
        case ALTA:
            nome = "Plataforma alta";
            break;
            
    }

}
