#ifndef SISTEMA_H
#define SISTEMA_H
#include "concessionaria.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::string;

// Sistema deve concentrar todas as operações
class Sistema {
private:
  std::vector<Concessionaria>
      concessionarias; // um vetor com todos as concessionarias

public:
std::vector<Concessionaria> getConcessionarias();
  /* Cria uma concessionaria e retorna uma string de erro/sucesso
           @param nome o nome da concessionaria
           @return uma string contendo uma mensagem de erro ou "Concessionaria
      Criada"

        TODO: Verificar se a linha comentada a seguir ainda é necessária (criar
     concessionária apenas pelo nome).
         string create_concessionaria(const string nome); */

  string create_concessionaria(const string nome, const string CNPJ,
                               const int estoque);

  /* Encerra o funcionamento do programa.
          @return uma string com a mensagem "Saindo.."
  */
  string quit();

  bool busca_concessionaria(string nome);

  bool create_car(const string nome, const string CNPJ, const int estoque);


};

#endif
