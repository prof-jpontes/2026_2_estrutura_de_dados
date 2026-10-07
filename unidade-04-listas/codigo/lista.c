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

int procurar(No* no, int v){
    while(no != NULL){
        if(no->valor == v) return 1;
        no = no->prox;
    }
    return 0;
}

No* remover(int v, No* inicio){
    No* atual = inicio;
    No* anterior = NULL;
    while(atual != NULL && atual->valor != v){
        anterior = atual;
        atual = atual->prox;
    }
    if(atual == NULL) return inicio; //O valor nao foi encontrado
    if(anterior == NULL){ //remover o primeiro
        inicio = atual->prox;
    }else{
        anterior->prox = atual->prox;
    }
    free(atual);
    return inicio;
}
No* remover_primeiro(No* inicio){
    if(inicio == NULL) return inicio;
    No* atual = inicio;
    inicio = inicio->prox;
    free(atual);
    return inicio;
}

No* limpar(No* inicio){
    No* aux = inicio;
    while(inicio != NULL){
        aux = inicio;
        inicio = inicio->prox;
        free(aux);
    }
    return inicio;
}

No* remover_ultimo(No* inicio){
    if(inicio == NULL) return inicio;
    if(inicio->prox == NULL){
        free(inicio);
        return NULL;
    }
    No* atual = inicio;
    No* anterior = NULL;
    while(atual->prox != NULL){
        anterior = atual;
        atual = atual->prox;
    }
    free(atual);
    anterior->prox = NULL;
    return inicio;
}
 
//No* inserir_ordenada(No* inicio, int v){
    //código aqui

   // return;
//}


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
    //inicio = remover(5, inicio);
    inicio = remover_ultimo(inicio);
    imprimir(inicio);
    return 0;
}

