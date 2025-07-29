/*
Tyler Sabin
Section 004
Lab 7
This program will take an input file, and reverse the run length process
*/

#include <iostream>
#include <fstream>
#include <string>

int main(){

    std::string fileName{};
    std::ifstream infile{};

    std::cout << "Enter filename to decompress: ";
    std::cin >> fileName;

    infile.open(fileName);
    
    if(!infile){
        std::cout << "File " << fileName << "does not exist!\n";
        return 0;
    }
    int numChar{};
    char character{};

    
    while(infile){
        if(infile >> numChar){
            infile.ignore(1);
            infile.get(character);
         for(int i{0}; i < numChar; i++){
            std::cout << character;
            } 
        }else{
            std::cout << '\n';
        }
    }
    std::cout << '\n';

    infile.close();
}