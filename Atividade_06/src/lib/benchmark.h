#include <ctime>
#include <chrono>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;
using namespace chrono;

#ifndef BENCHMARK_H
#define BENCHMARK_H

struct BenchmarkTimeList
{
  steady_clock::time_point time_stamp_array[2];
  string key;
  struct BenchmarkTimeList *next;
};

class Benchmark
{
private:
  BenchmarkTimeList *benchmarks;

  bool checkKeyExists(string key)
  {
    BenchmarkTimeList *auxiliaryList;
    bool keyWasFound = false;

    auxiliaryList = this->benchmarks;

    while (
        auxiliaryList != NULL &&
        auxiliaryList->key != key)
    {
      auxiliaryList = auxiliaryList->next;
    }

    keyWasFound = !(auxiliaryList == NULL);

    return keyWasFound;
  };

  BenchmarkTimeList *find(string key)
  {
    bool keyWasFound = false;
    BenchmarkTimeList *auxiliaryList;

    auxiliaryList = this->benchmarks;

    while (
        auxiliaryList != NULL &&
        auxiliaryList->key != key)
    {
      auxiliaryList = auxiliaryList->next;
    }

    keyWasFound = !(auxiliaryList == NULL);

    return auxiliaryList;
  }

public:
  Benchmark()
  {
    this->benchmarks = NULL;
  }

  void start_benchmark(string key)
  {
    if (this->checkKeyExists(key))
    {
      cout << "Duplicated key: " << key << endl;
      exit(1);
    }

    BenchmarkTimeList *auxiliarList = new BenchmarkTimeList;

    auxiliarList->key = key;
    auxiliarList->time_stamp_array[0] = steady_clock::now();
    auxiliarList->next = this->benchmarks;

    this->benchmarks = auxiliarList;
  }

  void stop_benchmark(string key)
  {
    BenchmarkTimeList *benchmark = this->find(key);

    if (benchmark == NULL)
    {
      cout << "Key not found: " << key << endl;
      exit(2);
    }

    benchmark->time_stamp_array[1] = steady_clock::now();

    // cout << duration_cast<microseconds>(benchmark->time_stamp_array[1] - benchmark->time_stamp_array[0]).count() << "µs" << endl;
    // return duration_cast<microseconds>(benchmark->time_stamp_array[1] - benchmark->time_stamp_array[0]).count();
  }

  void show_results()
  {
    BenchmarkTimeList *auxiliaryList;

    auxiliaryList = this->benchmarks;

    cout << "Strategy: Elapsed time" << endl
         << endl;

    while (auxiliaryList != NULL)
    {
      cout << auxiliaryList->key << ": " << duration_cast<microseconds>(auxiliaryList->time_stamp_array[1] - auxiliaryList->time_stamp_array[0]).count() << "µs" << endl;
      auxiliaryList = auxiliaryList->next;
    }
  }
};
#endif
