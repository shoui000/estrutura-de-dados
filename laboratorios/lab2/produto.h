#ifndef _PRODUTO_H
#define _PRODUTO_H

#include <stdio.h>

typedef struct produto tProduto;

tProduto *leProduto(FILE *input);
void freeProduto(tProduto *p);
int getIdProduto(tProduto *p);
char *getNomeProduto(tProduto *p);
float getValorProduto(tProduto *p);
int getIdProduto(tProduto *p);

tProduto *findProduto(tProduto **produtos, int qtdProdutos, int id);

#endif
