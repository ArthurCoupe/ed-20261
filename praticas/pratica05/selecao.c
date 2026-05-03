#include "selecao.h"

int linear_search(int *v, int n, int chave) {
    int i;
    for (i = 0; i < n; i++) {
        if (v[i] == chave) {
            return i;
        }
    }
    return -1;
}

static int partition(int *v, int inicio, int fim) {
    int pivo = v[fim];
    int i = inicio - 1;
    int j, aux;
    
    for (j = inicio; j < fim; j++) {
        if (v[j] <= pivo) {
            i++;
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
        }
    }
    aux = v[i + 1];
    v[i + 1] = v[fim];
    v[fim] = aux;
    
    return i + 1;
}

int quick_select(int *v, int inicio, int fim, int k) {
    if (inicio <= fim) {
        int pivo_indice = partition(v, inicio, fim);
        
        if (pivo_indice == k) {
            return v[pivo_indice];
        } else if (pivo_indice > k) {
            return quick_select(v, inicio, pivo_indice - 1, k);
        } else {
            return quick_select(v, pivo_indice + 1, fim, k);
        }
    }
    return -1;
}