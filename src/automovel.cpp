#include "automovel.h"

// Automovel Automovel{ { marca, double preco, string chassi, int anoFabricacao,
// string modelo)}
Automovel::Automovel(string marca, double preco, int anoFabricacao,
                     string tipoMotor)
    : Veiculo() {
  this->tipoMotor = tipoMotor;
  this->marca = marca;
  this->preco = preco;
  this->anoFabricacao = anoFabricacao;
}

string Automovel::getAtributoRelativo() { return tipoMotor; }

void Automovel::setAtributoRelativo(string tipoMotor) { this->tipoMotor = tipoMotor; }
