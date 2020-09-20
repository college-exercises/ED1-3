#include <iostream>
using namespace std;

#include "./lib/clear.h"
#include "./classes/Employee.h"
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

void resetTitle(string title)
{
  clear();

  cout << title << endl
       << endl;
}

EmployeeList *handleInsertEmployee(EmployeeList *employees)
{
  EmployeeListService employeeListService = EmployeeListService();

  int prontuario;
  string name, title = "Cadastro de novo funcionário";
  double salary;

  resetTitle(title);
  cout << "Digite o prontuário do novo funcionário(número inteiro): ";
  cin >> prontuario;

  resetTitle(title);
  cout << "Digite o nome do novo funcionário: ";
  cin >> name;

  resetTitle(title);
  cout << "Digite o salário do novo funcionário: ";
  cin >> salary;

  Employee newEmployee = Employee(prontuario, name, salary);

  return employeeListService.insert(employees, newEmployee);
};

void handleDeleteEmployee()
{
  cout << "Handle Delete Employee" << endl;
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

int main(int argc, char **argv)
{
  int option = 0;
  bool
      keepContent = false,
      invalidOptionSelected = false;

  EmployeeListService employeeListService = EmployeeListService();
  EmployeeList *employees;

  employees = employeeListService.init();

  //=======
  Employee func_01 = Employee();
  func_01.setProntuario(1);
  func_01.setName("Angelo");
  func_01.setSalary(4000);
  employees = employeeListService.insert(employees, func_01);

  Employee func_02 = Employee();
  func_02.setProntuario(2);
  func_02.setName("Ana");
  func_02.setSalary(4000);
  employees = employeeListService.insert(employees, func_02);
  //=======

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

    case 2:
      invalidOptionSelected = false;
      handleDeleteEmployee();
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
      employeeListService.print(employees);

      break;

    default:
      invalidOptionSelected = true;
      break;
    }

  } while (option != 0 || invalidOptionSelected);

  return 0;
}
