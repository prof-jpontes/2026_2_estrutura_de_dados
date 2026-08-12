#include <stdio.h>
#include <math.h>

int main () {
    printf ("Ler dois numeros inteiros e mostra a soma\n");
    int n0, n1;
    printf ("Primeiro numero: ");
    scanf ("%d", &n0);
    printf ("Segundo numero: ");
    scanf ("%d", &n1);
    printf ("Soma: %d\n", n0 + n1);
    printf ("Subtracao: %d\n", n0 - n1);
    printf ("Multiplicacao: %d\n", n0 * n1);
    printf ("Divisao: %d\n", n0 / n1);
    printf ("Dobro do primeiro valor: %d\n", n0 * 2);
    printf ("Metade do primeiro valor: %d\n", n0 / 2);
    printf ("Quadrado do primeiro valor: %d\n", n0 * n0);
    printf ("O primeiro elevado ao segundo: %.0lf\n", pow(n0, n1));
    printf ("Raiz Quadrada do primeiro valor: %lf\n", sqrt(n0));
    printf ("Raiz Quadrada do primeiro valor: %.1lf\n", sqrt(n0));
    printf ("Raiz Quadrada do primeiro valor arredondada para baixo: %.1lf\n", floor(sqrt(n0)));
    printf ("Raiz Quadrada do primeiro valor arredondada para cima: %.1lf\n", ceil(sqrt(n0)));
    printf ("Raiz Cubica do primeiro valor: %.1lf\n", pow(n0, 1.0/3.0));
    return 0;
}