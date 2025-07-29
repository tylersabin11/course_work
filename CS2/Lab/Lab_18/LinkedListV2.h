#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

// A structure defining the node.
struct Node {
  
  int data;    // some data
  Node *next;  // Pointer to another Node
};

class LinkedList {
private:
  Node *head; // pointer to first item in list
  Node *tail;

public:
  LinkedList();               // How do I initialize my object?
  void push_back(int value);  // add elements to the end of our LL
  void print() const;         // print all elements
  void push_front(int value); // push to front
  bool empty() const;         // function to determine if list is empty
  void remove(int value);     // function to remove a value
  Node *find(int value);      // function to find a node with a value (nullptr if not found)
};

#endif