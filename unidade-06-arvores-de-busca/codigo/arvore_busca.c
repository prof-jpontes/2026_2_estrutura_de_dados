#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{
    int valor;
    struct No *esq;
    struct No *dir; 
}No;

No *criar_arvore(){
    return NULL;
}

No *criar_no(int valor){
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No *inserir_No(No *atual, int valor){
    // caso básico é quando atual for nulo
    if(atual == NULL)return criar_no(valor);
    
    // caso complexo é quando atual não é vazia
    if(valor < atual->valor){
        atual->esq = inserir_No(atual->esq, valor);
    }else{
        atual->dir = inserir_No(atual->dir, valor);
    }
    return atual;
}

void imprimir(No *atual, int nivel){
    if(atual != NULL){
        imprimir(atual->dir, nivel+1);
        int i;
        for(i = 0; i <= nivel; i++)printf("\t");
        printf("%d\n", atual->valor);
        imprimir(atual->esq, nivel+1);
    }
}

int buscar(No *atual, int valor){

    if(atual == NULL)return 0;
    if(valor == atual->valor)return 1;
    if(valor < atual->valor)return buscar(atual->esq, valor);
    return buscar(atual->dir, valor);
}

No *pegar_menor_no(No *atual){
    while (atual->esq != NULL) atual = atual->esq;

    return atual;
}

No *remover_no(No *atual, int valor){
    if(atual == NULL)return NULL;
    if(valor < atual->valor)atual->esq = remover_no(atual->esq, valor);
    else if(valor > atual->valor)atual->dir = remover_no(atual->dir, valor);
    else{
        //encontrei o valor que vou remover
        if(atual->esq == NULL && atual->dir == NULL){//é uma folha
            free(atual);
            return NULL;
        }else if(atual->esq == NULL){
            No *aux = atual->dir;
            free(atual);
            return aux;
        }else if(atual->dir == NULL){
            No *aux = atual->esq;
            free(atual);
            return aux;
        }else{
            No *aux = pegar_menor_no(atual->dir);
            atual->valor = aux->valor;
            atual->dir = remover_no(atual->dir, aux->valor);
        }
    }
    return atual;
}

int main(){

    No *raiz = criar_arvore();
    raiz = inserir_No(raiz, 10);
    raiz = inserir_No(raiz, 20);
    raiz = inserir_No(raiz, 5);
    raiz = inserir_No(raiz, 30);
    raiz = inserir_No(raiz, 40);
    raiz = inserir_No(raiz, 2);
    raiz = inserir_No(raiz, 7);
    raiz = inserir_No(raiz, 6);
    imprimir(raiz,0);
    //printf("\n%d ", buscar(raiz, 5));

    raiz = remover_no(raiz, 10);
    imprimir(raiz,0);
    return 0;
}