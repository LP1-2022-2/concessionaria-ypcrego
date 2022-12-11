#ifndef MOTO_H
#define MOTO_H
#include "veiculo.h"
#include <string>

using std::string;

class Moto : public Veiculo {
public:
  string modelo;
  Moto(string concessionaria, string marca, double preco, string chassi,
       int anoFabricacao, string modelo);
  // Retorna o tipo do veículo, ou seja, "Moto".
  string getTipo() override;

  // Imprime os dados específicos de caminhão.
  void print(std::ostream &oo) const override;

  // Aumenta o preço do caminhão em determinada porcentagem.
  double raisePrice(double num) override;
  ~Moto();
};

#endif