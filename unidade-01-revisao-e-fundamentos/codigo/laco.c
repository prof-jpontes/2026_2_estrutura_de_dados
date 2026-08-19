#include <stdio.h>

int main(){
    int senha = 123456;
    int entrada;
    do {
        printf("Digite a senha: ");
        scanf("%d", &entrada);
    }while (entrada != senha); 
    printf("Autenticacao realizada!");
    return 0;
}