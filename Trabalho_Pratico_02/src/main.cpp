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

int getAgeAverage(Contact contacts[], int countOfContacts)
{
  int average = 0;

  for (int i = 0; i < countOfContacts; i++)
  {
    average += contacts[i].getAge();
  }

  return average / countOfContacts;
}

string *getLargersThanAverageNames(Contact contacts[], int average, int countOfContacts, int &countOfLargers)
{
  int *largerThanAverageIndexes;
  countOfLargers = 0;

  largerThanAverageIndexes = (int *)malloc(sizeof(int) * countOfContacts);

  for (int i = 0; i < countOfContacts; i++)
  {
    if (contacts[i].getAge() > average)
    {
      *(largerThanAverageIndexes + countOfLargers) = i;

      countOfLargers++;
    }
  }

  string *largers = new string[countOfLargers];

  for (int i = 0; i < countOfLargers; i++)
  {
    largers[i] = contacts[*(largerThanAverageIndexes + i)].getName();
  }

  return largers;
}

Contact *getOlders(Contact contacts[], int countOfContacts, int &countOfOlders)
{
  int largerAge = 0;

  countOfOlders = 0;

  for (int i = 0; i < countOfContacts; i++)
  {
    if (contacts[i].getAge() > largerAge)
    {
      largerAge = contacts[i].getAge();
      countOfOlders = 1;
    }
    else if (contacts[i].getAge() == largerAge)
    {
      countOfOlders++;
    }
  }

  Contact *olders = new Contact[countOfOlders];

  int addedOlders = 0;

  for (int i = 0; i < countOfContacts; i++)
  {
    if (contacts[i].getAge() == largerAge)
    {
      olders[addedOlders] = contacts[i];
      addedOlders++;
    }
  }

  return olders;
}

void populateWithContacts(Contact contacts[])
{
  contacts[0] = Contact("Angelo", "angelo@email.test", "+5500999999999", Date(24, 6, 2001));
  contacts[1] = Contact("Iraci", "iraci@email.test", "+5500999999999", Date(28, 9, 1990));
  contacts[2] = Contact("Joao", "joao@email.test", "+5500999999999", Date(26, 1, 1990));
  contacts[3] = Contact("Andre", "andre@email.test", "+5500999999999", Date(10, 6, 2000));
  contacts[4] = Contact("Lucas", "lucas@email.test", "+5500999999999", Date(22, 6, 2001));
  contacts[5] = Contact("Jose", "jose@email.test", "+5500999999999", Date(10, 4, 1914));
  contacts[6] = Contact("Maria", "maria@email.test", "+5500999999999", Date(20, 2, 2006));
  contacts[7] = Contact("Ana", "ana@email.test", "+5500999999999", Date(15, 4, 2007));
  contacts[8] = Contact("Amanda", "amanda@email.test", "+5500999999999", Date(16, 7, 1914));
  contacts[9] = Contact("Paula", "paula@email.test", "+5500999999999", Date(24, 12, 2015));
}

int main()
{
  const int countOfContacts = 10;
  const bool autoPopulate = false;

  Contact contacts[countOfContacts];

  if (autoPopulate)
  {
    populateWithContacts(contacts);
  }
  else
  {
    for (int i = 0; i < countOfContacts; i++)
    {
      clear();

      cout << "Preenchendo dados para o " << i + 1 << "º contato." << endl
           << endl;
      int birthDay, birthMonth, birthYear;
      string name, email, telephone;

      requestUserInfo(name, email, telephone);
      clear();
      cout << "Preenchendo dados para o " << i + 1 << "º contato." << endl
           << endl;

      requestBirthDate(birthDay, birthMonth, birthYear);
      clear();
      cout << "Preenchendo dados para o " << i + 1 << "º contato." << endl
           << endl;

      Date contactBirthDate = Date(birthDay, birthMonth, birthYear);

      contacts[i] = Contact(name, email, telephone, contactBirthDate);
    }
  }
  int average = getAgeAverage(contacts, countOfContacts);

  string *largersThanAverage;
  int countOfLargers = 0;

  largersThanAverage = getLargersThanAverageNames(contacts, average, countOfContacts, countOfLargers);

  int countOfLegalAge = 0;

  for (int i = 0; i < countOfContacts; i++)
  {
    if (contacts[i].getAge() >= 18)
    {
      countOfLegalAge++;
    }
  }

  int largerAge = 0;
  int countOfOlders = 0;

  Contact *olders;

  olders = getOlders(contacts, countOfContacts, countOfOlders);

  //exibindo os resultados
  {
    cout << "Média de idades: " << average << endl
         << endl;

    cout << "Contatos com idades superior à média: " << endl;

    for (int i = 0; i < countOfLargers; i++)
    {
      cout << "- " << largersThanAverage[i] << endl;
    }

    cout << endl;

    cout << "Quantidade de contatos maiores de idade: " << countOfLegalAge << endl
         << endl;

    cout << "Contatos mais velhos" << endl;
    cout << "Quantidade de contatos mais velhos: " << countOfOlders << endl;
    cout << "Contatos: " << endl
         << endl;

    cout << "[" << endl;
    for (int i = 0; i < countOfOlders; i++)
    {
      cout << "  {" << endl;
      cout << "    Nome: " << olders[i].getName() << endl;
      cout << "    Email: " << olders[i].getEmail() << endl;
      cout << "    Telefone: " << olders[i].getTelephone() << endl;
      cout << "  }," << endl;
    }
    cout << "]" << endl;
  }

  return 0;
}
