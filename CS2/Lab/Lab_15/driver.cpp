//Tyler Sabin
//Section 004
//Lab 15
//In this lab we will overload operators and compare Rectangles

#include "Rectangle.h"
#include <iostream>

int main(){

    Rectangle rec1{};
    Rectangle rec2{};
    Rectangle rec3{7,23};
    Rectangle rec4{};
    Rectangle rec5{};

    rec5 = rec3;

    rec2.get_length();
    rec2.get_width();
    std::cout << '\n';

    rec4.get_length();
    rec4.get_width();
    std::cout << '\n';

    rec1.calculate_area();
    rec2.calculate_area();
    rec3.calculate_area();
    rec4.calculate_area();
    rec5.calculate_area();

    std::cout << "Rec1: \n";
    rec1.display_info();
    std::cout << '\n';
    std::cout << "Rec2: \n";
    rec2.display_info();
    std::cout << '\n';
    std::cout << "Rec3: \n";
    rec3.display_info();
    std::cout << '\n';
    std::cout << "Rec4: \n";
    rec4.display_info();
    std::cout << '\n';
    std::cout << "Rec5: \n";
    rec5.display_info();
    std::cout << '\n';

    if(rec3 == rec5){
        std::cout << "Rec3 & Rec5 are equal\n";
    }else{
        std::cout << "Rec3 & Rec5 are not equal\n";
    }

    if(rec1 != rec4){
        std::cout << "Rec1 & Rec4 are not equal\n";
    }else{
        std::cout << "Rec1 & Rec4 are equal\n";
    }

    if(rec3 >= rec5){
        std::cout << "Rec3 is greater than or equal to Rec5\n";
    }else{
        std::cout << "Rec3 is less than Rec5\n";
    }

    if(rec5 <= rec1){
        std::cout << "Rec5 is less than or equal to rec1\n";
    }else{
        std::cout << "Rec5 is greater than rec1\n";
    }

    if(rec1 < rec3){
        std::cout << "Rec1 is less than Rec3\n";
    }else{
        std::cout << "Rec1 is greater than Rec3\n";
    }

    if(rec2 > rec5){
        std::cout << "Rec2 is greater than Rec5\n";
    }else{
        std::cout << "Rec5 is greater than Rec2\n";
    }


    return 0;
}