#include <iostream>
#include "board.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "Tile.h"

int main(){

    int width{};
    int height{};

    std::cout << "Enter width of the board: ";
    std::cin >> width;
    std::cout << "Enter the height of the board: ";
    std::cin >> height;
    std::cout << '\n';

    Board sampleBoard(width,height);
    sampleBoard.place_mines();
    sampleBoard.update_counts();
    sampleBoard.revealed_board();

    return 0;
}