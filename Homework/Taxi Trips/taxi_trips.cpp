#include <iostream>
#include <stdexcept>
#include <string>
using std::string, std::cout, std::endl;
#include "taxi_trips.h"


bool is_payment_valid(string type, string valid_types[], unsigned int size) {
  if(size == 0)
    throw std::invalid_argument("Size is zero.");
  for(unsigned int i = 0; i < size; i++){
    if(type == valid_types[i])
      return true;
  }
  return false;
}

double max(double values[], unsigned int size) {
  if(size == 0)
    throw std::invalid_argument("Size is zero.");
  double max = values[0];
  for(unsigned int i = 0; i < size; i++){
    if(max <= values[i])
      max = values[i];
  }
  return max;
}

double min(double values[], unsigned int size) {
  if(size == 0)
    throw std::invalid_argument("Size is zero.");
  double min = values[0];
  for(unsigned int i = 0; i < size; i++){
    if(min >= values[i])
      min = values[i];
  }
  return min;
}

double average(double values[], unsigned int size) {
  if(size == 0)
    throw std::invalid_argument("Size is zero.");
  double avg = 0.0;
  for(unsigned int i = 0; i < size; i++){
      avg += values[i];
  }
  return avg/size;
}

double mode(double values[], unsigned int size) {
  if(size == 0)
    throw std::invalid_argument("Size is zero.");
  int count = 1;
  int countMode = 1;
  int mode = values[0];
  int number = values[0];
  for(unsigned int i = 1; i < size; i++){
    if(number == values[i]){
      count++;
    }
    if(count > countMode){
      mode = values[i];
    }
    number = values[i];
  }
  return mode;
}

unsigned int length_longest_seq_zeros(double values[], unsigned int size) {
  if(size == 0)
    throw std::invalid_argument("Size is zero.");
  int count = 1;
  int longestCount = 1;


    for (unsigned int i = 1; i <size; i++){
        if (values[i] != values[i-1] || values[i] != 0){
            count = 0;
        }
        count++;
        if (count > longestCount){
            longestCount = count;
        }
    }
  return longestCount;
}
