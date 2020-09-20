#include <iostream>
using namespace std;

#include "../lib/resetTittle.h"
#include "../services/EmployeeListService.h"

#ifndef APPHANDLER_H
#define APPHANDLER_H

EmployeeList *handleInsertEmployee(EmployeeList *employees)
{
  EmployeeListService employeeListService = EmployeeListService();

  int prontuario;
  string name, title = "Cadastro de novo funcionário";
  double salary;

  bool prontuarioIsAlreadyUsed = false;

  do
  {
    resetTitle(title);

    if (prontuarioIsAlreadyUsed)
    {
      cout << "O prontuário inserido já está em uso, tente novamente." << endl
           << endl;
    }

    cout << "Digite o prontuário do novo funcionário(número inteiro): ";
    cin >> prontuario;

    employeeListService.find(
        employees,
        prontuario,
        prontuarioIsAlreadyUsed);
  } while (prontuarioIsAlreadyUsed);

  resetTitle(title);
  cout << "Digite o nome do novo funcionário: ";
  cin >> name;

  resetTitle(title);
  cout << "Digite o salário do novo funcionário: ";
  cin >> salary;

  Employee newEmployee = Employee(prontuario, name, salary);

  return employeeListService.insert(employees, newEmployee);
};

void handleFindEmployee(EmployeeList *employees)
{
  string title = "Procurando empregado.";
  int employeeProntuario;

  resetTitle(title);

  cout << "Informe o prontuário do empregado: ";

  cin >> employeeProntuario;

  resetTitle(title);

  EmployeeListService employeeListService = EmployeeListService();
  EmployeeList *employeePointer;

  bool employeeWasFound = false;

  employeePointer = employeeListService.find(
      employees,
      employeeProntuario,
      employeeWasFound);

  if (!employeeWasFound)
  {
    cout << "Empregado não encontrado." << endl
         << endl;
  }
  else
  {
    cout << "Empregado encontrado." << endl
         << endl;

    cout << "Prontuário: " << employeePointer->data.getProntuario() << endl;
    cout << "Nome: " << employeePointer->data.getName() << endl;
    cout << "Salário: " << employeePointer->data.getSalary() << endl;
    cout << "------------------------Fim" << endl
         << endl;
  }
};

EmployeeList *handleDeleteEmployee(EmployeeList *employees)
{
  string title = "Removendo empregado.";
  int employeeProntuario;

  resetTitle(title);

  cout << "Informe o prontuário do empregado: ";

  cin >> employeeProntuario;

  resetTitle(title);

  EmployeeListService employeeListService = EmployeeListService();

  bool employeeWasDeleted = false;

  employees = employeeListService.remove(
      employees,
      employeeProntuario,
      employeeWasDeleted);

  if (employeeWasDeleted)
  {
    cout << "O empregado foi removido com sucesso." << endl
         << endl;
  }
  else
  {
    cout << "O empregado não foi removido, pois não foi encontrado" << endl
         << endl;
  }

  return employees;
};

#endif
