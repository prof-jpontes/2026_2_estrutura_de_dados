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
    int tamanho;
}Fila;

Fila criar_fila(){
    Fila f;
    f.inicio = NULL;
    f.fim = NULL;
    f.tamanho = 0;
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
    if (f->inicio == NULL){
        f->inicio = novo;
    }else{
        f->fim->prox = novo;
    }
    f->fim = novo;
    f->tamanho++;

}


void desenfileirar (Fila *f){
    if(f->inicio != NULL){
        No* temp = f->inicio;
        f->inicio = f->inicio->prox;
        free(temp);
        if(f->inicio == NULL){
            f->fim = NULL;
        } 
        f->tamanho--;
    }
}
void imprimir(Fila* f){
    No* aux = f->inicio;
    printf("{\n");
    while(aux != NULL){
        printf("[%s, %d]", aux->pessoa.nome, aux->pessoa.idade);
        aux = aux->prox;
        if(aux != NULL) printf(" -> ");
    }
    printf("\n}\n");
}   

int ehvazia(Fila* f){
    if(f->inicio == NULL) return 1;
    return 0;
} 

void limpar(Fila* f){
    while(ehvazia(f) == 0){
        desenfileirar(f);
    }
}

void destruir_fila(Fila* f){
    limpar(f);
    free(f);
}
int tamanho(Fila* f){
    return f->tamanho;
}

Pessoa frente(Fila *f){
    if(!ehvazia(f)){
        return f->inicio->pessoa;
    }
    return criar_pessoa("", -1); //sentinela
}

int main(){
    Fila f = criar_fila(); 
    
    Pessoa p = criar_pessoa("Joao",20);
    enfileirar (&f, p);

    p = criar_pessoa ("Pedro",90);
    enfileirar (&f, p);

    p = criar_pessoa ("Maria",50);
    enfileirar (&f, p);
    imprimir(&f);
    printf("Tamanho da fila: %d\n", tamanho(&f));
    limpar(&f);
    if(ehvazia(&f)){
        printf("Nao ha pessoas na lista\n");
    }else{
        printf("Primeira pessoa da fila: %s, %d\n", frente(&f).nome, frente(&f).idade);
    }
        /*printf("Limpando....\n");
    limpar(&f);
    if(ehvazia(&f)){
        printf("A lista esta vazia\n");
    } else{
        printf("A lista nao esta vazia\n");
    }
*/
    return 0;

}