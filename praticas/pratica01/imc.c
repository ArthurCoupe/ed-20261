#include <stdio.h>
int main() {
    float peso, altura, imc;

    printf("Digite o peso (em kg): ");
    scanf("%f", &peso);

    printf("Digite a altura (em metros): ");
    scanf("%f", &altura);

    imc = peso / (altura * altura);

    printf("O IMC eh: %.2f\n", imc);

    if (imc < 18.5) {
        printf("Classificacao: Abaixo do peso\n");
    } else if (imc >= 18.5 && imc < 25) {
        printf("Classificacao: Peso normal\n");
    } else if (imc >= 25 && imc < 30) {
        printf("Classificacao: Sobrepeso\n");
    } else {
        printf("Classificacao: Obesidade\n");
    }
        
        return 0;
}