#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

#include "./lib/clear.h"
#include "./classes/Date.h"
#include "./classes/Contact.h"

using namespace std;

void requestBirthDate(int &birthDay, int &birthMonth, int &birthYear)
{
  cout << "Digite o dia de seu nascimento: ";
  cin >> birthDay;

  cout << "Digite o mês de seu nascimento: ";
  cin >> birthMonth;

  cout << "Digite o ano de seu nascimento: ";
  cin >> birthYear;
}

void requestUserInfo(string &name, string &email, string &telephone)
{
  cout << "Digite o seu nome: ";
  cin >> name;

  cout << "Digite o seu email: ";
  cin >> email;

  cout << "Digite o seu telefone: ";
  cin >> telephone;
}

void showUserInfo(Contact user)
{
  cout << "Informação do usuário" << endl
       << endl;

  cout << "Nome: " << user.getName() << endl;
  cout << "Email: " << user.getEmail() << endl;
  cout << "Telefone: " << user.getTelephone() << endl;

  cout << "Data de nascimento: " << user.getBirthDate().getDate() << endl;
  cout << "Idade: " << user.getAge() << endl;
}

int main()
{
  int birthDay, birthMonth, birthYear;
  string name, email, telephone;

  requestUserInfo(name, email, telephone);
  clear();

  requestBirthDate(birthDay, birthMonth, birthYear);
  clear();

  Date userBirthDate = Date(birthDay, birthMonth, birthYear);

  Contact user = Contact(name, email, telephone, userBirthDate);

  showUserInfo(user);

  return 0;
}
