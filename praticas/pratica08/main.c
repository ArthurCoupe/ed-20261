#include <stdio.h>
#include "fila.h"

int main() {
    Fila* f = fila_criar();

    printf("Vazia: %d\n", fila_esta_vazia(f));

    fila_enfileirar(f, 10);
    fila_enfileirar(f, 20);
    fila_enfileirar(f, 30);

    printf("Vazia: %d\n", fila_esta_vazia(f));

    printf("Conteudo da fila:\n");
    fila_exibir(f);

    printf("Inicio: %d\n", fila_inicio(f));

    printf("Desenfileirado: %d\n", fila_desenfileirar(f));
    printf("Desenfileirado: %d\n", fila_desenfileirar(f));

    printf("Conteudo da fila apos desenfileirar:\n");
    fila_exibir(f);

    fila_destruir(f);

    return 0;
}