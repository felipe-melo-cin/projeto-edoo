#ifndef _GUARANA_H_
#define _GUARANA_H_
#include "Coletavel.h"

class guarana : public Coletavel {
private:
  inline static int codigo = 0; // a decidir qual o critério
public:
  static int pega_codigo() {
    return codigo;
}



