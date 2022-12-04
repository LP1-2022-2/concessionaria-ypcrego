#include "concessionaria.h"
#include <iostream>

using std::cout;
using std::endl;

Concessionaria::Concessionaria(string CNPJ, int estoque = 0)
    : CNPJ(CNPJ), estoque(estoque){};

/* Atualmente, lista os atributos simples de Concessionaria. TODO: Verificar se
// é necessário ou viável utilizar o << para listar uma Concessionária (com
// veículos, valores totais etc).
std::ostream &operator<<(std::ostream &oo, Concessionaria const &cc) {
  oo << "Nome: " << cc.nome << std::endl
     << "CNPJ: " << cc.CNPJ << std::endl
     << "Número de veículos: " << cc.estoque << std::endl;
  return oo;
}*/

void Concessionaria::addVeiculo(Veiculo &vv) {
  /*
	veiculos.push_back(vv);
  cout << "Veiculo adicionado com sucesso !" << endl;
  cout << "A marca dele: " << vv.marca << endl;
  cout << "Tamanho de veiculos: " << veiculos.size() << endl;
	*/
}