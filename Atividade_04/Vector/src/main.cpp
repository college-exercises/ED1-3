#include <iostream>
#include <stdlib.h>

using namespace std;

#include "./structs/Stack.h"
#include "./services/StackService.h"

#define MAX 30

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
      bool theValueWasPushed = false;

      if (isEven(newValue))
      {
        theValueWasPushed = stackService.push(evenStack, newValue, MAX);
        orderOfEntries[enteredQuantity] = 0;
      }
      else
      {
        theValueWasPushed = stackService.push(oddStack, newValue, MAX);
        orderOfEntries[enteredQuantity] = 1;
      }

      if (!theValueWasPushed)
      {
        cout << "An error occurred while pushing value." << endl;
        exit(1);
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

    bool theValueWasRemoved = false;
    int removedValue = 0;

    removedValue = currentValueIsEven
      ? stackService.pop(evenStack, theValueWasRemoved)
      : stackService.pop(oddStack, theValueWasRemoved);

    if (!theValueWasRemoved)
    {
      cout << "An error occurred while removing item." << endl;
      exit(1);
    }

    cout << removedValue << endl;
  }

  return 0;
}
