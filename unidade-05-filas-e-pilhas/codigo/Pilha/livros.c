#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

Pilha criar_pilha(){
    Pilha p;
    p.topo = NULL;
    p.tamanho = 0;
    return p;
}

Livro criar_livro(char titulo[], char autor[], int ano){
    Livro l;
    strcpy (l.titulo,titulo);
    strcpy (l.autor,autor);
    l.ano = ano;
    return l;
}

void empilhar(Pilha* pilha, Livro l){
    No* novo = malloc(sizeof(No));
    novo->livro = l;
    novo->prox = pilha->topo;
    pilha->topo = novo;
}