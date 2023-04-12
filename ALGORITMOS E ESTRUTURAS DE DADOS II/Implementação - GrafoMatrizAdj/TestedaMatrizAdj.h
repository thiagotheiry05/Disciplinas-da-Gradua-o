#pragma once
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>

struct GrafoMatrizAdj {
    int** arestas;
    char** rotuloVertices;
    int verticesInseridos;
    int maxNumVertices;
};

/**
 * Se o grafo for ponderado, inicializamos cada posicao da matriz com INT_MAX.
 * Se o grafo for n�o ponderado, inicializamos cada posicao da matriz com 0.
 **/
struct GrafoMatrizAdj* inicializar(int numVertices, bool ponderado) {

    int medida = ponderado ? INT_MAX : 0;
    GrafoMatrizAdj* grafo = (GrafoMatrizAdj*)malloc(sizeof(GrafoMatrizAdj));
    grafo->arestas = (int**)calloc(numVertices, sizeof(int*));
    grafo->rotuloVertices = (char**)calloc(numVertices, sizeof(char*));

    for (int i = 0; i < numVertices; i++) {
        grafo->arestas[i] = (int*)calloc(numVertices, sizeof(int));

        for (int j = 0; j < numVertices; j++) {
            grafo->arestas[i][j] = medida;
        }
    }
    
    grafo->verticesInseridos = 0;
    grafo->maxNumVertices = numVertices;
    return grafo;
}


/**
 * A principio nao temos nenhuma ordenacao usando os rotulos.
 * Portanto, usaremos busca linear
 **/
int obterIndiceVertice(struct GrafoMatrizAdj* grafo, char* rotuloVertice) {
    for (int i = 0; i < grafo->maxNumVertices; i++) {
        if (strcmp(grafo->rotuloVertices[i], rotuloVertice) == 0) {
            return i;
        }
    }
    return -1;
}

/**
 * Se o grafo for ponderado, usamos a variavel peso para especificar o peso da aresta.
 * Se o grafo for n�o ponderado, passaremos o valor 1 para a variavel peso, de modo que represente exist�ncia da aresta.
 * Se um dos rotulos dos vertices nao existir, simplesmente nao faremos nada.
 **/
void inserirAresta(struct GrafoMatrizAdj*grafo, char* rotuloVOrigem, char* rotuloVDestino, int peso) {
    int PosicaoOrigem = obterIndiceVertice(grafo, rotuloVOrigem);
    int PosicaoDestino = obterIndiceVertice(grafo, rotuloVDestino);
    grafo->arestas[PosicaoOrigem][PosicaoDestino] = peso;
}

/**
 * Usamos a variavel grafo->verticesInseridos para controlar a quantidade de vertices que ja foi inserido no grafo.
 * Logo, ela pode/deve ser usada para especificar em qual posicao o vertice a ser inserido sera alocado.
 **/
void inserirVertice(struct GrafoMatrizAdj*grafo, char* rotuloVertice) {
    grafo->rotuloVertices[grafo->verticesInseridos] = rotuloVertice;
    grafo->verticesInseridos++;
}

/**
 * Tomar cuidado com as diferen�as sem�nticas entre haver conex�o entre dois vertices em um grafo ponderado,
 * e haver conex�o entre dois vertices em um grafo nao-ponderado.
 **/
bool saoConectados(struct GrafoMatrizAdj* grafo, char* rotuloVOrigem, char* rotuloVDestino) {
    int PosicaoOrigem = obterIndiceVertice(grafo, rotuloVOrigem);
    int PosicaoDestino = obterIndiceVertice(grafo, rotuloVDestino);

    if (PosicaoOrigem != -1 && PosicaoDestino != -1) {
        if (grafo->arestas[PosicaoOrigem][PosicaoDestino] > 0) {
            return true;
        }
        else {
            return false;
        }
    }
    return false; 
}
