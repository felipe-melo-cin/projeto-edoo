#ifndef _GERADOR_ALEATORIEDADE_H_
#define _GERADOR_ALEATORIEDADE_H_

#include <random> // Biblioteca muito melhor para gerar aleatórios em relação as tranqueiras do C.
#include <ctime>  // Semente para deixar as saídas pseudoaleatórias

inline int gerador_aleatoriedade(int n) {

    static std::mt19937 gerador(std::time(nullptr)); // Gerador utilizando o unix timestamp para valores pseudoaleatórios únicos

    std::uniform_int_distribution<int> distribuicao(0, n-1);
    
    return distribuicao(gerador);
    
}

#endif