#include <iostream>
#include "../include/Coletavel.h"
#include <random>//biblioteca muito melhor para gerar aleatórios em relação as tranqueiras do C.
#include <ctime>//semente para deixar as saídas pseudoaleatórias


/*decide onde o coletavel vai nascer, baseado em qual posição do vetor da zona da instancia,atraves da geraçao de um numero aleatório de 0 a 12*/
int Coletavel::aparecer(){
    static std::mt19937 gerador(std::time(nullptr));//gerador utilizando o unix timestamp para valores pseudoaleatórios únicos
    std::uniform_int_distribution<int> distribuicao(0, 12);
    return distribuicao(gerador);
}
