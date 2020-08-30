#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

/*
  Esta funcao recebe o tamanho da colecao
  e salva a entrada dos inteiros digitados
  no terminal no endereco de memoria indicado
*/
#ifndef REQUESTVALUES_H
#define REQUESTVALUES_H

extern void requestValues(int *array, int array_length)
{
  int nextValue;

  for (int i = 0; i < array_length; i++)
  {
    cout << "Digite o valor para a posicao " << i << " ";

    cin >> nextValue;

    *(array + i) = nextValue;
  }
};

#endif
