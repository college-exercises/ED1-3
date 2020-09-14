#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
  int a, b, c;
  int *pa, *pb, *pc;

  pa = &a;
  pb = &b;
  pc = &c;

  a = 10;
  b = *pa * 2;

  *pc = *pa + b;

  cout << "Valor de a: " << a << endl;
  cout << "Valor de b: " << b << endl;
  cout << "Valor de c: " << c << endl;

  cout << endl;

  return 0;
}