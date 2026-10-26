#ifndef PILHA_H
#define PILHA_H

typedef struct Livro{
    char titulo[50];
    char autor[100];
    int ano;
}Livro;

typedef struct No{
    Livro livro;
    struct No* prox;
}No;

typedef struct Pilha{
    No* topo;
    int tamanho;
}Pilha;

Pilha criar_pilha();

Livro criar_livro(char titulo[], char autor[], int ano);

void empilhar(Pilha* pilha, Livro l);

void desempilhar(Pilha* pilha);

Livro topo(Pilha* pilha);

int ehvazia(Pilha* pilha);

int contar(Pilha* pilha);

void limpar(Pilha* pilha);

void destruir(Pilha* pilha);

#endif