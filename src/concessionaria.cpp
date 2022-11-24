#include "../include/concessionaria.h"

Concessionaria::Concessionaria(string nome, string CNPJ, int estoque = 0)
    : nome(nome), CNPJ(CNPJ), estoque(estoque){};

// Atualmente, lista os atributos simples de Concessionaria. TODO: Verificar se
// é necessário ou viável utilizar o << para listar uma Concessionária (com
// veículos, valores totais etc).
std::ostream &operator<<(std::ostream &oo, Concessionaria const &cc) {
  oo << "Nome: " << cc.nome << std::endl
     << "CNPJ: " << cc.CNPJ << std::endl
     << "Número de veículos: " << cc.estoque << std::endl;
  return oo;
}
