#include "lib/aluno.h"
#include "lib/lista.h"
#include "lib/professor.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	if (argc < 3) {
		perror("erro: menos argumentos que o mínimo necessário");
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

	Lista *l = cria_lista();

	char tipo, nome[128], cpf[16];
	float crsalario;
	for (int i = 0; i < n; i++) {
		scanf(" %c %s %s %f", &tipo, nome, cpf, &crsalario);

		if (tipo == 'A') {
			Aluno *a = cria_aluno(nome, cpf, crsalario);
			append_lista(l, (void *)a, ALUNO);
		} else if (tipo == 'P') {
			Professor *p = cria_professor(nome, cpf, crsalario);
			append_lista(l, (void *)p, PROFESSOR);
		}
	}


	imprime_relatorio_professor(l);
	putchar('\n');
	imprime_relatorio_aluno(l);

	free_lista(l);

	exit(EXIT_SUCCESS);
}
