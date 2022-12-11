#include "caminhao.h"

Caminhao::Caminhao(string concessionaria, string marca, double preco,
                   string chassi, int anoFabricacao, string tipoCarga)
    : Veiculo(concessionaria, marca, preco, chassi, anoFabricacao),
      tipoCarga(tipoCarga) {}

string Caminhao::getTipo() { return "Caminhao"; }

// Imprime os atributos herdados de Veículo e o atributo especial da classe.
// print() é chamado através do operador "<<", sobrecarregado em Veículo.
void Caminhao::print(std::ostream &oo) const {
	Veiculo::print(oo);
  oo << "Tipo de carga: " << tipoCarga << std::endl;
}

// Aumenta o preço do caminhão em 30%.
double Caminhao::raisePrice(double num) {
  preco *= 1 + (3 * num / 100.0);
  return preco;
}

Caminhao::~Caminhao(){}