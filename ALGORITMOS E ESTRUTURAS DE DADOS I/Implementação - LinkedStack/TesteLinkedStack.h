#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct no {
    int val;
    struct no* prox;
};

struct linkedstack {
    struct no* topo;
    int qtdade;
};

struct linkedstack* inicializar() {
    struct linkedstack* pilha = (struct linkedstack*)malloc(sizeof(struct linkedstack));
    pilha->topo = NULL;
    pilha->qtdade = 0;
    return pilha;
}

struct no* alocarNovoNo(int valor) {
    struct no* novoNo = (struct no*)malloc(sizeof(struct no));
    novoNo->val = valor;
    novoNo->prox = NULL;
    return novoNo;
}

//retornar true se a pilha for nula ou vazia
bool vazia(struct linkedstack* pilha) {
    if (pilha != NULL) {
        if (pilha->topo != NULL) {
            return false;
        }
        else {
            return true;
        }
    }
    else
    {
        return true;
    }
}

//se a pilha estiver nula, instancie a pilha
//por causa da possibilidade de instanciacao usamos struct linkedstack**
void empilhar(struct linkedstack** pilha, int valor) {
    if ((*pilha) == NULL) {
        (*pilha) = inicializar();
    }
    if ((*pilha)->topo != NULL) {
        struct no* novovalor = alocarNovoNo(valor);
        novovalor->prox = (*pilha)->topo;
        (*pilha)->topo = novovalor;
    }
    else
    {
        (*pilha)->topo = alocarNovoNo(valor);
    }
    (*pilha)->qtdade++;

}

//decrementar qtdade se a pilha não estiver nula ou vazia
void desempilhar(struct linkedstack* pilha) {
    if (pilha != NULL) {
        if (pilha->qtdade > 0) {
            if (pilha->topo->prox == NULL) {
                free(pilha->topo);
                pilha->topo = NULL;
            }
            else {
                struct no* novovalor = NULL;
                novovalor = pilha->topo->prox;
                free(pilha->topo);
                pilha->topo = novovalor;
            }

            pilha->qtdade--;
        }
        else
        {
            printf("pilha esta vazia \n");
        }

    }
    else
    {
        printf("pilha esta vazia \n");
    }
}

//retorne a constante INT_MIN se a pilha for nula ou vazia
int desempilharRetornando(struct linkedstack* pilha) {
    if (pilha != NULL) {
        if (pilha->topo != NULL) {
            int aux = pilha->topo->val;
            desempilhar(pilha);
            return aux;
        }
        else
        {
            return INT_MIN;
        }
    }
    else
    {
        return INT_MIN;
    }
}

//retorne a constante INT_MIN se a pilha for nula ou vazia
int topo(struct linkedstack* pilha) {
    if (pilha != NULL) {
        if (pilha->topo != NULL) {
            return pilha->topo->val;
        }
        else
        {
            return INT_MIN;
        }
    }
    else
    {
        return INT_MIN;
    }
}

void exibirPilha(struct linkedstack* pilha) {
    //usamos o aux para percorrer a lista
    if (!vazia(pilha)) {
        struct no* aux = pilha->topo;
        //navega partindo do topo até chegar NULL
        printf("_\n");
        do {
            printf("%d\n", aux->val);
            aux = aux->prox;
        } while (aux != NULL);
        printf("_");
    }
    else {
        printf("A pilha está vazia!");
    }
}