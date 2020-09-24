#include <benchmark/benchmark.h>
#include "../src/lexer/lexer.h"
#include <memory>
#include <functional>
#include <iostream>

static void BM_lexer_create(benchmark::State& state) {
  std::string x = "print a;";
  for (auto _ : state)
    create_lexer(x);
}

BENCHMARK(BM_lexer_create);

static void BM_lexer_readfile(benchmark::State& state) {
  std::string x = "string a = 'boop'; print(a);";

  for (auto _ : state){    
    std::unique_ptr<Lexer> l =  create_lexer(x);
    l->create_tokens();
  }
}

BENCHMARK(BM_lexer_readfile);

BENCHMARK_MAIN();
