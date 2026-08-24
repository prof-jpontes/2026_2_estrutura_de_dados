#include <stdio.h>

long long fatorial2(long long n) {
    if (n == 0 || n == 1) {            // caso base
        return 1;
    }
    return n * fatorial2(n - 1); // caso recursivo
}

long long fatorial(long long n){
    if (n==0 || n == 1) return 1;

    for(int i=n-1; i>1; i--){
        n *= i;
    }
    return n;
}
int main(){
    int n;
    printf("Digite um numero inteiro para calcular seu fatorial: \n");
    scanf("%d", &n);
    printf("%lld\n", fatorial2(n));
    
    return 0;
}