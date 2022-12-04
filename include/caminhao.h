#ifndef CAMINHAO_H
#define CAMINHAO_H
#include "veiculo.h"

#include <string>

using std::string;

class Caminhao : public Veiculo {
public:
  string tipoCarga;
  Caminhao(string marca, double preco, int anoFabricacao, string tipoCarga);

  string getAtributoRelativo() override;
  void setAtributoRelativo(string tipoCarga) override;

  string const nomeClasse() override;
};

#endif