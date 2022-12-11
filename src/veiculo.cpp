#include "veiculo.h"

Veiculo::Veiculo(string concessionaria, string marca, double preco,
                 string chassi, int anoFabricacao)
    : concessionaria(concessionaria), marca(marca), preco(preco),
      chassi(chassi), anoFabricacao(anoFabricacao) {}

Veiculo::~Veiculo() {}

void Veiculo::print(std::ostream &oo) const {
	oo << "Concessionaria: " << concessionaria << std::endl;
  oo << "Marca: " << marca << std::endl;
  oo << "Preço: " << preco << std::endl;
  oo << "Chassi: " << chassi << std::endl;
  oo << "Ano: " << anoFabricacao << std::endl;
}

std::ostream& operator<< (std::ostream& oo, const Veiculo& vv) {
	vv.print(oo);
	return oo;
}