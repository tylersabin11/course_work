/*
Tyler Sabin
Section 004
Project 2
In this project, we will be taking, and validating, 
inputs using a switch and case expression
*/

#include <iostream>
#include <string>
#include <iomanip>

int main(){

    //Set variables for choice, damage and category
    std::string Choice{};
    float Damage{};
    std::string Category{};

    float a_damage{};
    float n_damage{};
    float h_damage{};


    //Print out the calc UI and ask for inputs
    std::cout << "---------------------------------------" << '\n';
    std::cout << "------ Amazing Combat Calculator ------" << '\n';
    std::cout << "---------------------------------------" << '\n';
    std::cout << "Enter ability name: ";
    std::getline(std::cin, Choice);
    std::cout << "Enter base damage: ";
    std::cin >> Damage;
    std::cout << "Enter ability category: ";
    std::cin.ignore();
    std::getline(std::cin, Category);
    std::cout << '\n' << '\n';

    std::cout << std::fixed << std::setprecision(1);

    int Choice_Int{};


    //Convert input to an int for switch expression
    if(Choice == "Rest"){
        Choice_Int = 1;
    } else if(Choice == "Slap"){
        Choice_Int = 2;
    } else if(Choice == "FrostFire"){
        Choice_Int = 3;
    } else{
        Choice_Int = 4;
    }

    switch(Choice_Int){

        //For case 1-3, check to make sure the damage is between 0-9000
        case 1:
            if(Damage <= 0){
                std::cout << "All ability damage must be positive." << std::endl;
            } else if(Damage > 9000){
                std::cout << "Only Goku can deal more than 9000 dmg." << std::endl;
            } else{

                //Validate category and make proper calculations
                if(Category == "A"){
                    a_damage = Damage / 4.0;
                    std::cout << Choice << ' ' << " dealt " << a_damage << ' ' << "area of effect damage to each target." << std::endl;
                } else if(Category == "N"){
                    n_damage = Damage * 1.2;
                    std::cout << Choice << ' ' << " dealt " << n_damage << ' ' << "boring normal damage to the target." << std::endl;
                } else if(Category == "H"){
                    h_damage = Damage * (-1.0);
                    std::cout << Choice << ' ' << " dealt " << h_damage << ' ' << "damage healing the target." << std::endl;
                } else{
                    //If category is not a valid input, inform user
                    std::cout << "Ability category" << ' ' << Category << ' ' << "not implemented." << std::endl;
                }
            }
            break;
        case 2:
            if(Damage <= 0){
                std::cout << "All ability damage must be positive." << std::endl;
            } else if(Damage > 9000){
                std::cout << "Only Goku can deal more than 9000 dmg." << std::endl;
            } else{
                if(Category == "A"){
                    a_damage = Damage / 4.0;
                    std::cout << Choice << ' ' << " dealt " << a_damage << ' ' << "area of effect damage to each target." << std::endl;
                } else if(Category == "N"){
                    n_damage = Damage * 1.2;
                    std::cout << Choice << ' ' << " dealt " << n_damage << ' ' << "boring normal damage to the target." << std::endl;
                } else if(Category == "H"){
                    h_damage = Damage * (-1.0);
                    std::cout << Choice << ' ' << " dealt " << h_damage << ' ' << "damage healing the target." << std::endl;
                } else{
                    std::cout << "Ability category" << ' ' << Category << ' ' << "not implemented." << std::endl;
                }
            }
            break;
        case 3:
            if(Damage <= 0){
                std::cout << "All ability damage must be positive." << std::endl;
            } else if(Damage > 9000){
                std::cout << "Only Goku can deal more than 9000 dmg." << std::endl;
            } else{
                if(Category == "A"){
                    a_damage = Damage / 4.0;
                    std::cout << Choice << ' ' << " dealt " << a_damage << ' ' << "area of effect damage to each target." << std::endl;
                } else if(Category == "N"){
                    n_damage = Damage * 1.2;
                    std::cout << Choice << ' ' << " dealt " << n_damage << ' ' << "boring normal damage to the target." << std::endl;
                } else if(Category == "H"){
                    h_damage = Damage * (-1.0);
                    std::cout << Choice << ' ' << " dealt " << h_damage << ' ' << "damage healing the target." << std::endl;
                } else{
                    std::cout << "Ability category" << ' ' << Category << ' ' << "not implemented." << std::endl;
                }
            }
            break;
        default:
        //If the input for choice is not valid, we will let the user know
            std::cout << "Ability" << ' ' << Choice << ' ' << "not implemented yet." << std::endl;
            break;
    }
}