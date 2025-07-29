#ifndef MYSTACK_H
#define MYSTACK_H

struct Node{
    //Structure for a doubly linked list
    Node *next;
    Node *prev;
    char data;
};

class Stack{
private:
    //Top and bottom
    Node *bottom;
    Node *m_top;

public:
    //Constructor
    Stack();
    //Push function
    void push(char value);
    //Pop function
    void pop();
    
    //Return the top
    char top();
    //Check if stack is empty
    bool empty(){return m_top == nullptr;}
};
#endif