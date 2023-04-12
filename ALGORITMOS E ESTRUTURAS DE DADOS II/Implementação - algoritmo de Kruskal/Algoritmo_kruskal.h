#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include "stdbool.h"

using namespace std;

class GrafoListaAdj {
private:
    vector<string> vertices;

    //first é o indice do vertice, second é o peso (caso o grafo seja ponderado)
    vector<vector<pair<int, int>>> arestas;

    /**
    * A principio nao temos nenhuma ordenacao usando os rotulos.
    * Portanto, usaremos busca linear.
    **/
    int obterIndiceVertice(string rotuloVertice) {
        for (int i = 0; i < vertices.size(); i++) {
            if (vertices[i] == rotuloVertice) {
                return i;
            }
        }
        return -1;
    }

public:
    /**
    * Lembrem-se:
    *       1) nao podemos inserir vertices com mesmo rotulo
    *       2) toda vez que inserirmos um novo vértice, precisaremos
    *          inserir um vetor para representar as conexões daquele
    *          vértice na lista de adjacências
    **/
    void inserirVertice(string rotuloVertice) {
        if (obterIndiceVertice(rotuloVertice) != -1) {
            return;
        }
        else {
            vector<pair<int, int>> vec;
            vertices.push_back(rotuloVertice);
            arestas.push_back(vec);
        }
    }

    /**
     * Sempre que o grafo for não ponderado, adicionaremos o peso 1,
     * por conveniência.
     **/
    void inserirArestaDirecionada(string rotuloVOrigem, string rotuloVDestino) {
        inserirArestaDirecionada(rotuloVOrigem, rotuloVDestino, 1);
    }

    void inserirArestaNaoDirecionada(string rotuloVOrigem, string rotuloVDestino) {
        inserirArestaDirecionada(rotuloVOrigem, rotuloVDestino, 1);
        inserirArestaDirecionada(rotuloVDestino, rotuloVOrigem, 1);
    }

    void inserirArestaNaoDirecionada(string rotuloVOrigem, string rotuloVDestino, int peso) {
        inserirArestaDirecionada(rotuloVOrigem, rotuloVDestino, peso);
        inserirArestaDirecionada(rotuloVDestino, rotuloVOrigem, peso);
    }

    /**
    * Inserir uma aresta entre rotuloVOrigem e rotuloVDestino com o peso
    * especificado.
    **/
    void inserirArestaDirecionada(string rotuloVOrigem, string rotuloVDestino, int peso) {
        int PosicaoOrigem = obterIndiceVertice(rotuloVOrigem);
        int PosicaoDestino = obterIndiceVertice(rotuloVDestino);

        if (PosicaoOrigem == -1 || PosicaoDestino == -1) {
            return;
        }
        arestas.at(PosicaoOrigem).push_back(make_pair(PosicaoDestino, peso));
    }

    //Grupo do union-find
    class Grupo {
    public:
        int pai;
        int tamanho;
    };

    //encontrar raiz 
    //pode ser com ou sem path compression
    int encontrarRaiz(Grupo* grupos, int i) {
        if (grupos[i].pai == i) {
            return i;
        }
        else {
            return encontrarRaiz(grupos, grupos[i].pai);
        }
    }

    bool mesmoGrupo(Grupo* grupos, int a, int b) {
        return encontrarRaiz(grupos, a) == encontrarRaiz(grupos, b);
    }

    int tamanhoGrupo(Grupo* grupos, int a) {
        return grupos[a].tamanho;
    }

    void unirGrupos(Grupo* grupos, int a, int b) {
        int x = encontrarRaiz(grupos, a);
        int y = encontrarRaiz(grupos, b);

        if (x == y) {
            return;
        }
        else {
            if (grupos[x].tamanho < grupos[y].tamanho) {
                grupos[x].pai = y;
                grupos[y].tamanho += grupos[x].tamanho;
            }
            else {
                grupos[y].pai = x;
                grupos[x].tamanho += grupos[y].tamanho;
            }
        }
    }

    //criei essa classe pra facilitar a ordenacao
    //das arestas com menor peso (que faz parte do
    //algoritmo de Kruskal)
    class Aresta {
    public:
        int origem;
        int destino;
        int peso;
        Aresta(int origem, int destino, int peso)
            : origem(origem), destino(destino), peso(peso)
        {}
    };

    //sobrescrever operator< para que a priority_queue
    //ordene como desejamos
    friend bool operator<(const Aresta& a1, const Aresta& a2) {
        return a1.peso > a2.peso;
    }
    friend bool operator>(const Aresta& a1, const Aresta& a2) {
        return a1.peso < a2.peso;
    }

    //a funcao sera usada para criar uma arvore de espalhamento
    //minimo ou máximo, de acordo com o argumento
    GrafoListaAdj* KruskalMST(bool min) {
        GrafoListaAdj* mst = new GrafoListaAdj();
        for (int i = 0; i < vertices.size(); i++) {
            mst->inserirVertice(vertices[i]);
        }
        Grupo* grupos = (Grupo*)malloc(vertices.size() * sizeof(Grupo));
        for (int i = 0; i < vertices.size(); i++) {
            grupos[i].pai = i;
            grupos[i].tamanho = 1;
        }

        if (min) {
            priority_queue<Aresta, vector<Aresta>, less<vector<Aresta>::value_type>> ArestaComMenorPeso;
            for (int i = 0; i < vertices.size(); i++) {
                for (auto& p : arestas[i]) {
                    ArestaComMenorPeso.push({ i, p.first, p.second });
                }
            }
            while (!ArestaComMenorPeso.empty()) {
                Aresta aresta = ArestaComMenorPeso.top();
                ArestaComMenorPeso.pop();
                if (!mesmoGrupo(grupos, aresta.origem, aresta.destino)) {
                    mst->inserirArestaNaoDirecionada(vertices[aresta.origem], vertices[aresta.destino], aresta.peso);
                    unirGrupos(grupos, aresta.origem, aresta.destino);
                }
            }
        }
        else {
            priority_queue<Aresta, vector<Aresta>, greater<vector<Aresta>::value_type>> ArestaComMaiorPeso;
            for (int i = 0; i < vertices.size(); i++) {
                for (auto& p : arestas[i]) {
                    ArestaComMaiorPeso.push({ i, p.first, p.second });
                }
            }
            while (!ArestaComMaiorPeso.empty()) {
                Aresta aresta = ArestaComMaiorPeso.top();
                ArestaComMaiorPeso.pop();
                if (!mesmoGrupo(grupos, aresta.origem, aresta.destino)) {
                    mst->inserirArestaNaoDirecionada(vertices[aresta.origem], vertices[aresta.destino], aresta.peso);
                    unirGrupos(grupos, aresta.origem, aresta.destino);
                }
            }
        }
        free(grupos);
        return mst;
    }

    /*GrafoListaAdj* KruskalMST() {
        //IMPLEMENTAR
        //instanciamos um novo grafo, que armazenara
        //apenas as arestas da MST
        GrafoListaAdj* mst = new GrafoListaAdj();

        //adicionar vertices
        //inicializar estrutura do union-find (array de grupos)


        //inicializar priority_queue
        priority_queue<Aresta> arestasMenorPeso;
        //adicionar arestas na fila

        //iterar na fila de arestas
            //se os vertices da arestas nao pertencem ao mesmo grupo
            //una-os, e adicione a aresta no MST
        return mst;
    }*/

    vector<string> getVertices() {
        return vertices;
    }

    vector<vector<pair<int, int>>> getArestas() {
        return arestas;
    }
};