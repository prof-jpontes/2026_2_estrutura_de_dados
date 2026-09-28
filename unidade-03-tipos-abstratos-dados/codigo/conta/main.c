#include <stdio.h>
#include <stdlib.h>
#include "contabancaria.h"

int main(){
    Conta* c1 = criar_conta ("Joao", "123");
    Conta* c2 = criar_conta ("Maria","456");
    depositar(c1,1000000);
    sacar(c1, 500000);
    transferir(c1, c2, 100000);
    printf (" %s\n", relatorio(c1));
    printf (" %s\n", relatorio(c2));
    printf (" %s\n", relatorio(c1));

    return 0;
}