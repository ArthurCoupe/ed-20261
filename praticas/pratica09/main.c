#include <stdio.h>
#include "arvore_binaria.h"

int main() {
    Arvore* a = arvore_criar();

    printf("Vazia: %d\n", arvore_esta_vazia(a));

    arvore_inserir(a, 50);
    arvore_inserir(a, 30);
    arvore_inserir(a, 70);
    arvore_inserir(a, 20);
    arvore_inserir(a, 40);
    arvore_inserir(a, 60);
    arvore_inserir(a, 80);

    printf("Vazia: %d\n", arvore_esta_vazia(a));

    printf("Pre-ordem:\n");
    arvore_exibir_pre_ordem(a);

    printf("Em-ordem:\n");
    arvore_exibir_em_ordem(a);

    printf("Pos-ordem:\n");
    arvore_exibir_pos_ordem(a);

    arvore_destruir(a);

    return 0;
}