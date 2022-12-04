#ifndef AUTOMOVEL_H
#define AUTOMOVEL_H
#include "veiculo.h"

#include <string>

using std::string;

class Automovel : public Veiculo {
private:
  string tipoMmotor;

public:
  string tipoMotor;
  // Automovel(string marca, double preco, string chassi, int anoFabricacao, s
  /// ring tipoMotor);
  Automovel(string marca, double preco, int anoFabricacao, string tipoMotor);
  string getAtributoRelativo() override;
  void setAtributoRelativo(string tipoMotor) override;

  string const nomeClasse() override;
};

#endif