#include "estoque.h"
#include "produto.h"

#include <stdlib.h>
#include <stdio.h>

struct estoque {
  tProduto **itens;
  int *qtdItens;
  int qtdTiposItens;
  float valorTotal;
};

void calculaValorEstoque(tEstoque *e);

tEstoque *leEstoque(void **catalogo, int tamanhoColecao, FILE *input) {
  tProduto **colecaoProdutos = (tProduto **)catalogo;
  tEstoque *e = malloc(sizeof(struct estoque));

  fscanf(input, " %d", &(e->qtdTiposItens));

  e->itens = malloc(e->qtdTiposItens * sizeof(void *));
  e->qtdItens = malloc(e->qtdTiposItens * sizeof(int));

  e->valorTotal = 0;

  tProduto *prod;
  int idProd, qtdProd, qtdProdutosCadastrados = 0;
  for (int i = 0; i < e->qtdTiposItens; i++) {
    fscanf(input, " %d %d", &idProd, &qtdProd);

    prod = findProduto(colecaoProdutos, tamanhoColecao, idProd);

    if (prod == NULL) {
      printf("[ERRO] Produto nao cadastrado na colecao!\n");
      continue;
    }

    e->itens[qtdProdutosCadastrados] = prod;
    e->qtdItens[qtdProdutosCadastrados++] = qtdProd;
    e->valorTotal = qtdProd * getValorProduto(prod);
  }

  return e;
}

void freeEstoque(tEstoque *e) {
  free(e->itens);
  free(e->qtdItens);
  free(e);
}

float getValorTotal(tEstoque *e) {
  return e->valorTotal;
}

void calculaValorEstoque(tEstoque *e) {
  e->valorTotal = 0;

  for (int i = 0; i < e->qtdTiposItens; i++) {
    e->valorTotal += getValorProduto(e->itens[i]) * e->qtdItens[i];
  }
}

void imprimeEstoque(tEstoque *e, FILE *output) {
  fprintf(output, "Estoque: %.2f\n", e->valorTotal);
  for (int i = 0; i < e->qtdTiposItens; i++) {
    fprintf(output, "Item: %s, valor unitário: %.2f, quantidade: %d\n",
        getNomeProduto(e->itens[i]),
        getValorProduto(e->itens[i]),
        e->qtdItens[i]
        );
  }
}
