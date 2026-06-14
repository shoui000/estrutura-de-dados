#include "aluno.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno {
	char* nome;
	char* cpf;
	float cr;
};

Aluno* cria_aluno(char *nome, char *cpf, float cr) {
	Aluno *a = malloc(sizeof(struct aluno));

	a->nome = strdup(nome);
	a->cpf = strdup(cpf);
	a->cr = cr;

	return a;
}

char* alu_get_nome(Aluno *a) {
	return a->nome;
}

char* alu_get_cpf(Aluno *a) {
	return a->cpf;
}

float alu_get_cr(Aluno *a) {
	return a->cr;
}

void imprime_aluno(Aluno *a) {
	printf("%s, CPF: %s e CR: %.2f\n", a->nome, a->cpf, a->cr);
}

void free_aluno(Aluno *a) {
	free(a->nome);
	free(a->cpf);
	free(a);
}
