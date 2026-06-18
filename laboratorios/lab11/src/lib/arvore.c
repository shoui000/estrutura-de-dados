#include "arvore.h"

#include <stdio.h>
#include <stdlib.h>

#define max(x, y) (x > y) ? x : y

struct arvore {
	char dado;
	arv *filho, *irmao;
};

arv *cria_arvore(char elemento) {
	arv *a = malloc(sizeof(struct arvore));
	a->dado = elemento;
	a->filho = a->irmao = NULL;
	return a;
}

void insere_filho(arv *pai, arv *filho) {
	if (!pai) return;

	filho->irmao = pai->filho;
	pai->filho = filho;
}

int folhas(arv *arv) {
	if (!arv) return 0;

	return ((arv->filho) ? folhas(arv->filho) : 1) + folhas(arv->irmao);
}

void imprime_arvore(arv *arv) {
	if (!arv) return;
	printf("<%c", arv->dado);
	imprime_arvore(arv->filho);
	putchar('>');
	imprime_arvore(arv->irmao);
}

int altura(arv *a) {
  int hmax = -1;
  arv *p;
  for (p = a->filho; p; p = p->irmao) {
    int h = altura(p);
    if (h > hmax) hmax = h;
  }
  return hmax + 1;
}

char *find_arvore(arv *arv, char dado) {
	if (!arv) return NULL;

	if (arv->dado == dado) return &(arv->dado);

	char *dado_filho = find_arvore(arv->filho, dado);

	return (dado_filho) ? dado_filho : find_arvore(arv->irmao, dado);
}

void free_arvore(arv *arv) {
	if (!arv) return;
	free(arv);
}
