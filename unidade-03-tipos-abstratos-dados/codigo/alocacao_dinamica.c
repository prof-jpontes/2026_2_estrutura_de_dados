#include <stdio.h>
#include <stdlib.h>

int main(){
    int m;
    scanf("%d", &m);
    //int *p = malloc(m * sizeof(int));
    int *p = calloc(m, sizeof(int));
    for(int i = 0; i < m; i++){
        printf("%d\t", *(p + i));
    }
    printf("\nLeitura de %d elementos\n", m);
    for(int i = 0; i < m; i++){
        scanf("%d", p + i);
    }
    for(int i = 0; i < m; i++){
        printf("%d\t", *(p + i));
    }
    printf("\nRealocacao para %d elementos\n", 2*m);
    p = realloc(p, (m * 2) * sizeof(int));
    for(int i = 0; i < 2*m; i++){
        printf("%d\t", *(p + i));
    }
    
    return 0;
}