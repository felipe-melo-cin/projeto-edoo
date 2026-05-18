#ifndef _PIPA_H_
#define _PIPA_H_
#include "Coletavel.h"

class Pipa : public Coletavel {
private:
  const static int codigo = 2; // a decidir qual o critério
public:
  const static int get_codigo() {
    return codigo;
  }
};

#endif
