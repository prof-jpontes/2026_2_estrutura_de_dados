#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoa {
    char nome[50];
    int idade;
} Pessoa;

typedef struct No {
    Pessoa pessoa;
    struct No *prox;

}No;

typedef struct Fila{
    No *inicio;
    No *fim;
}Fila;

Fila criar_fila(){
    Fila f;
    f.inicio = NULL;
    f.fim = NULL;
    return f;   
}

Pessoa criar_pessoa(char nome[50],int idade){
    Pessoa p;
    strcpy(p.nome,nome);
    p.idade = idade;
    return p;
}

void enfileirar(Fila *f, Pessoa p){
    No *novo = malloc(sizeof(No));
    novo->pessoa = p;
    novo->prox = NULL;
    if (f->inicio == NULL)f->inicio = novo;
    if(f->fim != NULL)f->fim->prox = novo;
    f->fim = novo;
}

Pessoa frente(Fila *f){
    //if (f->inicio == NULL) return;
    return f->inicio->pessoa;
}
void desenfileirar (Fila *f){
    if (f->inicio == NULL)return;
    if (f->inicio == f->fim)f->fim = NULL;
    No *aux = f->inicio;
    f->inicio = f->inicio->prox;
    free(aux);

}

int main(){
    Fila f = criar_fila(); 
    
    Pessoa p = criar_pessoa("Joao",20);
    enfileirar (&f, p);

    p = criar_pessoa ("Pedro",90);
    enfileirar (&f, p);

    p = criar_pessoa ("Maria",50);
    enfileirar (&f, p);
    
    printf("Nome: %s\n", frente(&f).nome);
    desenfileirar(&f);
    printf("Nome: %s\n", frente(&f).nome);
    desenfileirar(&f);
    printf("Nome: %s\n", frente(&f).nome);
    return 0;

}