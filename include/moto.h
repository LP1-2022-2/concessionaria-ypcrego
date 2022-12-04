#ifndef MOTO_H
#define MOTO_H
#include "veiculo.h"

#include <string>

using std::string;

class Moto : public Veiculo {
public:
  string modelo;
  Moto(string modelo);
};

#endif