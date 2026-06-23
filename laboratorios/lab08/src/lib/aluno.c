#include "aluno.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno {
  char *nome;
  int mat;
  float cr;
};

Aluno *aluno_cria(char *nome, int mat, float cr) {
  Aluno *a = malloc(sizeof(struct aluno));
  a->nome = strdup(nome);
  a->mat = mat;
  a->cr = cr;

  return a;
}

void aluno_libera(Aluno *a) {
  free(a->nome);
  free(a);
}

int aluno_get_matricula(Aluno *a) { return a->mat; }
char *aluno_get_nome(Aluno *a) { return a->nome; }

void aluno_imprime(Aluno *a) { printf("{%s %d %.2f}", a->nome, a->mat, a->cr); }
