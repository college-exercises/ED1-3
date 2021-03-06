#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "./lib/clear.h"
#include "./lib/populaterandomly.h"
#include "./lib/requestvalues.h"

using namespace std;

/*
  Esta função retorna um ponteiro para
  um array contendo os itens maiores que
  a média da matriz de entrada
*/
int *getLargerThanAverage(int *numbers, int &quantityOfNumbers, int &av)
{
  int sum = 0;
  int countOfLargers = 0;

  for (int i = 0; i < quantityOfNumbers; i++)
  {
    sum += *(numbers + i);
  }

  int average = sum / quantityOfNumbers;
  int *largers = (int *)malloc(sizeof(int) * quantityOfNumbers);

  for (int i = 0; i < quantityOfNumbers; i++)
  {
    if (*(numbers + i) > average)
    {
      *(largers + countOfLargers) = *(numbers + i);
      countOfLargers++;
    }
  }

  int *treated_largers = (int *)malloc(sizeof(int) * countOfLargers);

  for (int i = 0; i < countOfLargers; i++)
  {
    treated_largers[i] = *(largers + i);
  }

  quantityOfNumbers = countOfLargers;
  av = average;

  return treated_largers;
}

int main(void)
{
  clear();
  const int quantityOfNumbers = 10;

  string randomNumbers = "N";
  int *numbers;

  cout << "Deseja gerar os valores aleatoriamente? (S/N) ";
  cin >> randomNumbers;

  clear();

  randomNumbers =
      randomNumbers != "N" && randomNumbers != "S" ? "N" : randomNumbers;

  numbers = (int *)malloc(sizeof(int) * quantityOfNumbers);

  if (randomNumbers == "N")
  {
    requestValues(numbers, quantityOfNumbers);
    clear();
  }
  else
  {
    populateRandomly(numbers, quantityOfNumbers);
  }

  // esta variavel será modificada para guardar a quantidade resultante
  int quantityOfLargers = quantityOfNumbers;
  int average;

  int *largers = getLargerThanAverage(numbers, quantityOfLargers, average);

  // Exibindo o resultado
  {
    cout << "Media: " << average << "." << endl;

    cout << "Quantidade de numeros: " << quantityOfLargers << "." << endl
         << endl;

    cout << "[" << endl;

    for (int i = 0; i < quantityOfLargers; i++)
    {
      cout << " " << largers[i] << ", " << endl;
    }

    cout << "]" << endl;
  }

  free(numbers);
  free(largers);

  return 0;
}
