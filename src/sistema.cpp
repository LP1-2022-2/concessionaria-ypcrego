#include "sistema.h"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <numeric>
// NOVO-TIPO-VEICULO: quando adicionar um novo tipo de veículo, aidcionar um
// método "create" para ele. Para demais alterações, buscar a palavra-chave.

/* COMANDOS */
string Sistema::quit() { return "Saindo..."; }

// Recebe as variáveis necessárias para a criação de uma concessionária e a
// cadastra no sistema.
string Sistema::create_concessionaria(const string nome, const string CNPJ,
                                      const int estoque) {
  concessionarias.insert(
      std::pair<string, Concessionaria>(nome, Concessionaria(CNPJ, estoque)));

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

// Verifica se um veículo já foi cadastro no sistema pelo chassi.
string Sistema::veiculoCriado(string *chassi) {

  for (map<string, Concessionaria>::iterator it = concessionarias.begin();
       it != concessionarias.end(); ++it) {

    // Verifica se o chassi está presente em qualquer um dos vetores relativos
    // aos tipos de veículo. NOVO-TIPO-VEICULO: adicionar mais uma condição ao
    // if.
    if (concessionarias.at(it->first).carros.count(*chassi) > 0 ||
        concessionarias.at(it->first).motos.count(*chassi) > 0 ||
        concessionarias.at(it->first).caminhoes.count(*chassi) > 0) {

      std::ostringstream oo;
      oo << "ERRO - Veículo " << *chassi << " já adicionado à concessionária "
         << it->first << std::endl;

      return oo.str();
    }
  };

  return "OK";
}

string Sistema::create_car(string nome, string chassi, Automovel aa) {
  // Verifica se o carro já foi criado.
  string returnVeiculoCriado = veiculoCriado(&chassi);
  if (returnVeiculoCriado != "OK") {
    return returnVeiculoCriado;
  }

  // Insere o carro "aa" dentro do map "carros", na concessionária que é
  // identificada por "nome", uma key. O carro é identificado pelo chassi.
  concessionarias.at(nome).carros.insert(
      std::pair<string, Automovel>(chassi, aa));

  // Aumenta o estoque da concessionária, uma vez que um veículo foi adicionado
  // nela.
  (concessionarias.at(nome).estoque)++;

  return "Veículo criado!\n";
}

string Sistema::create_bike(string nome, string chassi, Moto mm) {

  string returnVeiculoCriado = veiculoCriado(&chassi);
  if (returnVeiculoCriado != "OK") {
    return returnVeiculoCriado;
  }

  concessionarias.at(nome).motos.insert(std::pair<string, Moto>(chassi, mm));

  (concessionarias.at(nome).estoque)++;

  return "Veículo criado!\n";
}

string Sistema::create_truck(string nome, string chassi, Caminhao tt) {

  string returnVeiculoCriado = veiculoCriado(&chassi);
  if (returnVeiculoCriado != "OK") {
    return returnVeiculoCriado;
  }

  concessionarias.at(nome).caminhoes.insert(
      std::pair<string, Caminhao>(chassi, tt));

  (concessionarias.at(nome).estoque)++;

  return "Veículo criado!\n";
}

// Recebe um chassi e o pesquisa nas concessionárias do sistema.
// NOVO-TIPO-VEICULO: adicionar um for que o percorra. Seguir o padrão dos tipos
// já adicionados.
string Sistema::search_vehicle(string inputChassi) {

  // Percorre o container de concessionárias do sistema.
  for (map<string, Concessionaria>::iterator it = concessionarias.begin();
       it != concessionarias.end(); ++it) {

    // Busca o veículo (através de um chassi) no container de carros da
    // concessionária atual. Retorna seus dados caso seja encontrado.
    if ((it->second).carros.find(inputChassi) != (it->second).carros.end()) {

      map<string, Automovel>::iterator itVeiculo =
          (it->second).carros.find(inputChassi);

      Automovel aa = itVeiculo->second;

      std::ostringstream oo;
      oo << "Concessionaria: " << it->first << std::endl;
      oo << "Marca: " << aa.marca << std::endl;
      oo << "Preço: " << aa.preco << std::endl;
      oo << "Chassi: " << itVeiculo->first << std::endl;
      oo << "Ano: " << aa.anoFabricacao << std::endl;
      oo << "Tipo de motor: " << aa.tipoMotor << std::endl;
      return oo.str();
    }

    // Similar à busca de carros.
    else if ((it->second).motos.find(inputChassi) != (it->second).motos.end()) {
      map<string, Moto>::iterator itVeiculo =
          (it->second).motos.find(inputChassi);

      Moto mm = itVeiculo->second;

      std::ostringstream oo;
      oo << "Concessionaria: " << it->first << std::endl;
      oo << "Marca: " << mm.marca << std::endl;
      oo << "Preço: " << mm.preco << std::endl;
      oo << "Chassi: " << itVeiculo->first << std::endl;
      oo << "Ano: " << mm.anoFabricacao << std::endl;
      oo << "Modelo: " << mm.modelo << std::endl;
      return oo.str();
    }

    // Similar à busca de carros.
    else if ((it->second).caminhoes.find(inputChassi) !=
             (it->second).caminhoes.end()) {

      map<string, Caminhao>::iterator itVeiculo =
          (it->second).caminhoes.find(inputChassi);

      Caminhao tt = itVeiculo->second;

      std::ostringstream oo;
      oo << "Concessionaria: " << it->first << std::endl;
      oo << "Marca: " << tt.marca << std::endl;
      oo << "Preço: " << tt.preco << std::endl;
      oo << "Chassi: " << itVeiculo->first << std::endl;
      oo << "Ano: " << tt.anoFabricacao << std::endl;
      oo << "Tipo de carga: " << tt.tipoCarga << std::endl;
      return oo.str();
    }
  }

  // Retorno caso o veículo não seja encontrado em nenhuma concessionária.
  std::ostringstream oo;
  oo << "Veículo não encontrado!" << std::endl;
  return oo.str();
}

// Recebe um chassi e o pesquisa nas concessionárias do sistema, removendo o
// veículo ao qual é vinculado caso seja encontrado. A busca, em si, é
// constituída por código repetido da função "search_vehicle".
// NOVO-TIPO-VEICULO: Adicionar um if no for para o tipo de veículo.
string Sistema::remove_vehicle(string inputChassi) {

  // Variável de controle para interromper as buscas caso o veículo seja
  // encontrado e removido.
  bool removido = false;

  // Armazena o nome da concessionária em que o veículo for encontrado.
  string nomeEncontrado;

  for (map<string, Concessionaria>::iterator it = concessionarias.begin();
       it != concessionarias.end(); ++it) {

    // Busca o veículo (através de um chassi) no container de carros da
    // concessionária atual. Remove o veículo e interrompe o for caso esse seja
    // encontrado.
    if ((it->second).carros.find(inputChassi) != (it->second).carros.end()) {

      nomeEncontrado = it->first;

      map<string, Automovel>::iterator itVeiculo =
          (it->second).carros.find(inputChassi);

      (it->second).carros.erase(itVeiculo);

      ((it->second).estoque)--;

      removido = true;
      break;
    }

    // Similar ao de carros.
    else if ((it->second).motos.find(inputChassi) != (it->second).motos.end()) {

      nomeEncontrado = it->first;

      map<string, Moto>::iterator itVeiculo =
          (it->second).motos.find(inputChassi);

      (it->second).motos.erase(itVeiculo);
      ((it->second).estoque)--;

      removido = true;
      break;
    }

    // Similar ao de carros.
    else if ((it->second).caminhoes.find(inputChassi) !=
             (it->second).caminhoes.end()) {

      nomeEncontrado = it->first;

      map<string, Caminhao>::iterator itVeiculo =
          (it->second).caminhoes.find(inputChassi);

      (it->second).caminhoes.erase(itVeiculo);
      ((it->second).estoque)--;

      removido = true;
      break;
    }
  }

  std::ostringstream oo;

  // Caso o veículo tenha sido encontrado e removido.
  if (removido) {
    oo << "Veículo " << inputChassi << " removido da concessionária "
       << nomeEncontrado << std::endl;
    return oo.str();
  }

  oo << "Veículo não encontrado!" << std::endl;

  return oo.str();
}

// Recebe o nome de uma concessionária e lista seus dados, caso ela seja
// encontrada no sistema.
// NOVO-TIPO-VEICULO: adicionar um for para somar os preços no container
// relativo ao tipo de veículo. Seguir o exemplo dos outros tipos.
string Sistema::list_concessionaria(string nome) {

  // Vetor que armazena as somas dos preços de cada tipo de veículo. Exemplo: a
  // soma dos preços dos carros cadastrados na concessionária é armazenada em
  // somas[0]; a dos preços das motos é armazenada em somas[1].
  std::vector<double> somas;

  // Armazena a soma dos preços de um tipo de veículo.
  double temp_soma = 0;

  // Soma os preços dos carros na concessionária.
  for (map<string, Automovel>::iterator it =
           concessionarias.at(nome).carros.begin();
       it != concessionarias.at(nome).carros.end(); ++it) {
    temp_soma += (it->second).preco;
  }

  somas.push_back(temp_soma);

  temp_soma = 0;

  // Semelhante à soma de carros.
  for (map<string, Moto>::iterator it = concessionarias.at(nome).motos.begin();
       it != concessionarias.at(nome).motos.end(); ++it) {
    temp_soma += (it->second).preco;
  }

  somas.push_back(temp_soma);

  temp_soma = 0;

  // Semelhante à soma de carros.
  for (map<string, Caminhao>::iterator it =
           concessionarias.at(nome).caminhoes.begin();
       it != concessionarias.at(nome).caminhoes.end(); ++it) {
    temp_soma += (it->second).preco;
  }

  somas.push_back(temp_soma);

  temp_soma = 0;

  std::ostringstream oo;
  oo << "Concessionaria " << nome << std::endl;

  oo << "Total de Automóveis: " << concessionarias.at(nome).carros.size()
     << "; Valor total: R$ " << std::fixed << std::setprecision(2) << somas[0]
     << std::endl;

  oo << "Total de Motos: " << concessionarias.at(nome).motos.size()
     << "; Valor total: R$ " << somas[1] << std::endl;

  oo << "Total de Caminhões: " << concessionarias.at(nome).caminhoes.size()
     << "; Valor total: R$ " << somas[2] << std::endl;

  oo << "Valor total da frota: R$ "
     << std::accumulate(somas.begin(), somas.end(), 0) << std::endl;
  return oo.str();
}

// Recebe o nome de uma concessionária e um número; aumenta os preços dos
// veículos na concessionária de acordo com o número em porcentagem e com o tipo
// de veículo.
// NOVO-TIPO-VEICULO: criar for para percorrer os veículos do tipo; utilizar os
// já existentes como modelo.
string Sistema::raise_price(string nome, double num) {
  double aumento = 1 + (num / 100.0);

  // Percorre os carros da concessionária específica e aumenta o preço de cada
  // um.
  for (map<string, Automovel>::iterator it =
           concessionarias.at(nome).carros.begin();
       it != concessionarias.at(nome).carros.end(); ++it) {
    (it->second).preco *= aumento;
  }

  aumento = 1 + (2 * num / 100.0);

  // Semelhante ao aumento de preços em carros.
  for (map<string, Moto>::iterator it = concessionarias.at(nome).motos.begin();
       it != concessionarias.at(nome).motos.end(); ++it) {
    (it->second).preco *= aumento;
  }

  aumento = 1 + (3 * num / 100.0);

  // Semelhante ao aumento de preços em carros.
  for (map<string, Caminhao>::iterator it =
           concessionarias.at(nome).caminhoes.begin();
       it != concessionarias.at(nome).caminhoes.end(); ++it) {
    (it->second).preco *= aumento;
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

/*std::ostream &operator<<(std::ostream &oo, Veiculo const &vv) {
        map<string, Concessionaria>::iterator it;
        it = concessionarias.find(vv);
        string concessionariaString = it->first;
  oo << "Nome: " << cc.nome << std::endl
     << "CNPJ: " << cc.CNPJ << std::endl
     << "Número de veículos: " << cc.estoque << std::endl;
  return oo;
        }*/

/* IMPLEMENTAR MÉTODOS PARA OS COMANDOS RESTANTES */
