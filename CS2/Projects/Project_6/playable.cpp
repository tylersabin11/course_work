#include <iostream>
#include "Board.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "Tile.h"

int main(){

    int width{};
    int height{};
    int mines{};

    std::cout << "Enter width of the board: ";
    std::cin >> width;
    std::cout << "Enter the height of the board: ";
    std::cin >> height;
    std::cout << "Enter the amount of mines: ";
    std::cin >> mines;
    std::cout << '\n';

    Board sampleBoard(width,height,mines);
    sampleBoard.place_mines();
    sampleBoard.update_counts();
    sampleBoard.construct_playBoard();
    sampleBoard.PlayGame();

    return 0;
}