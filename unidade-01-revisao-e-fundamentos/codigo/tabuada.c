#include <stdio.h>

void exibirTabuada(int n){
    int i;
    printf("Soma: \n");
    for(i = 1; i < 11; i++){
        printf("%d + %d = %3d\n", n, i, n+i);
    }
    printf("\nSubtracao: \n");
    for(i = 1; i < 11; i++){
        printf("%d - %d = %3d\n", n, i, n-i);
    }
     printf("\nMultiplicacao: \n");
    for(i = 1; i < 11; i++){
        printf("%d x %d = %3d\n", n, i, n * i);
    }
     printf("\nDivisao: \n");
    for(i = 1; i < 11; i++){
        printf("%d / %d = %3d\n", n, i, n / i);
    }
    
}

int main(){
    int n;
    printf("Digite um numero de 1 a 10: ");
    scanf("%d", &n);
    exibirTabuada(n);

    return 0;
}