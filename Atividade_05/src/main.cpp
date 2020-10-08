#include <iostream>
#include <stdlib.h>

using namespace std;

#include "./structs/Queue.h"
#include "./services/QueueService.h"

// 🎉
void handleAttendance(Queue *mainQueue, Queue *answeredPasswords)
{
  QueueService queueService = QueueService();

  int currentPassword = queueService.dequeue(mainQueue);

  queueService.add(answeredPasswords, true, currentPassword);

  cout << "Senha atendida: " << currentPassword << endl;
}

// 🎉
void showMenu(bool useQueue = false, Queue *queue = NULL, string title = "Escolha uma das opções abaixo:")
{
  if (title != "")
  {
    cout << title << endl
         << endl;
  }

  cout << "0. Sair" << endl;
  cout << "1. Gerar senha" << endl;
  cout << "2. Realizar atendimento" << endl;

  if (useQueue)
  {
    QueueService queueService = QueueService();

    cout << "Quantidade de senhas restante: " << queueService.count(queue) << endl;
  }
}

int main(int argc, char **argv)
{
  QueueService queueService = QueueService();

  Queue
      *answeredPasswords = queueService.init(),
      *generatedPasswords = queueService.init();

  showMenu();

  return 0;
}
