#include <iostream>
using namespace std;

#include "./clear.h"

#ifndef RESETTITTLE_H
#define RESETTITTLE_H

extern void resetTitle(string title)
{
  clear();

  cout << title << endl
       << endl;
}

#endif
