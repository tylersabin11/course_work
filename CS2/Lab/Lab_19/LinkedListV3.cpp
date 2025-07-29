#include "LinkedListV3.h"
#include <iostream>

// TODO: Implement the functions below.
LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
}

void LinkedList::print() const {
    if(empty()){
        std::cout << "ERROR: empty list...\n";
        return;
    }
    Node *temp = head;
    while(temp != nullptr){
        std::cout << temp->data << '\n';
        temp = temp->next;
    }
}

void LinkedList::print_reverse() const {
    if(empty()){
        std::cout << "ERROR: empty list...\n";
        return;
    }
    Node *temp = tail;
    while(temp != nullptr){
        std::cout << temp->data << '\n';
        temp = temp->prev;
    }
}

void LinkedList::push_back(int value) {
    Node *newNode = new Node;
    newNode->data = value;
    if(head == nullptr){
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

bool LinkedList::empty() const {
    return head == nullptr;
}

LinkedList::~LinkedList() {
    if(empty()){
        return;
    }
    while(!empty()){
        Node *curr = tail;
        tail = curr->prev;
        delete curr;
    }
    head = nullptr;
    tail = nullptr;
}
