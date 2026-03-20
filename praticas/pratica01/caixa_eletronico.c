#include <stdio.h>

int main() {
    int valor;
    int n200, n100, n50, n20, n10, n5, n2;

    printf("Digite o valor do saque (maximo 1000): ");
    scanf("%d", &valor);

    if (valor > 1000 || valor < 2) {
        printf("Valor invalido.\n");
        return 0;
    }

    n200 = valor / 200;
    valor = valor % 200;

    n100 = valor / 100;
    valor = valor % 100;

    n50 = valor / 50;
    valor = valor % 50;

    n20 = valor / 20;
    valor = valor % 20;

    n10 = valor / 10;
    valor = valor % 10;

    n5 = valor / 5;
    valor = valor % 5;

    n2 = valor / 2;
    valor = valor % 2;

    printf("Notas de 200: %d\n", n200);
    printf("Notas de 100: %d\n", n100);
    printf("Notas de 50: %d\n", n50);
    printf("Notas de 20: %d\n", n20);
    printf("Notas de 10: %d\n", n10);
    printf("Notas de 5: %d\n", n5);
    printf("Notas de 2: %d\n", n2);

    return 0;
}