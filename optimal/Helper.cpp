//
//  Helper.cpp
//  optimal
//
//  Created by Paul Gribelyuk on 5/27/13.
//  Copyright (c) 2013 Paul Gribelyuk. All rights reserved.
//

#include "Helper.h"

Helper::Helper() {}

Helper::~Helper() {}

template <class T> void printVector(const std::vector<T>& v, const bool vertical, const size_t begin, const size_t len ) {
    auto it = v.begin() + begin;
  if ( len == -1 ) {
    len = v.size() - begin - 1;
  }
  for( ; it != min(v.end(), v.begin() + begin + len); ++it ) {
    std::cout<< *it << std::endl;
  }
}

template <class T> double vectorAverage(const std::vector<T>& v, const size_t begin, const size_t len) {
  double avg = 0;
  unsigned int count = 0;
  if ( len == -1 ) {
    len = v.size() - begin - 1;
  }
  
  size_t start = begin;
  size_t end = begin + len;
  if ( len % 2 ) {
    avg = v[begin];
    start++;
  }
  
  for ( unsigned int i = 0; i < len/2; ++i ) {
    avg += (avg - v[start+i] + v[end-i]) / (++count);
  }
}

template <class T> double slowerVectorAverage(const std::vector<T>& v, const size_t begin, const size_t len) {
  if ( len == -1 ) {
    len = v.size() - begin - 1;
  }
  auto it = v.begin() + begin;
  double avg = 0;
  unsigned int count = 0;
  for ( ; it != min(v.end(), v.begin() + begin + len); ++it ) {
    avg += ( *it - avg ) / (++count);
  }
}

/* either absThreshold or relThreshold must be specified */
bool equal(const double val1, const double val2, const double absThreshold, const double relThreshold) {
  return true;
}
/* generates vector containing 'length' uniform values in [a, b) */
std::vector<double> generateRandomVector(const size_t length=1000, const double a=0, const double b=1) {
  std::mt19937 eng;
  std::uniform_real_distribution<double> unif(a, b);
  std::vector<double> v( length );
  eng.seed( (unsigned int) time(NULL) );
  for ( size_t i = 0; i < length; ++i ) {
    v.push_back( unif( eng ) );
  }
  return v;
}