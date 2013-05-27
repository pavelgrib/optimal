//
//  Helper.h
//  optimal
//
//  Created by Paul Gribelyuk on 5/27/13.
//  Copyright (c) 2013 Paul Gribelyuk. All rights reserved.
//

#ifndef __optimal__Helper__
#define __optimal__Helper__

#include <iostream>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <random>

class Helper {
public:
  template <class T> static void printVector( const std::vector<T>& v, const bool vertical = false, const size_t begin=0, const size_t len=-1 );
  template <class T> static double vectorAverage( const std::vector<T>& v, const size_t begin = 0);
  
  template <class T> static double slowerVectorAverage(const std::vector<T>& v, const size_t begin=0, const size_t len=-1);

  static bool equal(const double val1, const double val2, const double absThreshold=1e-6, const double relThreshold=1e-6);
  
  static std::vector<double> generateRandomVector(const size_t length=1000, const double a = 0, const double b = 1);
  
private:
  Helper();
  ~Helper();
};

#endif /* defined(__optimal__Helper__) */
