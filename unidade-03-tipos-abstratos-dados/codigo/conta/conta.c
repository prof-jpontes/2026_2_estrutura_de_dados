#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contabancaria.h"

struct conta {
    char titular[50];
    char numero[4];
    double saldo;
};

Conta* criar_conta (char* t, char* n){
    Conta* c = malloc (sizeof(Conta));
    strcpy (c->titular, t);
    strcpy (c->numero, n);
    c->saldo = 0;
    return c;
}

char* relatorio (Conta *c){
    char* relatorio = calloc(200, sizeof(char));
    strcpy (relatorio, "\nTitular: ");
    sprintf (relatorio + strlen(relatorio),"%s", c->titular);
    sprintf (relatorio + strlen(relatorio),"%s","\nConta: " );
    sprintf (relatorio  + strlen(relatorio), "%s", c->numero);
    sprintf (relatorio + strlen(relatorio),"%s","\nSaldo: " );
    sprintf (relatorio  + strlen(relatorio), "%.2lf", c->saldo);
    return relatorio;

}

double consultar_saldo(Conta* c) {
    return c->saldo;
}

int depositar(Conta* c, double v){
    if (v > 0){
        c->saldo = c->saldo + v;
        return 1;
    }
    return 0;
}

int sacar (Conta* c, double v){
    if (c->saldo >= v && v > 0){
        c->saldo = c->saldo - v;
        return 1;
    }
    return 0;
}

int transferir (Conta* c1, Conta* c2, double v){
    if (sacar(c1,v)){
        depositar(c2,v);
        return 1;
    }
    return 0;
}