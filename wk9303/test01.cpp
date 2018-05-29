#include <benchmark/benchmark.h>

/*
Installation guide:
https://github.com/google/benchmark

Compile:
g++ -o test01 test01.cpp -Wall -Wextra --std=c++14 -lbenchmark -lpthread

*/
static void BM_StringCreation(benchmark::State& state) {
  for (auto _ : state)
    std::string empty_string;
}
// Register the function as a benchmark
BENCHMARK(BM_StringCreation);

// Define another benchmark
static void BM_StringCopy(benchmark::State& state) {
  std::string x = "hello";
  for (auto _ : state)
    std::string copy(x);
}
BENCHMARK(BM_StringCopy);

BENCHMARK_MAIN();