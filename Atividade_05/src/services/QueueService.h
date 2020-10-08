#include <iostream>
using namespace std;

#include "../structs/Queue.h"

#ifndef QUEUESERVICE_H
#define QUEUESERVICE_H

class QueueService
{
public:
  // 🎉
  Queue *init()
  {
    Queue *newQueue = new Queue;

    newQueue->begin = NULL;
    newQueue->end = NULL;

    return newQueue;
  }

  // 🎉
  bool isEmpty(Queue *queue)
  {
    return queue->begin == NULL;
  }

  // 🎉
  void add(Queue *queue, bool usePassword = false, int password = 0)
  {
    Knot *newKnot = new Knot;

    bool queueIsEmpty = isEmpty(queue);

    if (queueIsEmpty || usePassword)
    {
      newKnot->data = usePassword ? password : 1;
    }
    else
    {
      newKnot->data = queue->end->data + 1;
    }

    newKnot->next = NULL;

    if (queueIsEmpty)
    {
      queue->begin = newKnot;
    }
    else
    {
      queue->end->next = newKnot;
    }

    queue->end = newKnot;
  }

  // 🎉
  int dequeue(Queue *queue)
  {
    int removedItem;
    Knot *firstKnot = queue->begin;

    removedItem = firstKnot->data;

    queue->begin = firstKnot->next;

    if (queue->begin == NULL)
    {
      queue->end == NULL;
    }

    free(firstKnot);

    return removedItem;
  }

  // 🎉
  void print(Queue *queue)
  {
    Knot *currentKnot = queue->begin;

    while (currentKnot != NULL)
    {
      cout << currentKnot->data << endl;
      currentKnot = currentKnot->next;
    }

    cout << "---------------";
  }

  // 🎉
  int count(Queue *queue)
  {
    int countOfItems = 0;

    Knot *currentKnot = queue->begin;

    while (currentKnot != NULL)
    {
      countOfItems++;
      currentKnot = currentKnot->next;
    }

    return countOfItems;
  }

  // 🎉
  void freeQueue(Queue *queue)
  {
    Knot *currentKnot = queue->begin;

    while (currentKnot != NULL)
    {
      Knot *temporaryKnot = currentKnot->next;

      free(currentKnot);
      currentKnot = temporaryKnot;
    }

    free(queue);
  }
};

#endif
