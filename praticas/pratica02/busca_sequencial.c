#include <stdio.h>

int main() {
    int vetor[100];
    int valor, i, posicao = -1;

    printf("Digite 100 numeros:\n");
    for (i = 0; i < 100; i++) {
        scanf("%d", &vetor[i]);
    }

    printf("Digite o valor a ser buscado: ");
    scanf("%d", &valor);

    // Busca sequencial
    for (i = 0; i < 100; i++) {
        if (vetor[i] == valor) {
            posicao = i;
            break;
        }
    }

    if (posicao != -1)
        printf("Valor encontrado na posicao %d\n", posicao);
    else
        printf("Valor nao encontrado.\n");

    return 0;
}