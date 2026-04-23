#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "ordenacao.h"

int main() {
    int n = 100;
    int v[100], original[100];
    clock_t start, end;
    
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        original[i] = rand() % 1000;
    }

    memcpy(v, original, sizeof(int) * n);
    start = clock();
    bubble_sort(v, n);
    end = clock();
    printf("Bubble Sort: %f s\n", (double)(end - start) / CLOCKS_PER_SEC);

    memcpy(v, original, sizeof(int) * n);
    start = clock();
    selection_sort(v, n);
    end = clock();
    printf("Selection Sort: %f s\n", (double)(end - start) / CLOCKS_PER_SEC);

    memcpy(v, original, sizeof(int) * n);
    start = clock();
    quick_sort(v, 0, n - 1);
    end = clock();
    printf("Quick Sort: %f s\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}