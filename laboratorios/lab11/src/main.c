#include "lib/arvore.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

  if (argc < 3) {
    perror("[erro] foram passados menos argumentos que o necessário [3]\n");
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

  arv *nos[26];
  arv *raiz;

  for (int i = 0; i < 26; i++) {
    nos[i] = cria_arvore('A' + i);
  }

  char a, b;
  while (scanf(" %c:%c", &a, &b) == 2) {
    if (b == '-') {
      raiz = nos[a-'A'];
      continue;
    }

    insere_filho(nos[b-'A'], nos[a-'A']);
  }

	printf("Arvore:\n");

	imprime_arvore(raiz);

	putchar('\n');
	putchar('\n');
	printf("Altura: %d\n", altura(raiz));
	printf("Folhas: %d\n", folhas(raiz));
	putchar('\n');
	printf("Digite um aluno para buscar:\n");
  if (find_arvore(raiz, a)) {
    printf("Item encontrado na arvore.\n");
  } else {
    printf("Item não encontrado na arvore.\n");
  }
	for (int i = 0; i < 26; i++) {
		free_arvore(nos[i]);
	}
}

