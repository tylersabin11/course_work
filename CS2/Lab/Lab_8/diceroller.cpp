/*
Tyler Sabin
Section 004
Lab 8
This program will take two inputs, amount of dice and sides.
This will then Roll and give each roll & total
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

//Function to reference the variables in main
//Will also check to see if the values are negative
void dice_type_amount(int &num_dice , int &side_amnt){
    std::cin >> num_dice >> side_amnt;
    if(num_dice < 0 || side_amnt < 0){
        std::cout << "Illegal value entered...\n";
        return;
    }
}

//Function will take two arguments and randomly generate a number between 1-num of sides
//Will also print each roll and return the total
int roll_and_total(int amnt , int sides){
    int total{};
    std::cout << "Rolling " << amnt << 'd' << sides << '\n';
    for(int roll{0}; roll < amnt; roll++){
        int number{rand() % sides + 1};
        std::cout << number << '\n';
        total += number;
    }
    return total;
}

int main(){

    srand(time(0)); // Seed random
    int num_dice_user{};
    int num_sides{};
    int total{};

    std::cout << "++++ Super Awesome Dice Roller ++++\n";
    std::cout << "Enter amount and number of sides: ";
    
    dice_type_amount(num_dice_user,num_sides);
    std::cout << '\n';
    total = roll_and_total(num_dice_user,num_sides);

    std::cout << "Total: " << total << std::endl;
    return 0;

}