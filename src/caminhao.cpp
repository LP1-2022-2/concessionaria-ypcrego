#include "caminhao.h"

Caminhao::Caminhao(string marca, double preco, int anoFabricacao, string tipoCarga) : Veiculo() {
  this->marca = marca;
  this->preco = preco;
  this->anoFabricacao = anoFabricacao;
	this->tipoCarga = tipoCarga;
}

string Caminhao::getAtributoRelativo() { return tipoCarga; }

void Caminhao::setAtributoRelativo(string tipoCarga) { this->tipoCarga = tipoCarga; }