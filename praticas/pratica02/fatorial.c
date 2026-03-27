#include <stdio.h>

// Versão iterativa
long long fatorial_iterativo(int n) {
    long long resultado = 1;
    for (int i = 1; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

// Versão recursiva
long long fatorial_recursivo(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * fatorial_recursivo(n - 1);
}

int main() {
    int num;

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Numero invalido.\n");
        return 1;
    }

    printf("Fatorial (iterativo): %lld\n", fatorial_iterativo(num));
    printf("Fatorial (recursivo): %lld\n", fatorial_recursivo(num));

    return 0;
}