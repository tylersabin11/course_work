#ifndef ZENTHARIAN_H
#define ZENTHARIAN_H_H
#include <array>
#include <fstream>

const int kMaxZen{1000};
const int kMaxCrystal{20};

class Zentharian{

private:
    //Count for the Zen
    int m_ZenCount{0};
    //Count for the amount of Crystals that Zen has
    int m_CrystalCount{0};
    //Count for the total of the Crystals
    int m_crystalTotal{0};
    //File object
    std::string m_inFileName{0};
    //Array for the crystals then Zen has
    std::array<int,kMaxCrystal> m_arrCrystals{};

public:
    //open the file
    bool open_file();
    //Process the file
    void process_file();
    //Update the class members;
    void display_info();
    //Overloaded operator for comparison
    bool operator > (Zentharian& rhs);
};

#endif