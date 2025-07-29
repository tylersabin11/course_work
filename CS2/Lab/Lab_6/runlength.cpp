/*
Tyler Sabin
runlength.cpp
Section 004
this program will count the number of the same letter in a row
*/
#include <iostream>
#include <string>

int main(){
    
    std::string tempstring{""};
    int count{1};
    std::cout << "Enter text to compress: ";
    std::getline(std::cin, tempstring);

    int len = tempstring.length();

    for(int index = 0; index < len; index++){
        if(tempstring[index] == ' '){
            std::cout << ' ';
            count = 1;
        } else if(tempstring[index] == tempstring[index+1] && tempstring[index] != ' '){
            count ++;
        } else{
            std::cout << count << tempstring[index];
            count = 1;
        }
    }
    std::cout << '\n';

}