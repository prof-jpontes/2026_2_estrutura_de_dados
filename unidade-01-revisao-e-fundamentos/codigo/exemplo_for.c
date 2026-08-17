#include <stdio.h>

int main (){
    int i;
    for (i = 0; i <= 100; i+= 2){
        if(i % 11 == 0 && i != 11 && i != 0) continue;
        printf("%d\n", i);
    }

    return 0;
}