#include "executor.h"
#include <iostream>
#include <istream>
#include <ostream>
#include <queue>
#include <sstream>
#include <string>

using namespace std;

// Função de apoio que recebe um istringstream e
// le todo texto restante até o fim da linha
string restoDe(istringstream &ss) {
  string resto;
  getline(ss, resto, '\0'); // ler o resto da linha
  if (resto != "" && (resto[0] == ' ' || resto[0] == '\t')) {
    resto = resto.substr(1); // o primeiro caractere é um espaço, descartar
  }
  return resto;
}

// Construtor. Recebe uma referência ao sistema que vai operar
// Guarda o seu endereço para executar as operações.
Executor::Executor(Sistema &sistema) {
  this->sair = false;
  this->sistema = &sistema;
}

// Inicia o processamento dos comentarios.
// Esse método recebe por exemplo o "cin" e o "cout" no main
// Dessa forma ele faz o necessário para ler 1 comando por linha e
// o processar corretamente, colocando no stream de saída o resultado de cada
// um.
void Executor::iniciar(istream &inputStream, ostream &outputStream) {
  string linha, saida;
  this->sair = false;
  while (!this->sair) {
    if (std::getline(inputStream, linha)) {
      saida = processarLinha(linha);
      outputStream << saida << endl;
    }
  }
}

// Método responsável por processar cada linha, capturando o nome do comando
// e seus parâmetros em variáveis e executar o método correspondente no sistema
string Executor::processarLinha(string linha) {
  istringstream buf(linha);
  string nomeComando;
  buf >> nomeComando;

  if (nomeComando.empty()) {
    return "Comando Inválido <vazio>";
  }

  if (nomeComando == "quit") {
    this->sair = true;
    return sistema->quit();
  } else if (nomeComando == "create-concessionaria") {
    string dados = restoDe(buf);

    buf.clear();
    buf.str(dados);

    string nome;
    buf >> nome;

    string CNPJ;
    buf >> CNPJ;

    int estoque;
    buf >> estoque;

    return sistema->create_concessionaria(nome, CNPJ, estoque);

  } else if (nomeComando == "add-car" || nomeComando == "add-bike" ||
             nomeComando == "add-truck") {
    string dados = restoDe(buf);

    buf.clear();
    buf.str(dados);

    string nome;
    buf >> nome;

    if (!sistema->busca_concessionaria(nome)) {
      return "Concessionaria nao criada!";
    }

    string marca;
    buf >> marca;

    double preco;
    buf >> preco;

    string chassi;
    buf >> chassi;

    int anoFabricacao;
    buf >> anoFabricacao;

    string atributoRelativo;
    buf >> atributoRelativo;

    if (nomeComando == "add-car") {
      Automovel aa(marca, preco, anoFabricacao, atributoRelativo);
      return sistema->create_car(nome, chassi, aa);

    } else if (nomeComando == "add-bike") {
      Moto mm(marca, preco, anoFabricacao, atributoRelativo);
      return sistema->create_bike(nome, chassi, mm);

    } else if (nomeComando == "add-truck") {
      Caminhao tt(marca, preco, anoFabricacao, atributoRelativo);
      return sistema->create_truck(nome, chassi, tt);
    }

  } else if (nomeComando == "search-vehicle") {
    string inputChassi = restoDe(buf);
    return sistema->search_vehicle(inputChassi);

  } else if (nomeComando == "remove-vehicle") {
    string inputChassi = restoDe(buf);
    return sistema->remove_vehicle(inputChassi);

  } else if (nomeComando == "list-concessionaria") {
    string nome = restoDe(buf);
    return sistema->list_concessionaria(nome);

  } else if (nomeComando == "raise-price") {
    string dados = restoDe(buf);

    buf.clear();
    buf.str(dados);

    string nome;
    buf >> nome;

    double porcentagem;
    buf >> porcentagem;

    return sistema->raise_price(nome, porcentagem);

  } else {
    return "Comando não reconhecido!";
  }

  return "Erro";
}
