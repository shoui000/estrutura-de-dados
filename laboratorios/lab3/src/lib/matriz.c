#include "matriz.h"

#include <stdio.h>
#include <stdlib.h>

struct matriz
{
  int rows, cols;
  int **data;
};

Matriz *inicializaMatriz(int nlinhas, int ncolunas)
{
  Matriz *m = malloc(sizeof(struct matriz));
  if (m == NULL)
  {
    printf("[matriz] erro ao alocar matriz");
    exit(1);
  }

  m->cols = ncolunas;
  m->rows = nlinhas;

  m->data = calloc(nlinhas, sizeof(int *));

  if (m->data == NULL)
  {
    printf("[matriz] erro ao alocar matriz");
    exit(1);
  }

  int *linha;
  for (int i = 0; i < nlinhas; i++)
  {
    linha = calloc(ncolunas, sizeof(int));

    if (linha == NULL)
    {
      printf("[matriz] erro ao alocar matriz");
      exit(1);
    }

    m->data[i] = linha;
  }

  return m;
}

void modificaElemento(Matriz *mat, int linha, int coluna, int elem)
{
  mat->data[linha][coluna] = elem;
}

int recuperaElemento(Matriz *mat, int linha, int coluna)
{
  return mat->data[linha][coluna];
}

int recuperaNColunas(Matriz *mat)
{
  return mat->cols;
}

int recuperaNLinhas(Matriz *mat)
{
  return mat->rows;
}

Matriz *transposta(Matriz *mat)
{
  Matriz *m = malloc(sizeof(struct matriz));
  if (m == NULL)
  {
    printf("[matriz] erro ao alocar matriz");
    exit(1);
  }

  m->cols = mat->rows;
  m->rows = mat->cols;

  m->data = calloc(mat->cols, sizeof(int *));

  if (m->data == NULL)
  {
    printf("[matriz] erro ao alocar matriz");
    exit(1);
  }

  int *linha;
  for (int i = 0; i < mat->cols; i++)
  {
    linha = calloc(mat->rows, sizeof(int));

    if (linha == NULL)
    {
      printf("[matriz] erro ao alocar matriz");
      exit(1);
    }

    for (int j = 0; j < mat->rows; j++)
    {
      linha[j] = mat->data[j][i];
    }

    m->data[i] = linha;
  }

  return m;
}

Matriz *multiplicacao(Matriz *mat1, Matriz *mat2)
{
  Matriz *m = malloc(sizeof(struct matriz));
  m->rows = mat1->rows;
  m->cols = mat2->cols;

  m->data = malloc(m->rows * sizeof(int *));

  int *linha, sum = 0;
  for (int i = 0; i < m->rows; i++)
  {
    linha = malloc(m->cols * sizeof(int));

    for (int j = 0; j < m->cols; j++)
    {
      sum = 0;
      for (int x = 0; x < mat1->cols; x++)
      {
        sum += mat1->data[i][x] * mat2->data[x][j];
      }
      linha[j] = sum;
    }

    m->data[i] = linha;
  }

  return m;
}

void imprimeMatriz(Matriz *mat)
{
  for (int i = 0; i < mat->rows; i++)
  {
    for (int j = 0; j < mat->cols; j++)
    {
      printf("%d ", mat->data[i][j]);
    }
    putchar('\n');
  }
}

void imprimeLinha(Matriz *mat, int indice)
{
  for (int j = 0; j < mat->rows; j++)
  {
    printf("%d ", mat->data[indice][j]);
  }
  putchar('\n');
}

void destroiMatriz(Matriz *mat)
{
  for (int i = 0; i < mat->rows; i++)
  {
    free(mat->data[i]);
  }

  free(mat->data);
  free(mat);
}
