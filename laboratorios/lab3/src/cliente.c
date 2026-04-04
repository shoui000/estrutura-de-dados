#include <stdio.h>
#include <stdlib.h>

#include "matriz.h"

int main(int argc, char **argv) {

    if (argc < 3) {
        printf("[cliente] quantidade de argumentos abaixo do esperado\n");
        exit(EXIT_FAILURE);
    }

    if (freopen(argv[1], "r", stdin) == NULL) {
        perror("[cliente] erro ao abrir arquivo\n");
        exit(EXIT_FAILURE);
    }

    if (freopen(argv[2], "w", stdout) == NULL) {
        perror("[cliente] erro ao abrir arquivo\n");
        exit(EXIT_FAILURE);
    }

    int l, c;
    scanf(" %d %d", &l, &c);
    Matriz *m = inicializaMatriz(l, c);

    int n;
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf(" %d", &n);
            modificaElemento(m, i, j, n);
        }
    }

    imprimeMatriz(m);

    putchar('\n');

    printf("A matriz transposta eh:\n");
    Matriz *t = transposta(m);
    imprimeMatriz(t);

    putchar('\n');

    printf("A matriz multiplicacao eh:\n");
    Matriz *mult = multiplicacao(m, t);
    imprimeMatriz(mult);

    destroiMatriz(m);
    destroiMatriz(t);
    destroiMatriz(mult);

    exit(EXIT_SUCCESS);
}