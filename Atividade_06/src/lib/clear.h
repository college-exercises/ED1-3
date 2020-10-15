#include <stdio.h>
#include <iostream>
#include <stdlib.h>

#ifndef CLEAR_H
#define CLEAR_H

extern void clear()
{
#if defined(_WIN32) || defined(_WIN64)
  system("cls");
#else
  system("clear");
#endif
}
#endif
