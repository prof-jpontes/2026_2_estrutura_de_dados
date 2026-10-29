#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void menu(){
    printf("-------------------------------------------\n");
    printf("Escolha uma das opcoes:\n");
    printf("1: Retirar uma senha (o cliente)\n");
    printf("2: Chamar a proxima senha\n");
    printf("3: Ver o tamanho da fila de espera\n");
    printf("4: Sair\n");
}
void processar(int op, Fila *f){
    char nome[50];
    int idade;
    Pessoa p;
    switch(op){
        case 1:
            printf("Nome: ");
            scanf("%s", nome);
            printf("Idade: ");
            scanf("%d", &idade);
            p = criar_pessoa(nome, idade);
            enfileirar(f, p);
            break;
        case 2: 
            if(!desenfileirar(f, &p)){
                printf("Nao ha pessoa em espera\n");
            }else{
                printf("Senha %s, senhor(a) %s, compareca ao guiche\n", p.senha, p.nome);
            }
            break;
        case 3: 
            printf("Tamanho da fila: %d\n", f->tamanho);
            break;
        default:
            printf("Voce escolheu uma opcao invalida\n");
            break;
    }
}

int main(){
    Fila f = criar_fila();
    int opcao;

    menu();
    scanf("%d", &opcao);

    while (opcao != 4){
        processar(opcao, &f);
        menu();
        scanf("%d", &opcao);
    }
    while(f.tamanho > 0){
        Pessoa p;
        desenfileirar(&f, &p);
    }

    return 0;
}