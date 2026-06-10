#include <stdio.h>
#include "lista_encadeada.h"

int main(){
    ListaEncadeada *lista = criar();

    adicionar_final(lista,50);
    adicionar_final(lista,12);
    adicionar_final(lista,123);
    adicionar_final(lista,5);
    adicionar_final(lista,40);
    adicionar_final(lista,9);
    adicionar_final(lista,2);

    No *no = lista->primeiro;
    while(no !=NULL){
        printf("%i, ", no->dado);
        no= no->proximo;
    } printf("\n");

    no = buscar(lista, 123);
    printf("O valor 123 esta no %p\n", no);

        no = buscar(lista, 1);
    printf("O valor 1 esta no %p\n", no);

    remover(lista, 123);
    remover(lista, 50);
    remover(lista, 2);


    no = lista->primeiro;
    while(no !=NULL){
        printf("%i, ", no->dado);
        no= no->proximo;
    }
    

    return 0;
}