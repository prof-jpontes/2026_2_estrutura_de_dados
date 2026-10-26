#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "impressao.h"

Fila criar_fila(){
    Fila f;
    f.inicio = NULL;
    f.fim = NULL;
    f.tamanho = 0;
    f.tempo = 0;
    return f;
}

void enfileirar(Fila *f, char nome[], int paginas){
    //Criacao do documento em si — não é um ponteiro que aponte para um doc
    Documento doc;
    strcpy(doc.nome, nome);
    doc.qde_paginas = paginas;

    //Criação do ponteiro do nó que terá o documento
    No *novo = malloc(sizeof(No));
    novo->doc = doc;
    novo->prox = NULL;
    if(f->inicio == NULL){
        f->inicio = novo;
    }else{
        f->fim->prox = novo;
    }
    f->fim = novo;
}

void imprimir(Fila *f){ // É preciso garantir que fila não está vazia para chamar esta funcao
    Documento doc = f->inicio->doc;
    No *temp = f->inicio;
    f->inicio = f->inicio->prox;
    if(f->inicio == NULL) f->fim = NULL;
    free(temp);
    f->tamanho--;
    f->tempo += doc.qde_paginas * 2;
    printf("Nome: %s: %d paginas, concluido em %d segundos\n", doc.nome, doc.qde_paginas, f->tempo);
}

void processar_impressoes(Fila *f){
    if(f->inicio == NULL){
        printf("A fila está vazia\n");
    }
    while(f->inicio != NULL){
        imprimir(f);
    }
    f->tempo = 0;
}
