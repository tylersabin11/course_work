
#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(){
    m_length = 1;
    m_width = 1;
}
Rectangle::Rectangle(int len, int width){
    m_length = len;
    m_width = width;
}
void Rectangle::get_length(){
    int length{};
    std::cout << "Enter the length: ";
    std::cin >> length;
    m_length = length;
}
void Rectangle::get_width(){
    int width{};
    std::cout << "Enter the width: ";
    std::cin >> width;
    m_width = width;
}
void Rectangle::display_info(){
    std::cout << "Length: " << m_length << '\n' << "Width: " << m_width << '\n' << "Area: " << m_area << '\n';
}

//Overloaded Operators
bool Rectangle::operator == (Rectangle& rhs){
    bool isequal = false;
    if((m_length == rhs.m_length) && (m_width == rhs.m_width) && (m_area == rhs.m_area))
        isequal = true;
    return isequal;
}
bool Rectangle::operator != (Rectangle& rhs){
    bool notequal = false;
    if((m_length != rhs.m_length) || (m_width != rhs.m_width) || (m_area != rhs.m_area))
        notequal = true;
    return notequal;
}
bool Rectangle::operator < (Rectangle& rhs){
    bool lessThan = false;
    if(m_area < rhs.m_area)
        lessThan = true;
    return lessThan;
}
bool Rectangle::operator > (Rectangle& rhs){
    bool greaterThan = false;
    if(m_area > rhs.m_area)
        greaterThan = true;
    return greaterThan;
}
bool Rectangle::operator <= (Rectangle& rhs){
    bool lessThanOrEq = false;
    if(m_area <= rhs.m_area)
        lessThanOrEq = true;
    return lessThanOrEq;
}
bool Rectangle::operator >= (Rectangle& rhs){
    bool greaterThanOrEq = false;
    if(m_area >= rhs.m_area)
        greaterThanOrEq = true;
    return greaterThanOrEq;
}
void Rectangle::operator ++ (){
    m_length++;
    m_width++;
}
void Rectangle::operator -- (){
    m_length--;
    m_width--;
}