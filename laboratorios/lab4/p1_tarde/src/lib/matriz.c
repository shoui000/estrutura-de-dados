#include "matriz.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct matriz {
	int colunas, linhas;
	char ***data;
};

tMatriz *criaMatriz(int linhas, int colunas) {
	tMatriz *m = malloc(sizeof(tMatriz));

	m->linhas = linhas;
	m->colunas = colunas;

	m->data = malloc(linhas * sizeof(char **));
	
	for (int i = 0; i < linhas; i++) {
		m->data[i] = calloc(colunas, sizeof(char *));
	}

	return m;
}

void setElemento(tMatriz *m, int i, int j, char *elemento) {
  m->data[i][j] = strdup(elemento);
}

void procuraElemento(tMatriz *m, char *elemento) {
  int encontrado = 0;
  for (int i = 0; i < m->linhas; i++) {
    for (int j = 0; j < m->colunas; j++) {
      if (strcmp(elemento, m->data[i][j]) == 0) {
        printf("Palavra encontrada na posicao [%d][%d] :)!\n", i, j);
        encontrado = 1;
        break;
      }
    }
  }

  if (!encontrado) {
    printf("Palavra não encontrada... :(\n");
  }
}

void liberaMatriz(tMatriz *m) {
	for (int i = 0; i < m->linhas; i++) {
    for (int j = 0; j < m->colunas; j++) {
      free(m->data[i][j]);
    }
		free(m->data[i]);
	}

	free(m->data);
	free(m);
}

void imprimeMatriz(tMatriz *m) {
	for (int i = 0; i < m->linhas; i++) {
		for (int j = 0; j < m->colunas; j++) {
			printf("%s ", m->data[i][j]);
		}

		putchar('\n');
	}
}

