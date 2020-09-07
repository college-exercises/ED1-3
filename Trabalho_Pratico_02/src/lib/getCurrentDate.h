#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "../classes/Date.h"

using namespace std;

#ifndef GETCURRENTDATE_H
#define GETCURRENTDATE_H

extern Date getCurrentDate()
{
  time_t theTime = time(NULL);

  struct tm *aTime = localtime(&theTime);

  int currentDay = aTime->tm_mday;
  int currentMonth = aTime->tm_mon + 1;
  int currentYear = aTime->tm_year + 1900;

  return Date(currentDay, currentMonth, currentYear);
}

#endif
