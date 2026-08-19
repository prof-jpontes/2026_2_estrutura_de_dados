#include <stdio.h>

int main(){
    long long n, anterior = 0, atual = 1;
    scanf("%lld", &n);
    printf("F = 0");
    while (atual < n){
        printf(", %lld", atual);
        atual += anterior;
        anterior = atual - anterior; 
    }
    printf("\n");
    return 0;
}
