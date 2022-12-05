
# Identificação

* Nome: Yves Pablo Costa Rêgo

* Matrícula: 20210058235
  
# Compilação  

* a descrição de como compilar e rodar o programa, incluindo um roteiro de entradas e comandos que destaquem as funcionalidades 

# Limitações

* a descrição das limitações (caso existam) do programa e quaisquer dificuldades encontradas
  
	* Limitação/Dificuldade 1: A manutenção do código não é fluida. Para adicionar um novo tipo de veículo, devem ser feitas mudanças em muitos trechos do código.
	  * Detalhes: no momento de cadastrar veículos em uma concessionária, surgiu a necessidade de criar um container para armazená-los. Entretanto, caso o container tivesse como tipo a classe base Veículo, os objetos de classes derivadas inseridos nele perderiam seus atributos especiais (ex: o modelo de uma Moto), a não ser que fossem utilizados smart pointers ou downcasting. No entanto, além disso, pede-se para listar a quantidade de carros/motos/caminhões no container; não foi encontrado um método eficiente de fazer isso, mesmo pensando nas soluções anteriores. Com isso, a solução utilizada foi a de criar múltiplos containers, um para cada tipo de veículo, e armazenar os objetos de acordo com o tipo de cada um. Não parece ser uma resolução adequada, uma vez que, caso se deseje adicionar um novo tipo de veículo, muito código precisa ser repetido: criar um novo container para aquele tipo, criar os métodos relativos à sua inserção na concessionária, e atualizar os métodos relacionados à busca/remoção/listagem (que, por sua vez, já têm repetições).
	* Limitação/Dificuldade 2: partes significativas do código são repetidas.
	  * Detalhes: como complemento à limitação/dificuldade 1, muitos trechos do código são repetidos. Isso significa que, caso algo precise ser modificado em determinadas funcionalidades, a mudança deve ser feita várias vezes, uma para cada tipo de veículo.
	* Limitação/Dificuldade 3: o conceito de herança poderia ter sido melhor explorado.
		* Detalhes: como reflexo da limitação/dificuldade 1, foi excluída a possibilidade da criação de um vetor de Veículos. Assim, os objetos herdados de veículos obtiveram maior autonomia e menos código pôde ser reutilizado, tornando a existência da classe base menos útil do que poderia ter sido.
	* Limitação/Dificuldade 4: foi difícil visualizar a implementação de certas partes do exercício.
  * Detalhes: um exemplo de dificuldade nesse quesito foi na busca de veículos. A busca é realizada por um chassi, que, inicialmente, seria um atributo de um veículo; no entanto, houve complicações.
    A principal delas é que não foi fácil visualizar como obter um chassi a partir das múltiplas camadas em que ele estaria inserido - chassi seria um atributo (ou um método, considerando gets) pertencente a um objeto Veículo, que estaria em um vetor de Veículos; por sua vez, o vetor de Veículos estaria dentro de uma Concessionária, inserida em um vetor de Concessionárias.
    O acesso a um chassi através de tantas "subdivisões" se mostrou confuso, e o mesmo se aplicaria à outras funções. Uma solução parcial para tal foi utilizar mapas no lugar de vetores; desse modo, chassis virariam chaves, que facilitariam encontrar veículos.
    Embora essa alternativa tenha se mostrado eficaz, algumas questões ainda ficaram abertas: chassi ainda deveria ser um atributo de Veículo, mesmo que um determinado chassi já funcionasse como chave para um Veículo? No fim, para o código, essa necessidade foi suplantada, mas restaram dúvidas sobre qual seria a implementação fidedigna ao problema. 
   
# Autoavaliação

- Modelagem e implementação das classes Concessionária, Veículo, Automóvel, Moto, Caminhão | **10 / 10**
  - 0: sem modelagem e implementação de classes
  - 5: apenas algumas classes modeladas e implementadas; ausência de herança
  - 10: modelagem e implementação completa com uso de herança
  
- Implementação e uso do comando `create-concessionaria` | **10 / 10**
  - 0: não cria concessionária via linha de comando 
  - 5: permite criar apenas uma concessionária
  - 10: permite criar mais do que uma concessionária
  
- Implementação e uso dos comandos para adicionar veículos `add-car/add-bike/add-truck` | **10 / 10**
  - 0: não permite criar veículos via linha de comando
  - 5: permite criar apenas um ou outro veículo em uma única concessionária
  - 10: permite criar qualquer tipo de veículo em qualquer uma das concessionárias disponíveis

- Não permitir adicionar um veículo que já tenha sido anteriormente adicionado | **10 / 10**
  - 0: não realiza o teste
  - 10: realiza o teste e indica o erro  

- Implementação e uso do comando para remover veículos `remove-vehicle` | **10 / 10**
  - 0: comando não implementado
  - 10: comando implementado e funcional

- Implementação e uso do comando para busca de veículos `search-vehicle` | **15 / 15 - Bônus: ...**
  - 0: não implementado
  - 15: implementado e funcional
  - bonus +10: implementado com estratégia de busca diferente da busca exaustiva
  - bonus +10: uso de métodos virtuais para impressão na tela
  - bonus +10: uso de sobrecarga de operadores para impressão na tela

- Implementação e uso do comando `list-concessionaria` | **10 / 10 - Bônus: ...**
  - 0: não implementado
  - 10: implementado e funcional   
  - bonus +10: uso de sobrecarga de operadores para impressão na tela

- Implementação e uso do comando `raise-price` | **10 / 10 - Bônus: ...**
  - 0: não implementado
  - 10: implementado e funcional 
  - bonus +10: implementado com uso de método virtual

- Implementação e uso do comando `save-concessionaria` e `load-concessionaria` | **30 / 30**
  - 0: não implementado
  - 15: ambos os comandos implementados e funcionais
  
- Implementação eficiente através do uso de referencias e contêineres da STL | **5 / 10**
  - 0: não usou contêiner da STL nem fez uso eficiente dos recursos computacionais
  - 5: usou contêiner da STL mas não otimizou uso dos recursos computacionais
  - 10: usou contêiner da STL junto a algoritmos e práticas de bom uso de recursos computacionais
  
- Organização do código em src, include, data | **5 / 5**
  - 0: não organizou o código
  - 5: organizou o código 
  
- Documentação do código | **0 / 5**
  - 0: não documentou o código
  - 5: documentou o código 
  
- Implementação e documentação de arquivos e procedimentos de compilação e teste | **0 / 15**
  - 0: não implementou arquivos e procedimentos de compilação e teste
  - 5: implementou alguns arquivos e procedimentos de compilação e teste (com alguma documentação) 
  - 15: Ampla implementação e documentação de arquivos e procedimentos de compilação e teste (com exemplos)
 
 # Total
 
 **125 / 150 ** pontos (sem bônus)
 
 **125 / 200 ** pontos (com bônus)
