#include "lista.h"

#include <stdlib.h>
#include <stdio.h>

typedef struct no tNo;

struct no {
  void *elemento;
  funcao_libera libera;
  funcao_imprime imprime;
  funcao_get_valor getValor;
  tNo *prox;
};

struct lista {
  tNo *inicio;
  tNo *fim;
};

tLista *criaLista() {
  tLista *l = malloc(sizeof(struct lista));

  l->inicio = l->fim = NULL;

  return l;
}

void freeLista(tLista *l) {
  tNo *a, *b = l->inicio;
  while (b != NULL) {
    a = b;
    b = b->prox;
    a->libera(a->elemento);
    free(a);
  }

  free(l);
}

void pushLista(tLista *l, funcao_get_valor getValor, funcao_libera libera, funcao_imprime imprime, void *elemento) {
  tNo *n = malloc(sizeof(tNo));
  n->elemento = elemento;
  n->libera = libera;
  n->imprime = imprime;
  n->getValor = getValor;
  n->prox = NULL;


  if (l->inicio == NULL) {
    l->inicio = l->fim = n;
    return;
  }

  l->fim->prox = n;
  l->fim = n;
}

void removeLista(tLista *l, funcao_compara f, void *elemento) {
  tNo *a, *b;

  for (a = l->inicio, b = NULL; a != NULL; b = a, a = a->prox) {
    if (f(elemento, a->elemento)) {
      if (a->prox == NULL) {
        l->fim = b;
      }
      
      if (b == NULL) {
        l->inicio = a->prox;
      } else {
        b->prox = a->prox;
      }

      a->libera(a->elemento);
      free(a);
      break;

    }
  }

}

void imprimeLista(tLista *l) {
  for (tNo *a = l->inicio; a != NULL; a = a->prox) {
    a->imprime(a->elemento);
  }

  printf("Média: %.2f\n", calculaMedia(l));
}

float calculaMedia(tLista *l) {
  float soma = 0;
  int qtd = 0;
  for (tNo *a = l->inicio; a != NULL; a = a->prox) {
    qtd++;
    soma += a->getValor(a->elemento);
  }

	if (qtd == 0) return 0;
  return soma / qtd;
}

