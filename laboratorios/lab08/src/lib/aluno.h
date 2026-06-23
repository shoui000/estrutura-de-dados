#ifndef _ALUNO_H
#define _ALUNO_H

typedef struct aluno Aluno;

Aluno *aluno_cria(char *nome, int mat, float cr);

char *aluno_get_nome(Aluno *a);

void aluno_libera(Aluno *a);

int aluno_get_matricula(Aluno *a);

void aluno_imprime(Aluno *a);

#endif // !_ALUNO_H
