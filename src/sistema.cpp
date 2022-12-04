#include "sistema.h"

/* COMANDOS */
string Sistema::quit() { return "Saindo..."; }

string Sistema::create_concessionaria(const string nome, const string CNPJ,
                                      const int estoque) {
  concessionarias.insert(
      std::pair<string, Concessionaria>(nome, Concessionaria(CNPJ, estoque)));

  /* Imprime as concessionárias criadas.
                std::cout << "\nConcessionarias existentes: ";
                for (std::vector<Concessionaria>::iterator it =
                concessionarias.begin(); it != concessionarias.end(); ++it)
                cout << endl << *it << endl;
*/

  return "Concessionária criada!";
}

std::map<string, Concessionaria> Sistema::getConcessionarias() {
  return concessionarias;
}

bool Sistema::busca_concessionaria(string nome) {
  return (concessionarias.count(nome) == 1);
}

string Sistema::create_veiculo(string nome, string chassi, Veiculo vv) {

  if (concessionarias.at(nome).veiculos.count(chassi) > 0) {
		
    std::ostringstream oo;
    oo << "ERRO - Veículo " << chassi << " já adicionado à concessionária "
       << nome;
		
    return oo.str();
  };

  concessionarias.at(nome).veiculos.insert(
      std::pair<string, Veiculo>(chassi, vv));
  return "\0";
}

string Sistema::search_vehicle(string inputChassi) {
  for (map<string, Concessionaria>::iterator it = concessionarias.begin();
       it != concessionarias.end(); ++it) {

    if ((it->second).veiculos.find(inputChassi) ==
        (it->second).veiculos.end()) {

      continue;

    } else {

      map<string, Veiculo>::iterator itVeiculo =
          (it->second).veiculos.find(inputChassi);
      Veiculo vv = itVeiculo->second;

      //	std::cout << "Atributo especial: " << vv.getAtributoRelativo()
      //<< std::endl;
      std::ostringstream oo;
      oo << "Concessionaria: " << it->first << std::endl;
      oo << "Marca: " << vv.marca << std::endl;
      oo << "Preço: " << vv.preco << std::endl;
      oo << "Chassi: " << itVeiculo->first << std::endl;
      oo << "Preço: " << vv.anoFabricacao << std::endl;
      return oo.str();
    }
  }
  std::ostringstream oo;
  oo << "Veículo não encontrado!";
  return oo.str();
}

// TODO Remover código repetido de remove_vehicle (códígo para buscar um
// veículo).

string Sistema::remove_vehicle(string inputChassi) {
  for (map<string, Concessionaria>::iterator it = concessionarias.begin();
       it != concessionarias.end(); ++it) {

    if ((it->second).veiculos.find(inputChassi) ==
        (it->second).veiculos.end()) {

      continue;

    }

    else {

      map<string, Veiculo>::iterator itVeiculo =
          (it->second).veiculos.find(inputChassi);

      Veiculo vv = itVeiculo->second;
      (it->second).veiculos.erase(itVeiculo);

      std::ostringstream oo;
      oo << "Veículo " << inputChassi << " removido da concessionária "
         << (it->first);
      return oo.str();
    }
  }

  std::ostringstream oo;
  oo << "Veículo não encontrado!";

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
