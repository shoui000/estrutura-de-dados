#include "supermercado.h"
#include "filial.h"
#include "estoque.h"

#include <stdlib.h>
#include <stdio.h>

struct supermercado {
  char *nome;

  int qtdFiliais;
  tFilial **filiais;
};

tSuper *leSupermercado(void **catalogo, int tamanhoCatalogo, FILE *input) {
  tSuper *s = malloc(sizeof(struct supermercado));

  fscanf(input, " %ms", &(s->nome));
  fscanf(input, " %d", &(s->qtdFiliais));

  s->filiais = malloc(s->qtdFiliais * sizeof(void *));

  for (int i = 0; i < s->qtdFiliais; i++) {
    s->filiais[i] = leFilial(catalogo, tamanhoCatalogo, input);
  }

  return s;
}

void freeSupermercado(tSuper *s) {
  free(s->nome);

  for (int i = 0; i < s->qtdFiliais; i++) {
    freeFilial(s->filiais[i]);
  }

  free(s);
}

float getValorEstoqueSupermercado(tSuper *s) {
  float soma = 0.0;

  for (int i = 0; i < s->qtdFiliais; i++) {
    soma += getValorEstoque(s->filiais[i]);
  }

  return soma;
}

void imprimeSupermercado(tSuper *s, FILE *output) {
  fprintf(output, "Nome: %s\n", s->nome);
  for (int i = 0; i < s->qtdFiliais; i++) {
    imprimeFilial(s->filiais[i], output);
  }
}
