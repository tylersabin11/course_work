#ifndef BOARD_H
#define BOARD_H
#include "Tile.h"

class Board{
private:
    int m_width{};
    int m_height{};
    int m_size{};
    int mine_count{};
    //Row
    int m_x{};
    //Col
    int m_y{};
    Tile *tile{nullptr};
    Tile *board{nullptr};

public:
    //default constructor
    Board(int, int, int);
    //function called place_mines; will randomly place mines on a board
    void place_mines();
    // //function called update_counts; will show the amount of mines near the tile
    void update_counts();

    //Constructor for play board
    void construct_playBoard();
    //View the Play board
    void view_playBoard();

    void get_game_input();
    void PlayGame();
    
    // //function called revealed_board to display the board in 2-d fasshion
    void revealed_board();
    //default destructor
    ~Board(){
        delete[] tile;
    }
};
    

#endif