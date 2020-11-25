#include "Stack.h"

template <typename T>
Stack<T>::Stack()
{
   this->length = 0;
   this->capacity = 1;
   A = new T[1];
}

template <typename T>
bool Stack<T>::isEmpty(){
   return this->length == 0;
}

template <typename T>
void Stack<T>::push(T element){
   if(this->length == this->capacity){
       T* temp = new T[this->length * 2];
       for(int i = 0; i < this->length; i++){
           temp[i] = this->A[i];
       }
       delete[] this->A;
       this->A = temp;
       this->capacity *= 2;
   }
   this->A[this->length++] = element;
}

template <typename T>
T Stack<T>::pop(){
   if(this->isEmpty()){
       this->exit(0);
   }
   T result = this->A[--this->length];
   return result;
}

template <typename T>
Stack<T>::~Stack()
{
   delete[] this->A;
}
