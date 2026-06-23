#include "arvore.h"

#include "aluno.h"

#include <stdio.h>
#include <stdlib.h>

#define max(x, y) (x > y) ? x : y

struct arv {
  Aluno *a;
  Arv *esq, *dir;
};

Arv *arv_criavazia(void) { return NULL; }

Arv *arv_cria(Aluno *c, Arv *e, Arv *d) {
  Arv *a = malloc(sizeof(struct arv));
  a->a = c;
  a->esq = e;
  a->dir = d;

  return a;
}

Arv *arv_libera(Arv *a) {
  if (a) {
    arv_libera(a->esq);
    arv_libera(a->dir);
    aluno_libera(a->a);
    free(a);
  }

  return NULL;
}

Arv *arv_insere(Arv *a, Aluno *c) {
	if (!a) return arv_cria(c, NULL, NULL);

	if (aluno_get_matricula(c) > aluno_get_matricula(a->a)) a->dir = arv_insere(a->dir, c);
	if (aluno_get_matricula(c) < aluno_get_matricula(a->a)) a->esq = arv_insere(a->esq, c);

	return a;
}

int arv_vazia(Arv *a) { return (!a); }

int arv_pertence(Arv *a, int mat) {
  if (!a)
    return 0;

  if (aluno_get_matricula(a->a) == mat)
    return 1;

  return arv_pertence(a->esq, mat) || arv_pertence(a->dir, mat);
}

void arv_imprime(Arv *a) {
	if (!a) {
		printf("<>");
		return;
	}

	printf("< ");
	aluno_imprime(a->a);
	putchar(' ');
	arv_imprime(a->esq);
	putchar(' ');
	arv_imprime(a->dir);
	printf(" >");
}

Arv *arv_pai(Arv *a, int mat) {
	 if (!a || !(a->esq || a->dir)) return NULL;

  if ((a->esq && aluno_get_matricula(a->esq->a) == mat) || (a->dir && aluno_get_matricula(a->dir->a) == mat)) {
    return a;
  }

  Arv *pai_l = arv_pai(a->esq, mat);

  return pai_l ? pai_l : arv_pai(a->dir, mat);
}

int folhas(Arv *a) {
	if (!a) return 0;

	if (!(a->esq || a->dir)) return 1;

	return folhas(a->esq) + folhas(a->dir);
}

int ocorrencias(Arv *a, int mat) {
	if (!a) return 0;

	return (aluno_get_matricula(a->a) == mat) + ocorrencias(a->esq, mat) + ocorrencias(a->dir, mat);
}

int altura(Arv *a) {
	if (!a) return 0;

	return (max(altura(a->esq), altura(a->dir)) + 1);
}
