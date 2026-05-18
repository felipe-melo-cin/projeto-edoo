#ifndef FUNCOES_UTEIS_H
#define FUNCOES_UTEIS_H
#include <random>//biblioteca muito melhor para gerar aleatórios em relação as tranqueiras do C.
#include <ctime>//semente para deixar as saídas pseudoaleatórias

inline int aleatorizar(int n) {
    static std::mt19937 gerador(std::time(nullptr));//gerador utilizando o unix timestamp para valores pseudoaleatórios únicos
    std::uniform_int_distribution<int> distribuicao(0, n-1);
    return distribuicao(gerador);
}
#endif
