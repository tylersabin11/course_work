/*
Tyler Sabin
Section 004
Lab 11
*/

#include <iostream>
#include <array>
#include <string>

//Declare global variables
const int kMaxSize_Arr1{5};
const int kMaxSize_Arr2{5};

//Define function prototypes
std::array<double,kMaxSize_Arr1> GetGrades();
bool GradesAreSame(std::array <double,kMaxSize_Arr1> arr1, std::array <double,kMaxSize_Arr2> arr2);

int main(){

    //Declare array variables & bool variable
    std::array <double,kMaxSize_Arr1> array1{};
    std::array <double,kMaxSize_Arr2> array2{};
    bool gradeSame{};

    std::cout << "Getting Student One" << '\n';
    //Call get grade function to store grades in an array
    array1 = GetGrades();
    std::cout << "Getting Student Two" << '\n';
    array2 = GetGrades();
    //Call bool function
    gradeSame = GradesAreSame(array1,array2);
    std::cout << '\n';

    if(gradeSame == true){
        std::cout << "Both students have the SAME grades!" << '\n';
    } else{
        std::cout << "Both students have the DIFFERENT grades!" << '\n';
    }


    return 0;
}


std::array<double,kMaxSize_Arr1> GetGrades(){
    //Declare local array and variable for grades
    std::array <double,kMaxSize_Arr1> locArray{};
    double tempGrade{};
    //For loop to collect grade and store it in the array index
    for(int i{0}; i < kMaxSize_Arr1; i++){
        std::cout << "Enter grade: ";
        std::cin >> tempGrade;
        locArray[i] = tempGrade;
    }
    //Return array
    return locArray;
}

bool GradesAreSame(std::array <double,kMaxSize_Arr1> arr1, std::array <double,kMaxSize_Arr2> arr2){
    //Test to see if the arrays are the same
    if(arr1 == arr2){
        return true;
    } else{
        return false;
    }
}