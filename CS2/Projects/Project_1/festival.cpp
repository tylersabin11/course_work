//Tyler Sabin
//Section 004

#include <iostream>
#include <iomanip>
#include <string>

int main(){

    //Set variables for amount sold
    int Mushroom{};
    int Lembas{};
    int Cram_Bread{};
    int Salt_Pork{};
    int Rab_Stew{};
    int Hon_Cake{};
    int Well_Wat{};

    //Set variables for total price sold
    float mush_sold{};
    float lem_sold{};
    float cram_sold{};
    float salt_sold{};
    float rab_sold{};
    float hon_sold{};
    float well_sold{};

    //Set variables for total, cut, total-cut, and total pre-cut
    float total{};
    float cut{};
    float tot_min_cut{};
    float prof_pre_cut{};

    //Get input for amount of each product sold
    std::cout << "How many Mushrooms were sold?" << ' ';
    std::cin >> Mushroom;
    std::cout << "How many Lembas were sold?" << ' ';
    std::cin >> Lembas;
    std::cout << "How many Cram Bread were sold?" << ' ';
    std::cin >> Cram_Bread;
    std::cout << "How many Salted Pork were sold?" << ' ';
    std::cin >> Salt_Pork;
    std::cout << "How many Rabbit Stew were sold?" << ' ';
    std::cin >> Rab_Stew;
    std::cout << "How many Honey Cake were sold?" << ' ';
    std::cin >> Hon_Cake;
    std::cout << "How many Well Water were sold?" << ' ';
    std::cin >> Well_Wat;

    //Calculate the total amount (in price) sold for each product
    mush_sold = Mushroom * .8;
    lem_sold = Lembas * 3.0;
    cram_sold = Cram_Bread * 2.0;
    salt_sold = Salt_Pork * 2.25;
    rab_sold = Rab_Stew * 3.25;
    hon_sold = Hon_Cake * 2.0;
    well_sold = Well_Wat * 1.25;

    //Calculate the total, cut, total-cut, and profit pre-cut
    total = mush_sold + lem_sold + cram_sold + salt_sold + rab_sold + hon_sold + well_sold;
    cut = total * .0675;
    tot_min_cut = total - cut;
    prof_pre_cut = total / 2.0;

    //Print output

    std::cout << std::fixed << std::setprecision(2);
    std::cout << '\n' << '\n';
    std::cout << "----------------------------------------------" << '\n';
    std::cout << "------"<< "Tomburan Longriver's Savory Dishes" << "------" << std::endl;
    std::cout << "----------------------------------------------" << '\n';
    std::cout << "QTY" << std::setw(13) << "DISH NAME" << std::setw(12) <<
    "UNIT PRICE" << std::setw(16) << "TOTAL RECEIVED" << std::endl;
    std::cout << "----------------------------------------------" << '\n';
    std::cout << '\n';
    std::cout << Mushroom << "      " << "Mushrooms" << std::setw(7) << '$' << ' ' << .8 << std::setw(11) << '$' << ' ' << mush_sold << std::endl;
    std::cout << Lembas << "      " << "Lembas" << std::setw(10) << '$' << ' ' << 3.0 << std::setw(11) << '$' << ' ' << lem_sold << std::endl;
    std::cout << Cram_Bread << "      " << "Cram Bread" << std::setw(6) << '$' << ' ' << 2.0 << std::setw(11) << '$' << ' ' << cram_sold << std::endl;
    std::cout << Salt_Pork << "      " << "Salted Pork" << std::setw(5) << '$' << ' ' << 2.25 << std::setw(11) << '$' << ' ' << salt_sold << std::endl;
    std::cout << Rab_Stew << "      " << "Rabbit Stew" << std::setw(5) << '$' << ' ' << 3.25 << std::setw(11) << '$' << ' ' << rab_sold << std::endl;
    std::cout << Hon_Cake << "      " << "Honey Cake" << std::setw(6) << '$' << ' ' << 2.0 << std::setw(11) << '$' << ' ' << hon_sold << std::endl;
    std::cout << Well_Wat << "      " << "Well Water" << std::setw(6) << '$' << ' ' << 1.25 << std::setw(11) << '$' << ' ' << well_sold << std::endl;
    std::cout << std::setw(45) << "---------" << '\n' << '\n';
    std::cout << std::setw(30) << "TOTAL RECEIVED" << std::setw(8) << '$' << ' ' << total << '\n';
    std::cout << std::setw(30) << "CUT TAKEN" << std::setw(8) << '$' << ' ' << cut << '\n';
    std::cout << std::setw(30) << "TOTAL MINUS CUT" << std::setw(8) << '$' << ' ' << tot_min_cut << '\n';
    std::cout << '\n' << '\n' << "Total Profit pre-cut: " << '$' << prof_pre_cut << '\n';

}