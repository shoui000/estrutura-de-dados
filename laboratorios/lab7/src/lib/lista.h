/*
 * Dimitry Deveza - Laboratório 7 da disciplina Estrutura de Dados
 * Professora: Patrícia Dockhorn
 *
 * lista.h - Lista Ligada simples heterogênea com Sentinela
 */

#ifndef _LISTA_H
#define _LISTA_H

#include "professor.h"
#include "aluno.h"

typedef struct lista Lista;

typedef enum {
	PROFESSOR,
	ALUNO
} Tipo;

Lista* cria_lista();

void append_lista(Lista *l, void *elemento, Tipo tipo);

void imprime_relatorio_aluno(Lista *l);
void imprime_relatorio_professor(Lista *l);

void free_lista(Lista *l);

#endif // !_LISTA_H
