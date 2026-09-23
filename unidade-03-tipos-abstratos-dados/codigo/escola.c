#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char nome[50];
    int idade;
    char matricula[20];
    double cra;
}Aluno;

void imprimir(Aluno *v, int t, double cra){
    
    for(int i = 0; i < t; i++){
        if(v[i].cra < cra){
            printf("%s - %.2lf\n", v[i].nome, v[i].cra);
        }
    }
}

void insertionSort(Aluno *v, int t){
    int i, j;
    Aluno aux;
    double chave;
    for(i = 1; i < t; i++){
        chave = v[i].cra;   
        aux = v[i];
        j = i - 1;
        while(j >= 0 && v[j].cra < chave){
            v[j+1] = v[j];
            j--;

        }

        v[j+1] = aux;
       
    }
  

}


int main(){
    Aluno turma[3];

    strcpy(turma[0].nome, "Ana");
    turma[0].idade = 18;
    strcpy(turma[0].matricula, "an456b");
    turma[0].cra = 9.8;

    strcpy(turma[1].nome, "Bruno");
    turma[1].idade = 20;
    strcpy(turma[1].matricula, "br450c");
    turma[1].cra = 6.1;

    strcpy(turma[2].nome, "Mateus");
    turma[2].idade = 20;
    strcpy(turma[2].matricula, "br450c");
    turma[2].cra = 9.9;

   //imprimir(turma, 3,7.0);
    insertionSort(turma, 3);
    imprimir(turma, 3,11);
    return 0;
}
