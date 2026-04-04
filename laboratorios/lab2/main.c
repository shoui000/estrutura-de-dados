#include "supermercado.h"
#include "produto.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
	if (argc < 3) {
		printf("[ERRO] Caminho dos arquivos de entrada e saida não foram passados!\n");
		exit(1);
	}

  FILE *input = fopen(argv[1], "r");
  FILE *output = fopen(argv[2], "w");

  if (input == NULL) {
    printf("[ERRO] Arquivo de input nao existe!\n");
    exit(1);
  }

  if (output == NULL) {
    printf("[ERRO] Arquivo de output nao existe!\n");
    exit(1);
  }

  tProduto **catalogo;
  int tamanhoCatalogo;

  fscanf(input, " %d", &tamanhoCatalogo);

  catalogo = malloc(tamanhoCatalogo * sizeof(void *));

  for (int i = 0; i < tamanhoCatalogo; i++) {
    catalogo[i] = leProduto(input);
  }

  tSuper *s = leSupermercado((void **)catalogo, tamanhoCatalogo, input);

  imprimeSupermercado(s, output);

  freeSupermercado(s);
  
  for (int i = 0; i < tamanhoCatalogo; i++) {
    freeProduto(catalogo[i]);
  }

  fclose(input);
  fclose(output);
  exit(0);
}
