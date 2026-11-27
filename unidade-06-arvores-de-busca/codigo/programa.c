#include <stdio.h>
#include "arvore_binaria.h"

void menu(){
    printf("\nESCOLHA UMA OPCAO:\n");
    printf("1.Inserir um no.\n");
    printf("2.Imprimir arvore.\n");
    printf("3.Buscar valor\n");
    printf("4.Mostrar o Menor\n");
    printf("5.Excluir um No\n");
    printf("0.Sair do sistema.\n");
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
        printf("\n==================================\n");
        imprimir_formatada(raiz, 0);
        printf("\n==================================\n");
        break;
    case 3:
        printf("Valor: ");
        scanf("%d", &valor);
        if(buscar(raiz, valor)){
            printf("O valor %d existe na arvore\n", valor);
            
        }else{
            printf("O valor %d nao esta na arvore\n", valor);
        }
        break;

    case 4:
        printf("Menor: %d\n", menor_no(raiz)->valor);
        break;

    case 5:
        printf("Digite um valor: ");
        scanf("%d", &valor);
        raiz = remover_no(raiz, valor);
        printf("Arvore resultante: \n");
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
    while (op != 0){
        raiz = processar(raiz, op);
        menu();
        scanf("%d", &op);
    }
    printf("Voce saiu do sistema.");
    

    imprimir(raiz);



    return 0;
}