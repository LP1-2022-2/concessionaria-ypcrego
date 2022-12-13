#include "concessionaria.h"

#include <iomanip>
#include <numeric>

// Construtor de concessionária. Inicializa os mapas "quantidades" e "mapas",
// pois, mesmo que determinado veículo não seja cadastrado, deve ser listado.
Concessionaria::Concessionaria(string nome, string CNPJ, int estoque = 0)
    : nome(nome), CNPJ(CNPJ), estoque(estoque) {

  quantidades.insert(std::pair<string, int>("Automovel", 0));
  quantidades.insert(std::pair<string, int>("Moto", 0));
  quantidades.insert(std::pair<string, int>("Caminhao", 0));

  somas.insert(std::pair<string, int>("Automovel", 0));
  somas.insert(std::pair<string, int>("Moto", 0));
  somas.insert(std::pair<string, int>("Caminhao", 0));
};

std::ostream &operator<<(std::ostream &oo, Concessionaria const &cc) {
  oo << "Concessionaria " << cc.nome << std::endl;

  oo << "Total de Automóveis: " << cc.quantidades.at("Automovel")
     << "; Valor total: R$ " << std::fixed << std::setprecision(2)
     << cc.somas.at("Automovel") << std::endl;

  oo << "Total de Motos: " << cc.quantidades.at("Moto") << "; Valor total: R$ "
     << cc.somas.at("Moto") << std::endl;

  oo << "Total de Caminhões: " << cc.quantidades.at("Caminhao")
     << "; Valor total: R$ " << cc.somas.at("Caminhao") << std::endl;

  double total =
      std::accumulate(cc.somas.begin(), cc.somas.end(), 0,
                      [](double anterior, std::pair<string, double> atual) {
                        return anterior + atual.second;
                      });

  oo << "Valor total da frota: R$ " << total << std::endl;

  return oo;
}