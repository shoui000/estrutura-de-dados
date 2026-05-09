#ifndef _ALUNO_H

typedef struct aluno Aluno;

Aluno* cria_aluno(char *nome, char *cpf, float cr);

char* alu_get_nome(Aluno *a);
char* alu_get_cpf(Aluno *a);
float alu_get_cr(Aluno *a);

void imprime_aluno(Aluno *a);

void free_aluno(Aluno *a);

#endif // !_ALUNO_H
