#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack
{
private:
    int length;
    int capacity;
    T* A;
public:
    Stack(){
        this->length = 0;
        this->capacity = 1;
        A = new T[1];
    }
    bool isEmpty(){
        return this->length == 0;
    }
    void push(T element){
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
    T pop(){
        if(this->isEmpty()){
            exit(0);
        }
        T result = this->A[--this->length];
        return result;
    }
    ~Stack(){
        delete[] this->A;
    }

};

#endif // STACK_H
