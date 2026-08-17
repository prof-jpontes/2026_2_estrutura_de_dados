#include <stdio.h>

int main(){
    float nota1, nota2, nota3;

    printf("Digite a primeira nota:\t");
    scanf("%f", &nota1);
    printf("Digite a segunda nota:\t");
    scanf("%f", &nota2);
    printf("Digite a terceira nota:\t");
    scanf("%f", &nota3);

    float media = (nota1 + nota2 + nota3) / 3;

    printf("Media: %.1f\n", media);

    /*if (media >= 7) printf("Aprovado!\n");
    else if (media > 5) printf("Recuperacao!\n");
    else printf("Reprovado.\n");*/
    if(nota1 < 0 || nota1 > 10 || nota2 < 0 || nota2 > 10 || nota3 < 0 || nota3 > 10){
        printf("Ao menos 1 nota invalida.\n");
    } else {
        printf("%s/n", media >= 7 ? "Aprovado!" : media > 5 ? "Recuperacao." : "Reprovado.\n");
    }
    return 0;
}