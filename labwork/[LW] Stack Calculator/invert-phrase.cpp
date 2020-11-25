#include <iostream>
#include <string>
#include "Stack.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    // YOUR CODE GOES HERE
    Stack<string> s;
    string line;
    while(cin >> line){
        string data;
        if(!isalpha(line.at(line.size() - 1))){
            data = line.substr(0, line.size() - 1);
        }
        else{
            data = line;
        }
        s.push(data);
    }
    while(!s.isEmpty()){
        cout << s.pop() << " ";
    }
    
    return 0;
}
