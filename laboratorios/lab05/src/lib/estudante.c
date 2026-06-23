#include "estudante.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct estudante {
  char *nome;
  float cr;
  int matricula;
};

tEstudante *criaEstudante(int matricula, float cr, char *nome) {
  tEstudante *e = malloc(sizeof(struct estudante));

  e->matricula = matricula;
  e->cr = cr;
  e->nome = strdup(nome);

  return e;
};

void freeEstudante(void *e) {
  tEstudante *es = (tEstudante *)e;
  free(es->nome);
  free(es);
}

char *getNome(tEstudante *e) {
  return e->nome;
}

void setNome(tEstudante *e, char *nome) {
	free(e->nome);
  e->nome = strdup(nome);
}

int getMatricula(tEstudante *e) {
  return e->matricula;
}
void setMatricula(tEstudante *e, int matricula) {
  e->matricula = matricula;
}

float getCr(void *e) {
  tEstudante *es = e;
  return es->cr;
}
void setCr(tEstudante *e, float cr) {
  e->cr = cr;
}

void imprimeEstudante(void *e) {
  tEstudante *es = (tEstudante *)e;
  printf("%d %s %.1f\n", es->matricula, es->nome, es->cr);
}
  
int comparaMatricula(void *matricula, void *estudante) {
  int *m = matricula;
  tEstudante *e = estudante;

  return *m == e->matricula;
}
