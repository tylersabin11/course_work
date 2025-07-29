#include <iostream>
#include <string>

int main(){
    std::string Title{};
    int Num{};
    std::string Name{};
    std::string Alien_Name{};
    float FloNum{};
    std::string Noun{};
    std::string PlurNoun{};

    std::cout << "Suggest a Sci-Fi themed title:\n";
    std::getline(std::cin, Title);

    std::cout << "Enter an integer:\n";
    std::cin >> Num;

    std::cout << "Enter a cool name:\n";
    std::cin.ignore();
    std::getline(std::cin, Name);

    std::cout << "Suggest an alien race name:\n";
    std::cin >> Alien_Name;

    std::cout << "Enter a floating point number:\n";
    std::cin >> FloNum;

    std::cout << "Enter a singular noun:\n";
    std::cin >> Noun;

    std::cout << "Enter a plural noun:\n";
    std::cin >> PlurNoun;

    std::cout << '\n' << "\"" << Title << "\"" << '\n' << '\n';
    std::cout << "In the year " << Num << " , a daring explorer named " << Name 
    << " embarked on a crucial mission. Armed with a mysterious family heirloom passed down for " << FloNum 
    << " generations, " << Name << " journeyed through space." << '\n' << '\n';
    std::cout << "An urgent plea for help arrived from the " << Alien_Name << " , whose homeworld faced destruction in just days."
    << '\n' << '\n';
    std::cout << "In fact, it would be destroyed by Friday at 5:00pm (which is coincidentally when Labs are due)" << '\n' << '\n';
    std::cout << "With unyielding resolve, " << Name << " encountered a strange " << Noun << " and unexpected " << PlurNoun << ", inching closer to the " << Alien_Name 
    << "\'s planet. As " << Name << " neared their destination, the fate of the galaxy rested on their shoulders, with just a few hours to save the " << Alien_Name << " 's world from annihilation." 
    << '\n';
}