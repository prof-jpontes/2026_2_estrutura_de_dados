#include <stdio.h>

int main(){
    printf("Tamanho dos dados, em bytes, separados por tipo\n");
    printf("Char: %zu\n", sizeof(char));
    printf("Int: %zu\n", sizeof(int));
    printf("Long long: %zu\n", sizeof(long long));
    printf("Float: %zu\n", sizeof(float));
    printf("Double: %zu\n", sizeof(double));
    return 0;
}