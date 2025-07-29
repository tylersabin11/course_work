#include "MyStack.h"

Stack::Stack(){
    //Set both to a nullptr
    bottom = nullptr;
    m_top = nullptr;
}
void Stack::push(char value){
    //Create a new node
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    //Check if empty
    if(empty()){
        //If empty, set the top & bottom to the new node
        m_top = newNode;
        bottom = newNode;
        return;
    }
    //Push the new node to the front of the list
    m_top->next = newNode;
    newNode->prev = m_top;
    m_top = newNode;
}
char Stack::top(){
    return m_top->data;
}
void Stack::pop(){
    //Check if not empty
    if(!empty()){
        //Create a temp and set to the top
        Node *temp = m_top;
        m_top = temp->prev;
        //Delete the temp node
        delete temp;
    }
}