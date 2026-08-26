#include <stdio.h>

void bubbleSort(int *v, int tam){ 
    int aux;
    for (int i = tam - 1; i > 0; i--){
        for (int j = 0; j < i; j++){
            if (*(v+j) < *(v+j+1)){ //TROCA
                aux = *(v+j);
                *(v+j) = *(v+j+1);
                *(v+j+1) = aux; 
            }
        }
    }
}

int main(){
    int v[] = {12, 18, 7, 5, 12, 1, 12};
    printf("Vetor antes da ordenacao: \n");
    for (int i = 0; i < 7; i++){ 
        printf("%d\t", *(v + i));
    }
    bubbleSort(v, 7);
    printf("\n\nVetor apos a ordenacao: \n");
    for (int i = 0; i < 7; i++){ 
        printf("%d\t", *(v + i));
    }

    return 0;
}