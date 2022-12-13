#ifndef AUTOMOVEL_H
#define AUTOMOVEL_H
#include "veiculo.h"
#include <string>

using std::string;

class Automovel : public Veiculo {
public:
  string tipoMotor;
  Automovel(string concessionaria, string marca, double preco, string chassi,
            int anoFabricacao, string tipoMotor);

  // Retorna o tipo do veículo, ou seja, "Automovel".
  string getTipo() override;

  // Imprime os dados específicos de automóvel.
  void print(std::ostream &oo) const override;

  // Aumenta o preço do automóvel em determinada porcentagem.
  double raisePrice(double num) override;
  ~Automovel();
};

#endif