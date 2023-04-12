#pragma once
#include <iostream>
#include <vector>
using namespace std;

class GrafoListaAdj {
private:
    vector<string> vertices;

    //first � o indice do vertice, second � o peso (caso o grafo seja ponderado)
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
    *       2) toda vez que inserirmos um novo v�rtice, precisaremos
    *          inserir um vetor para representar as conex�es daquele
    *          v�rtice na lista de adjac�ncias
    **/
    void inserirVertice(string rotuloVertice) {
        if (obterIndiceVertice(rotuloVertice) != -1) {
            return;
        }
        else {
            vector<pair<int, int>> vetor;
            vertices.push_back(rotuloVertice);
            arestas.push_back(vetor);
        }
    }

    /**
    * Sempre que o grafo for n�o ponderado, adicionaremos o peso 1,
    * por conveni�ncia.
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
        int posicaoOrigem = obterIndiceVertice(rotuloVOrigem);
        int posicaoDestino = obterIndiceVertice(rotuloVDestino);
        arestas.at(posicaoOrigem).push_back(make_pair(posicaoDestino, peso));
    }

    /**
    * Verifica se v�rtice rotuloVOrigem e v�rtice rotuloVDestino s�o
    * conectados (vizinhos).
    **/
    bool saoConectados(string rotuloVOrigem, string rotuloVDestino) {
        int posicaoOrigem = obterIndiceVertice(rotuloVOrigem);
        int posicaoDestino = obterIndiceVertice(rotuloVDestino);

        for (int i = 0; i < arestas.at(posicaoOrigem).size(); i++) {
            if (arestas.at(posicaoOrigem).at(i).first == posicaoDestino) {
                return true;
            }
        }
        return false;
    }

    vector<string> getVertices() {
        return vertices;
    }

    vector<vector<pair<int, int>>> getArestas() {
        return arestas;
    }
};
