#ifndef _ARVORE_H
#define _ARVORE_H

typedef struct arvore arv;

arv *cria_arvore(char elemento);
void insere_filho(arv *pai, arv *filho);
int folhas(arv *arv);
void imprime_arvore(arv *arv);
int altura(arv *arv);
char *find_arvore(arv *arv, char dado);
void free_arvore(arv *arv);

#endif // !_ARVORE_H
