#include <stdio.h>
#include <time.h>

#define TAM 10

int main() {
    int matriz[TAM][TAM];
    int i, j;
    clock_t inicio, fim;

    // Inicializando matriz
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            matriz[i][j] = i + j;
        }
    }

    // 1ª forma: dois laços
    inicio = clock();
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    fim = clock();

    double tempo1 = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("\nTempo com dois lacos: %f segundos\n\n", tempo1);

    // 2ª forma: um laço
    inicio = clock();
    for (i = 0; i < TAM * TAM; i++) {
        printf("%d ", matriz[i / TAM][i % TAM]);
        if ((i + 1) % TAM == 0)
            printf("\n");
    }
    fim = clock();

    double tempo2 = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("\nTempo com um laco: %f segundos\n", tempo2);

    return 0;
}