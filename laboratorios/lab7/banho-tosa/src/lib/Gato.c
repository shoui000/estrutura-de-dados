#include "Gato.h"

struct gato {
	char *nome;
	Agressividade a;
};

Gato *inicGato(char *nome, Agressividade a) {
	Gato *g = malloc(sizeof(struct gato));
	g->nome = strdup(nome);
	g->a = a;

	return g;
}

void atribuiNivelAgressividadeGato(Gato *c, Agressividade n) {
	c->a = n;
}

Agressividade get_agressividade_gato(Gato *d) {
	return d->a;
}

void imprimeGato(Gato *g) {
	printf("Gato: %s, ", g->nome);
	printf((g->a == BRAVO) ? "Bravo" : "Manso");
	putchar('\n');
}

void liberaGato(Gato *g) {
	free(g->nome);
	free(g);
}
