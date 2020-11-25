#include "LinkedList.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    // TODO(student): the rest of the Tests
    LinkedList list;
    list.push_back(3);
    list.push_back(2);
    list.push_back(1);
    list.push_back(0);
    list.push_back(-3);
    list.push_back(2);
    list.push_back(1);
    list.push_back(0);
    list.remove_duplicates();
    cout << list.length_max_decreasing() <<"\n";
    list.display();
    LinkedList list_A;
    for(int n = 1; n <= 3; n++){
      list_A.push_back(n);
    }
    LinkedList list_B(list_A);
    list_A.display();
    cout << "\n";
    list_B.display();
    cout << "\n";
    list_B.push_back(4);
    list_A.display();
    cout << "\n";
    list_B.display();
    cout << "\n";
    list_A = list_B;
    list_A.display();
    cout << "\n";
    list_B.display();
    cout << "\n";
    list_B.push_back(5);
    list_A.display();
    cout << "\n";
    list_B.display();
    cout << "\n";
    list_A.push_back(5);
    list_A.display();
    cout << "\n";
    return 0;
}
