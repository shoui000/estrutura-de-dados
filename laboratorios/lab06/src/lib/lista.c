#include "lista.h"
#include "estudante.h"

#include <stdio.h>
#include <stdlib.h>

struct lista {
	tEstudante *e;
	tLista *prox;
	tLista *ant;
};

tLista *criaLista() {
	return NULL;
}

void freeLista(tLista *l) {
	tLista *x = l->prox;

	while (l) {
		freeEstudante(l->e);
		free(l);
		l = x;
		if (x) {
			x = x->prox;
		}
	}
}

tLista *pushLista(tLista *l, tEstudante *e) {
	tLista *new = malloc(sizeof(tLista));
	new->e = e;
	new->prox = l;
	new->ant = NULL;

	if (l) {
		l->ant = new;
	}

	return new;
}

tLista *removeLista(tLista *l, int matricula) {
	tLista *p = l;
	while (l) {
		if (getMatricula(l->e) == matricula) {

			if (l->ant) {
				l->ant->prox = l->prox;
			} else {
				p = l->prox;
			}

			if (l->prox) {
				l->prox->ant = l->ant;
			}

			freeEstudante(l->e);
			free(l);

			break;
		}

		l = l->prox;
	}

	return p;
}

void imprimeLista(tLista *l) {
	float soma = 0;
	int count = 0;

	while (l->prox) { l = l->prox; }

	while (l) {
		imprimeEstudante(l->e);
		soma += getCr(l->e);
		count++;
		l = l->ant;
	}

	float media = (count == 0) ? 0 : soma / count;
	printf("Média: %.2f\n", media);
	printf("================\n");
}

tLista *interpolaListas(tLista *l1, tLista *l2) {
	tLista *l3 = NULL;

	while (l1->prox) {l1 = l1->prox;}
	while (l2->prox) {l2 = l2->prox;}

	int count = 0;
	while (l1 != NULL || l2 != NULL) {
		if ((l1 && count % 2 == 0) || !l2) {
			tEstudante *e = criaEstudante(getMatricula(l1->e), getCr(l1->e), getNome(l1->e));
			l3 = pushLista(l3, e);
			l1 = l1 ->ant;
		}

		if ((l2 && count % 2 == 1) || !l1) {
			tEstudante *e = criaEstudante(getMatricula(l2->e), getCr(l2->e), getNome(l2->e));
			l3 = pushLista(l3, e);
			l2 = l2->ant;
		}

		count++;
	}

	return l3;
}
