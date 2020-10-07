#include <iostream>
using namespace std;

#include "../structs/Queue.h"
// #include "../structs/Knot.h"

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
    return queue->top == NULL;
  }

  void add(Queue *queue, float v)
  {
  }

  float dequeue(Queue *queue)
  {
  }

  void print(Queue *queue)
  {
  }

  int count(Queue *queue)
  {
  }

  void freeQueue(Queue *queue)
  {
  }
};

#endif
