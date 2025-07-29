#include <iostream>
#include "Board.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "Tile.h"


//Loop through the array, and set the index to 0
//Initialize mine_count to 10
Board::Board(int width, int height, int mine){
    m_width = width;
    m_height = height;
    m_size = m_width * m_height;
    tile = new Tile[m_size];

    for(int i{0}; i < m_size; i++){
        tile[i].update_tile('0');
    }

    mine_count = mine;
}

void Board::place_mines(){
    //Seed the random number generator 
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    
    for(int i{0}; i < mine_count; i++){
        //Produce a random index
        int index = std::rand() % m_size;

        //Check to see if the index is already a mine
        if(tile[index].get_tile() != 'M'){
            //If a mine is not present, place the mine
            tile[index].update_tile('M');
        } else{
            //If no mine is placed, subtract one
            //As we did not place a mine
            i--;
        }
    }
    
}

//Loop through the array, print out the index
void Board::revealed_board(){
    std::cout << '\n';
    for(int i{0}; i < m_width; i++){
        std::cout << "|---";
    }
    std::cout << "|\n";
    for(int i{0}; i < m_size; i++){
        if(i % m_width == 0 && i != 0){
            std::cout << '\n';
            for(int i{0}; i < m_width; i++){
                std::cout << "|---";
            }
            std::cout << "|\n";
        }
        std::cout << '|' << std::setw(2) << tile[i].get_tile() << ' ' ;
        if((i+1) % m_width == 0){
            std::cout << '|';
        }
    }
    std::cout << '\n';
    for(int i{0}; i < m_width; i++){
        std::cout << "|---";
    }
    std::cout << "|\n";
}

void Board::update_counts(){
    int row{-1};
    int col{0};
    int count{0};
    for(int index{0}; index < m_size; index++){
        if(index % m_width == 0){
            row++;
        }
        //index = width * row + column
        if(tile[index].get_tile() != 'M'){
        //if row is 0
            if(row == 0){
                //if col is 0
                if(col == 0){
                        //check index + m_width, index + m_width + 1, index + 1
                    if(tile[index + m_width].get_tile() == 'M'){count += 1;}
                    if(tile[index + m_width + 1].get_tile() == 'M'){count += 1;}
                    if(tile[index + 1].get_tile() == 'M'){count += 1;}
                    tile[index].update_tile(static_cast<char>(count + '0'));
                    }
                //else if col is (m_width - 1) 
                else if(col == (m_width -1)){
                    //check index + m_width, index + m_width - 1, index -1
                    if(tile[index + m_width].get_tile() == 'M'){count += 1;}
                    if(tile[index + m_width - 1].get_tile() == 'M'){count += 1;}
                    if(tile[index - 1].get_tile() == 'M'){count += 1;}
                    tile[index].update_tile(static_cast<char>(count + '0'));
                }
                //else
                else{
                    //check index +/- 1, index + m_width, index + m_width +/- 1
                    if(tile[index + m_width].get_tile() == 'M'){count += 1;}
                    if(tile[index + m_width + 1].get_tile() == 'M'){count += 1;}
                    if(tile[index + m_width - 1].get_tile() == 'M'){count += 1;}
                    if(tile[index + 1].get_tile() == 'M'){count += 1;}
                    if(tile[index - 1].get_tile() == 'M'){count += 1;}
                    tile[index].update_tile(static_cast<char>(count + '0'));
                }
            }
            //else if row is (m_height - 1)
            else if(row == (m_height - 1)){
                //if col is 0 
                if(col == 0){
                    //check index - m_width, index - m_width + 1, index + 1
                    if(tile[index - m_width].get_tile() == 'M'){count += 1;}
                    if(tile[index - m_width + 1].get_tile() == 'M'){count += 1;}
                    if(tile[index + 1].get_tile() == 'M'){count += 1;}
                    tile[index].update_tile(static_cast<char>(count + '0'));
                }
                //else if col is (m_width - 1)
                else if(col == (m_width - 1)){
                    //check index - m_width, index - m_width - 1, index -1
                    if(tile[index - m_width].get_tile() == 'M'){count += 1;}
                    if(tile[index - m_width - 1].get_tile() == 'M'){count += 1;}
                    if(tile[index - 1].get_tile() == 'M'){count += 1;}
                    tile[index].update_tile(static_cast<char>(count + '0'));
                }
                //else
                else{
                    //check index +/- 1, index - m_width, index - m_width +/- 1
                    if(tile[index - m_width].get_tile() == 'M'){count += 1;}
                    if(tile[index - m_width + 1].get_tile() == 'M'){count += 1;}
                    if(tile[index - m_width - 1].get_tile() == 'M'){count += 1;}
                    if(tile[index + 1].get_tile() == 'M'){count += 1;}
                    if(tile[index - 1].get_tile() == 'M'){count += 1;}
                    tile[index].update_tile(static_cast<char>(count + '0'));
                }
            }
            //else
            else{
                //if col is 0
                if(col == 0){
                    //check index +/- m_width, index +/- m_width + 1, index + 1
                    if(tile[index + m_width].get_tile() == 'M'){count += 1;}
                    if(tile[index - m_width].get_tile() == 'M'){count += 1;}
                    if(tile[index - m_width + 1].get_tile() == 'M'){count += 1;}
                    if(tile[index + m_width + 1].get_tile() == 'M'){count += 1;}
                    if(tile[index + 1].get_tile() == 'M'){count += 1;}
                    tile[index].update_tile(static_cast<char>(count + '0'));
                }
                //else if col is (m_width - 1)
                else if(col == (m_width - 1)){
                    //check index +/- m_width, index +/- m_width - 1, index -1
                    if(tile[index + m_width].get_tile() == 'M'){count += 1;}
                    if(tile[index - m_width].get_tile() == 'M'){count += 1;}
                    if(tile[index - m_width - 1].get_tile() == 'M'){count += 1;}
                    if(tile[index + m_width - 1].get_tile() == 'M'){count += 1;}
                    if(tile[index - 1].get_tile() == 'M'){count += 1;}
                    tile[index].update_tile(static_cast<char>(count + '0'));
                }
                //else
                else{
                    //check index +/- m_width, index +/- m_width +/- 1, index +/- 1
                    if(tile[index + m_width].get_tile() == 'M'){count += 1;}
                    if(tile[index - m_width].get_tile() == 'M'){count += 1;}
                    if(tile[index - m_width - 1].get_tile() == 'M'){count += 1;}
                    if(tile[index + m_width - 1].get_tile() == 'M'){count += 1;}
                    if(tile[index - m_width + 1].get_tile() == 'M'){count += 1;}
                    if(tile[index + m_width + 1].get_tile() == 'M'){count += 1;}
                    if(tile[index - 1].get_tile() == 'M'){count += 1;}
                    if(tile[index + 1].get_tile() == 'M'){count += 1;}
                    tile[index].update_tile(static_cast<char>(count + '0'));
                }
            }
        }
        if(col == (m_width - 1)){
            col = 0;
            count = 0;
        }else{
            col++;
            count = 0;
        }
    }
}

void Board::construct_playBoard(){

    board = new Tile[m_size];

    for(int i{0}; i < m_size; i++){
        board[i].update_piece('#');
    }
}

void Board::view_playBoard(){
    std::cout << '\n';
    for(int i{0}; i < m_width; i++){
        std::cout << "|---";
    }
    std::cout << "|\n";
    for(int i{0}; i < m_size; i++){
        if(i % m_width == 0 && i != 0){
            std::cout << '\n';
            for(int i{0}; i < m_width; i++){
                std::cout << "|---";
            }
            std::cout << "|\n";
        }
        std::cout << '|' << std::setw(2) << board[i].get_piece() << ' ' ;
        if((i+1) % m_width == 0){
            std::cout << '|';
        }
    }
    std::cout << '\n';
    for(int i{0}; i < m_width; i++){
        std::cout << "|---";
    }
    std::cout << "|\n";
}

void Board::get_game_input(){
    int tempX{};
    int tempY{};
    std::cout << "Enter a row and column to dig: ";
    std::cin >> tempX >> tempY;
    m_x = tempX;
    m_y = tempY;
}

void Board::PlayGame(){
    view_playBoard();
    get_game_input();
    //Convert to an index
    int index = (m_width * m_x) + m_y;
    //Intialize the count to 1 since the user already made a move
    int count{1};
    //Check to see if it is a mine & the count is less than the size - mine count
    while(tile[index].get_tile() != 'M' && count < (m_size - mine_count)){
        board[index].update_piece(tile[index].get_tile());
        count++;
        view_playBoard();
        get_game_input();
        index = (m_width * m_x) + m_y;
    }
    //Update the last tile
    board[index].update_piece(tile[index].get_tile());
    std::cout << '\n';
    //Check to see if won or lost
    if(count == (m_size - mine_count)){
        std::cout << "YOU'VE WON!!!" << '\n';
        std::cout << "Final Board:" << '\n';
        view_playBoard();
        std::cout << '\n';
    }else{
        std::cout << "YOU'VE LOST!!!" << '\n';
        std::cout << "Final Board:" << '\n';
        revealed_board();
        std::cout << '\n';
    }
}