#include <stdio.h>
#include "impressao.h"

void menu(){
    printf("-------------------------------------------\n");
    printf("Escolha uma das opcoes:\n");
    printf("1: Enviar documento para impressao\n");
    printf("2: Processsar a fila de impressao\n");
    printf("3: Sair\n");
}
void processar(int op, Fila *f){
    int qde_paginas;
    char nome[50];
    switch(op){
        case 1:
            printf("Nome do arquivo: ");
            scanf("%s", nome);
            printf("Quantidade de paginas: ");
            scanf("%d", &qde_paginas);
            enfileirar(f, nome, qde_paginas);
            break;
        case 2: 
            processar_impressoes(f);
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