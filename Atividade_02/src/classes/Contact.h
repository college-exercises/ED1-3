#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>

#include "../lib/getCurrentDate.h"
#include "./Date.h"

using namespace std;

#ifndef CONTACT_H
#define CONTACT_H

class Contact
{
private:
  string email;
  string name;
  string telephone;
  Date birthDate;

public:
  Contact(string name, string email, string telephone, Date birthDate)
  {
    this->name = name;
    this->email = email;
    this->telephone = telephone;
    this->birthDate = birthDate;
  }

  Contact()
  {
    this->name = "";
    this->email = "";
    this->telephone = "";
    this->birthDate = Date();
  }

  string getName()
  {
    return this->name;
  }

  string getEmail()
  {
    return this->email;
  }

  string getTelephone()
  {
    return this->telephone;
  }

  Date getBirthDate()
  {
    return this->birthDate;
  }

  int getAge()
  {
    Date today = getCurrentDate();

    int age = today.getYear() - this->birthDate.getYear();

    if (this->birthDate.getMonth() <= today.getMonth())
    {
      if (this->birthDate.getDay() < today.getDay())
      {
        age--;
      }
    }

    return age;
  }
};

#endif
