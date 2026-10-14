#include "matmul.h"
#include <algorithm>

void naive_matmul(int N, const std::vector<float>& A, const std::vector<float>& B, std::vector<float>& C) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            float sum = 0.0f;
            for (int k = 0; k < N; ++k) {
                sum += A[i * N + k] * B[k * N + j];
            }
            C[i * N + j] = sum;
        }
    }
}

void loop_optimized_matmul(int N, const std::vector<float>& A, const std::vector<float>& B, std::vector<float>& C) {
    std::fill(C.begin(), C.end(), 0.0f);
    for (int i = 0; i < N; ++i) {
        for (int k = 0; k < N; ++k) {
            float r = A[i * N + k];
            for (int j = 0; j < N; ++j) {
                C[i * N + j] += r * B[k * N + j];
            }
        }
    }
}

void tiled_matmul(int N, const std::vector<float>& A, const std::vector<float>& B, std::vector<float>& C) {
    std::fill(C.begin(), C.end(), 0.0f);
    for (int i = 0; i < N; i += BLOCK_SIZE) {
        for (int j = 0; j < N; j += BLOCK_SIZE) {
            for (int k = 0; k < N; k += BLOCK_SIZE) {
                for (int ii = i; ii < std::min(i + BLOCK_SIZE, N); ++ii) {
                    for (int kk = k; kk < std::min(k + BLOCK_SIZE, N); ++kk) {
                        float r = A[ii * N + kk];
                        for (int jj = j; jj < std::min(j + BLOCK_SIZE, N); ++jj) {
                            C[ii * N + jj] += r * B[kk * N + jj];
                        }
                    }
                }
            }
        }
    }
}