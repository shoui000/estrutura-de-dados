#ifndef _FILIAL_H
#define _FILIAL_H

#include <stdio.h>

typedef struct filial tFilial;

tFilial *leFilial(void **catalogo, int tamanhoCatalogo, FILE *input);

void freeFilial(tFilial *f);

void imprimeFilial(tFilial *f, FILE *output);

float getValorEstoque(tFilial *f);

#endif
