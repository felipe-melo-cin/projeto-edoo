#include "../../include/mundo/Plataforma.h"

Plataforma::Plataforma(Camada camada) : camada(camada) {

    switch (camada) {

        case Camada::CHAO :
            nome = "Chão"            ;
            break;
        case Camada::BAIXA:
            nome = "Plataforma baixa";
            break;
        case Camada::MEDIA:
            nome = "Plataforma média";
            break;
        case Camada::ALTA :
            nome = "Plataforma alta" ;
            break;
            
    }

}