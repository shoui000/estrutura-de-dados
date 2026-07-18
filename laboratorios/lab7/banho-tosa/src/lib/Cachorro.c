#include "Cachorro.h"

struct cachorro {
	char *nome;
	Agressividade a;
};

Cachorro *inicCachorro(char *nome, Agressividade a) {
	Cachorro *g = malloc(sizeof(struct cachorro));
	g->nome = strdup(nome);
	g->a = a;

	return g;
}

void atribuiNivelAgressividadeCachorro(Cachorro *c, Agressividade n) {
	c->a = n;
}

Agressividade get_agressividade_cachorro(Cachorro *d) {
	return d->a;
}

void imprimeCachorro(Cachorro *g) {
	printf("Cachorro: %s, ", g->nome);
	printf((g->a == BRAVO) ? "Bravo" : "Manso");
	putchar('\n');
}

void liberaCachorro(Cachorro *g) {
	free(g->nome);
	free(g);
}
