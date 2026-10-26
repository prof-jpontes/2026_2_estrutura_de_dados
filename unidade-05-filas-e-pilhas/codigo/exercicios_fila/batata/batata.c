#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

Fila criar_fila(){
    Fila f;
    f.inicio = NULL;
    f.fim = NULL;
    f.tamanho = 0;
    return f;
}

void enfileirar(Fila *f, char nome[]){
    //Criar nó
    No *novo = malloc(sizeof(No));
    strcpy(novo->nome, nome);
    if(f->inicio == NULL){
        f->inicio = novo;
    }else{
        f->fim->prox = novo;
    }
    novo->prox = f->inicio;
    f->fim = novo;
    f->tamanho++;
}

int ehvazia(Fila *f){
    if(f->inicio == NULL) return 1;
    return 0;
}

//É preciso verificar se não é vazia
char* desenfileirar(Fila *f){
    if(ehvazia(f)) return NULL;

    char *nome = malloc(50 * sizeof(char));
    strcpy(nome, f->inicio->nome);
    No *temp = f->inicio;

    if(f->tamanho == 1){
        f->inicio = NULL;
        f->fim = NULL;
    }else{
        f->inicio = temp->prox;
        f->fim->prox = f->inicio;   // mantém a lista circular
    }
    f->tamanho--;
    free(temp);
    return nome;
}


void girar_batata(Fila *f, int k){
    int i;
    while(f->tamanho > 1){
        for(i=0; i<k; i++){
            f->inicio = f->inicio->prox;
            f->fim = f->fim->prox;
        }
        char *temp = desenfileirar(f);
        printf("Removido: %s\n", temp);
        free(temp);
    }
    printf("Vencedor: %s\n", f->inicio->nome);
    char *lixo = desenfileirar(f);
    free(lixo);
}