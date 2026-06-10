#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

struct no_t {
    struct no_t* esquerda;
    int valor;
    struct no_t* direita;
};

struct arvore_t {
    struct no_t* raiz;
};

Arvore* arvore_criar() {
    Arvore* arvore = (Arvore*)malloc(sizeof(Arvore));
    if (arvore != NULL) {
        arvore->raiz = NULL;
    }
    return arvore;
}

static struct no_t* inserir_no(struct no_t* no, int valor) {
    if (no == NULL) {
        struct no_t* novo = (struct no_t*)malloc(sizeof(struct no_t));
        if (novo != NULL) {
            novo->valor = valor;
            novo->esquerda = NULL;
            novo->direita = NULL;
        }
        return novo;
    }
    if (valor < no->valor) {
        no->esquerda = inserir_no(no->esquerda, valor);
    } else if (valor > no->valor) {
        no->direita = inserir_no(no->direita, valor);
    }
    return no;
}

void arvore_inserir(Arvore* arvore, int valor) {
    if (arvore == NULL) return;
    arvore->raiz = inserir_no(arvore->raiz, valor);
}

static void pre_ordem(struct no_t* no) {
    if (no != NULL) {
        printf("%d ", no->valor);
        pre_ordem(no->esquerda);
        pre_ordem(no->direita);
    }
}

void arvore_exibir_pre_ordem(Arvore* arvore) {
    if (arvore == NULL || arvore->raiz == NULL) return;
    pre_ordem(arvore->raiz);
    printf("\n");
}

static void em_ordem(struct no_t* no) {
    if (no != NULL) {
        em_ordem(no->esquerda);
        printf("%d ", no->valor);
        em_ordem(no->direita);
    }
}

void arvore_exibir_em_ordem(Arvore* arvore) {
    if (arvore == NULL || arvore->raiz == NULL) return;
    em_ordem(arvore->raiz);
    printf("\n");
}

static void pos_ordem(struct no_t* no) {
    if (no != NULL) {
        pos_ordem(no->esquerda);
        pos_ordem(no->direita);
        printf("%d ", no->valor);
    }
}

void arvore_exibir_pos_ordem(Arvore* arvore) {
    if (arvore == NULL || arvore->raiz == NULL) return;
    pos_ordem(arvore->raiz);
    printf("\n");
}

int arvore_esta_vazia(Arvore* arvore) {
    if (arvore == NULL) return 1;
    return (arvore->raiz == NULL);
}

static void destruir_nos(struct no_t* no) {
    if (no != NULL) {
        destruir_nos(no->esquerda);
        destruir_nos(no->direita);
        free(no);
    }
}

void arvore_destruir(Arvore* arvore) {
    if (arvore == NULL) return;
    destruir_nos(arvore->raiz);
    free(arvore);
}