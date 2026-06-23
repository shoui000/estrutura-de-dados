#include <stdio.h>
#include <stdlib.h>

#include "lib/arvore.h"

int main(int argc, char **argv) {
  if (argc < 3) {
    perror("[erro] menos argumentos que o necessario (3)\n");
    exit(EXIT_FAILURE);
  }

  if (freopen(argv[1], "r", stdin) == NULL) {
    perror("[erro] houve erro ao abrir o arquivo de entrada\n");
    exit(EXIT_FAILURE);
  }

  if (freopen(argv[2], "w", stdout) == NULL) {
    perror("[erro] houve erro ao abrir o arquivo de saida\n");
    exit(EXIT_FAILURE);
  }

  arv *a = NULL;

  char buffer[512];
  while (scanf(" %511[^. ]", buffer) == 1) {
    a = insere_arv(a, buffer);
  }

	int n = get_tamanho(a);
	arv *palavras[n];

	get_palavras(a, palavras);

	qsort(palavras, n, sizeof(arv *), compara_nos);

	for (int i = 0; i < n; i++) {
		printf("%s %d\n", get_palavra_arv(palavras[i]), get_frequencia_palavra(palavras[i]));
	}

	printf("------------------------\n");

	printf("%d palavras distintas encontradas\n", n);
	printf("%d palavras no total\n", get_quantidade_palavras(a));
	arv *palavra_mais_frequente = get_palavra_mais_frequente(a);
	printf("%s é a palavra de maior frequência (%d)\n", get_palavra_arv(palavra_mais_frequente), get_frequencia_palavra(palavra_mais_frequente));

  free_arv(a);

  exit(EXIT_SUCCESS);
}
