#include <iostream>

using std::cin, std::cout, std::endl;

int main() {
  int input = -1;
  int sum = 0;
  int max = 0;
  int min = 2147483647;
  int i = 0;
  int avg = 0;
    cout << "Input numbers: ";
    while(input != 0){
      cin >> input;
      if(input%2 == 1){
        sum += input;
        i++;
        if(input > max)
          max = input;

        else if(input < min && input != 0)
          min = input;
      }
    }
    if(i != 0)
    {
      avg = sum/i;
      cout << "min " << min << " max " << max << " average " << avg;
    }
    else
      cout << "no values";
}
