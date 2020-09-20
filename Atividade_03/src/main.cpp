#include <iostream>
using namespace std;

#include "./lib/clear.h"
#include "./classes/Employee.h"
#include "./handlers/AppHandler.h"
#include "./services/EmployeeListService.h"

void showMenu()
{
  cout << "Escolha uma das opções abaixo." << endl
       << endl;

  cout << "0. Sair" << endl;
  cout << "1. Incluir" << endl;
  cout << "2. Excluir" << endl;
  cout << "3. Pesquisar" << endl;
  cout << "4. Listar" << endl;
}

int main(int argc, char **argv)
{
  int option = 0;
  bool
      json = false,
      keepContent = false,
      invalidOptionSelected = false;

  EmployeeListService employeeListService = EmployeeListService();
  EmployeeList *employees;

  employees = employeeListService.init();

  do
  {
    if (!keepContent)
      clear();
    keepContent = false;

    if (invalidOptionSelected)
    {
      cout << "Atenção. A opção inserida anteriormente não é válida." << endl
           << endl;
    }

    showMenu();

    cout << endl
         << "Sua escolha: ";

    cin >> option;

    switch (option)
    {
    case 0:
      exit(0);

    case 1:
      clear(); //=>> 🎉
      invalidOptionSelected = false;
      employees = handleInsertEmployee(employees);
      break;

    case 2: //=>> 🎉
      keepContent = true;
      invalidOptionSelected = false;
      employees = handleDeleteEmployee(employees);
      break;

    case 3: //=>> 🎉
      keepContent = true;
      invalidOptionSelected = false;
      handleFindEmployee(employees);
      break;

    case 4: //=>> 🎉
      clear();
      keepContent = true;
      invalidOptionSelected = false;
      employeeListService.print(employees, json);

      break;

    default:
      invalidOptionSelected = true;
      break;
    }

  } while (option != 0 || invalidOptionSelected);

  return 0;
}
