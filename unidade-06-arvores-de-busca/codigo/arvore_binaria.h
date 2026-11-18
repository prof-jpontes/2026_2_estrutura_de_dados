#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H


typedef struct No{
    int valor;
    struct No* esq;
    struct No* dir;
}No;

No* criar_arvore();

No* criar_no(int valor);

No* inserir_no(No* atual, int valor);

void imprimir(No* atual);

int buscar(No* atual, int valor);

No* menor_no(No* atual);

No* remover_no(No* atual, int valor);

No* limpar_arvore(No* atual);

void excluir_arvore(No* atual);





#endif 