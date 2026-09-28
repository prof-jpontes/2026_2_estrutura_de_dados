#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H

typedef struct conta Conta;

Conta* criar_conta (char* t, char* n);

char* relatorio (Conta *c);

double consultar_saldo(Conta* c);

int depositar(Conta* c, double v);

int sacar(Conta* c, double v);

int transferir(Conta* c1, Conta* c2, double v);

#endif