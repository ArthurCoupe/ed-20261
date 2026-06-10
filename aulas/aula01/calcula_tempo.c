#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
    //ligou o cronometro
    clock_t tempo_inicial = clock();

    long int soma = 10 +20; //0(1)

    clock_t tempo_final = clock();
    //desligou o cronometro

    double duracao = (double)(tempo_final - tempo_inicial)/ CLOCKS_PER_SEC;

    printf("o tempo de execucao foi %.10f\n", duracao);

    tempo_inicial = clock();

    for(long int i = 0; i<100000000000L; i++){// 0(n)
        soma = soma + 1;
    }

    tempo_final = clock();
    duracao = (double)(tempo_final - tempo_inicial)/ CLOCKS_PER_SEC;
    printf("o tempo de execucao foi %.10f\n", duracao);

    tempo_inicial = clock();

    for(int i = 0; i<100000; i++){ //0(n^2)
        for(int j =0;j<10000;j++){
        soma = soma + 1;
        }// 0(n)
        
    }

    tempo_final = clock();
    duracao = (double)(tempo_final - tempo_inicial)/ CLOCKS_PER_SEC;
    printf("o tempo de execucao foi %.10f\n", duracao);

    return 0;
}