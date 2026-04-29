#ifndef _LISTA_H
#define _LISTA_H

#include "estudante.h"

typedef struct lista tLista;

tLista *criaLista();

void freeLista(tLista *l);

tLista *pushLista(tLista *l, tEstudante *e);

tLista *removeLista(tLista *l, int matricula);

void imprimeLista(tLista *l);

tLista *interpolaListas(tLista *l1, tLista *l2);

#endif
