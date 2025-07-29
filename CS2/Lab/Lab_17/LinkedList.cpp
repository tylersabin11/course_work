#include "LinkedList.h"
#include <iostream>

// TODO: Implement the functions below.
LinkedList::LinkedList() {
    //Create head at address 0
    head = nullptr;
}

void LinkedList::print() const {
    //check to see if the head is a nullptr
    if(head == nullptr){
        std::cout << "Current List:  empty...\n";
    }else{
        //Create a temp node
        Node *temp = head;
        std::cout << "Current List: ";
        //If the temp is not a nullptr
        while(temp != nullptr){
            //Print out the data
            std::cout << ' ' << temp->data;
            //Go to the next node
            temp = temp->next;
        }
        std::cout << '\n';
    }
}

void LinkedList::push_front(int value) {
    //Create a new node
    Node *newNode = new Node;
    //Insert the value into the data portion
    newNode->data = value;
    //The next portion will point what the head was pointing to
    newNode->next = head;
    //This sets the head to the newly created node (Head points to the new node and makes it the first node in the list)
    head = newNode;
}

void LinkedList::push_back(int value) {
    //Create a new node
    Node *newNode = new Node;
    //Have the new node point to null
    newNode->next = nullptr;
    //Insert the value into the data section
    newNode->data = value;
    //if the head is a nullptr, replace the head for the new node (since the list is empty)
    if(head == nullptr){
        head = newNode;
    }else{
        //Create a temp node
        Node *temp = head;
        //While the 'next' section is not a nullptr
        while(temp->next != nullptr){
            //set the temp to look at the next node
            temp = temp->next;
        }
        //Once it is a nullptr, have the 'next' point to the new node
        temp->next = newNode;
    }
}

void LinkedList::remove_front(){
    //Create a temp pointer
    Node *temp = head;
    //Move head up
    head = temp->next;
    //Set the temp to look at a nullptr
    temp->next = nullptr;
    //Delete the temp
    delete temp;
}

void LinkedList::remove_back(){
    //2 pointers, one at head, one null; keep the one that is null 1 behind the head one
}

LinkedList::~LinkedList(){
    Node *temp = head;
    if(head == nullptr){
        std::cout << "Destructor Success!\n";
    }else{
        while(head != nullptr){
            head = temp->next;
            temp->next = nullptr;
            delete temp;
            temp = head;
        }
        std::cout << "Destructor Success!\n";
    }
}