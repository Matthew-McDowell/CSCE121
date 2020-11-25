#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
using namespace std;

struct Node {
    int data;
    Node* next;
// TODON'T(student): change the visibility, types, or names of the members
// TOMAYBE(student): the optional-rest of the Node
    Node(int value);
    void setNext(Node* other);
};

class LinkedList {
// the type to use for sizes and indices is size_t.
// TODO(student): the rest of the LinkedList
private:
  size_t _size;
  Node *_head, *_tail, *_prev, *_curr;
public:
  LinkedList(){
    _size = 0;
    _head = nullptr;
    _tail = nullptr;
    _prev = nullptr;
    _curr = nullptr;
  };
  ~LinkedList();
  LinkedList(const LinkedList& other);
  LinkedList & operator=(const LinkedList & other);
  int pop();
  void clear();
  bool empty();
  size_t size() const;
  const Node* head() const;
  void push_back(int value);
  void remove_duplicates();
  size_t length_max_decreasing() const;
  void display();
};

#endif  // LINKEDLIST_H
