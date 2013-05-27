//
//  Givens.h
//  optimal
//
//  Created by Paul Gribelyuk on 5/27/13.
//  Copyright (c) 2013 Paul Gribelyuk. All rights reserved.
//

#ifndef __optimal__Givens__
#define __optimal__Givens__

#include <iostream>
#include <vector>
#include <assert.h>
#include <math.h>

class Givens {
public:
  Givens(std::vector<double>* v);
  ~Givens();
  
  void applyGivens(const double theta, const int i, const int j);
  void reverseGivens();
private:
  bool givensApplied;
  double theta, i, j;
  std::vector<double>* v;
};

#endif /* defined(__optimal__Givens__) */
