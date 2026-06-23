#include "lista.h"
#include "professor.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula Celula;

struct celula {
	void *data;
	Tipo tipo;
	Celula *prox;
};

struct lista {
	Celula *inicio, *fim;
};

Lista* cria_lista() {
	Lista *l = malloc(sizeof(struct lista));

	l->inicio = l->fim = NULL;

	return l;
}

void append_lista(Lista *l, void *elemento, Tipo tipo) {
	Celula *c = malloc(sizeof(struct celula));

	c->data = elemento;
	c->tipo = tipo;
	c->prox = NULL;

	if (l->fim) {
		l->fim->prox = c;
	}

	l->fim = c;

	if (!l->inicio) {
		l->inicio = c;
	}
}

void free_lista(Lista *l) {
	Celula *c = l->inicio, *temp;
	while (c) {
		temp = c;
		c = c->prox;
		switch (temp->tipo) {
			case PROFESSOR:
				free_professor(temp->data);
				break;
			case ALUNO:
				free_aluno(temp->data);
				break;
				
		}
		free(temp);
	}
	free(l);
}

void imprime_relatorio_professor(Lista *l) {
	Celula *c = l->inicio;

	float media = 0;
	int qtd = 0;

	printf("PROFESSORES\n");
	while (c) {
		if (c->tipo != PROFESSOR) {
			c = c->prox;
			continue;
		}

		Professor *p = c->data;

		imprime_professor(p);
		media += pro_get_salario(p);
		qtd++;

		c = c->prox;
	}

	putchar('\n');

	media = (qtd > 0) ? (media / (float) qtd) : 0;

	printf("Média de salário dos %d professores: %.2f\n", qtd, media);
}

void imprime_relatorio_aluno(Lista *l) {
	Celula *c = l->inicio;

	float media = 0;
	int qtd = 0;

	printf("ALUNOS\n");
	while (c) {
		if (c->tipo != ALUNO) {
			c = c->prox;
			continue;
		}

		Aluno *a = c->data;

		imprime_aluno(a);
		media += alu_get_cr(a);
		qtd++;

		c = c->prox;
	}

	putchar('\n');

	media = (qtd > 0) ? (media / (float) qtd) : 0;

	printf("Média de CR dos %d alunos: %.2f\n", qtd, media);
}
