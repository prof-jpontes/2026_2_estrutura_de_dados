#include  <stdio.h>

void tentaTrocar(int* a, int* b){
    printf("Impressao antes da troca: %d, %d\n", *a, *b);
    int aux = *a;
    *a = *b;
    *b = aux;
    printf("Impressao apos a troca: %d, %d\n", *a, *b);
}

int main(){
    printf("Informe dois numeros inteiros: ");
    int x, y;
    scanf("%d%d", &x, &y);
    x = x * y;
    y = x - 10;
    tentaTrocar(&x, &y);
    printf("Impressao na funcao main: %d, %d\n", x, y);
    return 0;
}