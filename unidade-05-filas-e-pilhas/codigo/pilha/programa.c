#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"
void menu(){
	printf("MEUS LIVROS\n");
	printf("1 - Empilhar livro.\n");
	printf("2 - Ler um livro.\n");
	printf("3 - Sair.\n");
}

void processar(Pilha* pilha, int op){
	char titulo[50], autor[100];
	int ano;
	Livro l, leitura;
	switch (op){
		case 1: 
		printf("Titulo: ");
		scanf("%s", titulo);
		printf("Autor: ");
		scanf("%s", autor);
		printf("Ano de publicacao: ");
		scanf("%d", &ano);
		l = criar_livro(titulo, autor, ano);
		empilhar(pilha, l);
		break;
		case 2:
		if(desempilhar(pilha, &leitura)){
			printf("Voce comecou a ler o livro %s, de %s, publicado em %d \n", leitura.titulo, leitura.autor, leitura.ano);
		}else {
			printf("Sua pilha de livros esta vazia\n");
		}
		break;
		default:
		printf("Opcao invalida\n");
		break;
	}
}

int main(){
	menu();
	Pilha p = criar_pilha();
	int op;
	scanf("%d", &op);
	while(op != 3){
		processar(&p, op);
		menu();
		scanf("%d", &op);
	}
	destruir(&p);
	return 0;
}

