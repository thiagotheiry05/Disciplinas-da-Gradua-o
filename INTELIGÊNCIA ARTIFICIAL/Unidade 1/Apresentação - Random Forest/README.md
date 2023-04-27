# Modelo Random Forest 


### Definição

 * Random Forest é um algoritmo de aprendizado de máquina supervisionado.
 * Usado para problemas de regressão e classificação.
 * Random Forest cria árvores de decisão ao selecionar de forma aleatória amostra de dados, obter as predições para casa árvore e selecionar a solução mais votada.
 * as árvore de decisão individuais são geradas usando um indicador de seleção de atributos tais como ganho de informação, taxa de ganhor e índice Gini para cada atributo.
 * Cada árvore depende de uma amostra aleatória independente.
 * Usando classificação, cada árvore vota em uma classe a mais popular ganha.
 * Usando o caso de regressão é usado a média.
 
### Funcionamento

  Random Forest tem 4 etapas:
 
    1. Seleciona aleatoriamente amostra de um determinado dado.
    2. Constrói uma árvore de decisão para casa amostra e obtém a predição de casa árvore.
    3. Realiza a votação para cada resultado predito.
    4. Seleciona o resultado mais votado.
    
  #### Imagens  
  ![image1](https://www.freecodecamp.org/news/content/images/2020/08/how-random-forest-classifier-work.PNG)
  
  ![image2](https://static.javatpoint.com/tutorial/machine-learning/images/random-forest-algorithm2.png)

### Característica Importantes 

  * Bom indicador para seleção das melhores características
  * Esta nota ajudará a escolher as características mais importantes e remover as menos importantes na hora de construir o modelo.
  * Usa a importância de Gini ou diminuição médio em impureza (MDI), para calcular a importância de cada características.
  * Gini é conhecido como a diminuição total na impureza do nó.
  * Quanto maior a diminuição, maior será a importância desta característica.

#### Prós e Contras

* Prós
   - Robusto devido ao números de árvores no processo.
   - Não sofre com problma de overfitting.
   - Pode trabalhar com valores ausentes, usa valores da mediana para substituir.
   - podemos obter a importância das características.

* contras
   - Lento em gerar predições devido ao grande números de árvores
   - Difícil interpretar o modelo.


#### Matriz de confusão do exemplo usado

![image](https://github.com/PabloSanttana/Inteligencia-Artificial-UFRN/blob/master/Unidade_1/RandomForestClassifier/Captura%20de%20Tela%202023-04-26%20%C3%A0s%2021.14.35.png)
