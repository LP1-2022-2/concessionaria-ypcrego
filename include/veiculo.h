#ifndef VEICULO_H
#define VEICULO_H
#include <iostream>
#include <string>

using std::string;

class Veiculo {
public:
  string concessionaria;
  string marca;
  double preco;
  string chassi;
  int anoFabricacao;
  Veiculo(string concessionaria, string marca, double preco, string chassi,
          int anoFabricacao);

  // Método virtual que se refere ao tipo de cada veículo (ex: "Automovel").
  virtual string getTipo() = 0;

  // Método virtual que imprime cada atributo de veículo.
  virtual void print(std::ostream &oo) const;

  // Método que chama a função print().
  friend std::ostream &operator<<(std::ostream &oo, const Veiculo &vv);

  // Método virtual para aumentar o preço para cada tipo de veículo.
  virtual double raisePrice(double num) = 0;
  virtual ~Veiculo();
};

#endif
