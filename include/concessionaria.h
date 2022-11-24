#ifndef CONCESSIONARIA_H
#define CONCESSIONARIA_H

#include <ostream>
#include <string>

using std::string;

class Concessionaria {
public:
  string nome;
  string CNPJ;
  int estoque;
  Concessionaria(string nome, string CNPJ, int estoque);
  friend std::ostream &operator<<(std::ostream &oo, Concessionaria const &cc);
  // TODO: vector<Veiculos>
};

#endif