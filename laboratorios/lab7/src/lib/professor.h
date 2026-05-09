#ifndef _PROFESSOR_H

typedef struct professor Professor;

Professor* cria_professor(char *nome, char* cpf, float salario);

char* pro_get_nome(Professor *p);
char* pro_get_cpf(Professor *p);
float pro_get_salario(Professor *p);

void imprime_professor(Professor *p);

void free_professor(Professor *p);

#endif // !_PROFESSOR_H
