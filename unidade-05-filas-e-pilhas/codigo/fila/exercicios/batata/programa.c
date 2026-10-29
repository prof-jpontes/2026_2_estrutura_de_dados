#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"


void menu(){
    printf("-------------------------------------------\n");
    printf("Jogo da Batata\n");
    printf("1: Adicionar pessoa\n");
    printf("2: Girar Batata\n");
    printf("3: Sair\n");
}
void processar(int op, Fila *f){
    int k;
    char nome[50];
    switch(op){
        case 1:
            printf("Nome da pessoa: ");
            scanf("%s", nome);
            enfileirar(f, nome);
            break;
        case 2: 
            printf("Quantidade de passos: ");
            scanf("%d", &k);
            if(ehvazia(f)){
                printf("A fila está vazia. Não ha vencedor\n");
            }else{
                girar_batata(f, k);
            }
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

    while (opcao != 3){
        processar(opcao, &f);
        menu();
        scanf("%d", &opcao);
    }

    return 0;
}