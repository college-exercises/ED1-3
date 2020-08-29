#include <stdio.h>
#include <iostream>

using namespace std;

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

void populateRandomly(int *array, int array_length)
{
  // para que os resultados sejam diferentes
  srand((unsigned)time(0));

  int randomNumber;

  for (int i = 0; i < array_length; i++)
  {
    randomNumber = (rand() % 35) + 1;

    *(array + i) = i + randomNumber;
  }
}

int main(void)
{
  const int quantityOfNumbers = 10;
  int *numbers;

  numbers = (int *)malloc(sizeof(int) * quantityOfNumbers);

  populateRandomly(numbers, quantityOfNumbers);

  // esta variavel será modificada para guardar a quantidade resultante
  int quantityOfLargers = quantityOfNumbers;
  int average;

  int *largers = getLargerThanAverage(numbers, quantityOfLargers, average);

  cout << "Media: " << average << "." << endl;

  cout << "Quantidade de numeros: " << quantityOfLargers << "." << endl
       << endl;

  for (int i = 0; i < quantityOfLargers; i++)
  {
    cout << largers[i] << endl;
  }
}
