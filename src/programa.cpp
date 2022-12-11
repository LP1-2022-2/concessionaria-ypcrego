// TODO Verificar possível substituição de atributos públicos por getters e setters
// Todo terminar os outros comandos; usar static e virtual pra contar
#include "executor.h"
#include "sistema.h"
#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

int main() {
  // inicialização do sistema
  Sistema sistema;
  Executor executor(sistema);

  // o executor recebe o cin e o cout. Ele os utilizará para ler as linhas
  // de comando, executar o método correto em "sistema" e exibir as mensagens
  executor.iniciar(cin, cout);

  return 0;
}
