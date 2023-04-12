#pragma once
#include <iostream>
#include <vector>
#include <queue>
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

    /**
    * O argumento indicesVerticesVisitados serve para controlar quais
    * vertices já foram visitados.
    * Lembrando que DFS é uma função recursiva.
    **/
    void dfs(string rotuloVOrigem, bool* indicesVerticesVisitados) {
        int PosicaoOrigem = obterIndiceVertice(rotuloVOrigem);
        
        if (indicesVerticesVisitados[PosicaoOrigem]) {
            return;
        }
        else {
            indicesVerticesVisitados[PosicaoOrigem] = true;
        }

        for (auto x : arestas[PosicaoOrigem]) {
            dfs(vertices.at(x.first), indicesVerticesVisitados);
        }
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

    /**
    * Verifica se vértice rotuloVOrigem e vértice rotuloVDestino são
    * conectados (vizinhos).
    **/
    bool saoConectados(string rotuloVOrigem, string rotuloVDestino) {
        int PosicaoOrigem = obterIndiceVertice(rotuloVOrigem);
        int PosicaoDestino = obterIndiceVertice(rotuloVDestino);

        for (int i = 0; i < arestas.at(PosicaoOrigem).size(); i++) {
            if (arestas.at(PosicaoOrigem).at(i).first == PosicaoDestino) {
                return true;
            }
        }
        return false;
    }

    /**
    * Verifica se há algum caminho entre vértice rotuloVOrigem e
    * vértice rotuloVDestino.
    * A melhor forma de fazer isto é reusando a função dfs.
    **/
    bool haCaminho(string rotuloVOrigem, string rotuloVDestino) {
        bool* visitados = (bool*)malloc(vertices.size() * sizeof(bool));
        int PosicaoOrigem = obterIndiceVertice(rotuloVOrigem);
        int PosicaoDestino = obterIndiceVertice(rotuloVDestino);

        for (int i = 0; i < vertices.size(); i++) {
            visitados[i] = false;
        }

        dfs(rotuloVOrigem, visitados);
        visitados[PosicaoOrigem] = saoConectados(rotuloVOrigem, rotuloVDestino);

        if (visitados[PosicaoDestino]) {
            return true;
        }
        else {
            return false;
        }
    }

    /**
    * Muda os rótulos do vértices dos diferentes componentes para
    * nomes que representam cores.
    * Dica: procura componentes partindo do vértice v0 ou v1, em ordem
    * crescente (mas você pode usar outra ordem se desejar).
    * Retorna a quantidade de componentes.
    * A melhor forma de fazer isto é reusando a função dfs.
    **/
    int colorir() {
        bool* visitados = (bool*)malloc(vertices.size() * sizeof(bool));
        bool* coloridos = (bool*)malloc(vertices.size() * sizeof(bool));
        int cor = 0;

        for (int i = 0; i < vertices.size(); i++) {
            coloridos[i] = false;
        }

        for (int i = 0; i < vertices.size(); i++) {
            if (coloridos[i]) {
                continue;
            }
            for (int j = 0; j < vertices.size(); j++) {
                visitados[j] = false;
            }
            dfs(vertices[i], visitados);

            for (unsigned long j = 0; j < vertices.size(); j++) {
                visitados[j] = false;
            }

            dfs(vertices[i], visitados);

            for (int j = 0; j < vertices.size(); j++) {
                if (visitados[j]) {
                    vertices[j] = vertices[i];
                    coloridos[j] = true;
                }
            }
            cor++;

        }
        return cor;
    }

    /**
    * Usa a abordagem de navegação BFS para listar as distâncias
    * entre o vértice rotuloVOrigem e cada um dos demais vértices.
    * A função BFS consegue listar a menor distância entre um vértice
    * e os demais se o grafo for NÃO-PONDERADO.
    * Retorna um vetor de inteiros com a quantidade de arestas
    * (distância) e o vértice rotuloVOrigem e cada um dos demais vértices.
    * Não é uma função recursiva.
    * É necessário utilizar a ED fila.
    **/
    int* bfs(string rotuloVOrigem) {
        int PosicaoOrigem = obterIndiceVertice(rotuloVOrigem);
        int* distancia = (int*)malloc(sizeof(int) * (vertices.size()));
        bool* visitados = (bool*)malloc(vertices.size() * sizeof(bool));

        if (PosicaoOrigem == -1) {
            return NULL;
        }

        queue<int> visitar;
        visitar.push(PosicaoOrigem);

        for (int i = 0; i < vertices.size(); i++) {
            distancia[i] = false;
            visitados[i] = false;
        }

        visitados[PosicaoOrigem] = true;

        while (!visitar.empty()) {
            int frente = visitar.front();
            visitar.pop();

            for (pair<int, int> v : arestas[frente]) {
                if (!visitados[v.first]) {
                    visitados[v.first] = true;
                    distancia[v.first] = distancia[frente] + 1;
                    visitar.push(v.first);
                }
            }

        }
        return distancia;
    }

    vector<string> getVertices() {
        return vertices;
    }

    vector<vector<pair<int, int>>> getArestas() {
        return arestas;
    }
};