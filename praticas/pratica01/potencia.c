#include <stdio.h>

int main() {
    int base, expoente;
    int resultado = 1;
    int i;

    printf("Digite a base: ");
    scanf("%d", &base);

    printf("Digite o expoente (inteiro positivo): ");
    scanf("%d", &expoente);

    for(i = 1; i <= expoente; i++) {
        resultado = resultado * base;
    }

    printf("Resultado: %d\n", resultado);

    return 0;
}