#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159

void calc_esfera(float r, float *area, float *volume);

int raizes(float a, float b, float c, float *x1, float *x2);

int pares(int n, int *vet);

void inverte(int n, int *vet);

double avalia(double *poli, int grau, double x);

int **inverte2(int n, int *vet);

int main() {
  int option;

  printf("[main] digite sua opcao:\n");
  printf("[main] -> ");
  scanf(" %d", &option);

  if (option == 0) {
    float r, area, volume;

    printf("[calc_esfera] Digite o raio de uma esfera qualquer:\n");
    printf("[calc_esfera] -> ");
    scanf(" %f", &r);
    calc_esfera(r, &area, &volume);
    printf("[calc_esfera] Raio: %.2f - Area: %.2f - Volume: %.2f\n", r, area, volume);
  } else if (option == 1) {
    float a, b, c, x1, x2, existeRaizes;

    printf("[raizes] Digite uma equação do segundo grau:\n");
    printf("[raizes] a: ");
    scanf(" %f", &a);
    printf("[raizes] b: ");
    scanf(" %f", &b);
    printf("[raizes] c: ");
    scanf(" %f", &c);
    existeRaizes = raizes(a, b, c, &x1, &x2);

    if (!existeRaizes) {
      printf("[raizes] %.2fx² %.2fx %.2f nao tem raizes... (◞‸ ◟)\n", a, b, c);
    } else {
      printf("[raizes] As raizes sao:\n");
      printf("[raizes] x1: %.2f\n", x1);
      printf("[raizes] x2: %.2f\n", x2);
    }
  } else if (option == 2) {

    int qtdPares;

    printf("[pares] Digite o tamanho do array de inteiros:\n");
    printf("[pares] -> ");
    scanf(" %d", &qtdPares);
    int arrayPares[qtdPares];

    printf("[pares] Digite os inteiros:\n");

    for (int i = 0; i < qtdPares; i++) {
      printf("[pares] %d: ", i);
      scanf(" %d", &arrayPares[i]);
    }

    printf("[pares] existem %d inteiros pares no array\n", pares(qtdPares, arrayPares));
  } else if (option == 3) {

    int qtdInverte;

    printf("[inverte] Digite o tamanho do array de inteiros:\n");
    printf("[inverte] -> ");
    scanf(" %d", &qtdInverte);
    int arrayInverte[qtdInverte];

    printf("[inverte] Digite os inteiros:\n");

    for (int i = 0; i < qtdInverte; i++) {
      printf("[inverte] %d: ", i);
      scanf(" %d", &arrayInverte[i]);
    }

    inverte(qtdInverte, arrayInverte);

    printf("[inverte] o array invertido eh:\n[inverte] ");
    for (int i = 0; i < qtdInverte; i++) {
      printf("%d ", arrayInverte[i]);
    }
    putchar('\n');
  } else if (option == 4) {

    int qtdPoli;
    printf("[avalia] digite o grau do seu polinomio:\n");
    printf("[avalia] -> ");
    scanf(" %d", &qtdPoli);
    qtdPoli++;
    double arrayPoli[qtdPoli];

    printf("[avalia] digite os coeficientes:\n");

    for (int i = 0; i < qtdPoli; i++) {
      printf("[avalia] x ^ %d: ", i);
      scanf(" %lf", &arrayPoli[i]);
    }

    printf("[avalia] digite o valor de x:\n");
    printf("[avalia] -> ");
    double xPoli;
    scanf(" %lf", &xPoli);

    printf("[avalia] o resultado do polinomio eh %.2lf\n", avalia(arrayPoli, qtdPoli-1, xPoli));
  } else if (option == 5) {

    int qtdDesafio;
    printf("[desafio] digite o tamanho do array de inteiros:\n");
    printf("[desafio] -> ");
    scanf(" %d", &qtdDesafio);
    int arrayDesafio[qtdDesafio];

    for (int i = 0; i < qtdDesafio; i++) {
      printf("[desafio] %d: ", i);
      scanf(" %d", &arrayDesafio[i]);
    }

    printf("[desafio] array ordenado:\n");

    int **arrayInvertido = inverte2(qtdDesafio, arrayDesafio);
    for (int i = 0; i < qtdDesafio; i++) {
      printf("[desafio] %d: %d\n", i, *arrayInvertido[i]);
    }
  }






}

void calc_esfera(float r, float *area, float *volume) {
  *area = 4 * PI * r * r;
  *volume = (4 * PI * r * r * r) / 3;
}

int raizes(float a, float b, float c, float *x1, float *x2) {
  float delta;
  delta = (b*b) - 4 * a * c;

  if (delta < 0)
    return 0;

  *x1 = (-b + sqrt(delta)) / 2 * a;
  *x2 = (-b - sqrt(delta)) / 2 * a;

  return delta == 0 ? 1 : 2;
}

int pares(int n, int *vet) {
  int sum = 0;

  for (int i = 0; i < n; i++) {
    if (vet[i] % 2 == 0)
      sum++;
  }

  return sum;
}

void inverte(int n, int *vet) {
  for (int i = 0; i < n/2; i++) {
    vet[i] ^= vet[n - (i+1)];
    vet[n - (i+1)] ^= vet[i];
    vet[i] ^= vet[n - (i+1)];
  }
}

double avalia(double *poli, int grau, double x) {
  double soma = 0;

  for (int i = 0; i < grau + 1; i++) {
    soma += poli[i] * (pow(x, i));
  }

  return soma;
}

int **inverte2(int n, int *vet) {
  int **vetor = malloc(n * sizeof(int *));

  for (int i = 0; i < n; i++) {
    vetor[i] = vet + i;
  }

  int swaps = 0;
  do {
    swaps = 0;
    for (int i = 0; i < n-1; i++) {
      if (*vetor[i] > *vetor[i+1]) {
        int *temp = vetor[i];
        vetor[i] = vetor[i+1];
        vetor[i+1] = temp;
        swaps++;
      }
    }
  } while (swaps > 0);

  return vetor;
}
