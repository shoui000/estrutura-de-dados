#ifndef _LISTA_H
#define _LISTA_H

#include <stdlib.h>
#include "Gato.h"
#include "Cachorro.h"

typedef struct lista Lista;

typedef enum {
	tGato,
	tCachorro
} Especie;

Lista *insere_lista(Lista *l, void *animal, Especie e);

Lista *remove_lista(Lista *l, void *animal);

int percorre_lista(Lista *l, int (*func)(void *animal, Especie e));

void free_lista(Lista *l);

#endif // !_LISTA_H
