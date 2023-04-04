#pragma once

#include <stdlib.h>
#include <stdio.h>

struct no {
    struct no* ant;
    int val;
    struct no* prox;
};

struct doublylinkedlist {
    struct no* cabeca;
    struct no* cauda;
    int qtdade;
};

struct doublylinkedlist* inicializar() {
    struct doublylinkedlist* lista = (struct doublylinkedlist*)malloc(sizeof(struct doublylinkedlist));
    lista->cabeca = NULL;
    lista->cauda = NULL;
    lista->qtdade = NULL;
    return lista;
}

struct no* alocarNovoNo(int valor) {
    struct no* newNo = (struct no*)malloc(sizeof(struct no));
    newNo->val = valor;
    newNo->ant = NULL;
    newNo->prox = NULL;

    return newNo;
}

void inserirElementoNoInicio(struct doublylinkedlist* lista, int valor) {
    if (lista->cabeca != NULL) {
        struct no* novovalor = alocarNovoNo(valor);
        novovalor->prox = lista->cabeca;
        novovalor->ant = lista->cauda;
        lista->cabeca = novovalor;
    }

    else {
        lista->cabeca = alocarNovoNo(valor); 
        lista->cauda = lista->cabeca; 
    }
    lista->qtdade++; 

}

void inserirElementoNoFim(struct doublylinkedlist* lista, int valor) {
    if (lista->cabeca != NULL) {
        struct no* novovalor = alocarNovoNo(valor);
        struct no* temporario = lista->cauda;
        novovalor->ant = temporario;
        temporario->prox = novovalor;
        lista->cauda = novovalor;

    }
    else {
        lista->cabeca = alocarNovoNo(valor);
        lista->cauda = lista->cabeca;

    }

    lista->qtdade++;
}

void inserirElementoEmPosicao(struct doublylinkedlist* lista, int valor, int posicao) {
    if (posicao > 0 && posicao < lista->qtdade) {
        struct no* novovalor = lista->cabeca;
        struct no* temporario = NULL;

        for (int i = 1; i < posicao; i++) {
            novovalor = novovalor->prox;
        }

        temporario = alocarNovoNo(valor);
        temporario->prox = novovalor->prox;
        novovalor->prox->ant = temporario;
        novovalor->prox = temporario;
        lista->qtdade++;
    }
    else if (posicao == 0) {
        inserirElementoNoInicio(lista, valor);
    }
    else if (posicao == lista->qtdade) {
        inserirElementoNoFim(lista, valor);
    }
}

int obterElementoEmPosicao(struct doublylinkedlist* lista, int posicao) {
    if (posicao >= 0 && posicao < lista->qtdade) {

        struct no* novovalor = lista->cabeca;

        for (int i = 0; i < posicao; i++)
        {
            if (novovalor->prox != NULL) {
                novovalor = novovalor->prox;
            }
            else
            {
                return -0;
            }
        }
        return novovalor->val;
    }
}

void removerElementoEmPosicao(struct doublylinkedlist* lista, int posicao) {
    if (lista != NULL) {
        if (posicao > 0 && posicao < lista->qtdade - 1) {

            struct no* novovalor = lista->cabeca;
            struct no* temporario = NULL;
            for (int i = 1; i < posicao; i++) {
                novovalor = novovalor->prox;
            }

            temporario = novovalor->prox;
            novovalor->prox = temporario->prox;
            temporario->prox->ant = novovalor;

            free(temporario);
            lista->qtdade--;

        }
        else if (posicao == 0) {
            if (lista->cabeca->prox != NULL) {
                struct no* novacabeca = lista->cabeca->prox;

                novacabeca->ant = lista->cauda;

                free(lista->cabeca);
                lista->cabeca = novacabeca;
                lista->qtdade--;
            }
            else {
                free(lista->cabeca);
                lista->cabeca = NULL;
                lista->cauda = NULL;
                lista->qtdade--;
            }
        }
        else if (posicao == lista->qtdade - 1) {
            struct no* novacauda = lista->cauda;
            lista->cauda = novacauda->ant;
            lista->cauda->prox = NULL;
            free(novacauda);
            lista->qtdade--;
        }
        else {
            printf("Index invalido \n");

        }

    }
    else
    {
          printf("remocao invalida \n");

    }
}

void imprimirLista(struct no** cabeca) {
    //usamos o aux para percorrer a lista
    if ((*cabeca) != NULL) {
        struct no* aux = (*cabeca);
        //navega partindo da cabeça até chegar NULL
        printf("[");
        do {
            printf("%d", aux->val);
            aux = aux->prox;
            if (aux != NULL) {
                printf(", ");
            }
        } while (aux != NULL);
        printf("]");
    }
    else {
        printf("A lista está vazia!");
    }
}
