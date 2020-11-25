#include "StackDouble.h"
#include <cmath>

StackDouble::StackDouble():
capacity{1}, length{0}
{
    this->A = new double[1];
}

void StackDouble::push(double element){
    if(this->length == this->capacity){
        double* temp = new double[this->length * 2];
        for(int i = 0; i < this->length; i++){
            temp[i] = this->A[i];
        }
        delete[] this->A;
        this->A = temp;
        this->capacity *= 2;
    }
    this->A[this->length++] = element;
}

double StackDouble::pop(){
    if(this->length <= 0){
        return NAN;
    }
    double result = this->A[--this->length];
    return result;
}

StackDouble::~StackDouble()
{
}

