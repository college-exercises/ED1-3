#include <iostream>
#include <stdlib.h>

using namespace std;

#include "./lib/clear.h"
#include "./lib/benchmark.h"

void print(int values[], int length)
{
  for (int i = 0; i < length; i++)
  {
    cout << values[i] << endl;
  }
}

void insertion_sort(int values[], int length)
{
  if (length <= 1)
  {
    return;
  }

  insertion_sort(values, length - 1);

  if (values[length] < values[length - 1])
  {
    /* code */
  }

  cout << "Length: "<< length<< " - [length]: "<<  values[length] << " - [length -1]: " << values[length - 1] << endl;
}

int main(int argc, char **argv)
{
  int values[] = {26, 49, 38, 13, 58, 87, 34, 93};
  int num_of_elements = sizeof(values) / sizeof(int);

  Benchmark benchmark = Benchmark();

  // benchmark.start_benchmark("insertion_sort");
  insertion_sort(values, num_of_elements);
  // benchmark.stop_benchmark("insertion_sort");

  // print(values, num_of_elements);

  // benchmark.show_results();

  return 0;
}
