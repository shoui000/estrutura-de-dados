#ifndef _CACHORRO_H
#define _CACHORRO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Agressividade.h"

typedef struct cachorro Cachorro;

Cachorro *inicCachorro(char *nome, Agressividade a);

void atribuiNivelAgressividadeCachorro(Cachorro *c, Agressividade n);

Agressividade get_agressividade_cachorro(Cachorro *d);

void imprimeCachorro(Cachorro *c);

void liberaCachorro(Cachorro *c);

#endif // !_CACHORRO_H
