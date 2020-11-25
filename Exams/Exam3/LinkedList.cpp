#include "LinkedList.h"
#include <iostream>
#include <string>

using namespace std;


//LinkedList stuff


size_t LinkedList::size() const
{
  return _size;
}
const Node* LinkedList::head() const
{
  return _head;
}
LinkedList::LinkedList(const LinkedList & other)
{
  _head = nullptr;
  _curr = other._head;
  int i = 0;
  while(_curr != nullptr)
  {
    push_back(_curr->data);
    _curr = _curr->next;
    i++;
  }
}
LinkedList& LinkedList::operator=(const LinkedList & other)
{
  if(this!= &other)
  {
    while(_head != nullptr)
      pop();
    _curr = other._head;
    int i = 0;
    while(_curr != nullptr)
    {
      push_back(_curr->data);
      _curr = _curr->next;
      i++;
    }
  }
  return *this;
}

int LinkedList::pop()
{
  int returnVal = _head->data;
  Node* oldHead = _head;
  _head = _head->next;
  delete oldHead;
  return returnVal;
}

void LinkedList::clear() {
    _curr = _head;
    while(_curr != nullptr)
    {
      Node* temp = _curr -> next;
      delete _curr;
      _curr = temp;
    }
    _head = nullptr;
    _tail = nullptr;
    _prev = nullptr;
    _size = 0;
}
LinkedList::~LinkedList()
{
  clear();
}
void LinkedList::push_back(int value)
{
      Node* NewNode = new Node(value);
      if(empty())
      {
          _head = NewNode;
          _tail = NewNode;
      }
      else
      {
        _tail -> setNext(NewNode);
        _tail = NewNode;
      }
      _size++;
    }
bool LinkedList::empty()
{
    return _head == nullptr;
}
void LinkedList::display()
{
    Node* temp= _head;
    while(temp!=nullptr)
    {
      cout<<temp->data<<"\t";
      temp=temp->next;
    }
  }
void LinkedList::remove_duplicates()
{
  Node *ptr1,*ptr2,*dup;
  ptr1 = _head;
  while(ptr1 != nullptr && ptr1->next != nullptr)
  {
    ptr2 = ptr1;
    while(ptr2->next != nullptr)
    {
      if(ptr1->data == ptr2->next->data)
      {
        dup = ptr2->next;
        ptr2->next = ptr2->next->next;
        delete(dup);
        _size--;
      }
      else
        ptr2 = ptr2->next;
    }
    ptr1 = ptr1->next;
  }
}
size_t LinkedList::length_max_decreasing() const
{
  if(_head == nullptr)
  {
    return 0;
  }
  Node *ptr1;
  ptr1 = _head;
  size_t length = 1;
  size_t maxLength = 1;
  while(ptr1 != nullptr && ptr1 -> next != nullptr)
  {
    if(ptr1->data > ptr1 -> next -> data)
    {
      length++;
    }
    else
    {
      if(length > maxLength)
      {
        maxLength = length;
        length = 1;
      }
    }
    ptr1 = ptr1->next;
  }
  return maxLength;
}

//Node stuff

Node::Node(int value)
{
    data = value;
    next = nullptr;
}
void Node::setNext(Node* other)
{
    next = other;
}
// TODO(student): the rest of the LinkedList
