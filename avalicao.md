
# Identificação

* Nome: Yves Pablo Costa Rêgo

* Matrícula: 20210058235


# 1. Compilando, executando e testando o programa Concessionária.

 
## 1.1 Compilação e execução

Os arquivos do GitHub já estão em suas devidas pastas. Para compilar o programa e executar, há duas opções: a compilação/execução normal e a compilação/execução para checar vazamentos de memória.

Para a compilação e execução normal, basta usar os comandos:

```
make
./build/programa
```

e o programa deve ser executado sem erros.

Para a compilação e execução checando vazamentos de memória, é necessário alterar o arquivo Makefile. Nele, deve-se alterar a linha:

```
g++ -Wall -fsanitize=address -Iinclude $(OBJECTS) src/programa.cpp -o build/programa
```

para:

```
g++ -Wall -Iinclude $(OBJECTS) src/programa.cpp -o build/programa
 ```

e, então, executar os comandos:
```
make
valgrind -v --leak-check=full --show-reachable=yes ./build/programa
```

feito isso, o programa será executado verificando possíveis vazamentos de memória e poderá receber as instruções.


## 1.2 Instruções, entradas e comandos

O programa lê uma linha de cada vez, ou seja, cada comando é processado a partir de uma nova linha. Os comandos disponíveis estão listados aqui.

**create-concessionaria:**
Cria uma concessionária, admitindo nome, CNPJ e o número de veículos no estoque como argumentos, nessa ordem. Não é feita validação ou tratamento dos argumentos; certifique-se de inserir os dados corretamente.  
*Sintaxe*:

```
create-concessionaria <nome da concessionária> <CNPJ> <número de veículos>
``` 	

**add-car:**
Adiciona um carro em uma concessionária, admitindo nome da concessionária, preço do veículo, chassi do veículo, ano de fabricação e tipo de motor como argumentos, nessa ordem. O preço é um número real.
O programa impedirá o comando de ser finalizado na(s) seguinte(s) condição(ões): concessionária não encontrada; número de chassi do veículo já cadastrado no programa. O erro será indicado de acordo com o problema ocorrido.  
*Sintaxe*:

```
add-car <nome da concessionária> <marca> <preço> <chassi> <ano de fabricação> <tipo de motor>
``` 	

**add-bike:**
Adiciona uma moto em uma concessionária, admitindo nome da concessionária, preço do veículo, chassi do veículo, ano de fabricação e modelo como argumentos, nessa ordem. O preço é um número real.
O programa impedirá o comando de ser finalizado na(s) seguinte(s) condição(ões): concessionária não encontrada; número de chassi do veículo já cadastrado no programa. O erro será indicado de acordo com o problema ocorrido.  
*Sintaxe*:

```
add-bike <nome da concessionária> <marca> <preço> <chassi> <ano de fabricação> <modelo>
``` 	

**add-truck:**
Adiciona um caminhão em uma concessionária, admitindo nome da concessionária, preço do veículo, chassi do veículo, ano de fabricação e tipo de carga como argumentos, nessa ordem. O preço é um número real.
O programa impedirá o comando de ser finalizado na(s) seguinte(s) condição(ões): concessionária não encontrada; número de chassi do veículo já cadastrado no programa. O erro será indicado de acordo com o problema ocorrido.  
*Sintaxe*:

```
add-truck <nome da concessionária> <marca> <preço> <chassi> <ano de fabricação> <tipo de carga>
``` 	

**remove-vehicle:**
Remove um veículo do programa, admitindo o chassi do veículo como argumento.
O programa impedirá o comando de ser finalizado na(s) seguinte(s) condição(ões): número de chassi não encontrado. O erro será indicado de acordo com o problema ocorrido.  
*Sintaxe*:

```
remove-vehicle <chassi>
``` 	


**search-vehicle:**
Busca um veículo no programa, admitindo o chassi do veículo como argumento. A busca retornará uma lista de informações sobre o veículo: concessionária a que pertence, marca, preço, chassi, ano de fabricação e atributo especial (ex: modelo, para uma Moto). 
O programa impedirá o comando de ser finalizado na(s) seguinte(s) condição(ões): número de chassi não encontrado. O erro será indicado de acordo com o problema ocorrido.  
*Sintaxe*:

```
search-vehicle <chassi>
``` 	

**list-concessionaria:**
Busca uma concessionária no programa, admitindo o nome da concessionoária como argumento. A busca retornará uma lista de informações sobre a concessionária: nome, quantidade de veículos cadastrados para cada tipo e seus preços totais acumulados, e o valor total de veículos para a concessionária.
O programa impedirá o comando de ser finalizado na(s) seguinte(s) condição(ões): nome de concessionária não encontrado. O erro será indicado de acordo com o problema ocorrido.  
*Sintaxe*:

```
list-concessionaria <nome da concessionária>
``` 	


**raise-price:**
Aumenta os preços dos veículos em uma concessionária, admitindo, como argumento, o nome da concessionária e um número real representando uma porcentagem. Os preços dos carros, motos e caminhões na concessionária serão aumentados em \[X, 2X, 3X\]\% respectivamente, onde X é o número digitado.
O programa impedirá o comando de ser finalizado na(s) seguinte(s) condição(ões): nome de concessionária não encontrado. O erro será indicado de acordo com o problema ocorrido.  
*Sintaxe*:

```
raise-price <nome da concessionária> <porcentagem>
``` 	

# 1.3 Roteiro para execução
Aqui, consta uma sugestão de roteiro para testar o programa. 

```
make
./build/programa
create-concessionaria IMD_SA 11.111.111/0001-11 0
add-car IMD_SA Toyota 100000 9BRBLWHEXG0107721 2019 gasolina
add-bike IMD_SA Yamaha 23500 3BRBLJUEXG0308234 2022 BWS50
add-truck IMD_SA Scania 700000 7BRBLQHEXG0208811 2010 perigosa
add-car IMD_SA Toyota 100000 9BRBLWHEXG0107721 2019 gasolina
search-vehicle 9BRBLWHEXG0107721
remove-vehicle 9BRBLWHEXG0107721
search-vehicle 9BRBLWHEXG0107721
create-concessionaria UFRN_SA 12.345.678/9101-23 0
add-car UFRN_SA Toyota 100000 9BRBLWHEXG0107721 2019 gasolina
add-truck UFRN_SA Hyundai 80000 7BRBLQHEXG0208811 2015 comum
add-truck IFRN_SA Hyundai 80000 7BRBLQHEXG0208811 2015 comum
list-concessionaria IMD_SA
list-concessionaria UFRN_SA
raise-price IMD_SA 10
list-concessionaria IMD_SA
quit
```

Nesse roteiro, são criadas duas concessionárias. Na primeira delas, cadastra-se um veículo para cada tipo. Então, tenta-se cadastrar um dos veículos novamente - o código deve impedir isso e apontar um erro. Após isso, busca-se um veículo, remove-se ele e se realiza a mesma busca, o que também deve ser impedido e indicado. Na segunda concessionária criada, tenta-se adicionar, mais uma vez, um veículo já criado, mas de outra concessionária; espera-se uma mensagem de erro. Ainda, tenta-se adicionar o veículo em uma concessionária não existente. Depois, as concessionárias são listadas e a primeira tem seus preços aumentados, o que deve ser refletido quando ela é listada novamente.


# 2. Limitações

* a descrição das limitações (caso existam) do programa e quaisquer dificuldades encontradas


* 1. **A utilização de recursos novos foi árdua.**
	  * Detalhes: criou-se um único container para armazenar todos os veículos de uma concessionária. Para conseguir utilizar polimorfismo e evitar vazamentos de memória, utilizou-se o ponteiro inteligente shared_ptr. Assim, por se estar lidando com um conceito relativamente novo, algumas implementações ou *Sintaxe*s se mostraram confusas. Além disso, o algoritmo de accumulate se provou mais complicado do que o esperado, uma vez que se estava trabalhando com mapas.

	
* 2. **Foi difícil visualizar a implementação de certas partes do exercício.**
	  * Detalhes: um exemplo de dificuldade nesse quesito foi na busca de veículos. A busca é realizada por um chassi, que, inicialmente, seria um atributo de um veículo; no entanto, houve complicações.
    A principal delas é que não foi fácil visualizar como obter um chassi a partir das múltiplas camadas em que ele estaria inserido - chassi seria um atributo (ou um método, considerando gets) pertencente a um objeto Veículo, que estaria em um vetor de Veículos; por sua vez, o vetor de Veículos estaria dentro de uma Concessionária, inserida em um vetor de Concessionárias.
    O acesso a um chassi através de tantas "subdivisões" se mostrou confuso, e o mesmo se aplicaria à outras funções. Uma solução parcial para tal foi utilizar mapas no lugar de vetores; desse modo, chassis virariam chaves, que facilitariam encontrar veículos.
    Embora essa alternativa tenha se mostrado eficaz, algumas questões ainda ficaram abertas: chassi ainda deveria ser um atributo de Veículo, mesmo que um determinado chassi já funcionasse como chave para um Veículo? No fim, para o código, isso foi necessário, mas restaram dúvidas sobre qual seria a implementação eficiente para o problema. 
   
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

- Implementação e uso do comando para busca de veículos `search-vehicle` | **15 / 15 - Bônus: 20**
  - 0: não implementado
  - 15: implementado e funcional
  - bonus +10: implementado com estratégia de busca diferente da busca exaustiva
  - bonus +10: uso de métodos virtuais para impressão na tela
  - bonus +10: uso de sobrecarga de operadores para impressão na tela

- Implementação e uso do comando `list-concessionaria` | **10 / 10 - Bônus: 10**
  - 0: não implementado
  - 10: implementado e funcional   
  - bonus +10: uso de sobrecarga de operadores para impressão na tela

- Implementação e uso do comando `raise-price` | **10 / 10 - Bônus: 10**
  - 0: não implementado
  - 10: implementado e funcional 
  - bonus +10: implementado com uso de método virtual

- Implementação e uso do comando `save-concessionaria` e `load-concessionaria` | **0 / 30**
  - 0: não implementado
  - 15: ambos os comandos implementados e funcionais
  
- Implementação eficiente através do uso de referencias e contêineres da STL | **10 / 10**
  - 0: não usou contêiner da STL nem fez uso eficiente dos recursos computacionais
  - 5: usou contêiner da STL mas não otimizou uso dos recursos computacionais
  - 10: usou contêiner da STL junto a algoritmos e práticas de bom uso de recursos computacionais
  
- Organização do código em src, include, data | **5 / 5**
  - 0: não organizou o código
  - 5: organizou o código 
  
- Documentação do código | **5 / 5**
  - 0: não documentou o código
  - 5: documentou o código 
  
- Implementação e documentação de arquivos e procedimentos de compilação e teste | **15 / 15**
  - 0: não implementou arquivos e procedimentos de compilação e teste
  - 5: implementou alguns arquivos e procedimentos de compilação e teste (com alguma documentação) 
  - 15: Ampla implementação e documentação de arquivos e procedimentos de compilação e teste (com exemplos)
 
 # Total
 
 **120 / 150 ** pontos (sem bônus)
 
 **160 / 200 ** pontos (com bônus)
