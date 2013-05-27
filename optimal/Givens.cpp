//
//  Givens.cpp
//  optimal
//
//  Created by Paul Gribelyuk on 5/27/13.
//  Copyright (c) 2013 Paul Gribelyuk. All rights reserved.
//

#include "Givens.h"

Givens::Givens(std::vector<double>* inputVector) {
  this->v = inputVector;
  this->givensApplied = false;
}

Givens::~Givens() {}

void Givens::applyGivens( const double theta, const int i, const int j ) {
  assert( i < j );
  assert( j < (this->v)->size() );
  double c = cos( theta );
  double s = sin( theta );
  double tmp1 = (*this->v)[i];
  (*this->v)[i] = (*this->v)[i] * c - (*this->v)[j] * s;
  (*this->v)[j] = tmp1 * s - (*this->v)[j] * c;  
}