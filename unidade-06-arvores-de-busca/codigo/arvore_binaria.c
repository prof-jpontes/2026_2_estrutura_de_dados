#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

No* criar_arvore(){
    return NULL;
}

No* criar_no(int valor){
    No* novo = malloc(sizeof(No));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No* inserir_no(No* atual, int valor){
  if(atual == NULL)return criar_no(valor);
  if(valor < atual->valor){
    atual->esq = inserir_no(atual->esq, valor);
  }else{
    atual->dir = inserir_no(atual->dir, valor);
  }
  return atual;
}

void imprimir(No* atual){
    if(atual != NULL){
        imprimir(atual->esq);
        printf("%d\t", atual->valor);
        imprimir(atual->dir);
    }
}

void imprimir_formatada(No* atual, int profundidade){
    if(atual != NULL){
        imprimir_formatada(atual->dir, profundidade+1);
        for(int i = 0; i < profundidade; i++){
            printf("\t");
        }
        printf("%d\n", atual->valor);
        imprimir_formatada(atual->esq, profundidade+1);
    }
}