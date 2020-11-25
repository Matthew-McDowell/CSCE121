#include <iostream>
#include <fstream>
#include <string>
#include "taxi_trips.h"
using std::string, std::ifstream, std::cin, std::cout, std::endl;

int main() {
double a[] = {10,0,0,0.8,0,0,0,40,0,16};
cout << length_longest_seq_zeros(a, 10);
double b[] = {10,16,10,16,16};
cout << length_longest_seq_zeros(b, 5);
cout << length_longest_seq_zeros(b, 1);
double c[] = {0,1,1,1,1};
cout << length_longest_seq_zeros(c, 5);
cout << length_longest_seq_zeros(c, 1);
double d[] = {0,0,1,1,1,1,0,0,0};
cout << length_longest_seq_zeros(d, 9);
cout << length_longest_seq_zeros(d, 8);     
  return 0;
}
