#ifndef AUTOMOVEL_H
#define AUTOMOVEL_H
#include "veiculo.h"

#include <string>

using std::string;

class Automovel : public Veiculo {
public:
  string tipoMotor;
  //Automovel(string marca, double preco, string chassi, int anoFabricacao, s
  ///ring tipoMotor);
	Automovel(string marca, double preco, string chassi, int anoFabricacao, string tipoMotor);

};

#endif