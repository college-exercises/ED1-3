#include <iostream>
using namespace std;

void enche(int *p)
{
  for (int i = 0; i < 5; ++i)
  {
    *p = (i + 1) * 10;
    p++;
  }
}

int main(int argc, char **argv)
{
  int *v = new int[5];

  enche(v);

  for (int i = 0; i < 2; ++i)
  {
    ++v;
  }
  
  cout << "Saida 1: " << *v << endl;
  cout << "Saida 2: " << v[2] << endl;
  cout << "Saida 2: " << v[4] << endl;
  cout << endl;

  return 0;
}
