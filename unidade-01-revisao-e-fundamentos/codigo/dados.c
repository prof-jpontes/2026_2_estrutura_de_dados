#include <stdio.h>

int main(){
    int a = 10;
    int b;
    b = a;
    a = 20;
    printf("Valor de a: %d\n", a);
    printf("Valor de b: %d\n", b);
    char c = 'c';
    c = c + 4;
    printf("Valor de c: %c\n", c);
    float f = 4.0f;
    printf("Valor de f: %.2f\n", f);
    double d = 4.0;
    printf("Valor de d: %9.3lf\n", d);
    int h;
    scanf("%X", &h);
    printf("O valor de h: %o\n", h);//Imprime em octal
    double n1 = 120000000.02;
    printf("Valor de n1 em notação: %.1E\n", n1);
    double n2 = 0.000241;
    printf("Valor de n2 em notação: %.1E\n", n2);
    printf("Local de n1: %p\n", n1);


    return 0;
}