#include <stdio.h>
void imprimir(int *v, int tam){
    for (int i = 0; i < tam; i++){ 
        printf("%d\t", *(v + i));
    }
    printf("\n");
}

int bubbleSort(int *v, int tam){ 
    int aux, cont = 0;
    for (int i = tam - 1; i > 0; i--){
        for (int j = 0; j < i; j++){
            if (v[j] > v[j+1]){ //TROCA
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux; 
            }
            cont++;
        }
        imprimir(v, tam);
    }
    return cont;
}
int selectionSort(int *v , int tam){
    int i, j, iMin, aux, cont = 0;
    for(i = 0; i < tam-1; i++){
        iMin = i;
        for(j = i+1; j < tam; j++){
            if(v[j] < v[iMin]) iMin = j;

             cont++;
        }
        if(iMin != i ){
            aux = v[i];
            v[i] = v[iMin];
            v[iMin] = aux;
        }
        imprimir(v, tam);

    }
    return cont;


}
int insertionSort(int *v, int tam){
    int i, j, chave, cont = 0;
    for(i = 1; i < tam; i++){
        chave = v[i];
        j = i - 1;
        while(j >= 0 && v[j] > chave){
            v[j+1] = v[j];
            j--;

            cont++;
        }

        v[j+1] = chave;
        imprimir(v, tam);
    }
    return cont;

}



int main(){
    int v[] = {12, 18, 7, 5, 12, 1, 12};
    printf("Vetor antes da ordenacao: \n");
    imprimir(v, 7);
    //printf("\nBubblesort\n");
    //printf("Quantidade de interacoes: %d \n", bubbleSort(v, 7));
    
    //printf("\nSelectionSort\n");
    //printf("Quantidade de iteracoes: %d \n", selectionSort(v, 7));
    //printf("\n\nVetor apos a ordenacao: \n");
    //imprimir(v, 7);
    printf("\nInsertionSort\n");
    printf("Quantidade de iteracoes: %d \n", insertionSort(v, 7));
    return 0;
}