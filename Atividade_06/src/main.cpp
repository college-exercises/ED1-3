#include <iostream>
#include <stdlib.h>

using namespace std;

#include "./lib/clear.h"
#include "./lib/benchmark.h"

int main(int argc, char **argv)
{
  Benchmark benchmark = Benchmark();

  benchmark.start_benchmark("Hello");
  benchmark.stop_benchmark("Hello");

  benchmark.start_benchmark("teste");
  benchmark.stop_benchmark("teste");

  benchmark.show_results();

  return 0;
}
