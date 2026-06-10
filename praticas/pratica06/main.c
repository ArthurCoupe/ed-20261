#include <stdio.h>
#include "lista_linear.h"

int main() {
    printf("--- Testando o TDA de Lista Linear Duplamente Encadeada ---\n\n");

    Lista* minha_lista = lista_criar();
    if (minha_lista == NULL) {
        printf("Erro ao criar a lista.\n");
        return 1;
    }
    printf("A lista esta vazia? %s\n", lista_esta_vazia(minha_lista) ? "Sim" : "Nao");

    printf("\nInserindo valores: 10, 20, 30, 40, 50...\n");
    lista_inserir(minha_lista, 10);
    lista_inserir(minha_lista, 20);
    lista_inserir(minha_lista, 30);
    lista_inserir(minha_lista, 40);
    lista_inserir(minha_lista, 50);

    lista_exibir(minha_lista);
    printf("A lista esta vazia? %s\n", lista_esta_vazia(minha_lista) ? "Sim" : "Nao");

    printf("\n--- Buscas ---\n");
    int valor_busca1 = 30;
    int valor_busca2 = 100;
    
    printf("Buscando %d: %s\n", valor_busca1, lista_buscar(minha_lista, valor_busca1) ? "Encontrado" : "Nao encontrado");
    printf("Buscando %d: %s\n", valor_busca2, lista_buscar(minha_lista, valor_busca2) ? "Encontrado" : "Nao encontrado");

    printf("\n--- Remocoes ---\n");
    
    printf("Removendo 10 (primeiro elemento)...\n");
    lista_remover(minha_lista, 10);
    lista_exibir(minha_lista);

    printf("Removendo 50 (ultimo elemento)...\n");
    lista_remover(minha_lista, 50);
    lista_exibir(minha_lista);

    printf("Removendo 30 (elemento do meio)...\n");
    lista_remover(minha_lista, 30);
    lista_exibir(minha_lista);

    printf("Tentando remover 99 (nao existe)...\n");
    if(!lista_remover(minha_lista, 99)) {
        printf("Valor 99 nao encontrado na lista para remocao.\n");
    }

    printf("\nDestruindo a lista...\n");
    lista_destruir(minha_lista);
    printf("Lista destruida com sucesso. Fim do programa.\n");

    return 0;
}