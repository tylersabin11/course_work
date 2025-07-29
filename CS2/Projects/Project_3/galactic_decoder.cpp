/*
Tyler Sabin
Section 004
Project 3
In this project, we will be decoding a passcode
through a set of instructions given by a file with
a starting point of 5 on the pincode
*/

#include <iostream>
#include <fstream>
#include <string>

//Declare functions at the top
int open_file(std::ifstream &inFile);
std::string decode_passcode(std::ifstream &inFile, std::string &passcode);

int main(){

    //Declare variables for read file & passcode
    std::ifstream inFile{};
    std::string passcode{};
    int fileExists{};

    //Open file
    fileExists = open_file(inFile);

    //Store the returned passcode into a variable
    if(fileExists == 1){
        passcode = decode_passcode(inFile, passcode);
        //Print out the passcode
        std::cout << "Passcode: " << passcode << '\n';
    }
    

    //Close file
    inFile.close();

    return 0;
}






int open_file(std::ifstream &inFile){
    
    //Set variable for input file name
    std::string fileName{};

    std::cout << "Enter file to translate: ";
    std::cin >> fileName;
    std::cout << '\n';

    //Attempt to open file, if file doesn't exist, print an error code
    inFile.open(fileName);
    if(!inFile){
        std::cout << fileName << "was unable to be opened...\n";
        return 2;
    } else{
        return 1;
    }

}

std::string decode_passcode(std::ifstream &inFile, std::string &passcode){
    
    //Set variables for char instruction and starting point
    char instruction{};
    int startingPoint {5};

    //Loop through the file while contents exist
    while(inFile){
        //Get the char for the instruction (R/L/U/D)
        inFile.get(instruction);
        //If the character is a new line char, skip steps
        if(instruction != '\n'){
            /*
            If the char is U and the current position is not 2, subtract 3
            If the char is D and the current position is not 8, add 3
            If the char is R and the current position is not 3, 6, or 9, add 1
            If the char is L and the current position is not 1, 4, or 7, subtract 1
            */
            if(instruction == 'U' && startingPoint != 2){
                startingPoint = startingPoint - 3;
            } else if(instruction == 'D' && startingPoint != 8){
                startingPoint = startingPoint + 3;
            } else if(instruction == 'R' && (startingPoint != 3 && startingPoint != 6 && startingPoint != 9)){
                startingPoint = startingPoint + 1;
            } else if(instruction == 'L' && (startingPoint != 1 && startingPoint != 4 && startingPoint != 7)){
                startingPoint = startingPoint - 1;
            } else{
                startingPoint = startingPoint;
            }
        }else{
            //Concat the current point to the passcode
            passcode += std::to_string(startingPoint);
            startingPoint = 5;
        }
    }
    //Return the passcode as a string
    return passcode;

}