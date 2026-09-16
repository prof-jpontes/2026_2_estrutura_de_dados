#include <stdio.h>
#include <math.h>

int main(){
    int n, m, i, j;
    scanf("%d %d", &n, &m);
    int mat[n][m];
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    int cont = 0, max;
    for(j = 0; j < m; j++){
        max = 0;
        for(i = 0; i < n; i++){
            max = fmax(max, mat[i][j]);
        }
        cont += max;
    }
    printf("%d\n", cont);
    
    return 0;
}
