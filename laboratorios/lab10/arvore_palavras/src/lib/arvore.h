#ifndef _ARVORE_H
#define _ARVORE_H

typedef struct arv arv;

arv *insere_arv(arv *a, char *palavra);

arv *find_palavra(arv *a, char *palavra);

int get_quantidade_palavras(arv *a);

char *get_palavra_arv(arv *a);

int get_tamanho(arv *a);

int get_frequencia(arv *a, char *palavra);

arv *get_palavra_mais_frequente(arv *a);

void free_arv(arv *a);

int get_palavras(arv *a, arv **vetor);

int get_frequencia_palavra(arv *a);

int compara_nos(const void *a, const void *b);

#endif
