#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conta.h"

Conta conta[100];
int total = 0;

int main(){

    conta_criar(1313131);
    conta_depositar(conta,1000.50);
    conta_ver_saldo(conta);
    conta_sacar(conta, 500.50);
    conta_ver_saldo(conta);
    conta_sacar(conta, 2000);
    conta_ver_saldo(conta);

    return 0;
}