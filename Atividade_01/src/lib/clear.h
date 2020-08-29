#include <stdio.h>
#include <iostream>

#ifndef CLEAR_H
#define CLEAR_H
void clear()
{
#if defined(_WIN32) || defined(_WIN64)
  system("cls");
#else
  system("clear");
#endif
}
#endif
