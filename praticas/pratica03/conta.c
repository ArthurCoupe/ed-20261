#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conta.h"




Conta* conta_criar(int numero) {
    Conta* c = malloc(sizeof(Conta));


    if (c != NULL) {
        c->numero = numero;
        c->saldo = 0.0;
    }


    return c;
}


float conta_depositar(Conta *c, float deposito){
    if(c != NULL){
        c-> saldo += deposito;
    }
}
float conta_sacar(Conta *c,float saque){
     if(c != NULL && c-> saldo >= saque){
        c-> saldo -= saque;
    }
}


void conta_ver_saldo(Conta *c){
    printf("Seu saldo e de : %.2f\n", c ->saldo); 
}
void conta_destruir(Conta *c){
free(c);
}