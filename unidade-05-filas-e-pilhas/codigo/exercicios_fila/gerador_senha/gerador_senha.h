#ifndef GERADORSENHA_H
#define GERADORSENHA_H

typedef struct No{
    int senha;
    struct No *prox;
}No;

typedef struct{
    No *inicio;
    No *fim;
    int tamanho;
    int controle;
}Fila;

Fila criar_fila();

void pegar_senha(Fila *f);

int atender_senha(Fila *f);

int pegar_tamanho_fila(Fila *f);

void ver_fila_espera(Fila *f);

#endif