#ifndef MATMUL_H
#define MATMUL_H

#include <vector>

const int BLOCK_SIZE = 64; 

void naive_matmul(int N, const std::vector<float>& A, const std::vector<float>& B, std::vector<float>& C);
void loop_optimized_matmul(int N, const std::vector<float>& A, const std::vector<float>& B, std::vector<float>& C);
void tiled_matmul(int N, const std::vector<float>& A, const std::vector<float>& B, std::vector<float>& C);

#endif