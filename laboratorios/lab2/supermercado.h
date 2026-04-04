#ifndef _SUPERMERCADO_H
#define _SUPERMERCADO_H

#include <stdio.h>

typedef struct supermercado tSuper;

tSuper *leSupermercado(void **catalogo, int tamanhoCatalogo, FILE *input);

void freeSupermercado(tSuper *s);

void imprimeSupermercado(tSuper *s, FILE *output);

#endif
