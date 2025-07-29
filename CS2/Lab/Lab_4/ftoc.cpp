#include <iostream>
#include <string>
#include <iomanip>

//Tyler Sabin
//Section 2170-004

int main(){
    double fahrenheit{};

    double celsius{};

    std::cout << std::fixed << std::setprecision(3);
    std::cout << "Enter a temperature in Fahrenheit: ";
    std::cin >> fahrenheit;

    celsius = (5.0/9.0) * (fahrenheit - 32);

    std::cout << '\n' << std::setw(5) << fahrenheit << std::setw(4) << "F =" << 
    std::setw(7) << celsius << std::setw(3) <<"C" << std::endl;
}
