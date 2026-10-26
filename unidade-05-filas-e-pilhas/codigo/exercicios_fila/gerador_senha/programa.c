#include <stdio.h>
#include "gerador_senha.h"

void menu(){
    printf("-------------------------------------------\n");
    printf("Escolha uma das opcoes:\n");
    printf("1: Retirar uma senha (o cliente)\n");
    printf("2: Chamar a proxima senha\n");
    printf("3: Ver o tamanho da fila de espera\n");
    printf("4: Ver a fila de espera\n");
    printf("5. Sair\n");
}
void processar(int op, Fila *f){
    int r;
    switch(op){
        case 1:
            pegar_senha(f);
            break;
        case 2: 
            r = atender_senha(f);
            if(r == -1){
                printf("Nao ha pessoa em espera\n");
            }else{
                printf("Senha %d, compareca ao guiche\n", r);
            }
            break;
        case 3: 
            printf("Tamanho da fila: %d\n", f->tamanho);
            break;
        case 4:
            ver_fila_espera(f);
            break;
        default:
            printf("Você escolheu uma opcao invalida\n");
            break;
    }
}

int main(){
    Fila f = criar_fila();
    int opcao;

    menu();
    scanf("%d", &opcao);

    while (opcao != 5){
        processar(opcao, &f);
        menu();
        scanf("%d", &opcao);
    }

    return 0;
}