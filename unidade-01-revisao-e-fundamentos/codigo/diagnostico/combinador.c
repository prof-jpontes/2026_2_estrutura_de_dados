#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){
    char str1[51], str2[51], str_final[101];
    int n, i, j, k, menor;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        str1[0] = '\0';
        str2[0] = '\0';
        scanf("%s %s", str1, str2);
        menor = (strlen(str1) + strlen(str2) - abs(strlen(str1) - strlen(str2))) / 2;
        for (j = 0; j < menor; j++){
            printf("%c%c", str1[j], str2[j]);
        }
        for (k = j; k < strlen(str1); k++){
            printf("%c", str1[k]);
        }
        for (k = j; k < strlen(str2); k++){
            printf("%c", str2[k]);
        }
        printf("\n");
    }

    return 0;
}