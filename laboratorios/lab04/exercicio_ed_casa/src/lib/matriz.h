#ifndef _MATRIZ_H
#define _MATRIZ_H

typedef struct matriz tMatriz;

tMatriz *criaMatriz(int linha, int coluna);
void setElemento(tMatriz *m, int linha, int coluna, char *elemento);
char* getElemento(tMatriz *m, int linha, int coluna);
void exterminaMatriz(tMatriz *m);
void organizaMatriz(tMatriz *base);
tMatriz *criaTransposta(tMatriz *base);
void imprimeMatriz(tMatriz *m);

#endif
