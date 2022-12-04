#ifndef CONCESSIONARIA_H
#define CONCESSIONARIA_H

#include "automovel.h"
#include "veiculo.h"
#include <ostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Concessionaria {
public:
  string nome;
  string CNPJ;
  int estoque;
  Concessionaria(string nome, string CNPJ, int estoque);
  friend std::ostream &operator<<(std::ostream &oo, Concessionaria const &cc);
  vector<Veiculo> veiculos;
	void addVeiculo(Veiculo vv);
};

#endif