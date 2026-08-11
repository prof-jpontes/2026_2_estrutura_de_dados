#include <stdio.h>

int main(){
    int a = 10;
    int b;
    b = a;
    a = 20;
    printf("Valor de A: %d\n", a);
    printf("Valor de B: %d\n", b);
    //A variável B e A são independentes

    char c = 'c';
    c = c + 4;
    printf("Valor de c: %c\n", c); //char mapeia números em caractere pela tabela ASCII. 
   

    float f = 4.0f;
    printf("Valor de F formatado com duas casas apos o ponto: %.2f\n", f); 
    
    double d = 4.0;
    printf("Valor de D formatado com o tamanho 9 e 3 casas apos a virgula: %9.3lf\n", d);
    
    int h;
    printf("Informe um número inteiro em hexadecimal:");
    scanf("%X", &h);
    printf("O valor lido em decimal eh: %d\n", h);//Imprime em decimal
    printf("O valor lido em octal eh: %o\n", h);//Imprime em octal
    

    double n1 = 120000000.02;
    printf("Valor de n1 em notação: %.1E\n", n1); //Com uma casa após a vírgula
    double n2 = 0.000241;
    printf("Valor de n2 em notação: %.1E\n", n2);
    printf("Local de n1: %p\n", n1);


    return 0;
}