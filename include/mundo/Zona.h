#ifndef _ZONA_H_
#define _ZONA_H_

#include <vector>

#include "Plataforma.h"

#include "../objetos/Coletavel.h"
#include "../entidades/Inimigo.h"

class Zona {

    private:

        std::vector<Coletavel *> coletaveis ;
        std::vector<Inimigo   *> inimigos   ;
        std::vector<Plataforma*> plataformas;
    
    public:

        // Construtor
        Zona() {};
        // Destrutor
        ~Zona() {
            for (int i = 0; i < coletaveis .size(); ++i) {delete coletaveis .back(); coletaveis .pop_back();}
            for (int i = 0; i < inimigos   .size(); ++i) {delete inimigos   .back(); inimigos   .pop_back();}
            for (int i = 0; i < plataformas.size(); ++i) {delete plataformas.back(); plataformas.pop_back();}
        };

        // Instancia um novo membro da classe para o vetor

        void carregar_coletavel (Coletavel * colPtr ) {coletaveis .push_back(colPtr );}
        void carregar_inimigo   (Inimigo   * inimPtr) {inimigos   .push_back(inimPtr);}
        void carregar_plataforma(Plataforma* platPtr) {plataformas.push_back(platPtr);}

        // Busca um membro da classe armazenado no vetor por índice

        Coletavel * get_coletavel (int index) {return coletaveis .at(index);}
        Inimigo   * get_inimigo   (int index) {return inimigos   .at(index);}
        Plataforma* get_plataforma(int index) {return plataformas.at(index);}

        // Destrói o membro da classe armazenado no vetor

        void eliminar_coletavel (int index) {delete get_coletavel(index); coletaveis .erase(coletaveis .begin() + index);}
        void eliminar_inimigo   (int index) {delete get_inimigo  (index); inimigos   .erase(inimigos   .begin() + index);}
        void eliminar_plataforma(int index) {delete get_inimigo  (index); plataformas.erase(plataformas.begin() + index);}

        // Retorna a quantidade de membros da classe armazenados no vetor

        int quantidade_coletaveis () {return coletaveis .size();}
        int quantidade_inimigos   () {return inimigos   .size();}
        int quantidade_plataformas() {return plataformas.size();}

};

#endif