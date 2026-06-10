#include <stdio.h>
#include "ordenacao.h"
#include <stdlib.h>
#include <time.h>

#define tamanho 100000

int main(){

    

    int vetor [tamanho] ;
    for(int i = 0; i < tamanho; i++){
        vetor[i] = rand();
    }

    printf("antes de ordenar\n");
    //imprimir_vetor(vetor, tamanho);

    clock_t inicio = clock();
    quick_sort(vetor,0 , tamanho -1); //O(n log n)
    clock_t termino = clock();

    double duracao = (double)(termino - inicio)/ CLOCKS_PER_SEC;

    printf("depois de ordenar em %fs\n", duracao);

    //imprimir_vetor(vetor, tamanho);
    printf("depois de ordenar em %fs\n", duracao);

    return 0;
}