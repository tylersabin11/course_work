/*
Tyler Sabin
Section 004
Lab 20
*/

#include "MyStack.h"
#include <iostream>
#include <fstream>
#include <string>

int main(){

    std::string fileName;

    std::cout << "Enter file to reverse: ";
    std::cin >> fileName;
    std::cout << '\n';

    std::ifstream inFile{fileName};
    if(!inFile){
        std::cout << "ERROR file: " << fileName << " does not exist.";
    }

    //Create a stack object
    Stack stackLL;

    //Temp string
    std::string temp;

    while(inFile){
        //Get the line
        std::getline(inFile,temp);
        //Itterate over the string for each char
        for(int character{0}; character < static_cast<int>(temp.length()); character++){
            //Push the char to the stack
            stackLL.push(temp[character]);
        }
        //While the stack is not empty
        while(!stackLL.empty()){
            //Print out the char
            std::cout << stackLL.top();
            //Pop the top
            stackLL.pop();
        }
        //Print out new line character
        std::cout << '\n';
    }

    inFile.close();

    return 0;
}