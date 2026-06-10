#include <stdio.h>
#include "tabela_hash.h"

int main() {
    TabelaHash* h = hash_criar(7);

    printf("Vazia: %d\n", hash_esta_vazia(h));

    hash_inserir(h, 10);
    hash_inserir(h, 20);
    hash_inserir(h, 15);
    hash_inserir(h, 7);
    hash_inserir(h, 14);

    printf("Vazia: %d\n", hash_esta_vazia(h));

    printf("Conteudo da Tabela Hash:\n");
    hash_exibir(h);

    printf("Busca por 15: %d\n", hash_buscar(h, 15));
    printf("Busca por 99: %d\n", hash_buscar(h, 99));

    printf("Remover 15: %d\n", hash_remover(h, 15));
    printf("Remover 99: %d\n", hash_remover(h, 99));

    printf("Conteudo apos remocao:\n");
    hash_exibir(h);

    hash_destruir(h);

    return 0;
}