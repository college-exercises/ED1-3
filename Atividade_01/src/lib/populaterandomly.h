#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

#ifndef POPULATERANDOMLY_H
#define POPULATERANDOMLY_H

extern void populateRandomly(int *array, int array_length)
{
  // para que os resultados sejam diferentes
  srand((unsigned)time(0));

  int randomNumber;

  for (int i = 0; i < array_length; i++)
  {
    randomNumber = (rand() % 35) + 1;

    *(array + i) = randomNumber;
  }
}

#endif
