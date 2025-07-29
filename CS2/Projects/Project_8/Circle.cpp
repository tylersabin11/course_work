#include "Circle.h"
#include <iostream>
#include <cmath>

//Display the values
void Circle::print_values(){
    //Set diameter
    int diameter = radius * 2;
    //Set area
    double area = M_PI * pow(radius,2);
    //Print out contents
    std::cout << "The circle with radius " << radius << " has a diameter of " << diameter << " and an area of " << area << '\n';
}