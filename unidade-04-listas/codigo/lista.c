#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No* prox;
} No;

No* criar_lista(){
    return NULL;
};

No* inserir_inicio(int v, No* inicio){
    No* novo = malloc(sizeof(No));
    novo->valor = v;
    novo->prox = inicio;
    return novo;
}

No* inserir_fim(int v, No* inicio){
    No* novo = malloc(sizeof(No));
    novo->valor = v;
    novo->prox = NULL;
    No* aux = inicio;
    if(aux == NULL){
        return novo;
    }
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = novo;
    return inicio;
}

No* inserir_ordenada(No* inicio, int v){
    //código aqui

    return;
}

void imprimir(No* lista){
    while(lista != NULL){
        printf("%d > ",lista -> valor);
        lista = lista->prox;
    }
    printf(" |\n");
}

int main(){

    No* inicio = criar_lista();
    inicio = inserir_inicio(5, inicio);
    inicio = inserir_inicio(10, inicio);
    inicio = inserir_inicio(15, inicio);
    inicio = inserir_fim(0,inicio);
    imprimir(inicio);
    return 0;
}

