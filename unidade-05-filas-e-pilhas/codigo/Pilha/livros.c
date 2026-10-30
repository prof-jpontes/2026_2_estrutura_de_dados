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
    pilha->tamanho++;
}

int desempilhar(Pilha* pilha, Livro* leitura){
    if(pilha->topo == NULL){
        return 0;
    }
    No* temp = pilha->topo;
    *leitura = temp->livro;  
    pilha->topo = pilha->topo->prox;
    free(temp);
    pilha->tamanho--;
    return 1;
}

void remover(Pilha* pilha){
    No* temp = pilha->topo;
    pilha->topo = pilha->topo->prox;
    free(temp);
    pilha->tamanho--;
}

int ehvazia(Pilha* pilha){
    if(pilha->topo == NULL) return 1;
    return 0;
}

int contar(Pilha* pilha){
    return pilha->tamanho;
}

void limpar(Pilha* pilha){
    while(!ehvazia(pilha)){
        remover(pilha);
    }
}

void destruir(Pilha* pilha){
    limpar(pilha);
    free(pilha);
}