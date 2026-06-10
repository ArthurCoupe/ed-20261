#include <stdio.h>
#include "ordenacao.h"
#include <stdlib.h>
#include <time.h>

#define tamanho 100000

int main(){

    

    int vetor [tamanho] ;
    for(int i = 0; i < tamanho; i++){
        vetor[i] = rand()%100;
    }

    printf("antes de ordenar\n");

    clock_t inicio = clock();
    bubble_sort(vetor, tamanho);
    clock_t termino = clock();

    double duracao = (double)(termino - inicio)/ CLOCKS_PER_SEC;

    printf("depois de ordenar em %fs\n", duracao);

    return 0;
}