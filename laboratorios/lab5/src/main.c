#include <stdio.h>
#include <stdlib.h>

#include "lib/estudante.h"
#include "lib/lista.h"

int main(int argc, char **argv) {
	if (argc < 3) {
		perror("menos argumentos do que o necessário");
		exit(EXIT_FAILURE);
	}

  if (freopen(argv[1], "r", stdin) == NULL) {
    perror("erro ao abrir arquivo de entrada!\n");
    exit(EXIT_FAILURE);
  }

  if (freopen(argv[2], "w", stdout) == NULL) {
    perror("erro ao abrir arquivo de saida!\n");
    exit(EXIT_FAILURE);
  }

  int n;
  scanf("%d", &n);

  tLista *l = criaLista();

  for (int i = 0; i < n; i++) {
    int matricula;
    float cr;
    char nome[128];

    scanf("%d %s %f", &matricula, nome, &cr);

    tEstudante *e = criaEstudante(matricula, cr, nome);
    pushLista(l, getCr, freeEstudante, imprimeEstudante, (void *)e);
  }

  imprimeLista(l);
  printf("================\n");

  int num_a_remover;

	while ( scanf("%d", &num_a_remover) != EOF) {
		removeLista(l, comparaMatricula, &num_a_remover);
		imprimeLista(l);
		printf("================\n");
	}

  freeLista(l);
}
