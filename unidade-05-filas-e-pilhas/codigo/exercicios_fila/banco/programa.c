#include <stdio.h>
#include <stdlib.h>
#include "impressao.h"

void menu(){
    printf("-------------------------------------------\n");
    printf("Escolha uma das opcoes:\n");
    printf("1: Retirar uma senha (o cliente)\n");
    printf("2: Chamar a proxima senha\n");
    printf("3: Ver o tamanho da fila de espera\n");
    printf("4: Ver a fila de espera\n");
    printf("5: Ver tempos medios\n");     // novo
    printf("6: Sair\n");                  // saída mudou para 6
}

void processar(int op, Fila *f){
    int r, chegada, duracao, inicio, fim;
    switch(op){
        case 1:
            printf("Chegada (min): ");
            scanf("%d", &chegada);
            printf("Duracao (min): ");
            scanf("%d", &duracao);
            pegar_senha(f, chegada, duracao);
            break;
        case 2:
            r = atender_senha(f, &inicio, &fim);
            if(r == -1){
                printf("Nao ha pessoa em espera\n");
            }else{
                printf("Senha %d, compareca ao guiche (inicio: %d, fim: %d)\n", r, inicio, fim);
            }
            break;
        case 3:
            printf("Tamanho da fila: %d\n", f->tamanho);
            break;
        case 4:
            ver_fila_espera(f);
            break;
        case 5:
            printf("Espera media: %.2f min\n", media_espera(f));
            printf("Tempo medio para finalizar: %.2f min\n", media_finalizacao(f));
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

    while (opcao != 6){
        processar(opcao, &f);
        menu();
        scanf("%d", &opcao);
    }

    return 0;
}