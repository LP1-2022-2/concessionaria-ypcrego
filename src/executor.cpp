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
  }

  // Comando relativo à criação de uma concessionária.
  else if (nomeComando == "create-concessionaria") {
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

  }

  // Comandos relativos à adição de um veículo na concessionária.
  else if (nomeComando == "add-car" || nomeComando == "add-bike" ||
           nomeComando == "add-truck") {
    string dados = restoDe(buf);

    buf.clear();
    buf.str(dados);

    string concessionaria;
    buf >> concessionaria;

    // Busca uma concessionária por nome no sistema.
    if (!sistema->busca_concessionaria(concessionaria)) {
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

    // Cria um shared_ptr relativo ao tipo desejado e o adiciona no sistema.
    if (nomeComando == "add-car") {
      VeiculoPtr aa =
          std::make_shared<Automovel>(concessionaria, marca, preco, chassi,
                                      anoFabricacao, atributoRelativo);

      return sistema->create_vehicle(concessionaria, chassi, aa);

    } else if (nomeComando == "add-bike") {
      VeiculoPtr mm =
          std::make_shared<Moto>(concessionaria, marca, preco, chassi,
                                 anoFabricacao, atributoRelativo);
      return sistema->create_vehicle(concessionaria, chassi, mm);

    } else if (nomeComando == "add-truck") {
      VeiculoPtr tt =
          std::make_shared<Caminhao>(concessionaria, marca, preco, chassi,
                                     anoFabricacao, atributoRelativo);
      return sistema->create_vehicle(concessionaria, chassi, tt);
    }

  }

  // Comando relativo à busca de um veículo no sistema.
  else if (nomeComando == "search-vehicle") {
    string inputChassi = restoDe(buf);
    return sistema->search_vehicle(inputChassi);

  }

  // Comando relativo à remoção de um veículo do sistema.
  else if (nomeComando == "remove-vehicle") {
    string inputChassi = restoDe(buf);
    return sistema->remove_vehicle(inputChassi);

  }

  // Comando que lista informações de uma concessionária.
  else if (nomeComando == "list-concessionaria") {
    string concessionaria = restoDe(buf);

    if (!sistema->busca_concessionaria(concessionaria)) {
      return "Concessionaria nao criada!";
    }

    return sistema->list_concessionaria(concessionaria);

  }

  // Comando que aumenta todos os preços dos veículos em uma concessionária por
  // determinada % (porcentagem).
  else if (nomeComando == "raise-price") {
    string dados = restoDe(buf);

    buf.clear();
    buf.str(dados);

    string nome;
    buf >> nome;

    if (!sistema->busca_concessionaria(nome)) {
      return "Concessionaria nao criada!";
    }

    double porcentagem;
    buf >> porcentagem;

    return sistema->raise_price(nome, porcentagem);

  }

  // Relativo a comandos incorretos ou não adicionados.
  else {
    return "Comando não reconhecido!";
  }

  return "Erro";
}
