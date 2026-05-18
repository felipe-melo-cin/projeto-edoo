#ifndef _GUARANA_H_
#define _GUARANA_H_
#include "Coletavel.h"

class guarana : public Coletavel {
private:
  const static int codigo = 0; // a decidir qual o critério
public:
  const static int get_codigo() {
    return codigo;
  }
};

#endif
