#ifndef _MATRIZ_H
#define _MATRIZ_H

typedef struct matriz tMatriz;

tMatriz *criaMatriz(int linhas, int colunas);
void liberaMatriz(tMatriz *m);

int getElemento(tMatriz *m, int i, int j);
void setElemento(tMatriz *m, int i, int j, int elemento);

tMatriz *suavizaMatriz(tMatriz *m);

void imprimeMatriz(tMatriz *m);

#endif // !_MATRIZ_H
