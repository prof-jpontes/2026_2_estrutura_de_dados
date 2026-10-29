#ifndef IMPRESSAO_H
#define IMPRESSAO_H

typedef struct Documento{
    char nome[50];
    int qde_paginas;
}Documento;

typedef struct No{
    Documento doc;
    struct No *prox;
}No;

typedef struct Fila{
    No *inicio;
    No *fim;
    int tamanho;
    int tempo;
}Fila;

Fila criar_fila();

void enfileirar(Fila *f, char nome[], int paginas);

void imprimir(Fila *f);

void processar_impressoes(Fila *f);

#endif