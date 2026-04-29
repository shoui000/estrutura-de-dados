#include <stdio.h>
#include <stdlib.h>

#include "lib/estudante.h"
#include "lib/lista.h"

int main(int argc, char **argv) {
	if (argc < 5) {
		perror("erro: menos argumentos que o mínimo necessário");
		exit(EXIT_FAILURE);
	}

  if (freopen(argv[1], "r", stdin) == NULL) {
    perror("erro ao abrir arquivo de entrada!\n");
    exit(EXIT_FAILURE);
  }

  if (freopen(argv[3], "w", stdout) == NULL) {
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
    l = pushLista(l, e);
  }

  imprimeLista(l);

	 int num_a_remover;

	while ( scanf("%d", &num_a_remover) != EOF) {
		l = removeLista(l, num_a_remover);
		imprimeLista(l);
	}

  if (freopen(argv[2], "r", stdin) == NULL) {
    perror("erro ao abrir arquivo de entrada!\n");
    exit(EXIT_FAILURE);
  }

  if (freopen(argv[4], "w", stdout) == NULL) {
    perror("erro ao abrir arquivo de saida!\n");
    exit(EXIT_FAILURE);
  }

	scanf("%d", &n);

  tLista *l2 = criaLista();

  for (int i = 0; i < n; i++) {
    int matricula;
    float cr;
    char nome[128];

    scanf("%d %s %f", &matricula, nome, &cr);

    tEstudante *e = criaEstudante(matricula, cr, nome);
    l2 = pushLista(l2, e);
  }

	tLista *l3 = interpolaListas(l, l2);
	
	imprimeLista(l3);

  freeLista(l);
  freeLista(l2);
  freeLista(l3);
}
