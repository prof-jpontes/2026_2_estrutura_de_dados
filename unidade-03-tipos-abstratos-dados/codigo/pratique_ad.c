#include <stdio.h>
#include <stdlib.h>

int main(){
    int qtd = 10, numero, i = 0;
    int *p = malloc(qtd * sizeof(int));
    while(i < qtd){
        scanf("%d", &numero);
        if(numero == 0){
            break;
        }
        *(p + i) = numero;
        i++;
        if(i == qtd){
            qtd += 10;
            p = realloc(p, qtd * sizeof(int));
        }
    }
    for(int j = 0; j < i; j++){
        printf("%d\t", *(p + j));
    }

    return 0;
}