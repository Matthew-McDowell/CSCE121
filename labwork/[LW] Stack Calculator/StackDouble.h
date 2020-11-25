#ifndef STACKDOUBLE_H
#define STACKDOUBLE_H

class StackDouble
{
private:
    int capacity;
    int length;
    double* A;
public:
    StackDouble();
    void push(double element);
    double pop();
    ~StackDouble();

};

#endif // STACKDOUBLE_H
