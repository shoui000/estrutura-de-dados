#include "BanhoTosa.h"

#include "Gato.h"
#include "Lista.h"

#include <stdlib.h>
#include <string.h>

struct banhotosa {
	char *nome;
	Lista *agressivos;
	Lista *mansos;
};

BanhoTosa* inicBanhoTosa(char* nome) {
	BanhoTosa *b = malloc(sizeof(struct banhotosa));

	b->nome = strdup(nome);
	b->agressivos = b->mansos = NULL;

	return b;
}

void cadastraCachorro(BanhoTosa* loja, Cachorro* dog) {
	Lista **l = (get_agressividade_cachorro(dog) == BRAVO) ? &loja->agressivos : &loja->mansos;

	*l = insere_lista(*l, (void *)dog, tCachorro);
}

void cadastraGato(BanhoTosa* loja, Gato* cat) {
	Lista **l = (get_agressividade_gato(cat) == BRAVO) ? &loja->agressivos : &loja->mansos;

	*l = insere_lista(*l, (void *)cat, tGato);
}

void atualizaSituacaoGato(BanhoTosa *loja, Gato *cat) {
	loja->agressivos = remove_lista(loja->agressivos, cat);
	loja->mansos = remove_lista(loja->mansos, cat);

	cadastraGato(loja, cat);
}

void atualizaSituacaoCachorro(BanhoTosa *loja, Cachorro *dog) {
	loja->agressivos = remove_lista(loja->agressivos, dog);
	loja->mansos = remove_lista(loja->mansos, dog);

	cadastraCachorro(loja, dog);
}

int calculaPrecoAgressivo(void *animal, Especie e) {
	if (e == tGato) return 35;
	else return 45;
}

int calculaPrecoManso(void *animal, Especie e) {
	if (e == tGato) return 30;
	else return 40;
}

float calculaReceita(BanhoTosa* loja) {
	float sum = 0;

	sum += percorre_lista(loja->agressivos, calculaPrecoAgressivo);
	sum += percorre_lista(loja->mansos, calculaPrecoManso);

	return sum;
}

int imprimeAnimalAgressividade(void *animal, Especie e) {
	if (e == tGato) {
		imprimeGato((Gato *)animal);
	} else if (e == tCachorro) {
		imprimeCachorro((Cachorro *)animal);
	}

	return 0;
}

void imprimeBanhoTosa(BanhoTosa* loja) {
	printf("BANHO e TOSA %s\n", loja->nome);

	percorre_lista(loja->agressivos, imprimeAnimalAgressividade);
	percorre_lista(loja->mansos, imprimeAnimalAgressividade);
}

void liberaBanhoTosa(BanhoTosa* loja) {
	free_lista(loja->agressivos);
	free_lista(loja->mansos);
	free(loja->nome);
	free(loja);
}
