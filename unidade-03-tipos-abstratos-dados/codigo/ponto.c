#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct{
    double x;
    double y;
}Ponto;

Ponto* criar_ponto(double x, double y){
    Ponto* p = malloc(sizeof(Ponto));
    p->x = x;
    p->y = y;
    return p;
}
double obterx(Ponto* p){
    return p->x;
    
}
double obtery(Ponto* p){
    return p->y;
    
}
double calcular_distancia(Ponto* p1, Ponto* p2){
    double a = p1->x - p2->x;
    double b = p1->y - p2->y;
    double d = (a*a) + (b*b);
    return sqrt(d);
}
void mover(Ponto* p, double dx, double dy){
    p->x = p->x + dx;
    p->y = p->y + dy;
}
int main(){
    printf("Criar dois pontos: (0,0) e (1,2)\n");
    Ponto* p1 = criar_ponto(0, 0);
    Ponto* p2 = criar_ponto(1, 2);
    printf("X de p1: %.1lf\n", obterx(p1));
    printf("Y de p1: %.1lf\n", obtery(p1));
    printf("Distancia entre os pontos: %.2lf\n", calcular_distancia(p1, p2));
    mover(p2, 3, 1);
    printf("Distancia entre os pontos: %.2lf\n", calcular_distancia(p1, p2));
    return 0;
}