#include <iostream>
#include <random> // Biblioteca muito melhor para gerar aleatórios em relação as tranqueiras do C.
#include <ctime>  // Semente para deixar as saídas pseudoaleatórias

#include "../../include/objetos/Coletavel.h"

int Coletavel::gerarPosicao() {

    static std::mt19937 gerador(std::time(nullptr)); // Gerador utilizando o unix timestamp para valores pseudoaleatórios únicos

    std::uniform_int_distribution<int> distribuicao(0, 12);
    
    return distribuicao(gerador);
    
}