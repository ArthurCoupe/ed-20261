#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct no_t {
    int valor;
    struct no_t* proximo;
};

struct pilha_t {
    struct no_t* topo;
};

Pilha* pilha_criar() {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    if (pilha != NULL) {
        pilha->topo = NULL;
    }
    return pilha;
}

void pilha_empilhar(Pilha* pilha, int valor) {
    if (pilha == NULL) return;
    struct no_t* novo = (struct no_t*)malloc(sizeof(struct no_t));
    if (novo == NULL) return;
    novo->valor = valor;
    novo->proximo = pilha->topo;
    pilha->topo = novo;
}

int pilha_desempilhar(Pilha* pilha) {
    if (pilha == NULL || pilha_esta_vazia(pilha)) return -1;
    struct no_t* aux = pilha->topo;
    int valor = aux->valor;
    pilha->topo = aux->proximo;
    free(aux);
    return valor;
}

int pilha_topo(Pilha* pilha) {
    if (pilha == NULL || pilha_esta_vazia(pilha)) return -1;
    return pilha->topo->valor;
}

int pilha_esta_vazia(Pilha* pilha) {
    if (pilha == NULL) return 1;
    return (pilha->topo == NULL);
}

void pilha_exibir(Pilha* pilha) {
    if (pilha == NULL) return;
    struct no_t* atual = pilha->topo;
    while (atual != NULL) {
        printf("%d\n", atual->valor);
        atual = atual->proximo;
    }
}

void pilha_destruir(Pilha* pilha) {
    if (pilha == NULL) return;
    struct no_t* atual = pilha->topo;
    while (atual != NULL) {
        struct no_t* aux = atual;
        atual = atual->proximo;
        free(aux);
    }
    free(pilha);
}