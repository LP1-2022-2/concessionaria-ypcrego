#ifndef SISTEMA_H
#define SISTEMA_H
#include "concessionaria.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

using std::map;
using std::string;
// Sistema deve concentrar todas as operações
class Sistema {
private:
  map<string, Concessionaria>
      concessionarias; // um vetor com todos as concessionarias

public:
  // Modificar abaixo
  std::map<string, Concessionaria> getConcessionarias();
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

  string create_veiculo(string nome, string chassi, Veiculo cc);

  string search_vehicle(string inputChassi);

  friend std::ostream &operator<<(std::ostream &oo, Veiculo const &vv);

  string remove_vehicle(string inputChassi);
};

#endif
