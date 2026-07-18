#include "Lista.h"

struct lista {
	Especie e;
	void *s;
	Lista *next;
	Lista *prev;
};

Lista *insere_lista(Lista *l, void *animal, Especie e) {
	Lista *n = malloc(sizeof(struct lista));
	n->next = l;
	n->prev = NULL;
	n->e = e;
	n->s = animal;

	if (l) {
		l->prev = n;
	}

	return n;
}

Lista *remove_lista(Lista *l, void *animal) {
	Lista *aux = l;

	for (;l && l->s != animal; l = l->next);

	if (!l) {
		return aux;
	}

	if (l->prev)
		l->prev->next = l->next;
	else
		aux = l->next;

	if (l->next)
		l->next->prev = l->prev;

	if (!l->next && !l->prev)
		aux = NULL;

	free(l);

	return aux;
}

int percorre_lista(Lista *l, int (*func)(void *animal, Especie e)) {

	int sum = 0;

	while (l) {
		sum += func(l->s, l->e);

		l = l->next;
	}

	return sum;
}

void free_lista(Lista *l) {
	Lista *aux;
	while (l) {
		aux = l;
		l = l->next;
		free(aux);
	}

}
