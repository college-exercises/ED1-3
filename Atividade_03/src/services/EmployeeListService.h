#include <iostream>
using namespace std;

#include "../classes/Employee.h"

#ifndef EMPLOYEELISTSERVICE_H
#define EMPLOYEELISTSERVICE_H

struct EmployeeList
{
  Employee data;
  struct EmployeeList *next;
};

class EmployeeListService
{
public:
  static EmployeeList *init()
  {
    return NULL;
  }

  static EmployeeList *insert(EmployeeList *employees, Employee newEmployee)
  {
    EmployeeList *auxiliarList = new EmployeeList;

    auxiliarList->data = newEmployee;
    auxiliarList->next = employees;

    return auxiliarList;
  }

  static void print(EmployeeList *employees, bool json = true)
  {
    EmployeeList *auxiliaryList;

    auxiliaryList = employees;

    if (json)
    {
      cout << "[" << endl;

      while (auxiliaryList != NULL)
      {
        cout << "  {" << endl;
        cout << "    prontuario: " << auxiliaryList->data.getProntuario() << "," << endl;
        cout << "    nome: " << auxiliaryList->data.getName() << "," << endl;
        cout << "    salario: " << auxiliaryList->data.getSalary() << "," << endl;
        cout << "  }," << endl;

        auxiliaryList = auxiliaryList->next;
      }

      cout << "]" << endl;
    }
    else
    {
      cout << "Listagem de funcionários" << endl
           << endl;

      while (auxiliaryList != NULL)
      {
        cout << "Prontuário: " << auxiliaryList->data.getProntuario() << endl;
        cout << "Nome: " << auxiliaryList->data.getName() << endl;
        cout << "Salário: " << auxiliaryList->data.getSalary() << endl;
        cout << endl;

        auxiliaryList = auxiliaryList->next;
      }
    }

    cout << "------------------------ Fim" << endl
         << endl;
  }

  static EmployeeList *find(EmployeeList *employees, int prontuario, bool &employeeWasFound)
  {
    EmployeeList *auxiliaryList;

    auxiliaryList = employees;

    while (
        auxiliaryList != NULL &&
        auxiliaryList->data.getProntuario() != prontuario)
    {
      auxiliaryList = auxiliaryList->next;
    }

    employeeWasFound = !(auxiliaryList == NULL);

    return auxiliaryList;
  }
};

#endif
