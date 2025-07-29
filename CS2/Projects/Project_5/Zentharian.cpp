#include "Zentharian.h"
#include <iostream>
#include <fstream>
#include <string>
#include <array>


void Zentharian::process_file(){
    std::array<int,kMaxCrystal> tempArr{};
    //Count for num of Crystals
    int tempNum {};
    //Temp Variable for Crystal Total
    int tempCrystalTotal{};
    //Count for index
    int tempCount{0};
    //Temp variable for Get Line
    std::string tempString{};
    //Temp variable for Zen Count
    int tempZenCount{};

    std::ifstream inFile{m_inFileName};

    while(std::getline(inFile, tempString)){
        //Check to see if the file is empty
        if(!tempString.empty()){
            //convert string to int
            tempNum = std::stoi(tempString);            
            //Count index = Num of Crystals
            tempArr[tempCount] = tempNum;
            //Increase index
            tempCount++;
            //Total of crystals increased by the crystal number
            tempCrystalTotal += tempNum;
        }else{
            //Add one to the zen count
            tempZenCount++;
            //Compare the crystal totals
            if(tempCrystalTotal > m_crystalTotal){
                //Set the private data members of the class
                m_ZenCount = tempZenCount;
                m_CrystalCount = tempCount;
                m_crystalTotal = tempCrystalTotal;
                //copy the contents of the temp arr to the private array
                for(int i{0}; i < tempCount; i++){
                    m_arrCrystals[i] = tempArr[i];
                }
            
                //Reset the temp variables
                for(int i{0}; i < kMaxCrystal; i++){
                    tempArr[i] = 0;
                }
                tempCount = 0;
                tempCrystalTotal = 0;
            }else{
                //Reset the temp variables
                for(int i{0}; i < kMaxCrystal; i++){
                    tempArr[i] = 0;
                }
                tempCount = 0;
                tempCrystalTotal = 0;
            }
        }
    }
    
}

//Print the contents
void Zentharian::display_info(){
    std::cout << "Zentharian " << m_ZenCount << " has " << m_CrystalCount << " worth\n";
    for(int i{0}; i < m_CrystalCount; i++){
        std::cout << m_arrCrystals[i] << '\n';
    }
    std::cout << "fuel each. Totaling " << m_crystalTotal << " units.\n";
}




bool Zentharian::open_file(){
    //Set variables
    std::ifstream inFile{};
    std::string fileName{};
    bool boolTemp = false;

    std::cout << "Enter ledger file: ";
    std::cin >> fileName;
    std::cout << '\n';
    inFile.open(fileName);

    //If you cant open the file, print an error message
    if(!inFile){
        boolTemp = true;
        std::cout << "Your entered an invalid ledger..." << fileName << '\n';
    } else{
        m_inFileName = fileName;
    }
    return boolTemp;
}
bool Zentharian::operator > (Zentharian& rhs){
    bool greatThan = false;
    if(m_crystalTotal > rhs.m_crystalTotal)
        greatThan = true;
    return greatThan;
}