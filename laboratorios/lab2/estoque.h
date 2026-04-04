#ifndef _ESTOQUE_H
#define _ESTOQUE_H

#include "produto.h"

#include <stdio.h>

typedef struct estoque tEstoque;

tEstoque *leEstoque(void **colecaoProdutos, int tamanhoColecao, FILE *input);
void freeEstoque(tEstoque *e);
void imprimeEstoque(tEstoque *e, FILE *output);
float getValorTotal(tEstoque *e);

#endif
