#ifndef CAMINHAO_H
#define CAMINHAO_H
#include "veiculo.h"
#include <string>

using std::string;

class Caminhao : public Veiculo {
public:
  string tipoCarga;
  Caminhao(string concessionaria, string marca, double preco, string chassi,
           int anoFabricacao, string tipoCarga);
  // Retorna o tipo do veículo, ou seja, "Caminhao".
  string getTipo() override;

  // Imprime os dados específicos de caminhão.
  void print(std::ostream &oo) const override;

  // Aumenta o preço do caminhão em determinada porcentagem.
  double raisePrice(double num) override;
  ~Caminhao();
};

#endif