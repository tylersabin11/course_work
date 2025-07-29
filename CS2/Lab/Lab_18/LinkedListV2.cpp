#include "LinkedListV2.h"
#include <iostream>

// TODO: Implement the functions below.
LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
}

void LinkedList::print() const {
    if(empty()){
        std::cout << "ERROR: empty list...\n";
    }else{
        Node *temp = head;
        std::cout << "Data:\n";
        while(temp != tail){
            std::cout << temp->data << '\n';
            temp = temp->next;
        }
    }
    std::cout << '\n';
}

void LinkedList::push_front(int value) {
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void LinkedList::push_back(int value) {
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    if(head == nullptr){
        head = newNode;
        tail = newNode;
    }else{
        tail->next = newNode;
        tail = newNode;
    }
}

void LinkedList::remove(int value){
    //Set the address value to the found variable
    Node *address = find(value);
    //If it is null, then the value does not exist
    if(address == nullptr){
        std::cout << "ERROR: " << value << " not found, could not remove...\n";
        return;
    }else{
        //Set two temp nodes, one of them should trail
        Node *cur = head;
        Node *prev = nullptr;
        //Loop until the address is the correct one
        while(cur != address){
            //Move up both
            prev = cur;
            cur = cur->next;
        }
        //If it is the first node in the list
        if(prev == nullptr){
            //Set head to the 2nd node in the list
            head = cur->next;
        }else if(cur->next != tail){
            //If the next address for the node is not a nullptr
            //Set the prev to what the 'next' of the cur is looking at
            prev->next = cur->next;
        }else{
            //Must be the last node, so the prev should look to a nullptr
            prev->next = nullptr;
            tail = prev;
        }
        //delete the node
        delete cur;
    }
}

Node *LinkedList::find(int value){
    //Set variables for a temp node, and data_value
    Node *temp = head;
    int data_value{};
    //Loop until it is a nullptr or we find the correct address of the data value
    while(temp != tail){
        //Store the data in the temp variable
        data_value = temp->data;
        //See if it equals the value inputted
        if(data_value == value){
            //Return the address
            return temp;
        }
        //Move to the next node
        temp = temp->next;
    }
    //Since it did not find the value, return null
    return nullptr;
}

bool LinkedList::empty() const {
    return head == nullptr;
}

