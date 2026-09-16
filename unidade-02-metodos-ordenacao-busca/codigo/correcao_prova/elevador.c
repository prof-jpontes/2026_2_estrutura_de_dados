#include <stdio.h>

int main(){
    int n, c, s, e, quant = 0, i;
    char saida = 'N';

    scanf("%d %d", &n, &c);
    for(i = 0; i < n; i++){
        scanf("%d %d", &s, &e);
        quant = quant - s + e;
        if(quant > c){
            saida = 'S';
        }
    }
    printf("%c\n", saida);
}