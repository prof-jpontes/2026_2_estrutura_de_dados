#include <stdio.h>

int main(){
    int n, m, i, x;
    scanf("%d", &n);
    int album[n+1];
    for(i=0; i<=n; i++) album[i] = 0;
    scanf("%d", &m);
    int contador = 0;
    for(i=0; i<m; i++){
        scanf("%d", &x);
        if(album[x] == 0){
            album[x] = 1;
            contador++;
        }
    }
    printf("%d", (n-contador));
    return 0;
}