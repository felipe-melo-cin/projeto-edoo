#ifndef _GUARANA_H_
#define _GUARANA_H_
#include <string>
#include "Coletavel.h"

class Guarana : public Coletavel {
private:
  const static int codigo = 0; // a decidir qual o critério
public:
  Guarana();
  const static int get_codigo() {
    return codigo;
  }
};

#endif
