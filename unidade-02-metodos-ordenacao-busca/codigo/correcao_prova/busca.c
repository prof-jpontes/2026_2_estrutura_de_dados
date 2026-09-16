#include <stdio.h>
#include <math.h>

int main(){
    int t, n;
    scanf("%d %d", &t, &n);
    printf("%d\n", (int)(t/pow(2, n-1)));
    return 0;
}