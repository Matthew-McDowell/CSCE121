#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main(){


  int cities = 2;
  int days = 3;
  double **table;
  table = new double *[cities];
  for(int i = 0; i < days; ++i)
    table[i] = new double[days];
  for(int i = 0; i < cities; i++){
    for(int j = 0; j < days; j++){
      cout << "input: ";
      cin>>table[i][j];
    }
  }
  for(int i = 0; i < cities; i++){
    for(int j = 0; j < days; j++){
      cout<<table[i][j] << " ";
    }
    cout << endl;
  }


  return 0;
}
