#include <stdio.h>
#include "conta.h"

int main() {
    Conta minha_conta = conta_criar(1001);

    conta_depositar(minha_conta, 1500.50);
    printf("%.2f\n", conta_ver_saldo(minha_conta));

    conta_sacar(minha_conta, 300.00);
    printf("%.2f\n", conta_ver_saldo(minha_conta));

    conta_destruir(minha_conta);

    return 0;
}