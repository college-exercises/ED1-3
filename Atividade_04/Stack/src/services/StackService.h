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

    newStack->top = NULL;

    return newStack;
  }

  bool isEmpty(Stack *stack)
  {
    return (stack->top == NULL);
  }

  void push(Stack *originalStack, int newData)
  {
    Knot *newKnot = new Knot;

    newKnot->data = newData;
    newKnot->next = originalStack->top;

    originalStack->top = newKnot;
  }

  int pop(Stack *originalStack)
  {
    int removedData;

    Knot *knotToRemove = originalStack->top;

    removedData = knotToRemove->data;

    originalStack->top = knotToRemove->next;

    free(knotToRemove);

    return removedData;
  }

  void print(Stack *stack)
  {
    Knot *currentKnot;

    currentKnot = stack->top;

    while (currentKnot != NULL)
    {
      cout << currentKnot->data << endl;
      currentKnot = currentKnot->next;
    }

    cout << "------------------------" << endl;
  }

  int count(Stack *stack)
  {
    int quantityInStack = 0;

    Knot *currentKnot;

    currentKnot = stack->top;

    while (currentKnot != NULL)
    {
      quantityInStack++;
      currentKnot = currentKnot->next;
    }

    return quantityInStack;
  }

  void freeStack(Stack *stack)
  {
    Knot *currentKnot = stack->top;

    while (currentKnot != NULL)
    {
      Knot *temporaryKnot = currentKnot->next;

      free(currentKnot);

      currentKnot = temporaryKnot;
    }

    free(stack);
  }
};

#endif
