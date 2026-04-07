#include <stdio.h>
#include <stdlib.h>

#include "lib/matriz.h"

int main(int argc, char **argv) {
	if (argc < 3) {
		printf("[erro] Foram passados menos argumentos do que o necessário.\n");
		exit(EXIT_FAILURE);
	}

	int linhas, colunas, elemento;

	scanf("%d %d", &linhas, &colunas);
	tMatriz *base = criaMatriz(linhas, colunas);

	for (int i = 0; i < linhas; i++) {
		for (int j = 0; j < colunas; j++) {
			scanf("%d", &elemento);

			setElemento(base, i, j, elemento);
		}
	}

	imprimeMatriz(base);

	tMatriz *suavizada = suavizaMatriz(base);
	imprimeMatriz(suavizada);

	liberaMatriz(base);
	liberaMatriz(suavizada);

	exit(EXIT_SUCCESS);
}
