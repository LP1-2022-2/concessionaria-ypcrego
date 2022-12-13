#include "moto.h"

Moto::Moto(string concessionaria, string marca, double preco, string chassi,
           int anoFabricacao, string modelo)
    : Veiculo(concessionaria, marca, preco, chassi, anoFabricacao),
      modelo(modelo) {}

string Moto::getTipo() { return "Moto"; }

// Imprime os atributos herdados de Veículo e o atributo especial da classe.
// print() é chamado através do operador "<<", sobrecarregado em Veículo.
void Moto::print(std::ostream &oo) const {
  Veiculo::print(oo);
  oo << "Modelo: " << modelo << std::endl;
}

// Aumenta o preço da moto em 20%.
double Moto::raisePrice(double num) {
  preco *= 1 + (2 * num / 100.0);
  return preco;
}

Moto::~Moto() {}
