//Tyler Sabin
//Section 004

#include <iostream>
#include <iomanip>

int main(){

    float grade{};

    std::cout << "Enter a value between 0-100 (inclusive): " << ' ';
    std::cin >> grade;

    std::cout << std::fixed << std::setprecision(2);
    if(grade >= 73 && grade <= 100){
        std::cout << '\n' << grade << ' ' << "is Great." << std::endl;
    } else if(grade >= 60){
        std::cout << '\n' << grade << ' ' << "is Passing." << std::endl;
    } else if (grade < 60 && grade >= 0){
        std::cout << '\n' << grade << ' ' << "is Failing." << std::endl;
    } else{
        std::cout << '\n' << grade << ' ' << "INVALID GRADE!" << std::endl;
    }
}