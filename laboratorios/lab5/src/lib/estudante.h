#ifndef _ESTUDANTE_H
#define _ESTUDANTE_H

typedef struct estudante tEstudante;

tEstudante *criaEstudante(int matricula, float ct, char *nome);

void freeEstudante(void *e);

char *getNome(tEstudante *e);
void setNome(tEstudante *e, char *nome);

int getMatricula(tEstudante *e);
void setMatricula(tEstudante *e, int matricula);

float getCr(void *e);
void setCr(tEstudante *e, float cr);

void imprimeEstudante(void *e);

int comparaMatricula(void *matricula, void *estudante);

#endif
