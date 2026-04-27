#ifndef _LISTA_H
#define _LISTA_H

typedef struct lista tLista;

typedef int (*funcao_compara)(void *, void *);
typedef void (*funcao_imprime)(void *);
typedef void (*funcao_libera)(void *);
typedef float (*funcao_get_valor)(void *);

tLista *criaLista();

void freeLista(tLista *l);

void pushLista(tLista *l, funcao_get_valor getValor, funcao_libera libera, funcao_imprime imprime, void *elemento);

void removeLista(tLista *l, funcao_compara f, void *elemento);

void imprimeLista(tLista *l);

float calculaMedia(tLista *l);

#endif
