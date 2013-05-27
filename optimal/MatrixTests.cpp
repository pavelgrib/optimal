//
//  MatrixTests.cpp
//  optimal
//
//  Created by Paul Gribelyuk on 5/27/13.
//  Copyright (c) 2013 Paul Gribelyuk. All rights reserved.
//

#include "MatrixTests.h"

void print_matrix(const double* mat, const size_t M, const size_t N) {
  std::cout<< std::endl;
  for ( int i = 0; i < M; ++i ) {
    for ( int j = 0; j < N; ++j ) {
      std::cout<< mat[i*M + j] << " ";
    }
    std::cout<< std::endl;
  }
}

void ijk_ikj_test(const int n_iterations) {
  int N = 4;
  for ( int k = 0; k < n_iterations; ++k ) {
    N *= 2;
    float* A = (float*) malloc( sizeof(float) * N * N);
    float* B = (float*) malloc( sizeof(float) * N * N);
    float* C = (float*) malloc( sizeof(float) * N * N);
    
    init(A, N, N);
    init(B, N, N);
    
    std::cout<< N << "   ";
    std::cout<< mm1(A, B, C, N, N, N)/mm2(A, B, C, N, N, N) << std::endl;
    
  }
  
  std::cout<< std::endl;
  
  N = 4;
  for ( int k = 0; k < n_iterations; ++k ) {
    N *=2;
    double* A_d = (double*) malloc( sizeof(double) * N * N);
    double* B_d = (double*) malloc( sizeof(double) * N * N);
    double* C_d = (double*) malloc( sizeof(double) * N * N);
    
    init_d(A_d, N, N);
    init_d(B_d, N, N);
    
    std::cout<< N << "   ";
    std::cout<< mm1_d(A_d, B_d, C_d, N, N, N)/mm2_d(A_d, B_d, C_d, N, N, N) << std::endl;
  }
}

float mm1(const float* A, const float* B, float* C, const int m, const int n, const int p) {
  clock_t start = clock();
  
  for ( int i = 0; i < m; ++i ) {
    for ( int j = 0; j < p; ++j ) {
      C[i*m + j] = 0.0;
      for ( int k = 0; k < n; ++k ) {
        C[i*m + j] += A[i*m+k]*B[k*n+j];
      }
    }
  }
  start = clock() - start;
  
  return (double)(start) / CLOCKS_PER_SEC;
}

double mm1_d(const double* A, const double* B, double* C, const int m, const int n, const int p) {
  clock_t start = clock();
  
  for ( int i = 0; i < m; ++i ) {
    for ( int j = 0; j < p; ++j ) {
      C[i*m + j] = 0.0;
      for ( int k = 0; k < n; ++k ) {
        C[i*m + j] += A[i*m+k]*B[k*n+j];
      }
    }
  }
  start = clock() - start;
  
  return (float)(start) / CLOCKS_PER_SEC;
}

float mm2(const float* A, const float* B, float* C, const int m, const int n, const int p) {
  clock_t start = clock();
  
  for ( int i = 0; i < m; ++i ) {
    for ( int k = 0; k < n; ++k ) {
      for ( int j = 0; j < p; ++j ) {
        C[i*m + j] += A[i*m+k]*B[k*n+j];
      }
    }
  }
  start = clock() - start;
  
  return (float)(start) / CLOCKS_PER_SEC;
}

double mm2_d(const double* A, const double* B, double* C, const int m, const int n, const int p) {
  clock_t start = clock();
  
  for ( int i = 0; i < m; ++i ) {
    for ( int k = 0; k < n; ++k ) {
      for ( int j = 0; j < p; ++j ) {
        C[i*m + j] += A[i*m+k]*B[k*n+j];
      }
    }
  }
  start = clock() - start;
  
  return (double)(start) / CLOCKS_PER_SEC;
}

void init(float* A, const int m, const int n) {
  for ( int i = 0; i < m; ++i ) {
    for ( int j = 0; j < n; ++j ) {
      A[i*m + j] = float(rand()) / RAND_MAX;
    }
  }
}

void init_d(double* A, const int m, const int n) {
  for ( int i = 0; i < m; ++i ) {
    for ( int j = 0; j < n; ++j ) {
      A[i*m + j] = double(rand()) / RAND_MAX;
    }
  }
}

// assuming C has been malloc'd to a m_A*m_B by n_A*n_B matrix
void tensor(const double* A, const double* B, double* C, const size_t m_A, const size_t n_A,
            const size_t m_B, const size_t n_B) {
  
  for ( int i = 0; i < m_A; ++i ) {
    for ( int j = 0; j < n_A; ++j ) {
      size_t matrix_offset = m_B*n_B*m_A * i + m_B*n_B * j;
      double a_scalar = A[m_A*i + j];
      for ( int k = 0; k < m_B; ++k ) {
        for ( int p = 0; p < n_B; ++p ) {
          C[ matrix_offset + (m_B*k + p) ] = a_scalar * B[m_B*k + p];
        }
      }
    }
  }
}
