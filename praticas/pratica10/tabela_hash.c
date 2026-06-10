#include <stdio.h>
#include <stdlib.h>
#include "tabela_hash.h"

struct no_t {
    int valor;
    struct no_t* proximo;
};

struct hash_t {
    int tamanho;
    struct no_t** tabela;
};

static int calcular_hash(int valor, int tamanho) {
    if (valor < 0) {
        valor = -valor;
    }
    return valor % tamanho;
}

TabelaHash* hash_criar(int tamanho) {
    if (tamanho <= 0) return NULL;
    
    TabelaHash* hash = (TabelaHash*)malloc(sizeof(TabelaHash));
    if (hash != NULL) {
        hash->tamanho = tamanho;
        hash->tabela = (struct no_t**)calloc(tamanho, sizeof(struct no_t*));
        if (hash->tabela == NULL) {
            free(hash);
            return NULL;
        }
    }
    return hash;
}

void hash_inserir(TabelaHash* hash, int valor) {
    if (hash == NULL) return;
    
    int indice = calcular_hash(valor, hash->tamanho);
    struct no_t* novo = (struct no_t*)malloc(sizeof(struct no_t));
    if (novo == NULL) return;
    
    novo->valor = valor;
    novo->proximo = hash->tabela[indice];
    hash->tabela[indice] = novo;
}

int hash_buscar(TabelaHash* hash, int valor) {
    if (hash == NULL) return 0;
    
    int indice = calcular_hash(valor, hash->tamanho);
    struct no_t* atual = hash->tabela[indice];
    
    while (atual != NULL) {
        if (atual->valor == valor) {
            return 1;
        }
        atual = atual->proximo;
    }
    return 0;
}

int hash_remover(TabelaHash* hash, int valor) {
    if (hash == NULL) return 0;
    
    int indice = calcular_hash(valor, hash->tamanho);
    struct no_t* atual = hash->tabela[indice];
    struct no_t* anterior = NULL;
    
    while (atual != NULL) {
        if (atual->valor == valor) {
            if (anterior == NULL) {
                hash->tabela[indice] = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            return 1;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    return 0;
}

int hash_esta_vazia(TabelaHash* hash) {
    if (hash == NULL) return 1;
    
    for (int i = 0; i < hash->tamanho; i++) {
        if (hash->tabela[i] != NULL) {
            return 0;
        }
    }
    return 1;
}

void hash_exibir(TabelaHash* hash) {
    if (hash == NULL) return;
    
    for (int i = 0; i < hash->tamanho; i++) {
        printf("[%d]: ", i);
        struct no_t* atual = hash->tabela[i];
        while (atual != NULL) {
            printf("%d -> ", atual->valor);
            atual = atual->proximo;
        }
        printf("NULL\n");
    }
}

void hash_destruir(TabelaHash* hash) {
    if (hash == NULL) return;
    
    for (int i = 0; i < hash->tamanho; i++) {
        struct no_t* atual = hash->tabela[i];
        while (atual != NULL) {
            struct no_t* aux = atual;
            atual = atual->proximo;
            free(aux);
        }
    }
    free(hash->tabela);
    free(hash);
}