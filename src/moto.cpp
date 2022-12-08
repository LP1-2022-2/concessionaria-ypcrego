#include "moto.h"

Moto::Moto(string marca, double preco, int anoFabricacao, string modelo) : Veiculo() {
  this->marca = marca;
  this->preco = preco;
  this->anoFabricacao = anoFabricacao;
	this->modelo = modelo;
}