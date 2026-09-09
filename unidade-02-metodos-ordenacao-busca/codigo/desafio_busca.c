#include <stdio.h>
#include <stdlib.h>

void imprimir(int *v, int tam){
    int i;
    for (i = 0; i < tam; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

insertionSort(int *v, int tam){
    int i, j, chave;
    for(i = 1; i < tam; i++){
        chave = v[i];
        j = i - 1;
        while(j >= 0 && v[j] > chave){
            v[j+1] = v[j];
            j--;
        }

        v[j+1] = chave;
    }
}

int busca_sequencial(int *v, int t, int chave, int *contador){

    int i;
    for(i=0; i<t; i++){ //pode percorrer todo o vetor;
    *contador = *contador + 1;
        if(v[i] == chave) return i; //a chave foi encotrada, logo, retorno o índice onde ela foi encontrada. Observa-se que se a chave estiver repetida no vetor, o algoritmo retornará a primeira ocorrência. 
        }
    return -1; //-1 indica que a chave não foi encontrada.
}

int busca_binaria_recursiva(int *v, int ini, int fim, int chave, int *contador){
    *contador = *contador + 1;
    if(ini > fim ) return -1;
    int meio = (ini + fim)/2;
    if(v[meio] == chave) return meio;
    if(v[meio] > chave) return busca_binaria_recursiva(v, ini, meio-1, chave, contador);
    return busca_binaria_recursiva(v, meio+1, fim, chave, contador);
}

int main(){
    int n;
    printf("Informe a quantidade de elementos: ");
    scanf("%d", &n);
    int v[n];
    int i, num;
    for (i = 0; i < n; i++){
        v[i] = rand()%100;
    } 
    printf("Vetor original:\n");
    imprimir(v, n);
    printf("\nVetor ordenado:\n");
    insertionSort(v, n);
    imprimir(v, n);
    int contador = 0;
    printf("Digite a chave de busca: ");
    int chave;
    scanf("%d", &chave);
    printf("Indice da chave: %d\n", busca_sequencial(v, n, chave, &contador));
    printf("Quantidade de iteracoes: %d\n", contador);
    contador = 0;
    printf("Indice da chave: %d\n", busca_binaria_recursiva(v, 0, n - 1, chave, &contador));
    printf("Quantidade de iteracoes: %d\n", contador);
    return 0;
}