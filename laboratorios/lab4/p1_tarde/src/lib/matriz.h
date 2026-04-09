#ifndef _MATRIZ_H
#define _MATRIZ_H

typedef struct matriz tMatriz;

tMatriz *criaMatriz(int linhas, int colunas);
void liberaMatriz(tMatriz *m);
void setElemento(tMatriz *m, int i, int j, char *elemento);
void procuraElemento(tMatriz *m, char *elemento);

void imprimeMatriz(tMatriz *m);

#endif // !_MATRIZ_H
