#include <stdio.h>

long long fibonacci1(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    long long ant = 0, atual = 1;
    for(int i = 2; i <= n; i++){
        atual  = atual + ant;
        ant = atual - ant;
        
    }
    return atual;

}

long long fibonacci2(int n) {
    if (n == 0) return 0;   // 1º caso base
    if (n == 1) return 1;   // 2º caso base
    return fibonacci2(n - 1) + fibonacci2(n - 2); // caso recursivo
}

int main (){
    int n, atual = 1, anterior = 0;
    printf("Digite o numero n: ");
    scanf("%d", &n);
    printf("iterativa: %lld\n", fibonacci1(n));
    printf("recursiva: %lld\n", fibonacci2(n));
    return 0;
}