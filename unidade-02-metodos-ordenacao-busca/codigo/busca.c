#include <stdio.h>
int busca_sequencial(int *v, int t, int chave){

    int i;
    for(i=0; i<t; i++){ //pode percorrer todo o vetor;
        if(v[i] == chave) return i; //a chave foi encotrada, logo, retorno o índice onde ela foi encontrada. Observa-se que se a chave estiver repetida no vetor, o algoritmo retornará a primeira ocorrência. 
    }
    return -1; //-1 indica que a chave não foi encontrada.
}

int busca_binaria(int*v, int t, int chave ){
    int ini=0, fim=t-1;
    int meio;
    while(ini <= fim){
        meio = (ini + fim)/2;
        if(v[meio] == chave ) return meio;
        if(v[meio] < chave) ini = meio+1;
        else fim = meio-1;
    }
    return -1;
}

int busca_binaria_recursiva(int *v, int ini, int fim, int chave){
    if(ini > fim ) return -1;
    int meio = (ini + fim)/2;
    if(v[meio] == chave) return meio;
    if(v[meio] > chave) return busca_binaria_recursiva(v, ini, meio-1, chave);
    return busca_binaria_recursiva(v, meio+1, fim, chave);
}

int main(){
    int v[]={19,21,50,63,70,70,82};
    printf("%d\n" , busca_binaria_recursiva(v,0,6,50));
}
