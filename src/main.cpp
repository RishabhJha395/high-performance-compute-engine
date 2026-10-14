#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cstdlib> // For atoi
#include "matmul.h"

template <typename Func>
void benchmark(const std::string& name, Func f, int N, const std::vector<float>& A, const std::vector<float>& B, std::vector<float>& C) {
    auto start = std::chrono::high_resolution_clock::now();
    f(N, A, B, C);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << name << " took: " << duration.count() << " seconds.\n";
}

int main(int argc, char* argv[]) {
    // Default to 1024 if no argument is provided
    int N = (argc > 1) ? std::atoi(argv[1]) : 1024;

    std::cout << "Initializing Matrices (" << N << "x" << N << ")...\n";
    std::vector<float> A(N * N);
    std::vector<float> B(N * N);
    std::vector<float> C(N * N, 0.0f);

    std::mt19937 gen(42);
    std::uniform_real_distribution<float> dis(0.0f, 1.0f);
    for(int i = 0; i < N * N; ++i) {
        A[i] = dis(gen);
        B[i] = dis(gen);
    }

    std::cout << "Benchmarking Matrix Multiplication Strategies:\n";
    std::cout << "----------------------------------------------\n";

    benchmark("1. Naive MatMul         ", naive_matmul, N, A, B, C);
    benchmark("2. Loop Optimized (Cache)", loop_optimized_matmul, N, A, B, C);
    benchmark("3. Cache Tiled          ", tiled_matmul, N, A, B, C);

    return 0;
}