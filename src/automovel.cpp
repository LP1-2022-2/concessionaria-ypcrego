#include "automovel.h"

Automovel::Automovel(string marca, double preco, int anoFabricacao,
                     string tipoMotor)
    : Veiculo() {
  this->tipoMotor = tipoMotor;
  this->marca = marca;
  this->preco = preco;
  this->anoFabricacao = anoFabricacao;
}