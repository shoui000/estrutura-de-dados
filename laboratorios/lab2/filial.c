#include "filial.h"

#include "estoque.h"

#include <stdio.h>
#include <stdlib.h>

struct filial {
  char *nome;
  tEstoque *estoque;
};

tFilial *leFilial(void **colecaoProdutos, int tamanhoColecao, FILE *input) {
  tFilial *f = malloc(sizeof(struct filial));

  fscanf(input, " %ms", &(f->nome));
  f->estoque = leEstoque(colecaoProdutos, tamanhoColecao, input);

  return f;
}

void freeFilial(tFilial *f) {
  freeEstoque(f->estoque);
  free(f->nome);
  free(f);
}

void imprimeFilial(tFilial *f, FILE *output) {
  fprintf(output, "Filial: %s\n", f->nome);
  imprimeEstoque(f->estoque, output);
}

float getValorEstoque(tFilial *f) {
  return getValorTotal(f->estoque);
}
