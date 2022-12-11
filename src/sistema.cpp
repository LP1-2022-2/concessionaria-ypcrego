#include "sistema.h"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <numeric>

/* COMANDOS */
string Sistema::quit() { return "Saindo..."; }

// Recebe as variáveis necessárias para a criação de uma concessionária e a
// cadastra no sistema. O construtor de Concessionaria inicializa determinados
// containers.
string Sistema::create_concessionaria(const string nome, const string CNPJ,
                                      const int estoque) {
  concessionarias.insert(std::pair<string, Concessionaria>(
      nome, Concessionaria(nome, CNPJ, estoque)));

  return "Concessionária criada!\n";
}

// Retorna o container que contém todas as concessionárias do sistema.
std::map<string, Concessionaria> Sistema::getConcessionarias() {
  return concessionarias;
}

// Verifica se uma concessionária já foi cadastrada no sistema pelo nome.
bool Sistema::busca_concessionaria(string nome) {
  return (concessionarias.count(nome) == 1);
}

// Recebe um shared_ptr de Veículo e o cadastra no sistema.
string Sistema::create_vehicle(string nome, string chassi, VeiculoPtr vv) {

  if (concessionarias.at(nome).veiculos.count(chassi) > 0) {
    return "Veiculo ja existente!\n";
  }

  // Insere o shared_ptr no mapa de shared_ptr<Veiculo>. Sua key é o chassi do
  // veículo.
  concessionarias.at(nome).veiculos.insert(
      std::pair<string, VeiculoPtr>(chassi, vv));

  // Incrementa a quantidade de veículos do tipo em 1. "quantidades" é um
  // container em Concessionaria.
  (concessionarias.at(nome).quantidades.at((*vv).getTipo()))++;

  // A soma dos preços do tipo de veículo é incrementada. A incrementação é
  // baseada no preço do veículo sendo cadastrado. "somas" é um container em
  // Concessionaria.
  (concessionarias.at(nome).somas.at((*vv).getTipo())) += (*vv).preco;

  // Aumenta o estoque de veículos.
  concessionarias.at(nome).estoque++;

  return "Veiculo criado!\n";
}

// Verifica se um veículo já foi cadastro no sistema pelo chassi.

string Sistema::search_vehicle(string chassi) {
  std::map<string, VeiculoPtr>::iterator itVeiculo;

  for (std::map<string, Concessionaria>::iterator it = concessionarias.begin();
       it != concessionarias.end(); ++it) {

    itVeiculo = (it->second).veiculos.find(chassi);

    if (itVeiculo != (it->second).veiculos.end()) {
      std::ostringstream oo;
      oo << (*itVeiculo->second);
      return oo.str();
    }
  }

  return "Veiculo nao encontrado!\n";
}

// Recebe um chassi e o pesquisa nas concessionárias do sistema, removendo o
// veículo ao qual é vinculado caso seja encontrado.
string Sistema::remove_vehicle(string chassi) {

  for (std::map<string, Concessionaria>::iterator it = concessionarias.begin();
       it != concessionarias.end(); ++it) {

    if ((it->second).veiculos.erase(chassi) > 0) {
      (it->second).estoque--;
      return "Veiculo removido com sucesso!\n";
    }
  }
  return "Veiculo nao encontrado.\n";
}

// Recebe o nome de uma concessionária e lista seus dados, caso ela seja
// encontrada no sistema.
string Sistema::list_concessionaria(string nome) {
  std::ostringstream oo;
  oo << concessionarias.at(nome);
  return oo.str();
}

// Recebe o nome de uma concessionária e um número; aumenta os preços dos
// veículos na concessionária de acordo com o número em porcentagem e com o tipo
// de veículo.
string Sistema::raise_price(string nome, double num) {
  for (map<string, VeiculoPtr>::iterator it =
           concessionarias.at(nome).veiculos.begin();
       it != concessionarias.at(nome).veiculos.end(); ++it) {

    (concessionarias.at(nome).somas.at((*it->second).getTipo())) -=
        (concessionarias.at(nome).somas.at((*it->second).getTipo()));

    (*it->second).raisePrice(num);

    (concessionarias.at(nome).somas.at((*it->second).getTipo())) +=
        (*it->second).preco;
  }

  std::ostringstream oo;
  oo << "Aumento de 10% nos preços de automovéis da Concessionária " << nome
     << " realizado" << std::endl;
  oo << "Aumento de 20% nos preços de motos da Concessionária " << nome
     << " realizado" << std::endl;
  oo << "Aumento de 30% nos preços de caminhões da Concessionária " << nome
     << " realizado" << std::endl;
  return oo.str();
}

/*

IMPLEMENTAR MÉTODOS PARA OS COMANDOS RESTANTES  */
