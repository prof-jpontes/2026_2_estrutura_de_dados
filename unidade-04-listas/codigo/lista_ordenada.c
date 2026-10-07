#include <stdio.h>
#include <stdlib.h>

    typedef struct No{
        int valor;
        struct No* prox;
    }No;

    No* criar(){
        return NULL;
    }

    No* inserir(int v, No* inicio){
        No* novo = malloc(sizeof(No));
        novo->valor = v;
        novo->prox = NULL;
        if(inicio == NULL) return novo;
        No* atual = inicio;
        No* anterior = NULL;
        while(atual != NULL && atual->valor < v){
            anterior = atual;
            atual = atual->prox;
        }

        if(anterior == NULL){//Inserir na 1ª posição
            inicio = novo;
        }else{
            anterior->prox = novo;
        }
        
        novo->prox = atual;
        return inicio;
    }

    void imprimir(No* lista){
        while(lista != NULL){
            printf("%d > ",lista->valor);
            lista = lista->prox;
        }
    printf(" |\n");
}


    int main(){
        No* inicio = criar();
        inicio = inserir(20, inicio);
        inicio = inserir(5, inicio);
        inicio = inserir(17, inicio);
        inicio = inserir(13, inicio);
        inicio = inserir(2, inicio);
        imprimir(inicio);

        return 0;
    }