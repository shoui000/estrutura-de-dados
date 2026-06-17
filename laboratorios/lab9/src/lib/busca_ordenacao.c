#include "busca_ordenacao.h"

#include <stdlib.h>
#include <time.h>

/*
 * Função que cria uma matriz de n vetores com 100k de inteiros aleatórios cada.
 */
int **cria_vetores_base(int n) {
	int **matriz = malloc(n * sizeof(int *));
	srand(time(NULL));

	for (int i = 0; i < n; i++) {
		matriz[i] = malloc(100000 * sizeof(int));
	}

	int num;
	for (int j = 0; j < 100000; j++) {
		num = rand();
		for (int i = 0; i < n; i++) {
			matriz[i][j] = num;
		}
	}

	return matriz;
}

/*
 * Função que ordena um vetor usando do algoritmo de bubble sort (implementação própria)
 */
void bubble_sort(int *vetor, int n) {
	int swaps = 0;
	for (int i = 0; i < n; i++) {
		swaps = 0;
		for (int i = 0; i < n-1; i++) {
			if (vetor[i] > vetor[i+1]) {
				int tmp = vetor[i];
				vetor[i] = vetor[i+1];
				vetor[i+1] = tmp;
				swaps++;
			}
		}
		if (!swaps)break;
	}
}

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int *vetor, int low, int high) {
	int pivot = vetor[high];
	int i = low - 1;

	for (int j = low; j <= high - 1; j++) {
		if (vetor[j] < pivot) {
			i++;
			swap(&vetor[i], &vetor[j]);
		}
	}

	swap(&vetor[i + 1], &vetor[high]);

	return i+1;
}

/*
 * Função que ordena um vetor usando do algoritmo de quick sort (implementação própria)
 */
void quick_sort(int *vetor, int low, int high) {
	if (low < high) {
		int pi = partition(vetor, low, high);

		quick_sort(vetor, low, pi-1);
		quick_sort(vetor, pi+1, high);
	}
}

/*
 * Função que ordena um vetor usando do algoritmo de quick sort (implementação da biblioteca padrão)
 */

int compare_ints(const void *a, const void *b) {
	int arg1 = *(const int *)a;
	int arg2 = *(const int *)b;

	if (arg1 < arg2) return -1;
	if (arg2 > arg1) return 1;

	return 0;
}

void quick_sort_base(int *vetor, int n) {
	qsort(vetor, n, sizeof(int), compare_ints);
}

/*
 * Função que busca um elemento dentro de um vetor de inteiros usando de busca linear (implementação própria)
 */
int *linear_search(int *vetor, int n, int elemento) {
	for (int i = 0; i < n; i++) {
		if (vetor[i] == elemento) return vetor + i;
	}

	return NULL;
}

/*
 * Função que busca um elemento dentro de um vetor de inteiros usando de busca binaria (implementação própria)
 */
int *binary_search(int *vetor, int n, int elemento) {
	int low = 0, high = n - 1, mid;

	while (low < high) {
		mid = low + (high - low) / 2;

		if (vetor[mid] == elemento) return vetor + mid;
		else if (vetor[mid] < elemento) low = mid + 1;
		else high = mid - 1;
	}

	return NULL;
}

/*
 * Função que busca um elemento dentro de um vetor de inteiros usando de busca binaria (implementação da biblioteca padrão)
 */
int *binary_search_base(int *vetor, int n, int elemento) {
	return bsearch(&elemento, vetor, n, sizeof(int), compare_ints);
}
