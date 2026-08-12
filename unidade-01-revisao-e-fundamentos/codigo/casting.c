#include <stdio.h>

int main () {
    int a, b, c, d;
    scanf ("%d%d%d%d", &a, &b, &c, &d);
    float media = (float)(a + b + c + d) / 4;
    printf ("Media: %.2f\n", media);
    return 0;
}