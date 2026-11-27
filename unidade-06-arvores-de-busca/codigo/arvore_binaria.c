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

int buscar(No* atual, int valor){
   /*while(atual != NULL){
       if(valor == atual->valor) return 1;
        if(valor < atual->valor){
            atual = atual->esq;
        }else{
            atual = atual->dir;
        }
    }
    return 0;*/
    // Usar apenas uma das versões

   if(atual == NULL) return 0;
   if(valor == atual->valor) return 1;
   if(valor < atual->valor){
    return buscar(atual->esq, valor);
   }
   
    return buscar(atual->dir, valor);
   
}

No* menor_no(No* atual){
    if(atual == NULL) return NULL;
    if(atual->esq == NULL) return atual;
    return menor_no(atual->esq);
}

No* remover_no(No* atual, int valor){
    if(atual == NULL) return NULL;  //Arvore vazia
    if(valor < atual->valor){ 
        atual->esq = remover_no(atual->esq, valor);
    }
    if(valor > atual->valor){ 
        atual->dir = remover_no(atual->dir, valor);
    }
    //O No do valor foi encontrado
    if(atual->esq == NULL && atual->dir == NULL){
        //Eh folha
        free(atual);
        return NULL;
    }else if(atual->esq == NULL){//Filho do lado direito
        No* aux = atual->dir;
        free(atual);
        return aux;
    }else if(atual->dir == NULL){//Filho do lado esquerdo
        No* aux = atual->esq;
        free(atual);
        return aux;
    }else{
        //Tem dois filhos
        No* aux = menor_no(atual->dir);
        atual->valor = aux->valor;
        atual->dir = remover_no(atual->dir, aux->valor);
    }
    return atual;
}
