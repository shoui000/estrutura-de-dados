#include "matriz.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct matriz {
  int linha, coluna;
  char **data;
};

tMatriz *criaMatriz(int linha, int coluna) {
  tMatriz *m = malloc(sizeof(tMatriz));

  m->linha = linha;
  m->coluna = coluna;

  m->data = malloc(linha * coluna * sizeof(char *));
  return m;
}

void setElemento(tMatriz *m, int linha, int coluna, char *elemento) {
  m->data[(linha * m->coluna) + coluna] = strdup(elemento);
}

char* getElemento(tMatriz *m, int linha, int coluna) {
  return m->data[(linha * m->coluna) + coluna];
}

void exterminaMatriz(tMatriz *m) {
  for (int i = 0; i < m->linha * m->coluna; i++) {
    free(m->data[i]);
  }
  free(m->data);
  free(m);
}

void organizaMatriz(tMatriz *base) {
  int swaps;
  do {
    swaps = 0;
    for (int i = 0; i < (base->linha * base->coluna) - 1; i++) {
      if (strcmp(base->data[i], base->data[i+1]) > 0) {
        char *tmp = base->data[i];
        base->data[i] = base->data[i+1];
        base->data[i+1] = tmp;
        swaps++;
      }
    }
  } while(swaps);
}

void imprimeMatriz(tMatriz *m) {
  for (int i = 0; i < m->linha; i++) {
    for (int j = 0; j < m->coluna; j++) {
      printf("%s ", getElemento(m, i, j));
    }
    putchar('\n');
  }
}
