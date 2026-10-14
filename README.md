# High-Performance C++ Compute Engine

A C++ matrix multiplication engine built to benchmark and analyze computational bottlenecks, memory access patterns, and multi-core scalability. This project demonstrates how deeply understanding CPU architecture and memory hierarchy can yield massive performance gains over naive algorithmic implementations.

## Optimizations Implemented

1. **Baseline (Naive $O(N^3)$):** Standard nested loops. Causes severe L1/L2 cache misses due to column-wise traversal of Matrix B in a row-major memory layout.
2. **Loop Permutation (Memory Locality):** Reordered loops to `i-k-j`. This ensures sequential, contiguous memory access for both matrices, drastically reducing cache misses and proving the importance of hardware-aware code.
3. **Cache Blocking (Tiling):** Partitioned the matrices into smaller `64x64` sub-matrices (tiles) that fit entirely within the CPU L1/L2 cache, minimizing expensive trips to main memory.
4. **Shared-Memory Parallelization:** Integrated **OpenMP** (`#pragma omp parallel for collapse(2)`) to distribute the tiled workload across all physical and logical CPU cores, maximizing computational throughput.

## Build and Run
```bash
g++ -O3 -fopenmp main.cpp -o matmul_engine
./matmul_engine