#ifndef _BUSCA_ORDENACAO_H
#define _BUSCA_ORDENACAO_H

/*
 * Função que cria uma matriz de 4 vetores com 100k de inteiros aleatórios cada.
 */
int **cria_vetores_base(int n);

/*
 * Função que ordena um vetor usando do algoritmo de bubble sort (implementação própria)
 */
void bubble_sort(int *vetor, int n);

/*
 * Função que ordena um vetor usando do algoritmo de quick sort (implementação própria)
 */
void quick_sort(int *vetor, int low, int high);

/*
 * Função que ordena um vetor usando do algoritmo de quick sort (implementação da biblioteca padrão)
 */
void quick_sort_base(int *vetor, int n);

/*
 * Função que busca um elemento dentro de um vetor de inteiros usando de busca linear (implementação própria)
 */
int *linear_search(int *vetor, int n, int elemento);

/*
 * Função que busca um elemento dentro de um vetor de inteiros usando de busca binaria (implementação própria)
 */
int *binary_search(int *vetor, int n, int elemento);

/*
 * Função que busca um elemento dentro de um vetor de inteiros usando de busca binaria (implementação da biblioteca padrão)
 */
int *binary_search_base(int *vetor, int n, int elemento);


#endif // !_BUSCA_ORDENACAO_H
