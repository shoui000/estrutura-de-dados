#ifndef _ESTUDANTE_H
#define _ESTUDANTE_H

typedef struct estudante tEstudante;

tEstudante *criaEstudante(int matricula, float ct, char *nome);

void freeEstudante(tEstudante *e);

char *getNome(tEstudante *e);
void setNome(tEstudante *e, char *nome);

int getMatricula(tEstudante *e);
void setMatricula(tEstudante *e, int matricula);

float getCr(tEstudante *e);
void setCr(tEstudante *e, float cr);

void imprimeEstudante(tEstudante *e);

#endif
