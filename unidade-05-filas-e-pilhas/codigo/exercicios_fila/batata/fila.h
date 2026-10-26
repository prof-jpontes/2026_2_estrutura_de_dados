#ifndef FILA_H
#define FILA_H

typedef struct No{
    char nome[50];
    struct No *prox;
}No;

typedef struct Fila{
    int tamanho;
    No *inicio;
    No *fim;
}Fila;

Fila criar_fila();

void enfileirar(Fila *f, char nome[]);

int ehvazia(Fila *f);

char* desenfileirar(Fila *f);


void girar_batata(Fila *f, int k);

#endif