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

public:
  LinkedList();               // How do I initialize my object?
  void push_back(int value);  // add elements to the end of our LL
  void print() const;         // print all elements
  void push_front(int value); // push to front
  void remove_front();        // Delete something from the front
  void remove_back();         // Delete something from the back
  ~LinkedList();              // Destructor for Linked List
};

#endif