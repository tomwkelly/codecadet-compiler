#include <benchmark/benchmark.h>

#include <functional>
#include <iostream>
#include <memory>

#include "../src/lexer/lexer.h"

static void BM_lexer_create(benchmark::State& state) {
    std::string x = "print a;";
    for (auto _ : state) Lexer l(x);
}

BENCHMARK(BM_lexer_create);

static void BM_lexer_readfile(benchmark::State& state) {
    std::string x = "string a = 'boop'; print(a);";

    for (auto _ : state) {
        Lexer l(x);
        l.create_tokens();
    }
}

BENCHMARK(BM_lexer_readfile);

static void BM_lexer_create_ptr(benchmark::State& state) {
    std::string x = "print a;";
    for (auto _ : state) {
        std::unique_ptr<Lexer> l = std::make_unique<Lexer>(x);
    }
}

BENCHMARK(BM_lexer_create_ptr);

static void BM_lexer_readfile_ptr(benchmark::State& state) {
    std::string x = "string a = 'boop'; print(a);";

    for (auto _ : state) {
        std::unique_ptr<Lexer> l = std::make_unique<Lexer>(x);
        l->create_tokens();
    }
}

BENCHMARK(BM_lexer_readfile_ptr);

BENCHMARK_MAIN();
