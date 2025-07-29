#ifndef BOARD_H
#define BOARD_H
#include "Tile.h"

const int kRowSize {8};
const int kColSize {8};

class Board{
private:
    int m_width{};
    int m_height{};
    int m_size{};
    Tile *tile{nullptr};
    int mine_count{};

public:
    //default constructor
    Board(int, int);
    //function called place_mines; will randomly place mines on a board
    void place_mines();
    // //function called update_counts; will show the amount of mines near the tile
    void update_counts();
    // //function called revealed_board to display the board in 2-d fasshion
    void revealed_board();

    //default destructor
    ~Board(){
        delete[] tile;
    }
};
    

#endif