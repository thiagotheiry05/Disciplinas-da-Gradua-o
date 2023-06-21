# Métodos de Busca em Árvore e sua Aplicação na Solução de Problemas

Métodos de busca em árvore são algoritmos utilizados para explorar e encontrar soluções em espaços de busca, representados como uma estrutura em forma de árvore. Esses métodos são amplamente aplicados na solução de problemas em ciência da computação, inteligência artificial e outras áreas.

A busca em árvore consiste em explorar os nós de uma árvore de forma sistemática, seguindo um conjunto de regras ou estratégias. Os dois principais métodos de busca em árvore são a Busca em Largura (BFS) e a Busca em Profundidade (DFS).

A BFS explora os nós em uma camada por vez, expandindo os nós vizinhos antes de passar para a próxima camada. Isso garante que, quando um objetivo é encontrado, seja através de uma busca por soluções ou pela identificação de um caminho específico, o caminho percorrido é o mais curto em termos de número de arestas percorridas.

A DFS, por outro lado, explora um caminho o mais longe possível antes de retroceder. Ela desce profundamente em uma ramificação da árvore até alcançar um nó terminal ou um limite predefinido, para então retroceder e explorar as ramificações restantes.

A DFS tem a vantagem de utilizar menos espaço de memória em comparação com a BFS, pois armazena apenas um caminho completo da raiz até o nó atual. Além disso, a DFS é útil em problemas de busca de soluções onde o objetivo é encontrar uma solução qualquer, mesmo que não seja a mais curta. 

Realizamos uma implementação simples de uma DFS para encontrar o menor caminho entre 2 nós. [Questão 6](https://github.com/thiagotheiry05/Disciplinas-da-Graduacao/blob/main/INTELIG%C3%8ANCIA%20ARTIFICIAL/Unidade%203/Quest%C3%A3o%206/Quest%C3%A3o6_Lista3.ipynb)


