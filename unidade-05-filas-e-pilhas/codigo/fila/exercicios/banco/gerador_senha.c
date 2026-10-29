#include <stdio.h>
#include <stdlib.h>
#include "gerador_senha.h"

Fila criar_fila(){
    Fila f;
    f.inicio = NULL;
    f.fim = NULL;
    f.tamanho = 0;
    f.controle = 0;
    f.relogio = 0;
    f.total_atendidos = 0;
    f.soma_espera = 0;
    f.soma_total = 0;
    return f;
}

void pegar_senha(Fila *f, int chegada, int duracao){
    No *novo = malloc(sizeof(No));
    novo->prox = NULL;
    novo->chegada = chegada;
    novo->duracao = duracao;
    novo->senha = ++f->controle;
    if(f->inicio == NULL){
        f->inicio = novo;
    }else{
        f->fim->prox = novo;
    }     
    f->fim = novo;
    f->tamanho++;
}

int atender_senha(Fila *f, int *inicio, int *fim){
    if(f->tamanho != 0){
        No *temp = f->inicio;
        f->inicio = f->inicio->prox;
        if(f->inicio == NULL) f->fim = NULL;
        f->tamanho--;
        if(f->relogio > temp->chegada){
            *inicio = f->relogio;
        }else{
            *inicio = temp->chegada;
        }
        *fim = *inicio + temp->duracao;
        f->soma_espera += *inicio - temp->chegada;
        f->soma_total += *fim - temp->chegada;
        f->total_atendidos++;
        f->relogio = *fim;
        
        int senha = temp->senha;
        free(temp);
        return senha;
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

double media_espera(Fila *f){
    if(f->total_atendidos == 0) return 0.0;
    
    return (double) f->soma_espera / f->total_atendidos;
}

double media_finalizacao(Fila *f){
    if(f->total_atendidos == 0) return 0.0;

    return (double) f->soma_total / f->total_atendidos;
}