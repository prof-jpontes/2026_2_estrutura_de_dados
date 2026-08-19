#include <stdio.h>

int main (){
    int n, atual = 1, anterior = 0;
    printf("Digite o tamanho da sequencia: ");
    scanf("%d", &n);
    printf("F: 0, 1");
    for (int i = 2; i < n; i++){
        atual += anterior;
        anterior = atual - anterior;
        printf(", %d", atual);
    }
    printf("\n");
    return 0;
}