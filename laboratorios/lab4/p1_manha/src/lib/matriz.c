#include "matriz.h"

#include <stdio.h>
#include <stdlib.h>

struct matriz {
	int colunas, linhas;
	int **data;
};

tMatriz *criaMatriz(int linhas, int colunas) {
	tMatriz *m = malloc(sizeof(tMatriz));

	m->linhas = linhas;
	m->colunas = colunas;

	m->data = malloc(linhas * sizeof(int *));
	
	for (int i = 0; i < linhas; i++) {
		m->data[i] = calloc(colunas, sizeof(int));
	}

	return m;
}

void liberaMatriz(tMatriz *m) {
	for (int i = 0; i < m->linhas; i++) {
		free(m->data[i]);
	}

	free(m->data);
	free(m);
}

tMatriz *suavizaMatriz(tMatriz *m) {
	tMatriz *suavizada = malloc(sizeof(tMatriz));

	int linhas = m->linhas, colunas = m->colunas;

	suavizada->linhas = linhas;
	suavizada->colunas = colunas;

	suavizada->data = malloc(linhas * sizeof(int *));
	
	int *linha, soma;
	for (int i = 0; i < linhas; i++) {
		 linha = calloc(colunas, sizeof(int));

		 for (int j = 0; j < colunas; j++) {
			 if (i == 0 || j == 0 || i == linhas-1 || j == colunas-1) {
				 linha[j] = m->data[i][j];
			 } else {
				 soma = 0;

				 for (int y = i-1; y <= i+1; y++) {
					 for (int x = j-1; x <= j+1; x++) {
						 soma += m->data[y][x];
					 }
				 }

				 linha[j] = soma / 9;
			 }
		 }

		 suavizada->data[i] = linha;
	}

	return suavizada;
}

void imprimeMatriz(tMatriz *m) {
	for (int i = 0; i < m->linhas; i++) {
		for (int j = 0; j < m->colunas; j++) {
			printf("%d ", m->data[i][j]);
		}

		putchar('\n');
	}
}

int getElemento(tMatriz *m, int i, int j) {
	return m->data[i][j];
}

void setElemento(tMatriz *m, int i, int j, int elemento) {
	m->data[i][j] = elemento;
}
