#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No* prox;
}No;

typedef struct Lista{
    No* inicio;
    No* fim;
}Lista;

Lista criar() {
    Lista l;
    l.inicio = NULL;
    l.fim = NULL;
    return l;
}

void inserir_inicio (Lista* l, int v) {
    No* novo = malloc(sizeof(No));
    novo->valor = v;

    if (l->inicio == NULL) {
        l->inicio = novo;
        l->fim = novo;
        novo->prox = novo;
    }else {
        novo->prox = l->inicio;
        l->inicio = novo;
        l->fim->prox = novo;
    }
}

void inserir_fim(Lista* l, int v) {
    No* novo = malloc(sizeof(No));
    novo->valor = v;

    if (l->fim == NULL) {
        l->inicio = novo;
        l->fim = novo;
        novo->prox = novo;
    }else {
        l->fim->prox = novo;
        l->fim = novo;
        novo->prox = l->inicio;
    }
}

void imprimir(Lista* l) {
    No* aux = l->inicio;

    while(aux != NULL && aux->prox != l->inicio) {
        printf("%d\t", aux->valor);
        aux = aux->prox;
    }
    if(aux != NULL) printf("%d", aux->valor);
}

void excluir(Lista* l, int v) {
    if (l->inicio == NULL) return;
    if (l->inicio->valor == v) {
        No* aux = l->inicio;
        l->inicio = aux->prox;
        free(aux);
        l->fim->prox = l->inicio;
    }else{
        No* atual = l->inicio->prox;
        No* ant = l->inicio;

        while(atual->valor != v && atual != l->inicio) {
            ant = atual;
            atual = atual->prox;
        }
        if (atual != l->inicio) {
            ant->prox = atual->prox;
            free(atual);
        }
    }
}

int main () {
    Lista l = criar();
    inserir_inicio(&l, 6);
    inserir_inicio(&l, 8);
    inserir_inicio(&l, 10);
    inserir_fim(&l, 12);
    imprimir(&l);
    excluir(&l, 6);
    printf("\n");
    imprimir(&l);
    return 0;
}