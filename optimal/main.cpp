//
//  main.cpp
//  optimal
//
//  Created by Paul Gribelyuk on 5/7/13.
//  Copyright (c) 2013 Paul Gribelyuk. All rights reserved.
//


#include <iostream>
#include "Helper.h"
#include "MatrixTests.h"


int main(int argc, const char * argv[]) {

//  ijk_ikj_test(4);

  size_t m_A, n_A, m_B, n_B;
  m_A = 2;
  n_A = 2;
  m_B = 4;
  n_B = 4;
  
  double* A = (double*) calloc(sizeof(double), m_A * n_A);
  double* B = (double*) calloc(sizeof(double), m_B * n_B);
  double* C = (double*) calloc(sizeof(double), m_A*m_B * n_A*n_B);
  
  A[0] = 1;
  A[1] = 0;
  A[2] = 0;
  A[3] = 1;
  
  B[0] = 1;
  B[6] = 1;
  B[9] = 1;
  B[15] = 1;
  
//  tensor(B, A, C, m_A, n_A, m_B, n_B);
//  print_matrix(A, m_A, n_A);
//  print_matrix(B, m_B, n_B);
//  print_matrix(C, m_A*m_B, n_A*n_B);
 
  Helper::printVector( Helper::generateRandomVector(10) );
}