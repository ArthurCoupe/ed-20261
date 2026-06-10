#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "selecao.h"

#define tamanho 100

int main(){

    //gera vetor de tamanho (tamanho)
    int *vetor = (int *)malloc(tamanho * sizeof(int));
    for(int i = 0; i <=tamanho; i++){
        vetor[i] = rand() % tamanho;
        //printf("%i, ", vetor[i]);
    }
    printf("primeiro = %i, ultimo = %i\n", vetor[0], vetor[tamanho -1]);

    int valor;

    printf("Entre com um numero para buscar : ");
    scanf("%i", &valor);

    clock_t inicio = clock();
    int achou = linear_search(vetor, tamanho, valor);
    clock_t final = clock();

    double duracao = (double)(final - inicio)/ CLOCKS_PER_SEC;


    printf("A busca pelo valor %i resultou em %i\n", valor, achou);
    printf("Demorou %fs\n", duracao);

    int *vet = (int *)malloc(tamanho * sizeof(int));
    for(int i = 0; i <=tamanho; i++){
        vet[i] = rand() % tamanho;
        printf("%i, ", vetor[i]);
    }
    printf("\n");
    printf("primeiro = %i, ultimo = %i\n", vet[0], vetor[tamanho -1]);

    printf("Entre com um numero para buscar : ");
    scanf("%i", &valor);

    inicio = clock();
    achou = quick_select(vetor, 0, tamanho -1, valor);
    final = clock();

    duracao = (double)(final - inicio)/ CLOCKS_PER_SEC;

    printf("A busca pelo valor %i resultou em %i\n", valor, achou);
    printf("Demorou %fs\n", duracao);

    return 0;
}