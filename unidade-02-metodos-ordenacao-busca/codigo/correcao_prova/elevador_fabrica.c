#include <stdio.h>
void ordenar(int *v, int t){
    int i, j, chave;
    for(i = 1; i < t; i++){
        j = i - 1;
        chave = v[i];
        while(j >= 0 && v[j] > chave){
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = chave;
    }
}
int main(){
    int n, i;
    scanf("%d", &n);
    int caixas[n];
    for(i = 0; i < n; i++){
        scanf("%d", &caixas[i]);
    }
    ordenar(caixas, n);
    
    if(caixas[0] > 8){
        printf("N\n");
        return 0;
    }
    for(i = 1; i < n; i++){
        if(caixas[i] - caixas[i - 1] > 8){
            printf("N\n");
            return 0;
        }
    }
    printf("S\n");
    return 0; 
}