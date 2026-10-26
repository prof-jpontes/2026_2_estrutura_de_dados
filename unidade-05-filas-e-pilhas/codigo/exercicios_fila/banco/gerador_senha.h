#ifndef GERADORSENHA_H
#define GERADORSENHA_H

typedef struct No{
    int senha;
    int chegada;
    int duracao;
    struct No *prox;
}No;

typedef struct{
    No *inicio;
    No *fim;
    int tamanho;
    int controle;
    int relogio;
    int total_atendidos;
    int soma_espera;
    int soma_total;
}Fila;

Fila criar_fila();

void pegar_senha(Fila *f, int chegada, int duracao);

int atender_senha(Fila *f, int *inicio, int *fim);

int pegar_tamanho_fila(Fila *f);

void ver_fila_espera(Fila *f);

double media_espera(Fila *f);

double media_finalizacao(Fila *f);

#endif