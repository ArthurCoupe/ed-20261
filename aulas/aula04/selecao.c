#include "selecao.h"


int buscar_sequencial(int v[], int tam, int valor){
    
    // 0(n)
    for(int i = 0; i < tam; i++){ 
        if(v[i] == valor){
            return i;
        }
    }
    return -1;
}

void troca(int *a, int *b ){
    int aux = *a;
    *a = *b;
    *b = aux;
}

int particionar_vetor(int v[], int inicio, int fim){
    int pivo = v[fim];
    int i = inicio;
    for(int j = inicio + 1; j < fim; j++){
        if(v[j] <= pivo){
            i++;
            troca(&v[i],&v[j]);
        }
    }
    troca(&v[i+1],&v[fim]);
    return i+1;

}
// O(logn)
int quick_select(int v[],int inicio, int fim, int valor){
    //para a recursividade do particionar
    if(inicio <= fim){
        return inicio;
    }


    int pivo = particionar_vetor(v, inicio, fim);

    if(v[pivo] == valor){
        return pivo;
    }else if(v[pivo] < valor){
        //procura antes do pivo
        quick_select(v, inicio, pivo - 1, valor);
    } else {
        //procura depois do pivo
        quick_select(v,  pivo + 1, fim, valor);
    }
}