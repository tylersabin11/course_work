/*
Tyler Sabin
Section 004
Project 5
In this project, we will work with OOP and files.
Our goal is to see which Zen has the highest total of crystals
Using arrays, classes, overloaded operators and more
*/
#include <iostream>
#include "Zentharian.h"

int main(){
    Zentharian zen;

    if(zen.open_file()){
        return 0;
    }
    zen.process_file();
    zen.display_info();

    return 0;
}