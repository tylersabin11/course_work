#include <iostream>
#include <array>
#include <string>
#include <iomanip>
#include <fstream>


int main(){

    std::ifstream inFile{};
    int count{};


    
}

std::array ProcessFile(std::ifstream &inFile, int &count){
    std::string fileName{};
    std::array<int, count> grades{};
    std::cout << "Enter the input file: ";
    std::cin >> fileName;
    std::cout << '\n';
    inFile.open(fileName);
    int grade{};
    if(!inFile){
        std::cout << fileName << " does not exist.";
        return 0;
    }
    while(infile >> grade){
        count ++;
        grades[]
    }
}