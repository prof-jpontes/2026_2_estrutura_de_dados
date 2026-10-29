#ifndef FILA_H
#define FILA_H

typedef struct Pessoa{
    char nome[50];
    int idade;
    char senha[50];
}Pessoa;

typedef struct No{
    Pessoa pessoa;
    struct No *prox;
}No;

typedef struct Fila{
    No *inicio;
    No *fim_pri;
    No *fim;
    int tamanho;
    int controle_geral;
    int controle_pri;
}Fila;

Fila criar_fila();
Pessoa criar_pessoa(char nome[], int idade);
void enfileirar(Fila *f, Pessoa p);
int desenfileirar(Fila *f, Pessoa *saida);




#endif