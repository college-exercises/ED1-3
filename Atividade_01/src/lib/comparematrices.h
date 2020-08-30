#include <stdio.h>
#include <stdlib.h>

using namespace std;

/*
  Esta funcao recebe o duas matrizes e
  retorna um booleano indicando se as
  matrizes possuem os valores iguais
*/
#ifndef COMPAREMATRICES_H
#define COMPAREMATRICES_H

extern bool compareMatrices(
    int **matrixA,
    int **matrixB,
    int horizontalSize,
    int verticalSize)
{
  bool matricesAreEquals = true;

  cout << endl
       << endl;
  for (int i = 0; i < horizontalSize; i++)
  {
    for (int j = 0; j < verticalSize; j++)
    {
      matricesAreEquals = matrixA[i][j] == matrixB[i][j];

      if (!matricesAreEquals)
      {
        break;
      }
    }

    if (!matricesAreEquals)
    {
      break;
    }
  }

  return matricesAreEquals;
}

#endif
