#ifndef conta_h
#define conta_h

struct conta{
    int numero;
    float saldo;
};

typedef struct conta Conta;


Conta* conta_criar(int numero);
float conta_depositar(Conta *c, float deposito);
float conta_sacar(Conta *c,float saque);
void conta_ver_saldo(Conta *c);
void conta_destruir(Conta *c);


#endif