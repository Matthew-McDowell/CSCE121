/*
DADA function definitions
*/

#include <iostream>
#include <cmath>
#include "dada.h"
using std::cout;
using std::endl;
using std::abs;
using std::sqrt;


int amax(const double x[], const unsigned int len) {
  if(len == 0)
    return -1;
  int value = 0;
    for(unsigned int i = 1; i < len; ++i){
      if(abs(x[i-1]) < abs(x[i])){
        value = i;
      }
    }
    return value;
}

double asum(const double x[], const unsigned int len) {
  double sum = 0;
  for(unsigned int i = 0; i < len; ++i)
    sum += abs(x[i]);

  return sum;
}

void axpy(const double a, const double x[], double y[], const unsigned int len) {
  for(unsigned int i = 0; i < len; ++i)
    y[i] = x[i]*a+y[i];
}

void copy(const double src[], double dest[], const unsigned int len) {

  for(unsigned int i = 0; i < len; ++i)
    dest[i] = src[i];
}

double dot(const double x[], const double y[], const unsigned int len) {
    double dot = 0;
    for(unsigned int i = 0; i < len; ++i)
      dot += (x[i]*y[i]);
    return dot;
}

double norm2(const double x[], const unsigned int len) {
    double mag = 0;
    for(unsigned int i = 0; i < len; ++i)
      mag += (x[i]*x[i]);
    return sqrt(mag);
}

void scale(const double a, double x[], const unsigned int len) {
    for(unsigned int i = 0; i < len; ++i)
      x[i] *= a;
}

void swap(double x[], double y[], const unsigned int len) {
  double a;
  double b;
  for(unsigned int i = 0; i < len; ++i){
    a = 0;
    b = 0;
    a = x[i];
    b = y[i];
    y[i] = a;
    x[i] = b;
  }
}
