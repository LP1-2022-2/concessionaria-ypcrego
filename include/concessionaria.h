#ifndef CONCESSIONARIA_H
#define CONCESSIONARIA_H

#include "automovel.h"
#include "caminhao.h"
#include "moto.h"
#include "veiculo.h"
#include <map>
#include <memory>
#include <ostream>
#include <string>

using std::map;
using std::string;

typedef std::shared_ptr<Veiculo> VeiculoPtr;

class Concessionaria {
public:
  string nome;
  string CNPJ;
  int estoque;
  Concessionaria(string nome, string CNPJ, int estoque);

  // Sobrecarga do operador << para listar os dados de uma concessionária.
  friend std::ostream &operator<<(std::ostream &oo, Concessionaria const &cc);

  // Container dos veículos. Utiliza um shared_ptr em "VeiculoPtr".
  map<string, VeiculoPtr> veiculos;

  // Container das quantidades de cada veículo na concessionária. Cada
  // quantidade é identificada por uma string, referente ao tipo do veículo.
  map<string, int> quantidades;

  // Container das somas dos preços de cada tipo de veículo. Cada soma é
  // identificada pela string que se refere ao tipo do veículo.
  map<string, double> somas;
};

#endif