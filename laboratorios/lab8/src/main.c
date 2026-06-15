#include "lib/aluno.h"
#include "lib/arvore.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	if (argc < 3) {
		perror("[erro] foram passados menos argumentos que o necessário (3)\n");
		exit(EXIT_FAILURE);
	}

	if (freopen(argv[1], "r", stdin) == NULL) {
		perror("[erro] ocorreu um erro ao abrir o arquivo de entrada\n");
		exit(EXIT_FAILURE);
	}

	if (freopen(argv[2], "w", stdout) == NULL) {
		perror("[erro] ocorreu um erro ao abrir o arquivo de saida\n");
		exit(EXIT_FAILURE);
	}

	Arv *a = arv_criavazia();

	int n;
	scanf("%d ", &n);

	char buffer[512];
	int mat;
	float cr;

	for (int i = 0; i < n; i++) {
		scanf(" %[^\n] ", buffer);
		scanf(" %d %f", &mat, &cr);

		a = arv_insere(a, aluno_cria(buffer, mat, cr));
	}

	scanf("%[^\n] ", buffer);
	scanf("%d %f", &mat, &cr);
	Aluno *aluno = aluno_cria(buffer, mat, cr);

	printf("====== RELATÓRIO ======\n");
	printf("Árvore vazia? %s\n", (arv_vazia(a) ? "Sim" : "Não"));
	printf("%s pertence à Árvore? %s com %d ocorrências\n", aluno_get_nome(aluno), (arv_pertence(a, aluno_get_matricula(aluno)) ? "Sim" : "Não"), ocorrencias(a, aluno_get_matricula(aluno)));
	printf("Quantidade de folhas: %d\n", folhas(a));
	printf("Altura da Árvore: %d\n", altura(a));
	printf("Árvore:\n");
	arv_imprime(a);
	putchar('\n');
	printf("====== RELATÓRIO ======\n");

	arv_libera(a);
	aluno_libera(aluno);
}
