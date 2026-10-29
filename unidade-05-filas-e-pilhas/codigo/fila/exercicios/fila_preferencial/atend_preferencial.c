#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

Fila criar_fila(){
    Fila f;
    f.inicio = NULL;
    f.fim_pri = NULL;
    f.fim = NULL;
    f.tamanho = 0;
    f.controle_geral = 0;
    f.controle_pri = 0;

    return f;
}

Pessoa criar_pessoa(char nome[], int idade){
    Pessoa p;
    strcpy(p.nome, nome);
    p.idade = idade; //A senha da pessoa não é definida aqui
    return p;
}

void enfileirar(Fila *f, Pessoa p){
    No *novo = malloc(sizeof(No));
    novo->pessoa = p;
    novo->prox = NULL;

    // É prioridade?
    int pri = novo->pessoa.idade >= 60;
    if(pri) sprintf(novo->pessoa.senha, "P-%d", ++f->controle_pri);
    else    sprintf(novo->pessoa.senha, "C-%d", ++f->controle_geral);
    
    if(f->inicio == NULL){ // Fila vazia
        f->inicio = novo;
        f->fim = novo;
        if(pri) f->fim_pri = novo;
    }else if(!pri){ // Fila não vazia, não prioridade --- vai para o fim da fila
        f->fim->prox = novo;
        f->fim = novo;
    }else if(f->fim_pri == NULL){ // Fila não vazia, prioridade, sem prioridade na fila
        novo->prox = f->inicio;
        f->inicio = novo;
        f->fim_pri = novo;
    }else{ // Fila não vazia, prioridade com outras prioridades
        novo->prox = f->fim_pri->prox;
        f->fim_pri->prox = novo;
        if(f->fim == f->fim_pri) f->fim = novo;
        f->fim_pri = novo;
    }

    f->tamanho++;
}

int desenfileirar(Fila *f, Pessoa *saida){
    if(f->inicio == NULL) return 0; // Fila vazia, não há quem ser chamado.

    No *temp = f->inicio;
    *saida = temp->pessoa;
    f->inicio = f->inicio->prox;
    
    if(f->fim_pri == temp) f->fim_pri = NULL;

    if(f->fim == temp) f->fim = NULL;
    f->tamanho--;
    free(temp);

    return 1;
}