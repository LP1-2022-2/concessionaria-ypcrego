#include "../include/sistema.h"
#include "../include/concessionaria.h"
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

/* COMANDOS */
string Sistema::quit() { return "Saindo..."; }

string Sistema::create_concessionaria(const string nome, const string CNPJ,
                                      const int estoque) {
  concessionarias.push_back(Concessionaria(nome, CNPJ, estoque));

  /* Imprime as concessionárias criadas.
                std::cout << "\nConcessionarias existentes: ";
                for (std::vector<Concessionaria>::iterator it =
                concessionarias.begin(); it != concessionarias.end(); ++it)
                cout << endl << *it << endl;
*/

  return "Concessionária criada!";
}

/* IMPLEMENTAR MÉTODOS PARA OS COMANDOS RESTANTES */
