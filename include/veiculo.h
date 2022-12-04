#ifndef VEICULO_H
#define VEICULO_H

#include <string>

using std::string;

class Veiculo {
public:
  string marca;
  double preco;
  int anoFabricacao;
  virtual string getAtributoRelativo();
  virtual void setAtributoRelativo(string atributoRelativo){};
	virtual string const nomeClasse(); 
};

#endif
