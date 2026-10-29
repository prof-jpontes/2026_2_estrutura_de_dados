#include <stdio.h>
#include <stdlib.h>
#include "gerador_senha.h"

Fila criar_fila(){
    Fila f;
    f.inicio = NULL;
    f.fim = NULL;
    f.tamanho = 0;
    f.controle = 0;
    return f;
}

void pegar_senha(Fila *f){
    No *novo = malloc(sizeof(No));
    novo->prox = NULL;
    if(f->inicio == NULL){
        f->inicio = novo;
    }else{
        f->fim->prox = novo;
    }
    novo->senha = ++f->controle;
    f->fim = novo;
    f->tamanho++;
}

int atender_senha(Fila *f){
    if(f->tamanho != 0){
        No *temp = f->inicio;
        f->inicio = f->inicio->prox;
        f->tamanho--;
        int aux = temp->senha;
        free(temp);
        return aux;
    }
    return -1;
}

int pegar_tamanho_fila(Fila *f){
    return f->tamanho;
}

void ver_fila_espera(Fila *f){
    No *temp = f->inicio;
    while(temp != NULL){
        printf("%d", temp->senha);
        if(temp->prox != NULL) printf("; ");
        temp = temp->prox;
    }
    printf("\n");
}