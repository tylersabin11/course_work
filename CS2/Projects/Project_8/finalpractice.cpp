/*
Tyler Sabin
Section 004
Project 8
In this project we will recapp working with classes
*/

#include "Circle.h"
#include <iostream>
#include <array>

int main(){

    //Set variables for array, num of circs, and the class object
    std::array<int,20> radius{};
    int numCircs{};
    Circle circles;

    do{
        std::cout << "Input the number of circles to create between 1 and 20: ";
        std::cin >> numCircs;
    }while(numCircs <= 0 || numCircs > 20);

    for(int i{0}; i < numCircs; i++){
        radius[i] = i +1;
    }
    for(int i{0}; i < numCircs; i++){
        circles.set_radius(radius[i]);
        circles.print_values();
    }


    return 0;
}