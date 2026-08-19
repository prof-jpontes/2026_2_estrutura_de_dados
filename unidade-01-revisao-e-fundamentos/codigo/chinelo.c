#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int estoque[n+1];
    estoque[0] = 0;
    for (int i = 1; i <= n; i++){
        scanf("%d", &estoque[i]);
    } 
    int p, tam, vendas = 0;
    scanf("%d", &p);
    for (int i = 0; i < p; i++){
        scanf("%d", &tam);
            if (estoque[tam] > 0){
            estoque[tam]--;
            vendas++;
        }
    }
    printf("%d\n", vendas);

    return 0;
}