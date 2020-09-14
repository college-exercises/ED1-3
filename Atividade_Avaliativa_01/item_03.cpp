#include <iostream>
using namespace std;

void qualquer(int p1, int *p2, int &p3)
{
  p3 = p1 + *p2;
  p1 *= 2;
  *p2 *= 2;
}

int main(int argc, char **argv)
{
  int a, b, c;

  a = 2;
  b = 3;
  c = 0;

  qualquer(a, &b, c);

  cout << "Valor de a: " << a << endl;
  cout << "Valor de b: " << b << endl;
  cout << "Valor de c: " << c << endl;

  cout << endl;

  return 0;
}
