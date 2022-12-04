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
    /* TODO: Verificar se a linha comentada a seguir ainda pode ser necessária
       em algum momento (caso de criar concessionária apenas com nome) return
       sistema->create_concessionaria(nome); */
  } else if (nomeComando == "add-car") {
    string dados = restoDe(buf);

    buf.clear();
    buf.str(dados);

    string nome;
    buf >> nome;

    // if (!sistema->busca_concessionaria(nome)) {
    //   return "Concessionaria nao criada!";
    // }

    string marca;
    buf >> marca;

    double preco;
    buf >> preco;

    string chassi;
    buf >> chassi;

    int anoFabricacao;
    buf >> anoFabricacao;

    string tipoMotor;
    buf >> tipoMotor;

    Veiculo c = Automovel(marca, preco, chassi, anoFabricacao, tipoMotor);

		// Tamanhos diferentes e eu não sei pq vou chorarrr
    for (int ii = 0; ii < sistema->getConcessionarias().size(); ii++) {
      if (sistema->getConcessionarias()[ii].nome == nome) {
        sistema->getConcessionarias()[ii].addVeiculo(c);
        vector<Veiculo>::iterator it;
         cout << "2 Tamanho de veiculos : "
        << sistema->getConcessionarias()[ii].veiculos.size() << endl;
        for (it = sistema->getConcessionarias()[ii].veiculos.begin();
             it != sistema->getConcessionarias()[ii].veiculos.end(); ++it) {
          std::cout << "Tipo : " << (*it).marca << std::endl;
        }
      }
    }

    // O veiculo parece estar sendo adicionado la em concessionaria.cpp, mas nao
    // é impresso aqui embaixo. Verificar pq.
    for (int ii = 0; ii < sistema->getConcessionarias().size(); ii++) {
      vector<Veiculo>::iterator it;
      for (it = sistema->getConcessionarias()[ii].veiculos.begin();
           it != sistema->getConcessionarias()[ii].veiculos.end(); ++it) {
        std::cout << "Tipo : " << (*it).marca << std::endl;
      }
    }
    // for (it = codigos.begin(); it != codigos.end(); ++it) {
    // Iteracao sobre os elementos do vetor utilizando o iterador it
    //}
  }

  return "Erro";
}
