#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

#ifndef DATE_H
#define DATE_H

class Date
{
private:
  int day;
  int month;
  int year;

public:
  Date(int day, int month, int year)
  {
    this->day = day;
    this->month = month;
    this->year = year;
  }

  Date()
  {
    this->day = 0;
    this->month = 0;
    this->year = 0;
  }

  int getDay()
  {
    return this->day;
  }

  int getMonth()
  {
    return this->month;
  }

  int getYear()
  {
    return this->year;
  }

  string getDate()
  {
    return to_string(this->day) + "/" + to_string(this->month) + "/" + to_string(this->year);
  }

  Date *getNextDay()
  {
    int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    Date *nextDay = new Date(this->day, this->month, this->year);

    if (nextDay->year % 4 == 0)
    {
      monthDays[1]++;
    }

    nextDay->day++;
    if (nextDay->day > monthDays[nextDay->month - 1])
    {
      nextDay->day = 1;
      if (++nextDay->month > 12)
      {
        nextDay->month = 1;
        nextDay->year++;
      }
    }

    return nextDay;
  }
};

#endif
