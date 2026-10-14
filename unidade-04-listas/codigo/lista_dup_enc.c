#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No* ant;
    struct No* prox;
}No;

typedef struct Lista{
    No* inicio;
    No* fim;
}Lista;

Lista criar(){
    Lista l;
    l.inicio = NULL;
    l.fim = NULL;
    return l;
}

void inserir_inicio(Lista* l, int v){
    No* novo = malloc(sizeof(No));
    novo->valor = v;
    novo->ant = NULL;
    novo->prox = NULL;
    if(l->inicio == NULL){
        l->inicio = novo;
        l->fim = novo;
    }else {
        novo->prox = l->inicio;
        l->inicio->ant = novo;
        l->inicio = novo;
    }
}

void inserir_fim(Lista* l, int v) {
    No* novo = malloc(sizeof(No));
    novo->valor = v;
    novo->ant = NULL;
    novo->prox = NULL;

    if (l->fim == NULL) {
        l->inicio = novo;
        l->fim = novo;
    }else {
        l->fim->prox = novo;
        novo->ant = l->fim;
        l->fim = novo;
    }
}

void imprimir_inicio(Lista* l) {
    No* aux = l->inicio;
    while (aux != NULL) {
        printf("%d\t", aux->valor);
        aux = aux->prox;
    }
}

void imprimir_fim(Lista* l) {
    No* aux = l->fim;
    while(aux != NULL) {
        printf("%d\t", aux->valor);
        aux = aux->ant;
    }
}

/*
Exercícios:
 1. Inserir de forma ordenada crescente;
 2. Procurar um valor;
 3. Remover um valor - lembrar da função free;
 4. Limpar uma lista duplamente encadeada.
 Desafio: aplicar um algoritmo de ordenação em uma lista não ordenada
*/

int main(){
    Lista l = criar();
    inserir_inicio(&l, 5);
    inserir_inicio(&l, 10);
    inserir_inicio(&l, 15);
    inserir_inicio(&l, 20);
    inserir_fim(&l, 14);
    inserir_fim(&l, 15);
    inserir_fim(&l, 16);
    imprimir_inicio(&l);
    printf("\n");
    imprimir_fim(&l);
    return 0;
}