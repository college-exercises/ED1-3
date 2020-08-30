#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "./lib/clear.h"
#include "./lib/comparematrices.h"
#include "./lib/requestvalues.h"

using namespace std;

void printMatrix(
    int **matrix,
    int horizontalSize,
    int verticalSize,
    string alternativeTitle = "Matriz")
{
  cout << alternativeTitle << endl
       << endl;

  for (int i = 0; i < verticalSize; i++)
  {
    for (int j = 0; j < horizontalSize; j++)
    {
      cout << matrix[i][j] << " ";
    }

    cout << endl;
  }
}

int main(void)
{
  clear();
  const int horizontalSize = 3;
  const int verticalSize = 3;

  int **matrixA;
  int **matrixB;

  matrixA = (int **)malloc(sizeof(int) * verticalSize);
  matrixB = (int **)malloc(sizeof(int) * verticalSize);

  // alocando as "linhas"
  for (int i = 0; i < verticalSize; i++)
  {
    matrixA[i] = (int *)malloc(sizeof(int) * horizontalSize);
  }

  for (int i = 0; i < verticalSize; i++)
  {
    matrixB[i] = (int *)malloc(sizeof(int) * horizontalSize);
  }

  // populando
  {
    for (int i = 0; i < verticalSize; i++)
    {
      cout << "Populando a linha " << i << " da matrix A" << endl
           << endl;

      requestValues(matrixA[i], horizontalSize);
      clear();
    }

    for (int i = 0; i < verticalSize; i++)
    {
      cout << "Populando a linha " << i << " da matrix B" << endl
           << endl;

      requestValues(matrixB[i], horizontalSize);
      clear();
    }
  }

  printMatrix(matrixA, horizontalSize, verticalSize, "Matriz A");
  cout << endl;

  printMatrix(matrixB, horizontalSize, verticalSize, "Matriz B");

  bool matrixAreEquals = compareMatrices(
      matrixA,
      matrixB,
      horizontalSize,
      verticalSize);

  string AreEqualMessage = "As matrizes sao iguais";
  string AreDiffMessage = "As matrizes sao diferentes";

  cout << (matrixAreEquals ? AreEqualMessage : AreDiffMessage) << endl;

  free(matrixA);
  free(matrixB);

  return 0;
}
