#pragma once
#include <stdlib.h>
#include <stdio.h>

struct no {
    int val;
    struct no* prox;
};

struct linkedlist {
    struct no* cabeca;
    int qtdade;
};

struct linkedlist* inicializar() {
    struct linkedlist* lista = (struct linkedlist*)malloc(sizeof(struct linkedlist));
    lista->cabeca = NULL;
    lista->qtdade = NULL;
    return lista;
}

struct no* alocarNovoNo(int valor) {
    struct no* newNo = (struct no*)malloc(sizeof(struct no));
    newNo->val = valor;
    newNo->prox = NULL;

    return newNo;
}

void inserirElementoNoFim(struct linkedlist* lista, int valor) {
    if (lista->cabeca != NULL) {
        struct no* novovalor = lista->cabeca;
        while (novovalor->prox != NULL) {
            novovalor = novovalor->prox;
        }
        novovalor->prox = alocarNovoNo(valor);
    }
    else {
        lista->cabeca = alocarNovoNo(valor);
    }

    lista->qtdade++;
}


void inserirElementoNoInicio(struct linkedlist* lista, int valor) {
    if (lista->cabeca != NULL) {
        struct no* novovalor = alocarNovoNo(valor);
        novovalor->prox = lista->cabeca;
        lista->cabeca = novovalor;
    }
    else {
        lista->cabeca = alocarNovoNo(valor); 
        }
        lista->qtdade++; 

}

void inserirElementoEmPosicao(struct linkedlist* lista, int valor, int posicao) {
    if (posicao > 0 && posicao < lista->qtdade) {
        struct no* novovalor = lista->cabeca;
        struct no* novalortemp = NULL;

        for (int i = 1; i < posicao; i++) {
            novovalor = novovalor->prox;
        }

        novalortemp = alocarNovoNo(valor);
        novalortemp->prox = novovalor->prox;
        novovalor->prox = novalortemp;
        lista->qtdade++;
    }

    else if(posicao==0) {
        inserirElementoNoInicio(lista, valor); 
    }
    else if (posicao == lista->qtdade) {
        inserirElementoNoFim(lista, valor); 
    }

    else {
        printf("nao foi possivel inserir elemento \n"); 
    }
}

int obterElementoEmPosicao(struct linkedlist* lista, int posicao) {
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

void removerElementoEmPosicao(struct linkedlist* lista, int posicao) {
    if (posicao > 0 && posicao < lista->qtdade - 1) {
        struct no* novovalor = lista->cabeca;
        struct no* novalortemp = NULL;
        for (int i = 1; i < posicao; i++) {
            novovalor = novovalor->prox;
        }
        novalortemp = novovalor->prox;
        novovalor->prox = novalortemp->prox;

        free(novalortemp);
        lista->qtdade--; 
        }
    else if (posicao == 0) {
        struct no* novacabeca = lista->cabeca->prox;
        free(lista->cabeca);
        lista->cabeca = novacabeca; 
        lista->qtdade--;
    }
    else if (posicao == lista->qtdade - 1) {
        struct no* novovalor = lista->cabeca;

        while (novovalor->prox->prox != NULL) {
            novovalor = novovalor->prox;
        }
        free(novovalor->prox);
        novovalor->prox = NULL;
        lista->qtdade--;
    }
    else {
        printf("nao foi possivel remover elemento \n"); 
    }
}

void imprimirLista(struct linkedlist* lista) {
    //usamos o aux para percorrer a lista
    if (lista->cabeca != NULL) {
        struct no* aux = lista->cabeca;
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