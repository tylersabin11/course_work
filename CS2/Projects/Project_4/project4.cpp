/*
Tyler Sabin
Section 004
Project 4
This project will help us practice the use of 2-d arrays
as we will collect information regarding recipes from a file
store them in a 2-d array, calc the price for each product
and display the menu

Input: Files containing menu/recipe information for products
Output: Display a menu to the console
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <array>

//global constant variables
const int kMaxProducts{24};
const int kMaxIngredients{30};

//function prototypes
void open_file(std::ifstream &inFile);
void get_products(std::array <std::string, kMaxProducts> &,int &);
void get_recipe(std::array<std::array<int,kMaxProducts>,kMaxIngredients> &, std::array<float,kMaxIngredients> &, std::ifstream &inFile, int &, int &);
void flip_array(std::array<std::array<int,kMaxProducts>,kMaxIngredients> , std::array<std::array<int,kMaxProducts>,kMaxIngredients> &,int &, int &);
void calc_prod_prices(std::array<std::array<int,kMaxProducts>,kMaxIngredients> arrayFlip, std::array<float,kMaxIngredients> priceIngred, std::array<float,kMaxIngredients> &priceOfProd, int &, int &);
void display_menu(std::array<std::string, kMaxProducts>,std::array<std::array<int,kMaxProducts>,kMaxIngredients>, std::array<float,kMaxIngredients>,int , int);

int main(){

    std::ifstream inFile{};
    //array to conatin the list of products
    std::array<std::string, kMaxProducts> products{};
    //array to grab the ingredient count from the file
    std::array<std::array<int,kMaxProducts>,kMaxIngredients> recipes{};
    //array for price of ingredients
    std::array<float,kMaxIngredients> priceIngred{};
    //array to contain the proper format for printing out the ingredient count
    std::array<std::array<int,kMaxProducts>,kMaxIngredients> arrayFlip {};
    //array that contains the prices for each product
    std::array<float,kMaxIngredients> priceOfProd{};

    //variables for specific counts throughout the program
    int countProd{0};
    int recipesProd{0};
    int ingredCount{0};

    //run all functions 
    open_file(inFile);
    get_products(products,countProd);
    get_recipe(recipes, priceIngred, inFile, recipesProd, ingredCount);
    flip_array(recipes, arrayFlip, recipesProd, ingredCount);
    calc_prod_prices(arrayFlip,priceIngred, priceOfProd, recipesProd, ingredCount);
    display_menu(products, arrayFlip, priceOfProd, recipesProd, ingredCount);

    //close file
    inFile.close();

    return 0;
}

void open_file(std::ifstream &inFile){
    std::string fileName{};

    std::cout << "Enter the file name: ";
    std::cin >> fileName;

    inFile.open(fileName);

    while(!inFile){
        std::cout << "File open error.\n";
        std::cout << "Enter the file name: ";
        std::cin >> fileName;
        inFile.open(fileName);
    }

    std::cout << "File Open Successfully.\n";

}

void get_products(std::array <std::string, kMaxProducts> &products, int &countProd){
    std::ifstream product_file{};
    std::string prodTemp {};
    product_file.open("products.dat");

    //get the food item name and add it to the list
    while(std::getline(product_file,prodTemp)){
        products[countProd] = prodTemp;
        //set a count 
        countProd++;
    }
}

void get_recipe(std::array<std::array<int,kMaxProducts>,kMaxIngredients> &recipes, std::array<float,kMaxIngredients> &priceIngred, std::ifstream &inFile, int &recipesProd, int &ingredCount){
    //set a buffer for the rows and cols
    inFile >> recipesProd;
    inFile >> ingredCount;
    float tempPrice {};

    //itterate through the rest of the file and add 
    //to the 2-d array of ingredients
    for(int row{0}; row < ingredCount; row++){
        for(int col{0}; col < recipesProd; col++){
            inFile >> recipes[row][col];
        }
        //pick up the float and add to a seperate array
        inFile >> tempPrice;
        priceIngred[row] = tempPrice;
    }
}

void flip_array(std::array<std::array<int,kMaxProducts>,kMaxIngredients> recipes, std::array<std::array<int,kMaxProducts>,kMaxIngredients> &arrayFlip,int &recipesProd, int &ingredCount){
    //flip the cols and rows into a new array
    for (int row = 0; row < ingredCount; row++) {
        for (int col = 0; col < recipesProd; col++) {
            arrayFlip[col][row] = recipes[row][col];
        }
    }
}

void calc_prod_prices(std::array<std::array<int,kMaxProducts>,kMaxIngredients> arrayFlip, std::array<float,kMaxIngredients> priceIngred, std::array<float,kMaxIngredients> &priceOfProd, int &ingredCount, int &recipesProd){
    //set a temp variable
    float tempAmount{};
    
    //itterate through the array
    for(int row{0}; row < ingredCount; row++){
        for(int col{0}; col < recipesProd; col++){
            //add the amount to the temp variable
            tempAmount += (arrayFlip[row][col] * priceIngred[col]);
        }
        //add the price to a seperate array
        priceOfProd[row] = tempAmount;
        //reset the count
        tempAmount = 0;
    }
}

void display_menu(std::array<std::string, kMaxProducts> products,std::array<std::array<int,kMaxProducts>,kMaxIngredients> arrayFlip, std::array<float,kMaxIngredients> priceOfProd,int recipesProd, int ingredCount){
    int count {1};

    //print the menu
    std::cout << "**************************************************************************\n" << std::fixed;
    std::cout << "  Product" << "     Ing1" << "     Ing2" << "    Ing3" << std::setw(3) << "   Ing4" << std::setw(3) << "    Ing5" << std::setw(3) << "    Ing6" << std::setw(3) << "       Price\n"; 
    std::cout << "--------------------------------------------------------------------------\n";
    //I struggled with the formating, I did my best though
    //itterate through the array, print the product first, then row, then price
    for(int row{0}; row < recipesProd; row++){
        std::cout << std::setw(1) << count << std::setw(8) << products[row];
        for(int col{0}; col < ingredCount; col++){
            std::cout << std::setw(8) << arrayFlip[row][col];
        }
        std::cout << std::setprecision(2) <<  "      $" << priceOfProd[row] << '\n';
        count++;
    }
    std::cout << "--------------------------------------------------------------------------\n";
}