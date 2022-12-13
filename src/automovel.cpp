#include "automovel.h"

Automovel::Automovel(string concessionaria, string marca, double preco,
                     string chassi, int anoFabricacao, string tipoMotor)
    : Veiculo(concessionaria, marca, preco, chassi, anoFabricacao),
      tipoMotor(tipoMotor) {}

string Automovel::getTipo() { return "Automovel"; }

// Imprime os atributos herdados de Veículo e o atributo especial da classe.
// print() é chamado através do operador "<<", sobrecarregado em Veículo.
void Automovel::print(std::ostream &oo) const {
  Veiculo::print(oo);
  oo << "Tipo de motor: " << tipoMotor << std::endl;
}

// Aumenta o preço do automóvel em 10%.
double Automovel::raisePrice(double num) {
  preco *= 1 + (1 * num / 100.0);
  return preco;
}

Automovel::~Automovel() {}