#include <stdio.h>
#include "arvore_binaria.h"

void menu(){
    printf("\nESCOLHA UMA OPCAO:\n");
    printf("1.Inserir um no.\n");
    printf("2.Imprimir arvore.\n");
    printf("3.Sair do sistema.\n");
}

No* processar(No* raiz, int opcao){
    int valor;
    switch (opcao){
    case 1:
        printf("Digite o valor: ");
        scanf("%d", &valor);
        raiz = inserir_no(raiz, valor);
        break;

    case 2:
        imprimir_formatada(raiz, 0);
        break;
    
    default:
        printf("Voce escolheu a opcao errada.");
        break;
    }
    return raiz;
}

int main(){

    No* raiz = criar_arvore();

    int op;

    menu();
    scanf("%d", &op);
    while (op != 3){
        raiz = processar(raiz, op);
        menu();
        scanf("%d", &op);
    }
    printf("Voce saiu do sistema.");
    

    imprimir(raiz);

    return 0;
}