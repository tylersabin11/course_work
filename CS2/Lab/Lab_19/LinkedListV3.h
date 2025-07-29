#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

// A structure defining the node.
struct Node {
  
  int data;    // some data
  Node *next;  // Pointer to another Node
  Node *prev;
};

class LinkedList {
private:
  Node *head; // pointer to first item in list
  Node *tail;

public:
  LinkedList();               // How do I initialize my object?
  void push_back(int value);  // add elements to the end of our LL
  void print() const;         // print all elements
  void print_reverse() const;         // print all elements
  bool empty() const;         // function to determine if list is empty
  ~LinkedList();              // How do I clean up my list
};

#endif