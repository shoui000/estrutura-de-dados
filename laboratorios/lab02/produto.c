#include "produto.h"

#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

struct produto {
  int id;
  char *nome;
  float valor;
};

tProduto *leProduto(FILE *input) {
  tProduto *p = malloc(sizeof(struct produto));

  fscanf(input, " %d %ms %f", &(p->id), &(p->nome), &(p->valor));

  return p;
}

float getValorProduto(tProduto *p) {
  return p->valor;
}

int getIdProduto(tProduto *p) {
  return p->id;
}

char *getNomeProduto(tProduto *p) {
  return p->nome;
}

void freeProduto(tProduto *p) {
  free(p->nome);
  free(p);
}

tProduto *findProduto(tProduto **produtos, int qtdProdutos, int id) {
  for (int i = 0; i < qtdProdutos; i++) {
    if (produtos[i]->id == id) {
      return produtos[i];
    }
  }

  return NULL;
}
