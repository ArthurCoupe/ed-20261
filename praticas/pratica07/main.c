#include <stdio.h>
#include "pilha.h"

int main() {
    Pilha* p = pilha_criar();

    printf("Vazia: %d\n", pilha_esta_vazia(p));

    pilha_empilhar(p, 10);
    pilha_empilhar(p, 20);
    pilha_empilhar(p, 30);

    printf("Vazia: %d\n", pilha_esta_vazia(p));

    printf("Conteudo da pilha:\n");
    pilha_exibir(p);

    printf("Topo: %d\n", pilha_topo(p));

    printf("Desempilhado: %d\n", pilha_desempilhar(p));
    printf("Desempilhado: %d\n", pilha_desempilhar(p));

    printf("Conteudo da pilha apos desempilhar:\n");
    pilha_exibir(p);

    pilha_destruir(p);

    return 0;
}