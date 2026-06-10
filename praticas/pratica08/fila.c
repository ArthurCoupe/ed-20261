#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct no_t {
    int valor;
    struct no_t* proximo;
};

struct fila_t {
    struct no_t* inicio;
    struct no_t* fim;
};

Fila* fila_criar() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    if (fila != NULL) {
        fila->inicio = NULL;
        fila->fim = NULL;
    }
    return fila;
}

void fila_enfileirar(Fila* fila, int valor) {
    if (fila == NULL) return;
    
    struct no_t* novo = (struct no_t*)malloc(sizeof(struct no_t));
    if (novo == NULL) return;
    
    novo->valor = valor;
    novo->proximo = NULL;
    
    if (fila_esta_vazia(fila)) {
        fila->inicio = novo;
    } else {
        fila->fim->proximo = novo;
    }
    fila->fim = novo;
}

int fila_desenfileirar(Fila* fila) {
    if (fila == NULL || fila_esta_vazia(fila)) return -1;
    
    struct no_t* aux = fila->inicio;
    int valor = aux->valor;
    
    fila->inicio = aux->proximo;
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }
    
    free(aux);
    return valor;
}

int fila_inicio(Fila* fila) {
    if (fila == NULL || fila_esta_vazia(fila)) return -1;
    return fila->inicio->valor;
}

int fila_esta_vazia(Fila* fila) {
    if (fila == NULL) return 1;
    return (fila->inicio == NULL);
}

void fila_exibir(Fila* fila) {
    if (fila == NULL) return;
    
    struct no_t* atual = fila->inicio;
    while (atual != NULL) {
        printf("%d\n", atual->valor);
        atual = atual->proximo;
    }
}

void fila_destruir(Fila* fila) {
    if (fila == NULL) return;
    
    struct no_t* atual = fila->inicio;
    while (atual != NULL) {
        struct no_t* aux = atual;
        atual = atual->proximo;
        free(aux);
    }
    free(fila);
}