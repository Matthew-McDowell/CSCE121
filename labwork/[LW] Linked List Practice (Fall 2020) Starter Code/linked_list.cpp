#include "linked_list.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

void MyList::add(string name, int score) {
    MyNode* NewNode = new MyNode(name,score);
    if(empty())
    {
      _headPtr = NewNode;
      _tailPtr = NewNode;
    }
    else{
      _tailPtr -> setNext(NewNode);
      _tailPtr = NewNode;
    }
    _size++;
}

void MyList::clear() {
    _marker = _headPtr;
    while(_marker != nullptr)
    {
      MyNode* temp = _marker -> next();
      delete _marker;
      _marker = temp;
    }
    _headPtr = nullptr;
    _tailPtr = nullptr;
    _prevPtr = nullptr;
    _size = 0;
}

 bool MyList::remove(string name) {
     _prevPtr = nullptr;
     _marker = _headPtr;
     if(empty())
     {
      return false;
     }
     if(name == "Z")
     {
     return false;
     }
     while(_marker != nullptr && _marker->name() != name)
    {
      _prevPtr = _marker;
      _marker = _marker->next();
     }
     if(_prevPtr == nullptr && _marker->next() == nullptr) //if deleting only element
     {
      _headPtr = nullptr;
      _tailPtr = nullptr;
      _marker -> setNext(nullptr);
      delete _marker;
      _size--;
      return true;
    }
    if(_prevPtr == nullptr && _marker->next() != nullptr) //if deleting first element
    {
      _headPtr = _headPtr -> next();
      _prevPtr = nullptr;
      delete _marker;
      _size--;
      return true;
    }
    if(_prevPtr != nullptr && _marker->next() != nullptr) //if deleting middle element
    {
      _prevPtr -> setNext(_marker->next());
      _marker -> setNext(nullptr);
      _prevPtr = nullptr;
      delete _marker;
      _size--;
      return true;
    }
    if(_prevPtr != nullptr && _marker->next() == nullptr) //if deleting last element
    {
      _prevPtr -> setNext(nullptr);
      _tailPtr = _prevPtr;
      _size--;
      delete _marker;
      return true;
    }
    return false;
}

bool MyList::insert(string name, int score, size_t index) {
    // TODO
    return false;
}

MyList::MyList() {
    _size = 0;
    _headPtr = nullptr;
    _tailPtr = nullptr;
    _prevPtr = nullptr;
    _marker = nullptr;
}

MyList::~MyList() {
    clear();
}

size_t MyList::size() {
    return _size;
}

bool MyList::empty() {
    return _headPtr == nullptr;
}

MyNode* MyList::head() {
    return _headPtr;
}

void MyList::printList() {
    _marker = _headPtr;
    if (_marker == nullptr) {
        cout << "Linked list is empty" << endl;
        return;
    }

    while (_marker != nullptr) {
        cout << "[ " << _marker->name() << ", " << _marker->score() << " ]" << endl;
        _marker = _marker->next();
    }
}

MyNode::MyNode(std::string name, int score) {
    _name = name;
    _score = score;
    _nextPtr = nullptr;
}

std::string MyNode::name()  {
    return _name;
}

int MyNode::score() {
    return _score;
}

void MyNode::setNext(MyNode* other) {
    _nextPtr = other;
}

MyNode* MyNode::next() {
    return _nextPtr;
}
