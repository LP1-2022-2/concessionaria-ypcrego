#include "sistema.h"

// TODO mexer com smart pointers pra consertar o vetor
// Ou TODO criar 3 vetores

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

  return "Concessionária criada!\n";
}

std::map<string, Concessionaria> Sistema::getConcessionarias() {
  return concessionarias;
}

bool Sistema::busca_concessionaria(string nome) {
  return (concessionarias.count(nome) == 1);
}

string Sistema::veiculoCriado(string *chassi) {

  for (map<string, Concessionaria>::iterator it = concessionarias.begin();
       it != concessionarias.end(); ++it) {

    if (concessionarias.at(it->first).carros.count(*chassi) > 0 ||
        concessionarias.at(it->first).motos.count(*chassi) > 0 ||
        concessionarias.at(it->first).caminhoes.count(*chassi) > 0) {

      std::ostringstream oo;
      oo << "ERRO - Veículo " << *chassi << " já adicionado à concessionária "
         << it->first;

      return oo.str();
    }
  };

  return "OK";
}

string Sistema::create_car(string nome, string chassi, Automovel aa) {

  string returnVeiculoCriado = veiculoCriado(&chassi);
  if (returnVeiculoCriado != "OK") {
    return returnVeiculoCriado;
  }

  concessionarias.at(nome).carros.insert(
      std::pair<string, Automovel>(chassi, aa));

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

string Sistema::search_vehicle(string inputChassi) {
  for (map<string, Concessionaria>::iterator it = concessionarias.begin();
       it != concessionarias.end(); ++it) {

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

  std::ostringstream oo;
  oo << "Veículo não encontrado!";
  return oo.str();
}

// TODO Remover código repetido de remove_vehicle (códígo para buscar um
// veículo).

string Sistema::remove_vehicle(string inputChassi) {
  bool removido = false;
  map<string, Concessionaria>::iterator itEncontrado;
  for (map<string, Concessionaria>::iterator it = concessionarias.begin();
       it != concessionarias.end(); ++it) {

    if ((it->second).carros.find(inputChassi) != (it->second).carros.end()) {

      itEncontrado = it;

      map<string, Automovel>::iterator itVeiculo =
          (it->second).carros.find(inputChassi);

      (it->second).carros.erase(itVeiculo);

      removido = true;
      break;
    }

    if ((it->second).motos.find(inputChassi) != (it->second).motos.end()) {

      itEncontrado = it;

      map<string, Moto>::iterator itVeiculo =
          (it->second).motos.find(inputChassi);

      (it->second).motos.erase(itVeiculo);

      removido = true;
      break;
    }

    if ((it->second).caminhoes.find(inputChassi) !=
        (it->second).caminhoes.end()) {

      itEncontrado = it;

      map<string, Caminhao>::iterator itVeiculo =
          (it->second).caminhoes.find(inputChassi);

      (it->second).caminhoes.erase(itVeiculo);

      removido = true;
      break;
    }
  }

  std::ostringstream oo;

  if (removido) {
    oo << "Veículo " << inputChassi << " removido da concessionária "
       << (itEncontrado->first);
    return oo.str();
  }

  oo << "Veículo não encontrado!";

  return oo.str();
}

string Sistema::list_concessionaria(string nome) {
  std::vector<double> somas;
  double temp_soma = 0;

  for (map<string, Automovel>::iterator it =
           concessionarias.at(nome).carros.begin();
       it != concessionarias.at(nome).carros.end(); ++it) {
    temp_soma += (it->second).preco;
  }

  somas.push_back(temp_soma);

  temp_soma = 0;

  for (map<string, Moto>::iterator it = concessionarias.at(nome).motos.begin();
       it != concessionarias.at(nome).motos.end(); ++it) {
    temp_soma += (it->second).preco;
  }

  somas.push_back(temp_soma);

  temp_soma = 0;

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
     << "; Valor total: R$ " << somas[0] << std::endl;

  oo << "Total de Motos: " << concessionarias.at(nome).motos.size()
     << "; Valor total: R$ " << somas[1] << std::endl;

  oo << "Total de Caminhões: " << concessionarias.at(nome).caminhoes.size()
     << "; Valor total: R$ " << somas[2] << std::endl;

  oo << "Valor total da frota: R$ "
     << std::accumulate(somas.begin(), somas.end(), 0) << std::endl;
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
