#include <stdio.h>

int main(){
    printf("Ler 10 valores inteiros e mostra-os na ordem inversa.\n");
    int vet[10];
    for (int i = 0; i < 10; i++){
        printf("Vet[%d]: ", i);
        scanf("%d", &vet[i]);
    }
    for (int i = 9; i >= 0; i--){
        printf("%d\t", vet[i]);
    }
    printf("\nValores pares: \n");
    for (int i = 0; i < 10; i++){
        if (vet[i] % 2 == 0)
            printf("%d\t", vet[i]);
    }

    return 0;
}