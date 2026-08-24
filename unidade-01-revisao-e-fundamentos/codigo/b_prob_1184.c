#include <stdio.h>

int main(){
    char o;
    int i, j, contador = 0;
    float valor, soma = 0;

    scanf(" %c", &o);
    for(i = 0; i < 12; i++){
        for(j = 0; j < 12; j++){
            scanf("%f", &valor);
            if(i > j){
                soma += valor;
                contador++;
            }
        }
    }
    if(o == 'S') printf("%.1f\n", soma);
    else printf("%.1f\n", soma / contador);

return 0;
}