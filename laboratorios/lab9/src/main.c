#include "lib/busca_ordenacao.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Bubble sort possui uma complexidade de O(n^2) no pior e no caso médio e O(n) no melhor caso.
 * Quick Sort possui uma complexidade de O(n^2) no pior caso e O(n log n) no melhor e médio casos.
 *
 * Linear Search possui complexidade de O(n) 
 * Binary search possui complexidade de O(log n)
 */

int main() {
	int **vetores = cria_vetores_base(3);


	clock_t start_bubble_sort = clock();
	bubble_sort(vetores[0], 100000);
	clock_t end_bubble_sort = clock();

	clock_t start_quick_sort = clock();
	quick_sort(vetores[1], 0, 99999);
	clock_t end_quick_sort = clock();

	clock_t start_quick_sort_base = clock();
	quick_sort_base(vetores[2], 100000);
	clock_t end_quick_sort_base = clock();

	printf("bubble_sort de implementação própria gastou %f segundos\n", ((double) (end_bubble_sort - start_bubble_sort)) / CLOCKS_PER_SEC);
	printf("quick_sort de implementação própria gastou %f segundos\n", ((double) (end_quick_sort - start_quick_sort)) / CLOCKS_PER_SEC);
	printf("quick_sort de implementação da lib gastou %f segundos\n", ((double) (end_quick_sort_base - start_quick_sort_base)) / CLOCKS_PER_SEC);

	int posrandom = rand() % 100000;

	clock_t start_linear = clock();
	linear_search(vetores[0], 100000, vetores[0][posrandom]);
	clock_t end_linear = clock();

	clock_t start_binary = clock();
	binary_search(vetores[1], 100000, vetores[1][posrandom]);
	clock_t end_binary = clock();

	clock_t start_binary_base = clock();
	binary_search_base(vetores[2], 100000, vetores[2][posrandom]);
	clock_t end_binary_base = clock();

	printf("linear_search de implementação própria gastou %f segundos\n", ((double) (end_linear - start_linear)) / CLOCKS_PER_SEC);
	printf("binary_search de implementação própria gastou %f segundos\n", ((double) (end_binary - start_binary)) / CLOCKS_PER_SEC);
	printf("binary_search_base de implementação da lib gastou %f segundos\n", ((double) (end_binary_base - start_binary_base)) / CLOCKS_PER_SEC);

	for (int i = 0; i < 3; i++) {
		free(vetores[i]);
	}
	free(vetores);

	return 0;
}
