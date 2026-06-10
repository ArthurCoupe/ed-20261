#ifndef FILA_H
#define FILA_H

typedef struct No{
    int dado;
    struct No *proximo;
} No;

typedef struct Fila {
    No *primeiro;
    No *ultimo;
    int quantidade;
} Fila;

Fila *criar();
void enfileirar(Fila *fila, int valor); //enqueue
void desenfileirar(Fila *fila); //dequeue
void destruir(Fila *fila);
int fila_vazia(Fila *fila);

#endif