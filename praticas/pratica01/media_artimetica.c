#include <stdio.h>

int main() {
    int n, i;
    float numero, soma = 0, media;

    printf("Digite a quantidade de numeros (maximo 100): ");
    scanf("%d", &n);

    if (n > 100 || n <= 0) {
        printf("Quantidade invalida.\n");
        return 0;
    }

    for (i = 1; i <= n; i++) {
        printf("Digite o numero %d: ", i);
        scanf("%f", &numero);
        soma = soma + numero;
    }

    media = soma / n;

    printf("Media aritmetica = %.2f\n", media);

    return 0;
}