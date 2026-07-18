#ifndef _GATO_H
#define _GATO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Agressividade.h"

typedef struct gato Gato;

Gato *inicGato(char *nome, Agressividade a);

void atribuiNivelAgressividadeGato(Gato *c, Agressividade n);

Agressividade get_agressividade_gato(Gato *d);

void imprimeGato(Gato *g);

void liberaGato(Gato *g);

#endif // !_GATO_H
