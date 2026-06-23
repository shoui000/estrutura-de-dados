#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib/matriz.h"

int main(int argc, char **argv) {
	if (argc < 3) {
		perror("[erro] Foram passados menos argumentos do que o necessário.\n");
		exit(EXIT_FAILURE);
	}

	if (freopen(argv[1], "r", stdin) == NULL) {
		perror("[erro] freopen falhou ao abrir o arquivo de input");
		exit(EXIT_FAILURE);
	}

	if (freopen(argv[2], "w", stdout) == NULL) {
		perror("[erro] freopen falhou ao abrir o arquivo de output");
		exit(EXIT_FAILURE);
	}

	int linhas, colunas;
  char elemento[1024];

	scanf("%d %d", &linhas, &colunas);
	tMatriz *base = criaMatriz(linhas, colunas);

	for (int i = 0; i < linhas; i++) {
		for (int j = 0; j < colunas; j++) {
			scanf("%s", elemento);

			setElemento(base, i, j, elemento);
		}
	}

	imprimeMatriz(base);

	putchar('\n');
  printf("============================\n");

  char comando[1024];
  while (1) {
    printf("==> Digite a palavra para o caça-palavras ou 0, caso queira sair:\n");
    scanf(" %s", comando);
    if (strcmp(comando, "0") == 0) break;
    procuraElemento(base, comando);
    putchar('\n');
  }

	liberaMatriz(base);

	exit(EXIT_SUCCESS);
}
