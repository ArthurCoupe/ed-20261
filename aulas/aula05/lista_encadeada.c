#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

ListaEncadeada *criar(){
    ListaEncadeada *lista = (ListaEncadeada *) malloc(sizeof(ListaEncadeada));

    if(lista != NULL){
    lista ->primeiro = NULL;
    lista ->ultimo = NULL;
    lista->quantidade = 0;
    }
    
    return lista;
}

int lista_vazia(ListaEncadeada *lista){
    return lista != NULL && lista->primeiro == NULL;
}
void destruir(ListaEncadeada *lista){
    free(lista); // so apaga o descritor da lista

}

void adicionar_final(ListaEncadeada *lista, int valor){
    No *no = (No *) malloc(sizeof(No));
    if (no == NULL){
        return;
    }
    no->dado = valor;
    no->proximo = NULL;

    if(lista_vazia(lista)){
        lista->primeiro = no;
        lista->ultimo = no;
    } else {
        lista->ultimo->proximo = no;
        lista->ultimo = no;
    }

    lista->ultimo = no;
    lista->quantidade ++;

}

No *buscar(ListaEncadeada *lista, int valor){
    
    if(lista_vazia(lista)){
        return NULL;
    }

    
    No *no = lista->primeiro;
    while(no != NULL){
        if(no->dado == valor)
        return no;
        no = no->proximo;
    }

    return NULL;

}
void remover(ListaEncadeada *lista, int valor){


    if(lista_vazia(lista)){
        return;
    }

    //apaga o primeiro
    No *no =lista->primeiro;
    if(no->dado == valor){
        lista->primeiro = no->proximo;
        lista->quantidade--;
        free(no);
        return;
    }

    No *anterior = no;

    //remove o do meio
    while(no->proximo != NULL){
        anterior = no;
        no = no->proximo;
        if(no->dado == valor){
            anterior->proximo = no->proximo;
            lista->quantidade--;
            break;
        }
    }

    //apaga o ultimo
    if(no->proximo == NULL && no->dado == valor){
        lista->ultimo = anterior;
        lista->quantidade--;
    }

    free(no);




    // No *anterior = lista->primeiro;
    // No *posterior = anterior->proximo;
    // if(anterior->dado == valor){
    //     lista->primeiro = anterior->proximo;
    //     free(anterior);
    // } else {
    //     while (posterior != NULL){
    //         if(posterior->dado == valor){
    //             anterior->proximo = posterior-> proximo;
    //             break;
    //         }
    //     }
    // }
    // anterior =posterior;
    // posterior = posterior->proximo;
    // if(posterior->proximo == NULL){
    //     lista->ultimo = anterior;
    //     free(posterior);

    // }

    // lista->quantidade--;

}