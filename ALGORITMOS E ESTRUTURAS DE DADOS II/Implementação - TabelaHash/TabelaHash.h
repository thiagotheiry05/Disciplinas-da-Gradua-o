#pragma once
#include <vector>
#include<iostream>
using namespace std;

template <typename K, typename V>
class Tupla {
private:
	K chave;
	V valor;
	Tupla* prox;
public:
	Tupla(K c, V v) {
		chave = c;
		valor = v;
		prox = NULL;
	}

	K getChave() {
		return chave;
	}

	V getValor() {
		return valor;
	}

	Tupla* getProx() {
		return prox;
	}

	void setProx(Tupla* prox) {
		Tupla::prox = prox;
	}
};

template <typename Chave, typename Valor>
class TabelaHash2 {

private:
	Tupla<Chave, Valor>** tabela;

	//tamanho atual do array
	int qtdeBuckets;
	//qtdade de elementos já inseridos na tabela hash
	int qtdadeElementos;

	// funcao auxiliar para obter o valor hash
	int PosicaoDaChave(Chave chave) {
		hash<string> hash_string;
		int hash = hash_string(chave);

		return abs(hash) % qtdeBuckets;
	}
	/**
	* Função para inserir a tupla <c,v> na tabela.
	* 1) É preciso calcular o código hash a partir da chave c.
	* 2) Depois, usamos qtdeBuckets para descobrir o índice
	* dessa tupla, usando a operacao de modulo.
	* 3) Preste atenção na alocação de tupla quando há colisões.
	* 4) A função hash às vezes retorna valores negativos: use abs()
	* para evitar índices negativos.
	* 5) Como a implementacao eh in-place, se novoElemento for false,
	* o que indica que estamos reposicionando um elemento devido
	* ao aumento do array, podemos nos deparar com duas situações:
	*     Situação 1: o elemento foi mapeado para o mesmo bucket,
	*                 independente da mudança do array. Nesse caso,
	*                 não precisamos inseri-lo em um novo bucket.
	*     Situação 2: o elemento foi mapeado para outro bucket.
	*                 Nesse caso, precisamos inseri-lo em um novo
	*                 bucket.
	* IMPORTANTE: o retorno dessa funcao indica se um elemento
	*             foi reposicionado para um novo bucket. Esse valor
	*			  será utilizado na função para aumento do tamanho
	*			  do array. Perceba que esse retorno não é útil
	*			  para a função pública inserir(Chave c, Valor v)
	**/
	bool inserir(Chave c, Valor v, bool novoElemento) {

		int posicao = PosicaoDaChave(c);

		Tupla<Chave, Valor>* entrada = new Tupla<Chave, Valor>(c, v);

		if (tabela[posicao] == NULL) {
			tabela[posicao] = entrada;
		}
		else {
			Tupla<Chave, Valor>* entradas = tabela[posicao];

			while (entradas->getProx() != NULL) {
				entradas = entradas->getProx();
			}
			entradas->setProx(entrada);
		}
		return novoElemento;
	}

	/**
	* Função para aumentar o tamanho do array
	* 1) O tamanho do array (qtdeBuckets) deve ser multiplicado
	* por 8 para que essa operação seja feita com pouca frequência.
	* 2) Reposicionar as tuplas, considerando que:
	*     2.1) mesmo mudando de tamanho, ela pode permanecer no
	*	 mesmo bucket (posicao do array).
	*	 2.2) caso ela mude de posição, atente para a situação
	*		  da lista ligada, especialmente quando há colisões:
	*		2.2.1) esse elemento é o primeiro da lista ligada?
	*		talvez o ponteiro que fica no array precise ser
	*		atualizado (para NULL, caso seja o único do bucket,
	*		ou para o elemento posterior, caso contrário)
	*		2.2.2) esse elemento está no meio da lista ligada?
	*		ajuste o ponteiro prox do elemento anterior ao elemento
	*		removido
	*	Dica: você precisará navegar com 2 variáveis auxiliares,
	*		  de modo que uma esteja sempre apontando para o
	*		  elemento anterior.
	* 3) Não se esqueça de desalocar (delete) as tuplas que
	* você está inserindo em uma nova posição do array.
	**/
	void aumentaArray() {

		qtdeBuckets *= 8;
		tabela = (Tupla<Chave, Valor>**)realloc(tabela, sizeof(Tupla<Chave, Valor>*) * qtdeBuckets);

		for (int i = qtdeBuckets / 8; i < qtdeBuckets; i++) {
			tabela[i] = NULL;
		}

		for (int i = 0; i < qtdeBuckets / 8; i++) {

			Tupla<Chave, Valor>* item = tabela[i];
			if (item != NULL) {

				int valorhash = PosicaoDaChave(item->getChave());

				if (i != valorhash) {

					if (item->getProx() == NULL) {
						inserir(item->getChave(), item->getValor(), false);
						tabela[i] = NULL;
					}
					else {
						Tupla<Chave, Valor>* anterior = tabela[i];
						Tupla<Chave, Valor>* atual = anterior->getProx();

						while (atual->getProx() != NULL) {
							valorhash = PosicaoDaChave(atual->getChave());

							if (i != valorhash) {
								anterior->setProx(atual->getProx());
								inserir(atual->getChave(), atual->getValor(), false);
								free(atual);
								atual = anterior->getProx();
							}
							else {
								anterior = atual;
								atual = atual->getProx();
							}

						}
						valorhash = PosicaoDaChave(atual->getChave());

						if (i != valorhash) {
							anterior->setProx(atual->getProx());
							inserir(atual->getChave(), atual->getValor(), false);
							delete atual;
							atual = anterior->getProx();
						}
						atual = tabela[i]->getProx();
						inserir(tabela[i]->getChave(), tabela[i]->getValor(), false);
						tabela[i] = atual;
					}

				}
				else {

					if (item->getProx() != NULL) {
						Tupla<Chave, Valor>* anterior = tabela[i];
						Tupla<Chave, Valor>* atual = anterior->getProx();

						while (atual->getProx() != NULL) {
							valorhash = PosicaoDaChave(atual->getChave());

							if (i != valorhash) {
								anterior->setProx(atual->getProx());
								inserir(atual->getChave(), atual->getValor(), false);
								free(atual);
								atual = anterior->getProx();

							}
							else {
								anterior = atual;
								atual = atual->getProx();
							}

						}
						valorhash = PosicaoDaChave(atual->getChave());

						if (i != valorhash) {
							anterior->setProx(atual->getProx());
							inserir(atual->getChave(), atual->getValor(), false);
							delete atual;
							atual = anterior->getProx();
						}


					}

				}
			}
		}
	}

public:

	/**
	* Construtor
	* 1) Inicializar o array de tuplas com qtdeBuckets=8.
	* 2) Lembrar de setar todas as posições do vetor inicializado
	*    para NULL.
	* 3) Alocar o vetor no C-Style (calloc), para que depois
	*    consigamos usar a função realloc para trabalhar com
	*    o tamanho do vetor completamente in-place.
	**/
	TabelaHash2() {

		qtdeBuckets = 8;
		qtdadeElementos = 0;
		tabela = (Tupla<Chave, Valor>**)calloc(qtdeBuckets, sizeof(Tupla<Chave, Valor>*));
		for (int i = 0; i < qtdeBuckets; i++) {
			tabela[i] = NULL;
		}
	}

	/**
	* Essa é a função pública que nos permite inserir
	* uma tupla <c,v> na tabela.
	* 1) Aumentamos o array caso o load_factor >=1.
	* 2) Essa função pode reusar sua versão
	* sobrecarregada para inserir a tupla na tabela.
	* 3) Essa função também incrementa a quantidade de elementos
	* na tabela (variável qtdadeElementos).
	**/
	void inserir(Chave c, Valor v) {

		double fator_de_carga = load_factor();

		if (fator_de_carga >= 1) aumentaArray();

		inserir(c, v, true);
		qtdadeElementos++;
	}

	/**
	* Essa função retorna o fator de carga da Tabela Hash.
	**/
	double load_factor() {
		return (double)qtdadeElementos / qtdeBuckets;
	}

	/**
	* Há apenas um valor associado a uma chave.
	* Essa função retorna esse valor, caso a chave exista.
	* Se a chave não existir a função retorna NULL.
	* Lembre-se: em caso de colisão, é preciso navegar
	* no bucket (lista ligada) para ter certeza se a chave
	* existe ou não.
	**/
	Valor getValor(Chave chave) {

		int posicao = PosicaoDaChave(chave);
		Tupla<Chave, Valor>* entradas = tabela[posicao];

		if (entradas != NULL) {
			while (entradas->getChave() != chave && entradas->getProx() != NULL) {
				entradas = entradas->getProx();
			}
			return entradas->getValor();
		}
		return NULL;
	}

	/**
	* Essa função retorna true caso a chave exista,
	* false caso contrário.
	* Lembre-se: em caso de colisão, é preciso navegar
	* no bucket (lista ligada) para ter certeza se a chave
	* existe ou não.
	**/
	bool contemChave(Chave chave) {

		int posicao = PosicaoDaChave(chave);
		Tupla<Chave, Valor>* entradas = tabela[posicao];

		if (entradas != NULL) {
			// cout << "chave: " << entradas->getChave() << endl;
			while (entradas->getChave() != chave && entradas->getProx() != NULL) {
				entradas = entradas->getProx();
			}
			return true;
		}
	}

	vector<Chave> getChaves() {

		vector<Chave> vec;
		for (int i = 0; i < qtdeBuckets; i++) {
			Tupla<Chave, Valor>* entradas = tabela[i];

			if (entradas != NULL) {
				while (entradas != NULL) {
					vec.push_back(entradas->getChave());

					entradas = entradas->getProx();
				}
			}
		}
		return vec;
	}

	/**
	* Essa função desaloca os nós previamente alocados, e muda
	* o tamanho do array de tuplas para 8.
	**/
	void clear() {
		for (int i = 0; i < qtdeBuckets; i++) {
			Tupla<Chave, Valor>* atual = tabela[i];
			Tupla<Chave, Valor>* aux = NULL;

			if (atual != NULL) {
				while (atual->getProx() != NULL) {
					aux = atual->getProx();
					free(atual);
					atual = aux;
				}
			}
		}

		free(tabela);
		qtdeBuckets = 8;
		qtdadeElementos = 0;
		tabela = (Tupla<Chave, Valor>**)calloc(qtdeBuckets, sizeof(Tupla<Chave, Valor>*));
		for (int i = 0; i < qtdeBuckets; i++) {
			tabela[i] = NULL;
		}
	}

	/**
	* Há apenas um nó associado com uma mesma chave.
	* Essa função remove esse nó da tabela, caso a chave exista.
	* Se a chave não existir a função não faz nada.
	* Lembre-se: em caso de colisão, é preciso navegar
	* no bucket (lista ligada) para ter certeza se a chave
	* existe ou não.
	* Dica: olhar algoritmo de remoção em lista ligada, pois
	* após a remoção de um nó a lista precisa permanecer íntegra,
	* ou seja, navegável.
	**/
	void remover(Chave chave) {

		int posicao = PosicaoDaChave(chave);

		Tupla<Chave, Valor>* atual = tabela[posicao];
		Tupla<Chave, Valor>* anterior = atual;

		while (atual != NULL) {

			if (atual->getChave() == chave) {

				if (atual == anterior) {
					tabela[posicao] = atual->getProx();
				}
				else {
					anterior->setProx(atual->getProx());
				}
				delete atual;
				qtdadeElementos--;
				return;
			}
			else {
				anterior = atual;
				atual = atual->getProx();
			}
		}
	}

	/**
	* Essa função retorna a quantidade de elementos
	* que já foram inseridos na Tabela Hash.
	**/
	int size() {
		return qtdadeElementos;
	}

	/**
	* Essa função retorna o tamanho atual do
	* array usado para armazenar a Tabela Hash.
	**/
	int bucket_count() {
		return qtdeBuckets;
	}
};
