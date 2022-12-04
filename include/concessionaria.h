#ifndef CONCESSIONARIA_H
#define CONCESSIONARIA_H

#include "automovel.h"
#include "caminhao.h"
#include "moto.h"
#include "veiculo.h"
#include <map>
#include <ostream>
#include <string>

using std::map;
using std::string;

class Concessionaria {
public:
  string CNPJ;
  int estoque;
  Concessionaria(string CNPJ, int estoque);
  friend std::ostream &operator<<(std::ostream &oo, Concessionaria const &cc);
  map<string, Veiculo> veiculos;
  void addVeiculo(Veiculo vv);
};

#endif