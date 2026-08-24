#include <stdio.h>

int main(){
    char o;
    int i, j, contador = 0;↑
    double valor, soma = 0;

    scanf(" %c", &o);
    for(i = 0; i < 12; i++){
        for(j = 0; j < 12; j++){
            scanf("%lf", &valor);
            if(i < j && i + j < 11) {
                soma += valor;
                contador++;
            }
        }
    }
    if(o == 'S') printf("%.1lf\n", soma);
    else printf("%.1lf\n", soma / contador);

return 0;
}