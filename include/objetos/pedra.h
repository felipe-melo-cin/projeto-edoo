#ifndef _PEDRA_H_
#define _PEDRA_H_
#include "Coletavel.h"

class pedra : public Coletavel {
private:
  const static int codigo = 1; // a decidir qual o critério
public:
  const static int get_codigo() {
    return codigo;
  }
};

#endif