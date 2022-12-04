#include "sistema.h"

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

std::vector<Concessionaria> Sistema::getConcessionarias() {
	return concessionarias;
}

bool Sistema::busca_concessionaria(string nome) {
 /* auto it =
      find_if(concessionarias.begin(), concessionarias.end(),
              [&nome](const Concessionaria &obj) { return obj.nome == nome; });

  if (it != concessionarias.end()) {
    return 1;
    // found element. it is an iterator to the first matching element.
    // if you really need the index, you can also get it:
    // auto index = std::distance(concessionarias.begin(), it);
  }*/
  return 0;
}

/*bool Sistema::create_concessionaria(const string nome, const string CNPJ, const int estoque) {
	
}*/

/* IMPLEMENTAR MÉTODOS PARA OS COMANDOS RESTANTES */
