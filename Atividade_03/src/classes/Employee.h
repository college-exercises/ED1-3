#include <iostream>
using namespace std;

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee
{
private:
  int prontuario;
  string name;
  double salary;

public:
  Employee()
  {
    this->prontuario = 0;
    this->name = "";
    this->salary = 0;
  }

  Employee(int prontuario, string name, double salary)
  {
    this->prontuario = prontuario;
    this->name = name;
    this->salary = salary;
  }

  int getProntuario()
  {
    return this->prontuario;
  }

  string getName()
  {
    return this->name;
  }

  double getSalary()
  {
    return this->salary;
  }

  void setProntuario(int prontuario)
  {
    this->prontuario = prontuario;
  }

  void setName(string name)
  {
    this->name = name;
  }

  bool setSalary(double newValue)
  {
    if (newValue < 0)
    {
      return false;
    }

    this->salary = newValue;

    return true;
  }
};

#endif
