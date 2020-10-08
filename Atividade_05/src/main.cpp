#include <iostream>
#include <stdlib.h>

using namespace std;

#include "./lib/clear.h"
#include "./structs/Queue.h"
#include "./services/QueueService.h"

void handleAttendance(Queue *queueToDequeue, Queue *answeredPasswords, string &customAlert)
{
  QueueService queueService = QueueService();

  if (queueService.isEmpty(queueToDequeue))
  {
    customAlert = "Sem senhas para atender.";
    return;
  }

  int currentPassword = queueService.dequeue(queueToDequeue);

  queueService.add(answeredPasswords, true, currentPassword);

  cout << "Senha atendida: " << currentPassword << endl;
}

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

  cout << endl;

  if (useQueue)
  {
    QueueService queueService = QueueService();

    cout << "Quantidade de senhas restante: " << queueService.count(queue) << endl;
  }
}

void handleAddPassword(Queue *passwordQueue)
{
  QueueService queueService = QueueService();

  queueService.add(passwordQueue);
}

int main(int argc, char **argv)
{
  string customAlert = "";
  int currentOption;
  bool
      invalidOption = false,
      areAbleToExit = true;

  QueueService queueService = QueueService();
  Queue
      *answeredPasswords = queueService.init(),
      *generatedPasswords = queueService.init();

  do
  {
    clear();

    showMenu(true, generatedPasswords);

    cout << endl;

    if (customAlert != "")
    {
      cout << customAlert << endl
           << endl;
    }

    if (invalidOption)
    {
      cout << "A opção escolhida anteriormente é inválida." << endl
           << endl;
    }

    if (currentOption && !areAbleToExit)
    {
      cout << "Não é permitido fechar o programa antes de realizar todos os atendimentos." << endl
           << endl;
    }

    cout << "Sua escolha: ";

    cin >> currentOption;

    invalidOption = false;
    customAlert = "";
    areAbleToExit = queueService.isEmpty(generatedPasswords);

    switch (currentOption)
    {
    case 0:
      if (areAbleToExit)
      {
        cout << "Total de senhas atendidas: " << queueService.count(answeredPasswords) << endl;

        exit(0);
      }
      break;

    case 1:
      handleAddPassword(generatedPasswords);
      break;

    case 2:
      handleAttendance(generatedPasswords, answeredPasswords, customAlert);
      break;

    default:
      invalidOption = true;
      break;
    }
  } while (currentOption != 0 || invalidOption || !areAbleToExit);

  return 0;
}
