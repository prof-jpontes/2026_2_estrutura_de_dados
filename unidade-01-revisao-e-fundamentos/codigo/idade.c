#include <stdio.h>

int main (){
    int m, a, b, c;

    scanf("%d %d %d", &m, &a, &b);
    c = m - a - b;
    if (a > c && a > b){
        printf("%d\n", a);
    } else if (b > a && b > c){
        printf("%d\n", b);
    } else printf("%d\n", c);

    return 0;
}