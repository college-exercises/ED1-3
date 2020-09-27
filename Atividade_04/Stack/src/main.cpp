#include <iostream>
#include <stdlib.h>

using namespace std;

#include "./structs/Stack.h"
#include "./services/StackService.h"

bool isEven(int value)
{
  return value % 2 == 0;
}

int main(int argc, char **argv)
{
  int lastEnteredValue = 0, enteredQuantity = 0, quantityOfValues = 30;

  StackService stackService = StackService();
  Stack *evenStack, *oddStack;

  int *orderOfEntries = new int[quantityOfValues];
  /*
    0 -> even
    1 -> odd
  */

  evenStack = stackService.init();
  oddStack = stackService.init();

  bool invalidEntryWasEntered = false;

  while (enteredQuantity < quantityOfValues)
  {
    int newValue;

    if (invalidEntryWasEntered)
    {
      cout << "A entrada não foi considerada." << endl
           << endl;
    }

    cout << "Digite o " << enteredQuantity + 1 << "º valor: ";

    cin >> newValue;

    invalidEntryWasEntered = newValue <= lastEnteredValue;

    if (!invalidEntryWasEntered)
    {
      if (isEven(newValue))
      {
        stackService.push(evenStack, newValue);
        orderOfEntries[enteredQuantity] = 0;
      }
      else
      {
        stackService.push(oddStack, newValue);
        orderOfEntries[enteredQuantity] = 1;
      }

      lastEnteredValue = newValue;
      enteredQuantity++;
    }
  }

  cout << endl;

  // unstacking
  for (int i = 0; i < quantityOfValues; i++)
  {
    int currentIndexOfOrder = quantityOfValues - (i + 1);

    bool currentValueIsEven = orderOfEntries[currentIndexOfOrder] == 0;

    if (currentValueIsEven)
    {
      cout << stackService.pop(evenStack) << endl;
    }
    else
    {
      cout << stackService.pop(oddStack) << endl;
    }
  }

  return 0;
}
