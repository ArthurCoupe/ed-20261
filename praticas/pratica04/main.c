#include <stdio.h>
#include "ordenacao.h"
#include <stdlib.h>
#include <time.h>

#define tamanho 100

int main(){

    

    int vetor [tamanho] ;
    for(int i = 0; i < tamanho; i++){
        vetor[i] = rand()%100;
    }

    printf("antes de ordenar\n");
    imprimir_vetor(vetor, tamanho);

    clock_t inicio = clock();
    bubble_sort(vetor, tamanho);
    clock_t termino = clock();

    double duracao = (double)(termino - inicio)/ CLOCKS_PER_SEC;

    printf("depois de ordenar em %fs\n", duracao);
    int vet [tamanho] ;
    for(int i = 0; i < tamanho; i++){
        vet[i] = rand()%100;
    }

    imprimir_vetor(vet, tamanho);
    printf("depois de ordenar em %fs\n", duracao);

    printf("antes de ordenar\n");
    //imprimir_vetor(vetor, tamanho);

    inicio = clock();
    quick_sort(vetor,0 , tamanho -1); //O(n log n)
    termino = clock();

    duracao = (double)(termino - inicio)/ CLOCKS_PER_SEC;

    printf("depois de ordenar em %fs\n", duracao);

    imprimir_vetor(vet, tamanho);
    printf("depois de ordenar em %fs\n", duracao);