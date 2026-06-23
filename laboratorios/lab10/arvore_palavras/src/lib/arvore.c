#include "arvore.h"

#include <string.h>
#include <stdlib.h>

struct arv {
	char *palavra;
	int quantidade;
	arv *esq, *dir;
};

arv *insere_arv(arv *a, char *palavra) {
	if (!a) {
		a = malloc(sizeof(arv));
		a->palavra = strdup(palavra);
		a->esq = a->dir = NULL;
		a->quantidade = 1;
	} else {
		int diff = strcmp(a->palavra, palavra);

		if (diff == 0) {
			a->quantidade++;
		} else if (diff < 0) {
			a->esq = insere_arv(a->esq, palavra);
		} else if (diff > 0) {
			a->dir = insere_arv(a->dir, palavra);
		}
	}

	return a;
}

char *get_palavra_arv(arv *a) {
	return a->palavra;
}

arv *find_palavra(arv *a, char *palavra) {
	if (!a) return NULL;

	int diff = strcmp(a->palavra, palavra);
	if (diff == 0) return a;
	else if (diff > 0) return find_palavra(a->dir, palavra);
	else if (diff < 0) return find_palavra(a->esq, palavra);

	return NULL;
}

int get_tamanho(arv *a) {
	if (!a) return 0;

	return 1 + get_tamanho(a->esq) + get_tamanho(a->dir);
}

int get_quantidade_palavras(arv *a) {
	if (!a) return 0;

	return a->quantidade + get_quantidade_palavras(a->esq) + get_quantidade_palavras(a->dir);
}

int get_frequencia(arv *a, char *palavra) {
	return find_palavra(a, palavra)->quantidade;
}

int get_frequencia_palavra(arv *a) {
	return a->quantidade;
}

arv *get_palavra_mais_frequente(arv *a) {
	if (!a) return NULL;

	arv *mDir = get_palavra_mais_frequente(a->dir);
	arv *mEsq = get_palavra_mais_frequente(a->esq);

	if (mDir && mEsq) {
		return (a->quantidade > mEsq->quantidade && a->quantidade > mDir->quantidade ? a : (mEsq->quantidade > mDir->quantidade ? mEsq : mDir));
	} else if (mEsq) {
		return (a->quantidade > mEsq->quantidade) ? a : mEsq;
	} else if (mDir) {
		return (a->quantidade > mDir->quantidade) ? a : mDir;
	} 

	return a;
}

void free_arv(arv *a) {
	if (!a) return;

	free_arv(a->esq);
	free_arv(a->dir);
	free(a->palavra);
	free(a);
}

int get_palavras(arv *a, arv **vetor) {
	if (!a) return 0;

	int n = 0;
	n += get_palavras(a->dir, vetor);
	vetor[n++] = a;
	n += get_palavras(a->esq, vetor + n);

	return n;
}

int compara_nos(const void *a, const void *b) {
	arv *arv_a = *(arv **) a;
	arv *arv_b = *(arv **) b;

	if (arv_a->quantidade == arv_b->quantidade) return 0;

	return arv_a->quantidade > arv_b->quantidade ? 1 : -1;
}
