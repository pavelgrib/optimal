//
//  MatrixTests.h
//  optimal
//
//  Created by Paul Gribelyuk on 5/27/13.
//  Copyright (c) 2013 Paul Gribelyuk. All rights reserved.
//

#ifndef __optimal__MatrixTests__
#define __optimal__MatrixTests__

#include <iostream>
#include <cstdlib>
#include <math.h>
#include <ctime>

void print_matrix(const double* mat, const size_t M, const size_t N);
void init(float* A, const int m, const int n);
void init_d(double* A, const int m, const int n);
float mm1(const float* A, const float* B, float* C, const int m, const int n, const int p);
float mm2(const float* A, const float* B, float* C, const int m, const int n, const int p);
double mm1_d(const double* A, const double* B, double* C, const int m, const int n, const int p);
double mm2_d(const double* A, const double* B, double* C, const int m, const int n, const int p);
void ijk_ikj_test(const int n_iterations);
void tensor(const double* A, const double* B, double* C, const size_t m_A, const size_t n_A,
            const size_t m_B, const size_t n_B);

#endif /* defined(__optimal__MatrixTests__) */
