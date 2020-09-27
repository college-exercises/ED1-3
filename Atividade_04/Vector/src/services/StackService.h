#include <iostream>
using namespace std;

#include "../structs/Stack.h"

#ifndef STACKSERVICE_H
#define STACKSERVICE_H

class StackService
{
public:
  Stack *init()
  {
    Stack *newStack = new Stack;

    newStack->quantity = 0;

    return newStack;
  }

  bool isEmpty(Stack *stack)
  {
    return (stack->quantity == 0);
  }

  bool push(Stack *stack, int value, int maximum)
  {
    bool canStack = stack->quantity < maximum;

    if (canStack)
    {
      stack->knots[stack->quantity] = value;
      stack->quantity++;
    }

    return canStack;
  }

  int pop(Stack *stack, bool &itHasBeenUnstacked)
  {
    int unstackedValue = 0;

    bool canUnstack = stack->quantity > 0;

    if (canUnstack)
    {
      int lastIndexWithValue = stack->quantity - 1;

      unstackedValue = stack->knots[lastIndexWithValue];

      stack->quantity--;
    }

    itHasBeenUnstacked = canUnstack;

    return unstackedValue;
  }

  void print(Stack *stack)
  {
    for (int i = stack->quantity - 1; i >= 0; --i)
    {
      cout << stack->knots[i] << endl;
    }
  }

  int count(Stack *stack)
  {
    return stack->quantity;
  }

  void freeStack(Stack *stack)
  {
    free(stack);
  }
};

#endif
