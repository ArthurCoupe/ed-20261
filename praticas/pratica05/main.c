#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "selecao.h"

int main() {
    int n = 100;
    int v[100], original[100];
    clock_t start, end;
    int chave, k, resultado;
    
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        original[i] = rand() % 1000;
    }

    chave = original[50];
    k = 50;

    memcpy(v, original, sizeof(int) * n);
    start = clock();
    resultado = linear_search(v, n, chave);
    end = clock();
    printf("Linear Search: %f s\n", (double)(end - start) / CLOCKS_PER_SEC);

    memcpy(v, original, sizeof(int) * n);
    start = clock();
    resultado = quick_select(v, 0, n - 1, k);
    end = clock();
    printf("Quick Select: %f s\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}