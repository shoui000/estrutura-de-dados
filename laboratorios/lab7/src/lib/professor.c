#include "professor.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct professor {
	char* nome;
	char* cpf;
	float salario;
};

Professor* cria_professor(char *nome, char* cpf, float salario) {
	Professor *p = malloc(sizeof(struct professor));

	p->nome = strdup(nome);
	p->cpf = strdup(cpf);
	p->salario = salario;

	return p;
}

char* pro_get_nome(Professor *p) {
	return p->nome;
}

char* pro_get_cpf(Professor *p) {
	return p->cpf;
}

float pro_get_salario(Professor *p) {
	return p->salario;
}

void imprime_professor(Professor *p) {
	printf("%s, CPF: %s e Salário: %.2f\n", p->nome, p->cpf, p->salario);
}

void free_professor(Professor *p) {
	free(p->nome);
	free(p->cpf);
	free(p);
}
