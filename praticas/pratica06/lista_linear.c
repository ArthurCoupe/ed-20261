#include <stdio.h>
#include <stdlib.h>
#include "lista_linear.h"

typedef struct no_t {
    struct no_t* anterior;
    int valor;
    struct no_t* proximo;
} No;

struct lista_t {
    No* primeiro;
    No* ultimo;
};

Lista* lista_criar() {
    Lista* nova_lista = (Lista*) malloc(sizeof(Lista));
    if (nova_lista != NULL) {
        nova_lista->primeiro = NULL;
        nova_lista->ultimo = NULL;
    }
    return nova_lista;
}

void lista_inserir(Lista* lista, int valor) {
    if (lista == NULL) return;

    No* novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL) return; // Falha na alocação

    novo_no->valor = valor;
    novo_no->proximo = NULL;
    novo_no->anterior = lista->ultimo;

    if (lista_esta_vazia(lista)) {
        lista->primeiro = novo_no;
    } else {
        lista->ultimo->proximo = novo_no;
    }
    lista->ultimo = novo_no;
}

int lista_remover(Lista* lista, int valor) {
    if (lista == NULL || lista_esta_vazia(lista)) return 0;

    No* atual = lista->primeiro;

    while (atual != NULL) {
        if (atual->valor == valor) {
            if (atual == lista->primeiro) {
                lista->primeiro = atual->proximo;
                if (lista->primeiro != NULL) {
                    lista->primeiro->anterior = NULL;
                } else {
                    lista->ultimo = NULL; 
                }
            } 
            else if (atual == lista->ultimo) {
                lista->ultimo = atual->anterior;
                lista->ultimo->proximo = NULL;
            } 
            else {
                atual->anterior->proximo = atual->proximo;
                atual->proximo->anterior = atual->anterior;
            }

            free(atual);
            return 1;
        }
        atual = atual->proximo;
    }

    return 0;
}

int lista_buscar(Lista* lista, int valor) {
    if (lista == NULL) return 0;

    No* atual = lista->primeiro;
    while (atual != NULL) {
        if (atual->valor == valor) {
            return 1;
        }
        atual = atual->proximo;
    }
    return 0;
}

void lista_exibir(Lista* lista) {
    if (lista == NULL) return;

    if (lista_esta_vazia(lista)) {
        printf("Lista vazia.\n");
        return;
    }

    No* atual = lista->primeiro;
    printf("Lista: ");
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

int lista_esta_vazia(Lista* lista) {
    if (lista == NULL) return 1;
    return (lista->primeiro == NULL) ? 1 : 0;
}

void lista_destruir(Lista* lista) {
    if (lista == NULL) return;

    No* atual = lista->primeiro;
    while (atual != NULL) {
        No* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    free(lista);
}